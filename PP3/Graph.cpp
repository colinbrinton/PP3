
#include "stdafx.h"
#include "Graph.h"
#include <iostream>
#include <fstream>
#include <string> 
#include <queue>

using namespace std;

Graph::~Graph()
{
	const int EMPTY = 0;
	if (numVert != EMPTY)
	{
		matrixCleanUp(numVert);
	}
}

void Graph::load(char* filename)
{
	const char DELIM = '\n';
	const int SIZE_INDEX = 0;
	const int EDGES_START = 2;
	const int CONNECTION = 1;
	const int PARSE_SPACE = 2;
	string line;
	string allText = "";
	ifstream inputGraph(filename);
	if (inputGraph.is_open())
	{
		while (getline(inputGraph, line))
		{
			allText += line + DELIM;
		}
		inputGraph.close();
	}

	else cout << "Unable to open file";

	string temp;
	int inputVal;
	temp = allText[SIZE_INDEX];
	inputVal = stoi(temp);

	allocateMatrix(inputVal);
	numVert = inputVal;

	int node1;
	int node2;

	int i = EDGES_START;
	int edgesEnd = allText.size() - PARSE_SPACE;

	for (int i = EDGES_START; i < edgesEnd; i += PARSE_SPACE)
	{
		temp = allText[i];
		inputVal = stoi(temp);
		node1 = inputVal;
		i += 2;
		temp = allText[i];
		inputVal = stoi(temp);
		node2 = inputVal;

		adjMatrix[node1][node2] = CONNECTION;
		adjMatrix[node2][node1] = CONNECTION;
	}
}

void Graph::display()
{
	cout << "Adjacency Matrix" << endl;
	for (int i = 0; i < numVert; ++i)
	{
		for (int k = 0; k < numVert; ++k)
		{
			cout << adjMatrix[k][i] << " ";
		}
		cout << endl;
	}
}

void Graph::displayDFS(int vertex)
{
	const int INITIAL = 0;
	int* visited = new int[numVert];
	for (int i = 0; i < numVert; i++)
	{
		visited[i] = INITIAL;
	}

	cout << "DFS at vertex " << vertex << ": ";
	recursiveDFS(vertex, visited);
	cout << endl;

	delete[] visited;
}

void Graph::recursiveDFS(int vertex, int* visited)
{
	const int CONNECTION = 1;
	const int VISITED = 1;
	int k = 0;
	if (!(visited[vertex] == VISITED))
		cout << vertex << " ";
	visited[vertex] = VISITED;

	while (k < numVert && ((!(adjMatrix[vertex][k] == CONNECTION) || visited[k] == VISITED)))
		k++;

	if (k < numVert)
		recursiveDFS(k, visited);
}

void Graph::displayBFS(int vertex)
{
	const int CONNECTION = 1;
	const int VISITED = 1;
	const int INITIAL = 0;
	int* visited = new int[numVert];
	for (int i = 0; i < numVert; i++)
	{
		visited[i] = INITIAL;
	}

	queue<int> search;
	cout << "BFS at vertex " << vertex << ": ";
	search.push(vertex);
	cout << search.front() << " ";
	visited[search.front()] = VISITED;
	while (!search.empty())
	{
		vertex = search.front();
		for (int i = 0; i < numVert; i++)
		{
			if ((adjMatrix[vertex][i] == CONNECTION) && !(visited[i] == VISITED))
			{
				search.push(i);
				cout << i << " ";
				visited[i] = VISITED;
			}
		}
		search.pop();
	}

	cout << endl;
	delete[] visited;
}

void Graph::allocateMatrix(int size)
{
	const int INITIAL = 0;

	adjMatrix = new int*[size];
	for (int i = 0; i < size; ++i)
		adjMatrix[i] = new int[size];

	for (int i = 0; i < size; i++)
	{
		for (int k = 0; k < size; k++)
		{
			adjMatrix[i][k] = INITIAL;
		}
	}
}

void Graph::matrixCleanUp(int size)
{
	for (int i = 0; i < size; ++i) {
		delete[] adjMatrix[i];
	}
	delete[] adjMatrix;
}
