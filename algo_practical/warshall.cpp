/* 
   The problem is to find the shortest distances between every pair of vertices in a given edge-weighted directed graph. 
   The graph is represented as an adjacency matrix of size n*n. Matrix[i][j] denotes the weight of the edge from i to j. 
   If Matrix[i][j]=-1, it means there is no edge from i to j. 
*/


// With weights of edges

// #include<bits/stdc++.h>
// using namespace std;

// vector<vector<int>> shortest_distance(int V, vector<vector<int>> &matrix) {

//     for(int i=0; i<V; i++) {
//         for(int j=0; j<V; j++) {
//             if(matrix[i][j]==-1)
//                 matrix[i][j] = 1e9; // as this pair doesn't have an edge in between, so distance not possible, so putting it out of reach
//             if(i==j)
//                 matrix[i][j] = 0;
//         }
//     }

//     for(int k=0; k<V; k++) { // all these vertices will be used to traverse in between all pairs
//         for(int i=0; i<V; i++) {
//             for(int j=0; j<V; j++) {
//                 matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
//             }
//         }
//     }

//     for(int i=0; i<V; i++) {
//         for(int j=0; j<V; j++) {
//             if(matrix[i][j]==1e9)
//                 matrix[i][j] = -1;
//         }
//     }

//     return matrix;
// }

// int main() {

//     int V; // number of vertices
//     cout << "Enter the number of vertices: ";
//     cin >> V;

//     vector<vector<int>> matrix(V, vector<int>(V));

//     cout << "Enter the adjacency matrix:\n";
//     for (int i = 0; i < V; i++) {
//         for (int j = 0; j < V; j++) {
//             cin >> matrix[i][j];
//         }
//     }

//     vector<vector<int>> shortest_dist = shortest_distance(V, matrix);

//     for (int i = 0; i < V; i++) {
//         for (int j = 0; j < V; j++) {
//             cout << shortest_dist[i][j] << " ";
//         }
//         cout << endl;
//     }

//     return 0;
// }

// ------------------------------------------------------ XXX ------------------------------------------------------------------- //

// Without weights of edges

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> shortest_distance(int V, vector<vector<int>> &matrix) {

    for(int k=0; k<V; k++) { // all these vertices will be used to traverse in between all pairs
        for(int i=0; i<V; i++) {
            for(int j=0; j<V; j++) {
                if(matrix[i][k]==1 && matrix[k][j]==1)
                    matrix[i][j] = 1;
            }
        }
    }

    return matrix;
}

int main() {

    int V; // number of vertices
    cout << "Enter the number of vertices: ";
    cin >> V;

    vector<vector<int>> matrix(V, vector<int>(V));

    cout << "Enter the adjacency matrix:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> matrix[i][j];
        }
    }

    vector<vector<int>> matrix_path = shortest_distance(V, matrix);

    cout << "The effective matrix path required is: \n";

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cout << matrix_path[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
