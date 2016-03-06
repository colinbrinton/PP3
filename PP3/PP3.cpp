// PP3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Graph.h"
#include <iostream>
#include <fstream>
#include <string> 


using namespace std;

int main()
{
	const int NO_ERRORS = 0;

	Graph graph;

	char* file("graph0.txt");

	cout << file << endl << endl;

	graph.load(file);
	graph.display();
	graph.displayDFS(0);
	graph.displayBFS(0);

	cin.get();

	return NO_ERRORS;
}

