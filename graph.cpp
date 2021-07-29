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
	s = -1;
	t = -1;
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
	//cout << "The graph is:" << endl;
	for (int i = 0; i < NumOfVerticesInAdjacencyList; i++)
	{

		//cout << "The vertex " << adjacencyList[i].value << " has edges to the following vertices:";
		Node<Edge>* head = adjacencyList[i].neighbors.getHeadOfList();
		while (head)
		{
			cout <<"     "<< adjacencyList[i].value << "     "<< head->data << "\n";
			head = head->next;
		}
		

	}
}

int graph::IsEmpty()
{
	if (adjacencyList == nullptr || NumOfVerticesInAdjacencyList == 0)
		return 1;
	else
		return 0;
}

void graph::makeTransposeGraph(graph& g)
{

	//allocate vertices for g transpose
	int numOfVertices = g.getNumOfVerticesInAdjacencyList();
	this->MakeEmptyGraph(numOfVertices);


	//we go through every possible combination of edges
	for (int i = 0; i < numOfVertices; i++)
	{
		for (int j = 0; j < numOfVertices; j++)
		{
			if (g.IsAdjacent(i + 1, j + 1))
			{
				this->AddEdge(j + 1, i + 1);
			}
		}
	}
}


graph graph::findShortestPathsGraph()
{
	//step 1: run BFS from vertex s.
	List<int> Q;
	int sizeOfArray = this->getNumOfVerticesInAdjacencyList();
	int* d = new int[sizeOfArray];
	for (int i = 0; i < sizeOfArray; i++)
	{
		d[i] = infinity;
	}
	Q.push(this->s);
	d[this->s - 1] = 0;

	while (Q.isThisListEmpty() == false)
	{
		int u = Q.pop(); // u <- Q.Dequeu()
		List<Edge> AdjOfU = this->GetAdjList(u);
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

	//step 2: delete from the graph every edge (u,v) that does not live up
	// to the condition d[v] = d[u] + 1
	//to the graph we get lets call Gs

	for (int i = 0; i < sizeOfArray; i++)
	{
		for	(int j = 0; j < sizeOfArray; j++)
		{
			if (d[j] != d[i] + 1)
			{
				this->RemoveEdge(i + 1, j + 1);
			}
		}
	}

	

	//step 3: build Gs transpose 
	
	graph GsTranspose;
	GsTranspose.makeTransposeGraph((*this));


	//step 4: preform bfs on GsT and now run in from vertex t
	//delete every edge that is not eccessible from t 
	//to the graph we get lets call H_transpose

	List<int> QOfGsT;
	//sizeOfArray stays the same
	int* d_OfGsT = new int[sizeOfArray];

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//lets allocate a 2d array to all posible edges so we can easily delete afterwards the edges that are not eccesible from t
	int** allEdges = new int*[sizeOfArray];
	for (int i = 0; i < sizeOfArray; i++)
	{
		allEdges[i] = new int[sizeOfArray];
	}

	//lets make every 2d array memeber to zero first. 
	for (int i = 0; i < sizeOfArray; i++)
	{
		for (int j = 0; j < sizeOfArray; j++)
		{
			allEdges[i][j] = 0;
		}
	}
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


	for (int i = 0; i < sizeOfArray; i++)
	{
		d_OfGsT[i] = infinity;
	}
	QOfGsT.push(this->t);
	d_OfGsT[this->t - 1] = 0;

	while (QOfGsT.isThisListEmpty() == false)
	{
		int u = QOfGsT.pop(); // u <- Q.Dequeu()
		List<Edge> AdjOfU = GsTranspose.GetAdjList(u);
		Node<Edge>* currentAdj = AdjOfU.getHeadOfList();
		while (currentAdj)
		{
			//first lets mark to ourselfs that this edge has been visited
			allEdges[u-1][currentAdj->data-1] = 1;

			if (d_OfGsT[currentAdj->data - 1] == infinity)
			{
				d_OfGsT[currentAdj->data - 1] = d_OfGsT[u - 1] + 1;
				QOfGsT.push(currentAdj->data);
			}

			currentAdj = currentAdj->next;
		}

	}

	//now lets delete every edge that is not eccessible from t
	for (int i = 0; i < sizeOfArray; i++)
	{
		for (int j = 0; j < sizeOfArray; j++)
		{
			if (allEdges[i][j] == 0)
			{
				GsTranspose.RemoveEdge(i + 1, j + 1);
			}
		}
	}




	//step 5: from H_transpose build H
	graph H;
	H.makeTransposeGraph(GsTranspose);



	H.PrintGraph(); //this is the answer

	//free alloc memory
	delete[] d;
	delete[] d_OfGsT;
	return H;
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