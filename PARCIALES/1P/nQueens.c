#include <stdio.h>

#define DIRS 4

int nQueens(unsigned int n, char mat[n][n]);
int amenaza(unsigned int n, char movs[n][n], int fil, int col);

int main(){
    // Test case 1: Valid 4x4 board with 4 queens
    char board1[4][4] = {
        {'0', '1', '0', '0'},
        {'0', '0', '0', '1'},
        {'1', '0', '0', '0'},
        {'0', '0', '1', '0'}
    };
    if (!nQueens(4, board1)) return 1;

    // Test case 2: Invalid 4x4 board with queens threatening each other
    char board2[4][4] = {
        {'1', '0', '0', '0'},
        {'0', '1', '0', '0'},
        {'0', '0', '0', '0'},
        {'0', '0', '0', '0'}
    };
    if (nQueens(4, board2)) return 1;

    // Test case 3: Valid 1x1 board
    char board3[1][1] = {{'1'}};
    if (!nQueens(1, board3)) return 1;

    // Test case 4: Invalid board with queens in same row
    char board4[4][4] = {
        {'1', '1', '0', '0'},
        {'0', '0', '0', '0'},
        {'0', '0', '0', '0'},
        {'0', '0', '0', '0'}
    };
    if (nQueens(4, board4)) return 1;

    // Test case 5: Invalid board with queens in same diagonal
    char board5[4][4] = {
        {'1', '0', '0', '0'},
        {'0', '0', '0', '0'},
        {'0', '0', '1', '0'},
        {'0', '0', '0', '0'}
    };
    if (nQueens(4, board5)) return 1;

    puts("OK!");
    return 0;
}

int nQueens(unsigned int n, char mat[n][n]){
    int queens = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if(mat[i][j] == '1'){
                queens++;
                if(amenaza(n, mat, i, j)){
                    return 0;
                }
            }
        }
        
    }
    return 1;
}

int amenaza(unsigned int n, char mat[n][n], int fil, int col){
    static int movs[][2] = {{1, 0}, {0, 1}, {1, -1}, {1, 1}};       // ABAJO    DERECHA     DIAGONALABAJOIZQ       DIAGONALABAJODER
    for (int i = 0; i < DIRS; i++){
        int xAct = col + movs[i][1], yAct = fil + movs[i][0];
        while (xAct >= 0 && xAct < n && yAct >= 0 && yAct < n){
            if(mat[yAct][xAct] == '1')
                return 1;
            xAct += movs[i][1];
            yAct += movs[i][0];
        }
    }
    return 0;
}