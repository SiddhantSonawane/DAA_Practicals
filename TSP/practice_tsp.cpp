#include<bits/stdc++.h>
using namespace std;
#define Inf INT_MAX

class Node
{
public:
    int vertex;
    int cost;
    vector<vector<int>>graph;
    Node() {}
    Node(int v, vector<vector<int>>g)
    {
        this->vertex = v;
        this->graph = g;
    }

    int calculateCost(int r, int c)
    {
        int n = this->graph.size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j <n; j++){
                if(i==r || j==c) graph[i][j] = Inf;
            }
        }

        graph[c][r] = Inf;
        int cost = 0;

        cout<<"Calculation for vertex : "<<c<<endl;

        vector<int>row = vector<int>(n,0);
        vector<int>col = vector<int>(n,0);

        cout<<"Minimum Row wise: ";

        for(int i=0; i<n; i++)
        {
            int mini = Inf;
            for(int j=0; j<n; j++) mini = min(mini, graph[i][j]);
            if(mini==Inf) mini=0;
            cost+=mini;
            row[i] = mini;
            cout<<mini<<" ";
            for(int j=0; j<n; j++) if(graph[i][j]!=0 && graph[i][j]!=Inf) graph[i][j]-=mini;
        }

        cout<<"Minimum Column wise: ";

        for(int i=0; i<n; i++)
        {
            int mini = Inf;
            for(int j=0; j<n; j++) mini = min(mini, graph[j][i]);
            if(mini==Inf) mini=0;
            cost+=mini;
            col[i] = mini;
            cout<<mini<<" ";
            for(int j=0; j<n; j++) if(graph[j][i]!=0 && graph[j][i]!=Inf) graph[j][i]-=mini;
        }

        return cost;
    }
};

int main()
{
    vector<vector<int>>graph ={
        { Inf, 20, 30, 10,11 },
        { 15, Inf, 16, 4, 2 },
        { 3, 5, Inf, 2, 4 },
        { 19, 6, 18, Inf, 3 },
        { 16, 4, 7, 16, Inf }
    };

    int n = graph.size();

    Node Root(0, graph);

    int totalcost = Root.calculateCost(-1,-1);
    cout<<"Cost of the Root is: "<<totalcost<<endl;

    vector<int>visited(n,0);
    visited[0] = 1;

    vector<int>sequence;

    Node last = Root;
    int c = 1;

    while(c<n) 
    {
        int mini = Inf;
        Node minNode;

        for(int i=1; i<n; i++)
        {
            if(visited[i]==1) continue;

            Node n(i, last.graph);

            int cost = n.calculateCost(last.vertex, i)+last.graph[last.vertex][i];

            if(mini > cost)
            {
                mini = cost;
                minNode = n;
            }

            cout<<"Cost of the Node: "<<i+1<<" is "<<cost+totalcost<<endl;
        }

        totalcost+=mini;
        last = minNode;
        c++;
        visited[last.vertex]=1;
        sequence.push_back(last.vertex);

        cout<<"Minimum Cost Found!! "<<totalcost<<endl;
    }

    cout<<"The path is 1";
    for(int i=0; i<sequence.size(); i++) {
        cout<<" -> "<<sequence[i]+1;
    }
    cout<<"\n The total cost is "<<totalcost<<endl;
    return 0;
}