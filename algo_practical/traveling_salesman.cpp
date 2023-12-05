// BEGIN: Brute Force TSP
#include<bits/stdc++.h>
using namespace std;

int calculateDistance(vector<int>& path, vector<vector<int>>& graph) {
    int distance = 0;
    for (int i = 0; i < path.size() - 1; i++) {
        distance += graph[path[i]][path[i + 1]];
    }
    return distance;
}

int main() {
    int n; // number of cities
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n));

    // Read the graph input
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    vector<int> path(n);
    for (int i = 0; i < n; i++) {
        path[i] = i;
    }

    int minDistance = INT_MAX;
    vector<int> optimalPath;

    // Generate all possible permutations of the path
    do {
        int distance = calculateDistance(path, graph);
        if (distance < minDistance) {
            minDistance = distance;
            optimalPath = path;
        }
    } while (next_permutation(path.begin() + 1, path.end()));

    cout << "Optimal Path: ";
    for (int i = 0; i < n; i++) {
        cout << optimalPath[i] << " ";
    }
    cout << endl;

    cout << "Optimal Distance: " << minDistance << endl;

    return 0;
}
// END: Brute Force TSP
