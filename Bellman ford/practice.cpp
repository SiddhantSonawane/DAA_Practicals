#include<bits/stdc++.h>
using namespace std;


void printpath(int v, vector<int>&parent)
{
    if(v==-1) return;
    printpath(parent[v], parent);
    if(parent[v]!=-1) cout<<" -> ";
    cout<<v+1;
}

int main()
{
    int v,e;
    cout<<"Enter Number of vertices and number of edges: "<<endl;
    cin>>v>>e;
    vector<vector<int>>cost(e, vector<int>(3,0));
    vector<int>parentNodes(v,-1);

    cout<<"Enter source - destination - distance: "<<endl;
    for(int i=0;i<e;i++)
    {
        cout<<"Edge "<<i+1<<endl;
        cin>>cost[i][0]>>cost[i][1]>>cost[i][2];
    }

    int dist[v];
    for(int i=0;i<v;i++)
    {
        dist[i] = INT_MAX;
    }
    dist[0] = 0;

    for(int i=1; i<v;i++)
    {
        for(int j=0;j<e;j++)
        {
            int u = cost[j][0]-1;
            int v = cost[j][1]-1;
            int weight = cost[j][2];

            if(dist[u]!=INT_MAX && dist[u]+weight<dist[v])
            {
                dist[v] = dist[u]+weight;
                parentNodes[v] = u;
            }
        }
    }

    for(int j=0;j<e;j++)
    {
        int u = cost[j][0]-1;
        int v = cost[j][1]-1;
        int weight = cost[j][2];

        if(dist[u]!=INT_MAX && dist[u]+weight<dist[v])
        {
            cout<<"Negative edge cycle!!";
            return 0;
        }
    }

    cout << "Vertex\tDistance\tPath" << endl;
    for(int i=0;i<v;i++)
    {
        cout<<i+1<<"\t"<<dist[i]<<"\t\t";
        printpath(i,parentNodes);
        cout<<endl;
    }
    return 0;
}