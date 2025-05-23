/* Completed by Vinicius Intravartola (WIP) */
#include "Graph.h"

using namespace std;

/* Graph implementation: Shortest-paths to find most similar users and their interests */

// define constructor
Graph::Graph() { }

// define destructor (must match the header)
Graph::~Graph() { }


/* Adds a vertex to the graph if it does not already exist */
void Graph::addVertex(const string& vertex) 
{
    /* Create an empty list for this vertex */
    if (adjList.find(vertex) == adjList.end())  { adjList[vertex] = {}; }
}

/* Adds an edge(a connection between two identifiers of a user in the data).If undirected is true, adds an edge directed in the opposite direction too */
void Graph::addEdge(const string& from, const string& to, bool undirected)
{
    /* Add 'from' and 'to' vertices to the list*/
    addVertex(from); 
    addVertex(to); 

    adjList[from].push_back(to);

    if (undirected == true)    { adjList[to].push_back(from); }
}

/* Prints the contents of the adjacency list */
void Graph::printGraph() const
{
    cout << "Graph Adjacency List:" << endl;

    for (auto const& pair : adjList)
    {
        cout << pair.first << " -> ";
        auto const &neighbors = pair.second;

        for (unsigned int i = 0; i < neighbors.size(); ++i) 
        {
            cout << neighbors[i];

            if (i + 1 < neighbors.size())   { cout << ", "; }
        }

        cout << "\n";
    }


}

