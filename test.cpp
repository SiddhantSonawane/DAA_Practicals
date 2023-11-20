#include<bits/stdc++.h>
using namespace std;

void printsolution(vector<vector<int>>& board) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board.size(); j++) {
            if (board[i][j] != 0) {
                cout << "Q" << board[i][j] << " ";
            } else {
                cout << "* ";
            }
        }
        cout << endl;
    }
}

bool ispossibletoplace(vector<vector<int>>& board, int row, int col, int n) {
    for (int i = 0; i < col; i++) {
        if (board[row][i] != 0) {
            return false;
        }
    }

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] != 0) {
            return false;
        }
    }

    for (int i = row, j = col; i < n && j >= 0; i++, j--) {
        if (board[i][j] != 0) {
            return false;
        }
    }
    return true;
}

bool recursivenqueen(vector<vector<int>>& board, int col, int n) {
    if (col >= n) {
        return true;
    }
    for (int i = 0; i < n; i++) {
        if (ispossibletoplace(board, i, col, n)) {
            board[i][col] = col + 1; // Set the queen number
            cout << "\nQueen " << col + 1 << " placed:\n";
            printsolution(board);

            if (recursivenqueen(board, col + 1, n)) {
                return true;
            }

            board[i][col] = 0;
        }
    }
    cout << "\nBacktracking from Queen " << col + 1 << ":\n";
    printsolution(board);
    return false;
}

int main() {
    int n;
    cout << "Enter Number of Queens: ";
    cin >> n;
    if (n <= 3) {
        cout << "NO Possible Combination!";
        return 0;
    }
    vector<vector<int>> board(n, vector<int>(n, 0));
    if (!recursivenqueen(board, 0, n)) {
        cout << "\nNo valid configuration found.\n";
    }
    cout << "\nThe Final Solution is: \n" << endl;
    printsolution(board);
    cout << "\n\n" << endl;
    return 0;
}
