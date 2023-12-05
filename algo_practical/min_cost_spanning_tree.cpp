/*
Find Minimum Cost Spanning Tree of a given undirected graph using Kruskal’s algorithm.
*/

#include <bits/stdc++.h>
using namespace std;

int i,j,k,a,b,u,v,n,ne=1;
int cost[9][9], mincost = 0, parent[9];

int find(int i) {
    while(parent[i])
        i = parent[i];
    return i;
}

int uni(int i, int j) {
    if(i!=j) {
        parent[j] = i;
        return 1;
    }
    return 0;
}

int main() {
    cout << "Enter number of vertices: " << endl;
    cin >> n;

    cout << "\nEnter the cost adjacency matrix\n";
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++) {
            cin >> cost[i][j];

            if(cost[i][j]==0)
                cost[i][j]=999;
        }
    }

    cout << "\nThe edges of Minimum Cost Spanning Tree are\n\n";
    while(ne < n) {
        for(i=1,mincost=999;i<=n;i++) {
            for(j=1; j<=n;j++) {
                if(cost[i][j] < mincost) {
                    mincost=cost[i][j];
                    a=u=i;
                    b=v=j;
                }
            }
        }

        while(parent[u])
            u=parent[u];

        while(parent[v])
            v=parent[v];

        if(u!=v) {
            cout << ne++ << " edge (" << a << "," << b << ") = " << mincost << endl;
            mincost += mincost;
            parent[v]=u;
        }

        cost[a][b]=cost[b][a]=999;
    }

    cout << "\nMinimum cost = " << mincost << endl;
    
}
