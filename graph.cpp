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
    if(u>NumOfVerticesInAdjacencyList || u<1 || v>NumOfVerticesInAdjacencyList || v<1 || IsEmpty())
        return false;
    else
        return adjacencyList[u-1].neighbors.search(v);
}

List<Edge> graph::GetAdjList(int u)
{
	return adjacencyList[u-1].neighbors;
}

int graph::AddEdge(int u, int v)
{
    if(u>NumOfVerticesInAdjacencyList || u<1 || v>NumOfVerticesInAdjacencyList || v<1)
        return 0;
    else {
        adjacencyList[u - 1].neighbors.push(Edge(v));
        return 1;
    }
}

void graph::RemoveEdge(int u, int v)
{
    adjacencyList[u-1].neighbors.deleteListMember(v);
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
