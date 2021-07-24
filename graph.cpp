#include "graph.h"


Edge::Edge(int value, int weight) : value(value), weight(weight) {}

Edge::Edge(int value) : value(value) {weight=1;}

bool Edge::operator==(const Edge &edge) const {
    return value == edge.value;
}

bool Edge::operator==(const int &val) const {
    return value==val;
}

bool Edge::operator!=(const Edge &edge) const {
    return !(edge == *this);
}

Edge & Edge::operator=(Edge edge) {
    this->value = edge.value;
    this->weight = edge.weight;
    return *this;
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
    adjacencyList[u].neighbors.push(Edge(v,c));
}

void graph::RemoveEdge(int u, int v)
{
    adjacencyList[u].neighbors.deleteListMember(v);
}

void graph::ReadGraph()
{
}

void graph::PrintGraph()
{
}

int graph::IsEmpty()
{
	if(adjacencyList== nullptr || NumOfVerticesInAdjacencyList==0)
	    return 1;
	else
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
