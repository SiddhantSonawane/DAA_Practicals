#include<bits/stdc++.h>
using namespace std;

int main()
{
    int c,n;
    cout<<"\nEnter the capacity and number of items: ";
    cin>>c>>n;
    vector<pair<int,int>>pw(n);
    cout<<"\nEnter weights of the items: ";
    for(int i=0;i<n;i++){
        cin>>pw[i].first;
    }
    cout<<"\nEnter Profits of the items: ";
    for(int i=0;i<n;i++){
        cin>>pw[i].second;
    }

    int mat[n+1][c+1];

    for(int i=0;i<n+1;i++){
        mat[i][0] = 0;
    }
    for(int i=0; i<c+1;i++){
        mat[0][i] = 0;
    }

    for(int i=1; i<n+1; i++)
    {
        for(int j=0; j<c+1; j++)
        {
            if(j>=pw[i-1].first)
            {
                if(pw[i-1].second + mat[i-1][j-pw[i-1].first] > mat[i-1][j])
                {
                    mat[i][j] = pw[i-1].second + mat[i-1][j-pw[i-1].first];
                }
                else
                {
                    mat[i][j] = mat[i-1][j];
                }
            }
            else
            {
                mat[i][j] = mat[i-1][j];
            }
        }
    }

    cout<<"The matrix is : "<<endl;
    for(int i=0; i<n+1; i++)
    {
        for(int j=0; j<c+1; j++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }

    int i=n,j=c;
    while(i>0)
    {
        if(mat[i][j]==mat[i-1][j])
        {
            i--;
        }
        else
        {
            cout<<"Item picked "<<i<<" its wt is "<<pw[i-1].first<<" and profit is "<<pw[i-1].second<<endl;
            i--;
            j-=pw[i-1].first;
        }
    }

    cout<<"The total profit is : "<<mat[n][c]<<endl;
    return 0;
}