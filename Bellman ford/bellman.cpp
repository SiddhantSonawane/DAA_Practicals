#include <bits/stdc++.h>
using namespace std;

void printPath(int v, vector<int> &parent)
{
    if (v == -1)
        return;
    printPath(parent[v], parent);
    if (parent[v] != -1)
        cout << " -> ";
    cout << v + 1;
}

int main()
{
    // Input
    int v, e;
    cout << "Enter Number of vertices: ";
    cin >> v;
    cout << "Enter Number of Edges: ";
    cin >> e;

    // creating a vector to store distance between the vertices
    vector<vector<int>> cost(e, (vector<int>(3, 0)));
    vector<int> parentnodes(v, -1);

    cout << "Enter the edges one by one in Format(Source-Destination-Distance): \n";
    for (int i = 0; i < e; i++)
    {
        cout << "Edge " << (i + 1) << ": ";
        cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
    }

    // create a vector for storing distance

    int dist[v];
    for (int i = 0; i < v; i++)
    {
        dist[i] = INT_MAX;
    }
    //source
    dist[0] = 0;

    for (int i = 1; i < v; i++)
    {
        for (int j = 0; j < e; j++)
        {
            int u = cost[j][0] - 1;
            int v = cost[j][1] - 1;
            int weight = cost[j][2];

            if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
                parentnodes[v] = u;
            }
        }
    }

    // check for negative weight cycle
    int f = 0;
    for (int j = 0; j < e; j++)
    {
        int u = cost[j][0] - 1;
        int v = cost[j][1] - 1;
        int weight = cost[j][2];

        if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
        {
            cout << "Negative Weight Cycle is present!" << endl;
            return 0;
        }
    }

    // if(f) cout<<"Negative Weight Cycle is present!"<<endl;

    if (f == 0)
    {
        cout << "Vertex\tDistance\tPath" << endl;
        for (int i = 0; i < v; i++)
        {
            cout << i+1 << "\t" << dist[i] << "\t\t";
            printPath(i, parentnodes);
            cout << endl;
        }
    }
    return 0;
}