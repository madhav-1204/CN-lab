// Kruskal's Algorithm
#include <iostream>
using namespace std;

int main()
{
    int n, cost[10][10], parent[10] = {0};
    int minCost = 0, edges = 1;

    cout << "\nImplementation of Kruskal's Algorithm for Broadcast Tree\n";
    cout << "\nEnter the number of vertices: ";
    cin >> n;

    cout << "\nEnter the cost adjacency matrix:\n";

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> cost[i][j];

            if (cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }

    cout << "\nThe edges of Minimum Cost Spanning Tree are:\n";

    while (edges < n)
    {
        int min = 999, a = 0, b = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (cost[i][j] < min)
                {
                    min = cost[i][j];
                    a = i;
                    b = j;
                }
            }
        }

        int u = a, v = b;

        while (parent[u] != 0)
            u = parent[u];

        while (parent[v] != 0)
            v = parent[v];

        if (u != v)
        {
            cout << edges << ". Edge (" << a << ", " << b
                 << ") = " << min << endl;

            minCost += min;
            edges++;
            parent[v] = u;
        }

        cost[a][b] = cost[b][a] = 999;
    }

    cout << "\nMinimum Cost = " << minCost << endl;

    return 0;
}


// Enter the number of vertices: 4

// Enter the cost adjacency matrix:
// 0 10 6 5
// 10 0 0 15
// 6 0 0 4
// 5 15 4 0