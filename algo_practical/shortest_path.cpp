// Djikstra's Algorithm

#include <bits/stdc++.h>
using namespace std;

void dij(int size, int s, vector<vector<int>> &cost, vector<int> &dist)
{
    int i, u, count, w, flag[size], mini;

    for (i = 0; i < size; i++)
        flag[i] = 0, dist[i] = cost[s][i];
    count = 2;
    while (count <= size)
    {
        mini = 99;
        for (w = 0; w < size; w++)
            if (dist[w] < mini && !flag[w])
            {
                mini = dist[w];
                u = w;
            }
        flag[u] = 1;
        count++;
        for (w = 0; w < size; w++)
            if ((dist[u] + cost[u][w] < dist[w]) && !flag[w])
                dist[w] = dist[u] + cost[u][w];
    }
}

int main()
{
    int size;
    cout << "Enter the number of vertices: ";
    cin >> size;

    vector<vector<int>> cost(size, vector<int>(size,0));
    vector<int> dist(size, 0);

    cout << "\nEnter the elements of the matrix:\n";
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cin >> cost[i][j];

            if (cost[i][j] == 0)
                cost[i][j] = 1e9;
        }
    }

    cout << "Enter the source vertex" << endl;
    int s;
    cin >> s;

    dij(size, s, cost, dist);

    printf("\n shortest path : \n");
    for (int i = 0; i < size; i++)
        if (i != s)
            printf("%d->%d,cost=%d\n", s, i, dist[i]);
}
