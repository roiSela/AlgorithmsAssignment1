#pragma once 
#include<iostream>
#include "list.h"
using namespace std;



class Edge {
	int value;
	int weight;
public:
	Edge(int value, int weight);
	Edge(int value);

	bool operator==(const Edge& edge) const;
	bool operator==(const int& val) const;
	bool operator!=(const Edge& edge) const;
	Edge& operator=(Edge edge);
	operator int() { return value; }

};

class Vertex
{
public:
	int value;
	List<Edge> neighbors;
};


class graph
{
private:
	Vertex* adjacencyList;
	int NumOfVerticesInAdjacencyList;
	int s;
	int t;
public:
	graph();
	graph(graph& graphToCopyFrom);
	~graph(); //free all memory

	//creates a graph without bows with n vertices.
	void MakeEmptyGraph(int n);

	//if the bow (u,v) is in the graph return true, else return false.
	bool IsAdjacent(int u, int v);


	//returns a linked list of the neighbors of u
	List<Edge> GetAdjList(int u);

	//adding the edge (u,v) with weight of c
	int AddEdge(int u, int v);


	//Removing the edge (u,v) from the graph
	void RemoveEdge(int u, int v);


	//reading the graph from file
	void ReadGraph();


	//Prints graph
	void PrintGraph();

	//return 1 if the graph is empty 0 else
	int IsEmpty();

	//given a graph g, we make the graph that uses this function into g^t (he needs to be empty);
	void makeTransposeGraph(graph& g);



	int getNumOfVerticesInAdjacencyList()
	{
		return NumOfVerticesInAdjacencyList;
	}

	//The algorithem we were requested to implement.
	graph findShortestPathsGraph();

};

