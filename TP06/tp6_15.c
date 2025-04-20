/*
Ejercicio 15 ***
Una imagen bmp se almacena en un archivo como una matriz de píxeles.
Si la imagen es de escala de grises, cada píxel ocupa un solo byte. Así, si la imagen tiene 20x30 píxeles, ocupa
600 bytes donde un byte con el valor 0x00 corresponde al negro y un byte con el valor 0xFF corresponde al
blanco. Cualquier valor entre 0x00 y 0xFF será una tonalidad de gris.
Realizar una función suavizar que, dada una imagen, la suavice aplicando un filtro de media de valor W,
con W impar. Esto significa que cada píxel (i, j) de la nueva imagen se obtiene a partir de la media aritmética de
los píxeles que se encuentran en la imagen original de la submatriz de tamaño WxW centrada en (i,j).
La función suavizar recibe como únicos parámetros la matriz y W. Si W es menor que 3 o no es impar,
la función no altera la imagen.
El ancho y alto de la imagen son las constantes simbólicas ANCHO y ALTO respectivamente.
*/

#include <stdio.h>
#include <assert.h>

#define ALTO 6
#define ANCHO 5

void suavizar(unsigned char imagen[ALTO][ANCHO], unsigned int w );
static int promedio(unsigned char m[ALTO][ANCHO], int rol, int col, int w);
static void copy(unsigned char src[ALTO][ANCHO], unsigned char trg[ALTO][ANCHO], int fils, int cols);


#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

//TEST

int equals(unsigned int cols, unsigned char m1[][cols], unsigned char m2[][cols], unsigned int rows) {
  for (int i=0; i < rows; i++) {
     for(int j=0; j < cols; j++) {
         if ( m1[i][j] != m2[i][j]) {
            return 0;
         }
     }
  }
  return 1;  
}

int main(void) {
  unsigned char bmp[ALTO][ANCHO] =    {
      {10,10,20,23,24},
      {10,12,18,25,23},
      {12,14,18,26,22},
      {12,14,19,20,22},
      {13,16,19,20,22},
      {14,14,19,21,23}};
 
  
  suavizar(bmp, 3);
  unsigned char suave[ALTO][ANCHO] =    {
      {10,13,18,22,23},
      {11,13,18,22,23},
      {12,14,18,21,23},
      {13,15,18,20,22},
      {13,15,18,20,21},
      {14,15,18,20,21}};

  assert(equals(ANCHO, bmp, suave, ALTO));

  // Ahora una con w=5
  unsigned char suave5[ALTO][ANCHO] =    {
	{14,16,17,19,20},
	{14,16,17,18,20},
	{14,16,17,18,20},
	{15,16,17,18,20},
	{15,16,17,18,20},
	{15,16,17,18,19}};

   suavizar(bmp, 5);
   assert(equals(ANCHO, bmp, suave5, ALTO));

  puts("OK!");
  return 0;
}

static int promedio(unsigned char m[ALTO][ANCHO], int row, int col, int w){
    w /= 2;
    int suma = 0, cant = 0;
    for (int i = MAX(0, row - w); i <= MIN(ALTO - 1, row + w); i++){
        for (int j = MAX(0, col - w); j <= MIN(ANCHO - 1, col + w); j++){
            suma += m[i][j];
            cant++;
        }   
    }    
    return suma / cant;
}

static void copy(unsigned char src[ALTO][ANCHO], unsigned char trg[ALTO][ANCHO], int fils, int cols){
    for (int i = 0; i < fils; i++){
        for (int j = 0; j < cols; j++){
            trg[i][j] = src[i][j];
        }        
    }    
}

void suavizar(unsigned char imagen[ALTO][ANCHO], unsigned int w){
    if(w < 3 || (w % 2) == 0){
        return;
    }
    unsigned char aux[ALTO][ANCHO];
    for (int i = 0; i < ALTO; i++){
        for (int j = 0; j < ANCHO; j++){
            aux[i][j] = promedio(imagen, i, j, w);
        }
    }
    copy(aux, imagen, ALTO, ANCHO);
    return;    
}