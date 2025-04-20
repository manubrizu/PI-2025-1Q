#include <stdio.h>
#include <math.h>

double desviacionEstandar(const unsigned char arr[], unsigned int dim){
    int cont = 0; // dimension del vector de enteros
    double prom = 0, desvEstandar = 0;

    // CALCULO EL PROMEDIO
    for (int i = 0; i < dim; i++){
        prom += (arr[i] & 0xF0) >> 4;
        prom += arr[i] & 0x0F;
        cont += 2;
    }
    prom /= cont;

    // CALCULO LA DESVIACION ESTANDAR
    for (int i = 0; i < dim; i++){
        desvEstandar += pow(((arr[i] & 0xF0) >> 4) - prom, 2); 
        desvEstandar += pow((arr[i] & 0x0F) - prom, 2); 
    }
    return sqrt(desvEstandar / cont);    
}

int main() {
    unsigned char arreglo[] = { 0x37, 0xF2, 0x03, 0x4A, 0xFF };
    int cantidad = sizeof(arreglo) / sizeof(arreglo[0]);

    double resultado = desviacionEstandar(arreglo, cantidad);
    printf("La desviacion estandar es: %.2f\n", resultado);

    return 0;
}