#include "graph.h"

const int infinity = -1;

Edge::Edge(int value, int weight) : value(value), weight(weight) {}

Edge::Edge(int value) : value(value) { weight = 1; }

bool Edge::operator==(const Edge& edge) const {
	return value == edge.value;
}

bool Edge::operator==(const int& val) const {
	return value == val;
}

bool Edge::operator!=(const Edge& edge) const {
	return !(edge == *this);
}

Edge& Edge::operator=(Edge edge) {
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
	for (int i = 0; i < NumOfVerticesInAdjacencyList; i++)
	{
		adjacencyList[i].neighbors.deleteTheList();
	}

	delete[] adjacencyList;
}

void graph::MakeEmptyGraph(int n)
{
	adjacencyList = new Vertex[n];
	for (int i = 0; i < n; i++)
	{
		adjacencyList[i].value = i + 1;
	}
	NumOfVerticesInAdjacencyList = n;
}

bool graph::IsAdjacent(int u, int v)
{
	if (u > NumOfVerticesInAdjacencyList || u<1 || v>NumOfVerticesInAdjacencyList || v < 1 || IsEmpty())
		return false;
	else
		return adjacencyList[u - 1].neighbors.search(v);
}

List<Edge> graph::GetAdjList(int u)
{
	return adjacencyList[u - 1].neighbors;
}

int graph::AddEdge(int u, int v)
{
	if (u > NumOfVerticesInAdjacencyList || u<1 || v>NumOfVerticesInAdjacencyList || v < 1)
		return 0;
	else {
		adjacencyList[u - 1].neighbors.push(Edge(v));
		return 1;
	}
}

void graph::RemoveEdge(int u, int v)
{
	adjacencyList[u - 1].neighbors.deleteListMember(v);
}

void graph::ReadGraph()
{
	// numbers
	int n;
	int n_2;

	int i = 1;
	while (cin >> n)
	{

		if (i == 1)
		{
			MakeEmptyGraph(n);
		}
		else
		{
			if (i == 2)
			{
				s = n;
			}
			else
			{
				if (i == 3)
				{
					t = n;
				}
				else
				{

					cin >> n_2;
					AddEdge(n, n_2);
				}
			}

		}

		i++;


	}
}

void graph::PrintGraph()
{
	cout << "The graph is:" << endl;
	for (int i = 0; i < NumOfVerticesInAdjacencyList; i++)
	{

		cout << "The vertex " << adjacencyList[i].value << " has edges to the following vertices:";
		Node<Edge>* head = adjacencyList[i].neighbors.getHeadOfList();
		while (head)
		{
			cout << head->data << " ";
			head = head->next;
		}
		cout << "\n";

	}
}

int graph::IsEmpty()
{
	if (adjacencyList == nullptr || NumOfVerticesInAdjacencyList == 0)
		return 1;
	else
		return 0;
}

graph graph::makeTransposeGraph(graph& G)
{
	graph G_transpose;
	//allocate vertices for g transpose
	int numOfVertices = G.getNumOfVerticesInAdjacencyList();
	G_transpose.MakeEmptyGraph(numOfVertices);


	//we go through every possible combination of edges
	for (int i = 0; i < numOfVertices; i++)
	{
		for (int j = 0; j < numOfVertices; j++)
		{
			if (IsAdjacent(i+1, j+1))
			{
				G_transpose.AddEdge(j+1, i+1);
			}
		}
	}


	return G_transpose;
}



graph graph::findShortestPathsGraph(graph G)
{
	//step 1: run BFS from vertex s.
	List<int> Q;
	int sizeOfArray = G.getNumOfVerticesInAdjacencyList();
	int* d = new int[sizeOfArray];
	for (int i = 0; i < sizeOfArray; i++)
	{
		d[i] = infinity;
	}
	Q.push(G.s);
	d[G.s - 1] = 0;

	while (Q.isThisListEmpty() == false)
	{
		int u = Q.pop(); // u <- Q.Dequeu()
		List<Edge> AdjOfU = G.GetAdjList(u);
		Node<Edge>* currentAdj = AdjOfU.getHeadOfList();
		while (currentAdj)
		{
			if (d[currentAdj->data - 1] == infinity)
			{
				d[currentAdj->data - 1] = d[u - 1] + 1;
				Q.push(currentAdj->data);
			}

			currentAdj = currentAdj->next;
		}

	}

	///end of step 1.


	//TO DO: STEPS 2-5..

	graph g;
	return g;
}

graph::graph(graph& graphToCopyFrom)
{
	//first lets copy the int's
	this->NumOfVerticesInAdjacencyList = graphToCopyFrom.NumOfVerticesInAdjacencyList;
	this->s = graphToCopyFrom.s;
	this->t = graphToCopyFrom.t;
	//we must not do a shallow copy,we need to allocate a new list "this->adjacencyList = graphToCopyFrom.adjacencyList"

	//we need to allocate adjacency list of our own.
	this->MakeEmptyGraph(graphToCopyFrom.NumOfVerticesInAdjacencyList);

	//now lets add the edges

	for (int i = 0; i < graphToCopyFrom.NumOfVerticesInAdjacencyList; i++)
	{
		for (int j = 0; j < graphToCopyFrom.NumOfVerticesInAdjacencyList; j++)
		{
			if (graphToCopyFrom.IsAdjacent(i+1, j+1))
			{
				this->AddEdge(i+1, j+1);
			}
		}
	}

}