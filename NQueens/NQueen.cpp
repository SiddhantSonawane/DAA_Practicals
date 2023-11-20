#include<bits/stdc++.h>
using namespace std;

void printsolution(vector<vector<int>>&board)
{
    for(int i=0; i<board.size(); i++){
        for(int j=0; j<board.size(); j++){
            if(board[i][j]) cout<<"Q ";
            else cout<<"* ";
        }
        cout<<endl;
    }
}

bool ispossibletoplace(vector<vector<int>>&board, int row, int col, int n)
{
    for(int i=0; i<col; i++){
        if(board[row][i]) return false;
    }

    for(int i=row,j=col; i>=0&&j>=0; i--,j--){
        if(board[i][j]) return false;
    }

    for(int i=row,j=col; i<n&&j>=0; i++,j--){
        if(board[i][j]) return false;
    }
    return true;
}

bool recursivenqueen(vector<vector<int>>&board, int col, int n)
{
    if(col>=n) return true;
    for(int i=0; i<n; i++)
    {
        if(ispossibletoplace(board, i, col, n))
        {
            board[i][col] = 1;
            if(recursivenqueen(board, col+1, n))
            {
                cout << "\nValid configuration found:\n";
                printsolution(board);
                return true;
            }
            board[i][col] = 0;
        }
    }
    cout << "\nInvalid placement of queen: \n";
    printsolution(board);

    return false;
}
int main()
{
    int n;
    cout<<"Enter Number of Queens: ";
    cin>>n;
    if(n<=3)
    {
        cout<<"NO Possible Combination!";
        return 0;
    }
    vector<vector<int>>board(n, vector<int>(n,0));
    recursivenqueen(board, 0, n);
    cout<<"\nThe Final Solution is: \n"<<endl;
    printsolution(board);
    cout<<"\n\n"<<endl;
    return 0;
}