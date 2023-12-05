#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> graph(20, vector<int>(20,0)); 
int visited[20], n, i, j; 

// Function to perform DFS traversal
void DFS(vector<vector<int>>& graph, int currentNode, vector<bool>& visited) {
    visited[currentNode] = true;

    // Traverse all adjacent vertices of the current node
    for (int i = 0; i < graph.size(); i++) {
        if (graph[currentNode][i] && !visited[i]) {
            DFS(graph, i, visited);
        }
    }
}

// Function to check if a graph is connected
bool isConnected(vector<vector<int>>& graph) {
    int numNodes = graph.size();
    vector<bool> visited(numNodes, false);

    // Perform DFS traversal starting from the first node
    DFS(graph, 0, visited);

    // Check if all nodes have been visited
    for (bool nodeVisited : visited) {
        if (!nodeVisited) {
            return false;
        }
    }

    return true;
}

// Function to perform BFS traversal
void BFS(vector<vector<int>>& graph, int startNode) {
    int numNodes = graph.size();
    vector<bool> visited(numNodes, false);

    // Create a queue for BFS
    queue<int> q;

    // Mark the current node as visited and enqueue it
    visited[startNode] = true;
    q.push(startNode);

    while (!q.empty()) {
        // Dequeue a vertex from queue and print it
        int currentNode = q.front();
        q.pop();
        cout << currentNode << " ";

        // Get all adjacent vertices of the dequeued vertex
        // If an adjacent vertex has not been visited, then mark it
        // visited and enqueue it
        for (int i = 0; i < numNodes; i++) {
            if (graph[currentNode][i] && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

int main() {
    cout << "Enter number of vertices: " << endl;
    cin >> n;

    cout << "\nEnter the adjacency matrix\n";
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++) {
            cin >> graph[i][j];
        }
    }

    int startNode = 0; // Starting node for BFS traversal

    cout << "Nodes reachable from node " << startNode << " are: ";
    BFS(graph, startNode);

    bool connected = isConnected(graph);
    if (connected) {
        cout << "The graph is connected." << endl;
    } else {
        cout << "The graph is not connected." << endl;
    }

    return 0;
}
