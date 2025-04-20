#include <stdio.h>
#include <assert.h>

#define COLS 4

int sonAmigas(int (m1[])[COLS], unsigned int fils1,int (m2[])[COLS], unsigned int fils2 );

int esAmiga(int (m1[])[COLS], unsigned int fils1, int (m2[])[COLS], unsigned int fils2 );

// devuelve 1 si vec es amigo de alguna fila de m
int vecEnMatriz(const int vec[], int (m[])[COLS], unsigned int fils);

// devuelve 1 si vec1 esta contenido en vec2
int contiene(const int vec1[], const int vec2[], int dim);

int 
main(void)
{
  int m1[][COLS] = {{0,1,2,3}, {4,4,5,6}, {7,8,8,9}};
  int m2[][COLS] = {{0,1,2,3}, {-3,7,8,9}, {-1,3,4,7}, {4,5,6,8}};
  int m3[][COLS] = {{2,3,3,7}};
  assert(sonAmigas(m1,3,m2,4)==1);
  assert(sonAmigas(m1,1,m2,4)==1);
  assert(sonAmigas(m1,2,m2,4)==1);
  assert(sonAmigas(m1,2,m2,2)==0);
  assert(sonAmigas(m2,4,m1,3)==2);
  assert(sonAmigas(m1,3,m3,1)==0);
  assert(sonAmigas(m3,1,m1,3)==0);
  int res = sonAmigas(m1,3,m1,3);
  assert(res==1 || res==2);
  
  printf("OK !\n");

  return 0;
}


int contiene(const int vec1[], const int vec2[], int dim){
    int i, j;
    for (i = 0, j = 0; i < dim && j < dim; ){
        if(vec1[i] < vec2[j]){
            return 0;
        }
        else if(vec1[i] == vec2[j]){
            i++;
        }
        else{
            j++;
        }
    }

    return (i == dim);
    
    /*
    for (int i = 0; i < dim; i++){
        int found = 0;
        for (int j = 0; i < dim && !found; j++){
            if(vec1[i] == vec2[j]){
                found = 1;
            }
            if(!found){
                return 0;
            }
        }        
    }
    return 1;
    */
}

int vecEnMatriz(const int vec[], int (m[])[COLS], unsigned int fils){
    for (int i = 0; i < fils; i++){
        if(contiene(vec, m[i], fils)){
            return 1;
        }
    }
    return 0;
}

int esAmiga(int (m1[])[COLS], unsigned int fils1, int (m2[])[COLS], unsigned int fils2 ){
    for (int i = 0; i < fils1; i++){
        if(!vecEnMatriz(m1[i], m2, fils2)){
            return 0;
        }
    }
    return 1;
}

int sonAmigas(int (m1[])[COLS], unsigned int fils1,int (m2[])[COLS], unsigned int fils2 ){
    if(esAmiga(m1, fils1, m2, fils2)){
        return 1;
    }
    else if(esAmiga(m2, fils2, m1, fils1)){
        return 2;
    }
    else{
        return 0;
    }
}

