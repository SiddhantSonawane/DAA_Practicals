#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,c;
    cout<<"Enter numof items and initial capacity: "<<endl;
    cin >> n>>c;
    vector<pair<int,int>>pw(n);
    cout<<"Enter weights of items: "<<endl;
    for(int i=0; i<n; i++){
        cin>>pw[i].first;
    }
    cout<<"Enter profits of items: "<<endl;
    for(int i=0; i<n; i++){
        cin>>pw[i].second;
    }

    int mat[n+1][c+1];

    for(int i=0;i<n+1;i++){
        mat[i][0]=0;
    }
    for(int i=0;i<c+1;i++){
        mat[0][i]=0;
    }

    for(int i=1;i<n+1; i++)
    {
        for(int j=0;j<c+1;j++)
        {
            if(j>=pw[i-1].first)
            {
               if(pw[i-1].second+mat[i-1][j-pw[i-1].first]>mat[i-1][j])
               {
                    mat[i][j] = pw[i-1].second+mat[i-1][j-pw[i-1].first];
               }else mat[i][j] = mat[i-1][j];
            }else mat[i][j] = mat[i-1][j];
        }
    }

    cout<<"Matrix is: "<<endl;
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<c+1;j++)
        {
            cout<<mat[i][j]<<"\t";
        }
        cout<<endl;
    }
    int totalprofit = mat[n][c];
    int i = n, j=c;
    while(i>0)
    {
        if(mat[i][j]==mat[i-1][j]) i--;
        else{
            cout<<"Item is picked with profit: "<<pw[i-1].second<<" weight: "<<pw[i-1].first<<endl;
            i--;
            j-=pw[i-1].first;
        }
    }
    cout<<"max profit is: "<<totalprofit<<endl;
    return 0;
}