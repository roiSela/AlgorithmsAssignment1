#include <iostream> 
#include "graph.h"
using namespace std;


int main()
{
    graph g;
    g.MakeEmptyGraph(5);
    g.AddEdge(1,2,1);
    g.RemoveEdge(1,2);
}