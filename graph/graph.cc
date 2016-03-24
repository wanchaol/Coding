#include "../utils.h"

class Graph
{
public:
	Graph (int V);
	void addEdge(int v, int w);
	bool isCyclic();
	virtual ~Graph ();

private:
	int V;
	list<int> *adj;
	bool isCyclicUtil(int v, bool visited[], bool *rs);

};

Graph::Graph(int V) {
	this->V = V;
	adj = new list<int>[V];

}

Graph::~Graph() {
}

void Graph::addEdge(int v, int w) {
	adj[v].push_back(w);
}

bool Graph::isCyclic() {
	
	bool *visited = new bool[V];
	bool *recStack = new bool[V];

	for (int i = 0; i < V; ++i) {
		visited[i] = false;
		recStack[i] = false;
	}

	bool isCycle = false;
	//begin dfs
	for (int i = 0; i < V; ++i) {
		if (isCyclicUtil(i, visited, recStack)) {
			isCycle = true;
			break;
		}
	}
	
	delete[] visited;
	delete[] recStack;

	if (isCycle) {
		return true;
		
	}
	return false;
}

bool Graph::isCyclicUtil(int v, bool visited[], bool *recStack) {
	if (visited[v] == false) {

		visited[v] = true;
		recStack[v] = true;
		
		for(auto i = adj[v].begin(); i != adj[v].end(); ++ i) {
			
			if(!visited[*i] && isCyclicUtil(*i, visited, recStack))
				return true;
			else if(recStack[*i])
				return true;
		}

	}
	
	recStack[v] = false;
	return false;

}

int main()
{
    // Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    //g.addEdge(2, 0);
    g.addEdge(2, 3);
    //g.addEdge(3, 3);
 
    if(g.isCyclic())
        cout << "Graph contains cycle";
    else
        cout << "Graph doesn't contain cycle";
    return 0;
}
