#include<iostream>
#include <list>
#include <stack>
using namespace std;


class ITCertification
{
	int V;


	list<int> *coursearray;

	void topologicalCourseSorting(int v, bool visited[], stack<int> &Stack);
public:
	ITCertification(int V);

	void addEdge(int v, int w);
	void courseSort();
};

ITCertification::ITCertification(int V)
{
	this->V = V;
	coursearray = new list<int>[V];
}

void ITCertification::addEdge(int v, int w)
{
	coursearray[v - 1].push_back(w - 1);
}


void ITCertification::topologicalCourseSorting(int v, bool visited[],
	stack<int> &Stack)
{

	visited[v] = true;


	list<int>::iterator i;
	for (i = coursearray[v].begin(); i != coursearray[v].end(); ++i)
		if (!visited[*i])
			topologicalCourseSorting(*i, visited, Stack);


	Stack.push(v);
}


void ITCertification::courseSort()
{
	stack<int> Stack;


	bool *visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;


	for (int i = 0; i < V; i++)
		if (visited[i] == false)
			topologicalCourseSorting(i, visited, Stack);


	while (Stack.empty() == false)
	{
		cout << Stack.top() + 1 << " ";
		Stack.pop();
	}
}


int main()
{
	cout << "Courses are: " << endl;
	cout << "1: Programming in C " << endl;
	cout << "2: Distributed Computing " << endl;
	cout << "3: Database Systems " << endl;

	cout << "4: Algorithms 1 " << endl;
	cout << "5: Algorithms 2 " << endl;
	cout << "6: Programming in Java " << endl;
	cout << "7: Advanced Programming in Java " << endl;
	cout << "8: Big Data with Apache Spark " << endl;
	cout << "9: Programming in  " << endl;
	cout << "10: Probability " << endl;
	cout << "11: Scalable Machine  " << endl;
	cout << "12: Data Structures " << endl;

	ITCertification crse(12);
	crse.addEdge(1, 2);
	crse.addEdge(6, 2);
	crse.addEdge(11, 2);
	crse.addEdge(1, 3);
	crse.addEdge(6, 3);
	crse.addEdge(7, 3);
	crse.addEdge(8, 3);
	crse.addEdge(12, 3);
	crse.addEdge(1, 4);
	crse.addEdge(3, 4);
	crse.addEdge(9, 4);
	crse.addEdge(1, 5);
	crse.addEdge(3, 5);
	crse.addEdge(4, 5);
	crse.addEdge(12, 5);
	crse.addEdge(1, 6);
	crse.addEdge(6, 7);
	crse.addEdge(6, 8);
	crse.addEdge(7, 8);
	crse.addEdge(10, 8);
	crse.addEdge(12, 8);
	crse.addEdge(5, 9);
	crse.addEdge(8, 11);
	crse.addEdge(10, 11);

	cout << "Following is order of given courses \n";
	crse.courseSort();

	int a = 0;
	cin >> a;
	return 0;
}


