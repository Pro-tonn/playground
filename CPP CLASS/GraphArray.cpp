#include <iostream>

using namespace std;

// Define a node for the adjacency list
class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int val) {
        this->val = val;
        this->next = nullptr;
    }
};

// Graph class
class Graph {
public:
    int V; // Number of vertices
    ListNode** adjLists; // Pointer to an array containing adjacency lists

    // Constructor
    Graph(int V) {
        this->V = V;
        adjLists = new ListNode*[V];
        for (int i = 0; i < V; i++) {
            adjLists[i] = nullptr;
        }
    }

    // Function to add an edge
    void addEdge(int src, int dest) {
        // Add edge from src to dest
        ListNode* newNode = new ListNode(dest);
        newNode->next = adjLists[src];
        adjLists[src] = newNode;

        // Since graph is undirected, add an edge from dest to src also
        newNode = new ListNode(src);
        newNode->next = adjLists[dest];
        adjLists[dest] = newNode;
    }

    // Function to print the graph
    void printGraph() {
        for (int v = 0; v < V; ++v) {
            ListNode* temp = adjLists[v];
            cout << "\nAdjacency list of vertex " << v << "\nhead ";
            while (temp) {
                cout << "-> " << temp->val;
                temp = temp->next;
            }
            cout << endl;
        }
    }

    // Destructor
    ~Graph() {
        for (int i = 0; i < V; i++) {
            ListNode* current = adjLists[i];
            while (current != nullptr) {
                ListNode* next = current->next;
                delete current;
                current = next;
            }
        }
        delete[] adjLists;
    }
};

// Test the graph
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

    // Print the adjacency list representation of the graph
    g.printGraph();

    return 0;
}
