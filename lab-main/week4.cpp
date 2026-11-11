// Dijkstra's Algorithm

#include <iostream>
using namespace std;

#define MAX 10
#define INF 9999

int main()
{
    int cost[MAX][MAX], dist[MAX], visited[MAX], parent[MAX];
    int n, source, destination;
    int min, next, path[MAX], count = 0;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter the cost matrix:\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> cost[i][j];

            if (cost[i][j] == 0 && i != j)
                cost[i][j] = INF;
        }
    }

    cout << "Enter source vertex: ";
    cin >> source;

    cout << "Enter destination vertex: ";
    cin >> destination;

    for (int i = 0; i < n; i++)
    {
        dist[i] = cost[source][i];
        visited[i] = 0;

        if (cost[source][i] != INF)
            parent[i] = source;
        else
            parent[i] = -1;
    }

    dist[source] = 0;
    visited[source] = 1;
    parent[source] = -1;

    for (int i = 1; i < n; i++)
    {
        min = INF;
        next = -1;

        for (int j = 0; j < n; j++)
        {
            if (visited[j] == 0 && dist[j] < min)
            {
                min = dist[j];
                next = j;
            }
        }

        if (next == -1)
            break;

        visited[next] = 1;

        for (int j = 0; j < n; j++)
        {
            if (visited[j] == 0 && cost[next][j] != INF &&
                dist[next] + cost[next][j] < dist[j])
            {
                dist[j] = dist[next] + cost[next][j];
                parent[j] = next;
            }
        }
    }

    if (dist[destination] == INF)
    {
        cout << "\nNo path exists.";
    }
    else
    {
        cout << "\nMinimum Cost = " << dist[destination] << endl;

        int i = destination;

        while (i != -1)
        {
            path[count] = i;
            count++;
            i = parent[i];
        }

        cout << "Shortest Path: ";

        for (int i = count - 1; i >= 0; i--)
        {
            cout << path[i];

            if (i != 0)
                cout << " -> ";
        }
    }

    return 0;
}


// Enter number of vertices: 4
// Enter the cost matrix:
// 0 2 4 0
// 2 0 1 7
// 4 1 0 3
// 0 7 3 0
// Enter source vertex: 0
// Enter destination vertex: 3