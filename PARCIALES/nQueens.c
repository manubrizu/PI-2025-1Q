#include <stdio.h>

int nQueens(unsigned int n, char mat[n][n]);
int amenaza(unsigned int n, char movs[n][n], int fil, int col);

int main(){
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
    static int movs[][2] = {{1, 0}, {0, 1}, {1, -1}, {1, 1}};
    for (int i = 0; i < sizeof(mat) / sizeof(mat[0]); i++){
        int xAct = col + movs[i][1], yAct = fil + movs[i][0];
        while (xAct >= 0 && xAct < n && yAct >= 0 && yAct < 0){
            if(mat[yAct][xAct] == '1')
                return 1;
            xAct += movs[i][1];
            yAct += movs[i][0];
        }
    }
    return 0;
}