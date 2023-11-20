#include<bits/stdc++.h>
using namespace std;
#define Inf INT_MAX

class Node
{
public:
    int vertex;
    int cost;
    vector<vector<int>>graph;
    Node(){}
    Node(int v, vector<vector<int>> g)
    {
        this->vertex = v;
        this->graph = g;
    }

    int calcCost(int r, int c)
    {
        int n = this->graph.size();
        for(int i = 0; i < n;i++){
            for(int j = 0; j <n;j++){
                if(i==r || j==c) graph[i][j] = INT_MAX;
            }
        }
        graph[c][r] = INT_MAX;
        int cost = 0;

        vector<int>rowReduce = vector<int>(n,0);
        vector<int>colReduce = vector<int>(n,0);

        cout<<"Calculation for the Vertex: "<<c<<endl;

        //row wise reduction
        cout<<"Minimum Row Wise: ";
        for(int i=0; i < n; i++)
        {
            int mini = INT_MAX;
            for(int j=0; j < n; j++) mini = min(graph[i][j],mini);
            if(mini==INT_MAX) mini =0;
            cost += mini;
            rowReduce[i] = mini;
            cout<<mini<<" ";
            for(int j=0; j < n; j++) if(graph[i][j]!=0 && graph[i][j]!=INT_MAX) graph[i][j] -=mini;
        }

        //col wise reduction
        cout<<"Minimum Col Wise: ";
        for(int i=0; i < n; i++)
        {
            int mini = INT_MAX;
            for(int j=0; j < n; j++) mini = min(graph[j][i],mini);
            if(mini==INT_MAX) mini =0;
            cost += mini;
            colReduce[i] = mini;
            cout<<mini<<" ";
            for(int j=0; j < n; j++) if(graph[j][i]!=0 && graph[j][i]!=INT_MAX) graph[j][i] -=mini;
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
    
    Node root(0, graph);
    int totalcost = root.calcCost(-1,-1);
    cout<<"\nRoot Node Cost: "<<totalcost<<endl;

    vector<int>visited(n,0);
    visited[0]=1;

    vector<int>sequence;

    int c =1;
    Node last = root;

    while(c<n)
    {
        int mini = Inf;
        Node minNode;
        for(int i=1;i<n;i++)
        {
            if(visited[i]==1) continue;
            
            Node n(i, last.graph);

            int cost = n.calcCost(last.vertex,i)+last.graph[last.vertex][i];

            if(mini > cost)
            {
                mini = cost;
                minNode = n;
            }

            cout<<"\nCost of Node "<<i<<" is: "<<cost+totalcost<<endl;
        }
        
        totalcost+=mini;
        last=minNode;
        c++;
        visited[last.vertex] = 1;
        sequence.push_back(last.vertex);
        cout<<"\nMinimum Found!!"<<totalcost<<endl;
        cout<<"\n\n";
    }

    cout<<"The Path is: 1 ->";
    for(int i=0;i<sequence.size();i++)
    {
        cout<<sequence[i]+1<<" ->";
    }
    cout<<"The total cost is: "<<totalcost<<endl;
    return 0;
}