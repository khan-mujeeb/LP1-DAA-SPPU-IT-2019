#include<stdio.h>
#define n 4
int count = 0;

void nQueens(int board[n][n], int col);
void display(int board[n][n]);
int isSafe(int board[n][n], int row, int col);

int main() {
    int board[n][n];
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            board[i][j] = 0;
        }
    }
    nQueens(board,0);
    return 0;
}

void nQueens(int board[n][n], int col) {
    if(col==n) {
        count++;
        printf("\nSolution %d",count);
        printf("\n");
        display(board);
        return;
    }
    
    for(int row=0;row<n;row++) {
        if(isSafe(board,row,col)) {
            board[row][col] = 1;
            nQueens(board,col+1);
            board[row][col] = 0;
        }
    }
}

void display(int board[n][n]) {
    printf("\n");
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            printf("%d ",board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int isSafe(int board[n][n], int row, int col) {
    // row check
    for(int i=col;i>=0;i--) {
        if(board[row][i]==1) {
            return 0;
        }
    }

    // upper diagonal check
    int i = row;
    int j = col;
    
    while(i>=0 && j>=0) {
        if(board[i][j]==1) {
            return 0;
        }
        i--;
        j--;
    }

     // lower diagonal check
    i = row;
    j = col;
    while(i<n && j>=0) {
        if(board[i][j]==1) {
            return 0;
        }
        i++;
        j--;
    }

    return 1;
}