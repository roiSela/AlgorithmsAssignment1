#include <iostream> 
#include "graph.h"
using namespace std;


int main()
{
    graph g;
    g.MakeEmptyGraph(5);
    cout<<g.AddEdge(1, 2)<<endl;
    cout<<g.IsAdjacent(1,2)<<endl;
    cout<<g.IsAdjacent(2,1);
    g.RemoveEdge(1,2);
    cout<<g.IsAdjacent(1,2);

}