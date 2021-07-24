#include "graph.h"


Edge::Edge(int value, int weight) : value(value), weight(weight) {}

Edge::Edge(int value) : value(value) {weight=1;}

bool Edge::operator==(const Edge &edge) const {
    return value == edge.value;
}

bool Edge::operator!=(const Edge &edge) const {
    return !(edge == *this);
}

graph::graph()
{
	adjacencyList = nullptr;
	NumOfVerticesInAdjacencyList = 0;
}

graph::~graph()
{
    //TODO
}

void graph::MakeEmptyGraph(int n)
{
    adjacencyList = new Vertex[n];
    NumOfVerticesInAdjacencyList = n;
}

bool graph::IsAdjacent(int u, int v)
{
    return adjacencyList[u].neighbors.search(v);
}

List<Edge> graph::GetAdjList(int u)
{
	return adjacencyList[u].neighbors;
}

void graph::AddEdge(int u, int v, int c)
{

}

void graph::RemoveEdge(int u, int v)
{
}

void graph::ReadGraph()
{
}

void graph::PrintGraph()
{
}

int graph::IsEmpty()
{
	return 0;
}

int graph::AddEdge(int i, int j)
{
	return 0;
}

List<int> graph::Adj(int i)
{
	return List<int>();
}
