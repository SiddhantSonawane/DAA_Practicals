#include<bits/stdc++.h>
using namespace std;

void printsolution(vector<vector<int>>&board)
{
    for(int i = 0; i < board.size();i++){
        for(int j = 0; j < board.size();j++){
            if(board[i][j]!=0){
                cout<<"Q"<<board[i][j]<<"\t";
            }else{
                cout<<"*\t";
            }
        }
        cout<<endl;
    }
}

bool issafetoplace(vector<vector<int>>&board, int row, int col, int n)
{
    for(int i = 0; i < col; i++){
        if(board[row][i]!=0) return false;
    }

    for(int i=row,j=col; i>=0&&j>=0 ; i--,j--){
        if(board[i][j]!=0) return false;
    }

    for(int i=row,j=col; i<n&&j>=0 ; i++,j--){
        if(board[i][j]!=0) return false;
    }

    return true;
}


bool nqueen(vector<vector<int>>&board, int col, int n)
{
    if(col>=n) return true;
    for(int i=0; i<n;i++)
    {
        if(issafetoplace(board,i,col,n))
        {
            board[i][col] = col+1;
            cout<<"Queen "<<col+1<<"Placed!!"<<endl;
            printsolution(board);
            if(nqueen(board,col+1,n)){
                return true;
            }
            board[i][col]=0;
        }
    }
    cout<<"can't place queen backtrack for queen number "<<col+1<<endl;
    printsolution(board);

    return false;
}

int main()
{
    int q;
    cout<<"Enter the number of queens"<<endl;
    cin >> q;

    if(q<=3) 
    {
        cout<<"Impossible"<<endl;
        return 0;
    }

    vector<vector<int>> board(q, vector<int>(q,0));
    nqueen(board,0,q);
    cout<<"the final solution is: "<<endl;
    printsolution(board);
    return 0;
}