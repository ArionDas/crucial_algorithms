#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited, stack<int>& st) {
    visited[node] = true;
    
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, graph, visited, st);
        }
    }
    
    st.push(node);
}

vector<int> topologicalSort(vector<vector<int>>& graph, int n) {
    vector<bool> visited(n, false);
    stack<int> st;
    
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, graph, visited, st);
        }
    }
    
    vector<int> result;
    while (!st.empty()) {
        result.push_back(st.top());
        st.pop();
    }
    
    return result;
}

int main() {
    int n, m;
    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> m;
    
    vector<vector<int>> graph(n);
    
    cout << "Enter the edges:\n";
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }
    
    vector<int> sortedOrder = topologicalSort(graph, n);
    
    cout << "Topological Sort: ";
    for (int node : sortedOrder) {
        cout << node << " ";
    }
    
    return 0;
}
