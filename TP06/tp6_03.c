#include <stdio.h>
#include <math.h>

/*
 * Ejercicio 3 **
 * Dado un arreglo lineal de números reales, cuyo indicador de fin de elementos es cero, escribir una función para
 * obtener la mayor diferencia entre dos elementos consecutivos. (En no más de 5 líneas). Tener en cuenta que los números
 * pueden ser negativos. En caso de que el vector tenga un solo elemento deberá retornar como diferencia el valor cero.
*/

double maxDiff(const double vec[]){
    if(vec[0] == 0)
        return 0;    
    double maxDif = 0;
    for (int i = 0; vec[i + 1] != 0; i++)    {
        maxDif = fmax(maxDif, fabs(vec[i] - vec[i + 1]));
    }
    return maxDif;
}

int main(){
    double vec1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 10, 0};
    printf("%.2f\n", maxDiff(vec1));
    return 0;
}