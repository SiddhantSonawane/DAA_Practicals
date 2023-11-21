#include<bits/stdc++.h>
using namespace std;

void printSolution(vector<vector<int>>&board)
{
    for (int i = 0; i < board.size();i++)
    {
        for (int j = 0; j < board.size(); j++)
        {
            if(board[i][j]!=0) cout<<"Q  ";
            else cout<<"*  ";
        }
        cout<<endl;
    }
}

bool issafe(vector<vector<int>>&board, int row, int col, int n)
{
    for(int i = 0; i < col; i++){
        if(board[row][i]!=0) return false;
    }

    for(int i=row,j=col; i>=0&&j>=0; i--,j--){
        if(board[i][j]!=0) return false;
    }

    for(int i=row,j=col;i<n&&j>=0; i++,j--){
        if(board[i][j]!=0) return false;
    }

    return true;
}

bool nqueen(vector<vector<int>>&board, int col, int n) 
{
    if(col>=n) return true;
    for(int i = 0; i < n; i++)
    {
        if(issafe(board, i, col, n))
        {
            board[i][col] = col+1;
            cout<<"Queen "<<col+1<<" placed!!"<<endl;
            printSolution(board);
            cout<<endl;
            if(nqueen(board, col+1, n))
            {
                return true;
            }
            board[i][col] = 0;
        }
    }
    cout<<"Unable to place queen number "<<col+1<<endl;
    cout<<"BackTracking!!!"<<endl;
    printSolution(board);
    cout<<endl;
    return false;
}


int main()
{
    int n;
    cout<<"Enter number of queens: ";
    cin>>n;
    vector<vector<int>> board(n, vector<int>(n,0));

    nqueen(board, 0, n);
    return 0;
}