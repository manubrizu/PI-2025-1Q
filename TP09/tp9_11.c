#include <stdio.h>
#include <assert.h>

#define MAX 10
#define MAX_DIR 4

void reemplazo(int matriz[][MAX], int dim, int fil, int col);
void reemplazoRec(int matriz[][MAX], int dim, int fil, int col, int dir[]);

int main(void) {

  int m[5][MAX] = { {1,0,1,0,1},
                    {0,1,1,1,1},
                    {1,0,0,1,0},
                    {1,1,1,0,1},
                    {0,0,0,0,0}};
  reemplazo(m, 5, 1, 2);
  int m2[5][MAX] = { {1,1,1,1,1},
                    {0,1,0,1,1},
                    {1,1,0,0,0},
                    {0,1,1,0,0},
                    {0,0,0,0,0}};
  for(int i=0; i < 5; i++)
     for(int j=0; j<5; j++)
        assert(m[i][j]==m2[i][j]);
  reemplazo(m, 5, 1, 2);
  reemplazo(m, 5, 1, 2);
  for(int i=0; i < 5; i++)
     for(int j=0; j<5; j++)
        assert(m[i][j]==m2[i][j]);

  printf ("OK!\n");
  return 0;
}

void reemplazo(int matriz[][MAX], int dim, int fil, int col){
    int dir[][2] = { {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
    matriz[fil][col] = !(matriz[fil][col]);
    for (int i = 0; i < MAX_DIR; i++){
        reemplazoRec(matriz, dim, fil, col, dir[i]);
    }
    
}


void reemplazoRec(int matriz[][MAX], int dim, int fil, int col, int dir[]){
    fil += dir[0];
    col += dir[1];
    if(fil < 0 || fil > MAX || col < 0 || col > MAX){
        return;
    } 

    matriz[fil][col] = !(matriz[fil][col]);
    reemplazoRec(matriz, dim, fil, col, dir);
}