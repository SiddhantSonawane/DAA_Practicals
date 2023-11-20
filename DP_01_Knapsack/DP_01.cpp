#include<bits/stdc++.h>
using namespace std;

int main()
{
    //Taking Input
    int capacity,items;
    cout<<"\nEnter Capacity: ";
    cin>>capacity;
    cout<<"\nEnter the no. of items: ";
    cin>>items;
    vector<pair<int,int>>pw(items);
    cout<<"\nEnter Profits and weights of the items"<<endl;
    cout<<"\nEnter Weights: ";
    for(int i=0; i<items; i++){
        cin>>pw[i].first;
    }
    cout<<"\nEnter Profits: ";
    for(int i=0; i<items; i++){
        cin>>pw[i].second;
    }

    cout<<"\n\n\nThe Data is as Follows: "<<endl;
    cout<<"============================================================="<<endl;
    cout<<"Item NUmber: ->\t\t";
    for(int i=1; i<=items; i++) cout<<i<<"\t";
    cout<<"\n-------------------------------------------------------------"<<endl;
    cout<<"\nWeights(in Kg): ->\t";
    for(int i=0; i<items; i++)
        cout<<pw[i].first<<"\t";
    cout<<"\nProfits(in Rs): ->\t";
    for(int i=0; i<items; i++)
        cout<<pw[i].second<<"\t";
    cout<<"\n============================================================="<<endl;

    //Creating a matrix for storing the values
    int mat[items+1][capacity+1];
    for(int i=0; i<capacity+1; i++){
        mat[0][i]=0;
    }
    for(int i=0; i<items+1; i++){
        mat[i][0]=0;
    }

    for(int i=1; i<items+1; i++)
    {
        for(int j=0; j<capacity+1; j++)
        {
            if(j>= pw[i-1].first)
            {
                if((pw[i-1].second+mat[i-1][j-pw[i-1].first]) > mat[i-1][j])
                {
                    mat[i][j]= pw[i-1].second+mat[i-1][j-pw[i-1].first];
                }
                else
                {
                    mat[i][j]=mat[i-1][j];
                } 
            }else mat[i][j]=mat[i-1][j];
        }
    }

    cout<<"\nThe Matrix Will look like: "<<endl;
    cout<<"-------------------------------------------------"<<endl;
    for(int i=0; i<items+1; i++)
    {
        for(int j=0; j<capacity+1; j++)
        {
            cout<<mat[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<"-------------------------------------------------"<<endl;

    cout<<"============================================================="<<endl;
    cout<<"The Items getting Picked Are: "<<endl;
    int i=items,j=capacity;
    while(i>0)
    {
        if(mat[i][j]==mat[i-1][j])
        {
            i--;
        }
        else
        {
            cout<<"\nItem Picked: "<<i<<"\tIts Weight: "<<pw[i-1].first<<"\tIts Profit: "<<pw[i-1].second<<endl;
            i--;
            j=j-pw[i-1].first;
        }
    }
    cout<<"\nMaximum Profit Achieved is: "<<mat[items][capacity]<<endl;
    cout<<"\n\n\n"<<endl;
    return 0;
}