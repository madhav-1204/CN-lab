// Distance Vector Routing
#include <iostream>
using namespace std;

int main()
{
    int n, cost[20][20], dist[10][20], nextHop[10][20];
    int count;

    cout << "Enter the number of nodes: ";
    cin >> n;

    cout << "Enter the cost matrix:\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> cost[i][j];

            if (i == j)
                cost[i][j] = 0;

            dist[i][j] = cost[i][j];
            nextHop[i][j] = j;
        }
    }

    do
    {
        count = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    if (dist[i][j] > cost[i][k] + dist[k][j])
                    {
                        dist[i][j] = cost[i][k] + dist[k][j];
                        nextHop[i][j] = k;
                        count++;
                    }
                }
            }
        }

    } while (count != 0);

    for (int i = 0; i < n; i++)
    {
        cout << "\n\nRouting table for Router " << i + 1 << endl;
        cout << "Destination\tNext Hop\tDistance\n";

        for (int j = 0; j < n; j++)
        {
            cout << j + 1 << "\t\t"
                 << nextHop[i][j] + 1 << "\t\t"
                 << dist[i][j] << endl;
        }
    }

    return 0;
}


// Enter the number of nodes: 3
// Enter the cost matrix:
// 0 2 7
// 2 0 1
// 7 1 0