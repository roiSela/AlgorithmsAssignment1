#pragma once 

#include<iostream>
#include "graph.h"
#include "list.h"
using namespace std;



class Vertex
{
public:
	int value;
	List<int> neighbors;
};



class graph
{
private:
	Vertex* adjacencyList;
	int NumOfVerticesInAdjacencyList;
public:

	graph();
	~graph(); //free all memory

	//creates a graph without bows with n vertices.
	void MakeEmptyGraph(int n);

	//if the bow (u,v) is in the graph return true, else return false.
	bool IsAdjacent(int u, int v);


	//returns a linked list of the neighbors of u
	List<int> GetAdjList(int u);

	//adding the edge (u,v) with weight of c
	void AddEdge(int u, int v, int c);


	//Removing the edge (u,v) from the graph
	void RemoveEdge(int u, int v);


	//reading the graph from file
	void ReadGraph();


	//Prints graph
	void PrintGraph();



	//return 1 if the graph is empty 0 else
	int IsEmpty();


	//add the edge (i,j), return 1 if we succed in adding it,0 if error
	int AddEdge(int i, int j);


	//returns a linked list of the neighbors of i
	List<int> Adj(int i);



};

