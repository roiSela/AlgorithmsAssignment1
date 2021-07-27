#include <iostream> 
#include "graph.h"
using namespace std;


int main()
{
    graph g;
    g.ReadGraph();
    
    //g.MakeEmptyGraph(5);
    //cout << g.AddEdge(1, 2) << endl;
    //cout << g.IsAdjacent(1, 2) << endl;

    g.RemoveEdge(3, 1);
   
    g.AddEdge(3, 2);
    g.AddEdge(3, 5);
    g.PrintGraph();
    graph copy = g;
    
       
       g.PrintGraph();
    copy.PrintGraph();
   // g.PrintGraph();
    //cout << g.IsAdjacent(2, 4) <<endl;
  
}