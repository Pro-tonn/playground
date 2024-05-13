#include <iostream>
#include <vector>

using namespace std;

// Graph class represents an undirected graph using adjacency vectors
class Graph {
public:
    int V; // Number of vertices
    vector<vector<int>> adj; // Vector of vectors for Adjacency List Representation

    // Constructor
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    // Function to add an edge between two vertices
    void addEdge(int v, int w) {
        adj[v].push_back(w);
        adj[w].push_back(v); // Because the graph is undirected
    }

    // Function to print the adjacency list representation of the graph
    void printGraph() {
        for (int i = 0; i < V; ++i) {
            cout << "Vertex " << i << ":\n";
            for (int x : adj[i])
                cout << "-> " << x;
            cout << endl;
        }
    }
};

int main() {
    // Create a graph given in the above diagram (5 vertices)
    Graph g(5); // 5 vertices numbered from 0 to 4
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    // Print the adjacency list representation of the above graph
    g.printGraph();

    return 0;
}
