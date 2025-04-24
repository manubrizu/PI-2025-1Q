    #include <stdio.h>
    #include <assert.h>

    int comprimeArr(unsigned char valores[], unsigned char elemento, int resp[], int dimResp);
    
    
    /* Función auxiliar para comparar dos arreglos de unsigned char */
    void assertArrEqualsUC(const unsigned char a[], const unsigned char b[], int len) {
        for (int i = 0; i < len; i++) {
            assert(a[i] == b[i]);
        }
    }
    
    
    /* Función auxiliar para comparar dos arreglos de int */
    void assertArrEqualsInt(const int a[], const int b[], int len) {
        for (int i = 0; i < len; i++) {
            assert(a[i] == b[i]);
        }
    }

    int main(void){
        // Caso 1: ejemplo del enunciado
        unsigned char valores1[20] = {2,2,2,2,2,2,3,3,3,4,3,2,2,2,3,3,2,2,0};
        int vec1[10] = {0};
        int dim1 = comprimeArr(valores1, 2, vec1, 10);
        printf("A\n");
        fflush(stdout);
        assert(dim1 == 2);
        int esperadovec1[] = {5,2,1};
        assertArrEqualsInt(vec1, esperadovec1, dim1);
        unsigned char esperada1[] = {2,3,3,3,4,3,2,3,3,2,0};
        /* calculamos longitud de esperada1: */
        int len1 = 0;
        while (esperada1[len1] != 0) len1++;
        assertArrEqualsUC(valores1, esperada1, len1+1);
    
    
        puts("a");
        // Caso 2: mismo ejemplo, pero maxDim = 2
        unsigned char valores2[20] = {2,3,3,3,3,2,2,2,3,2,4,2,2,2,2,2,2,2,0};
        int vec2[2] = {0,0};
        int dim2 = comprimeArr(valores2, 2, vec2, 2);
        assert(dim2 == 2);
        int esperadovec2[] = {0,2};
        assertArrEqualsInt(vec2, esperadovec2, dim2);
        unsigned char esperada2[] = {2,3,3,3,3,2,3,2,4,2,2,2,2,2,2,2,0};
        int len2 = 0;
        while (esperada2[len2] != 0) len2++;
        assertArrEqualsUC(valores2, esperada2, len2+1);
    
    
        puts("a");
        // Caso 3: no hay 'n' en el arreglo
        unsigned char valores3[10] = {1,3,4,5,6,0};
        int vec3[5] = {123,123,123,123,123};
        int dim3 = comprimeArr(valores3, 2, vec3, 5);
        assert(dim3 == 0);
        unsigned char esperada3[] = {1,3,4,5,6,0};
        int len3 = 0;
        while (esperada3[len3] != 0) len3++;
        assertArrEqualsUC(valores3, esperada3, len3+1);
        /* vec3 no debe cambiar: */
        for (int i = 0; i < 5; i++) {
            assert(vec3[i] == 123);
        }

    
        // Caso 4: sólo 'n' en el arreglo
        unsigned char valores4[10] = {5,5,5,5,0};
        int vec4[3] = {0};
        int dim4 = comprimeArr(valores4, 5, vec4, 3);
        assert(dim4 == 1);
        assert(vec4[0] == 4 - 1);  // eliminamos repeticiones consecutivas: 4 elementos -> 3 eliminados
        unsigned char esperada4[] = {5,0};
        int len4 = 0;
        while (esperada4[len4] != 0) len4++;
        assertArrEqualsUC(valores4, esperada4, len4+1);
    

        // Caso 5: 'n' al final del arreglo
        unsigned char valores5[10] = {1,3,4,2,2,2,0};
        int vec5[2] = {0};
        int dim5 = comprimeArr(valores5, 2, vec5, 2);
        assert(dim5 == 1);
        assert(vec5[0] == 2);
        unsigned char esperada5[] = {1,3,4,2,0};
        int len5 = 0;
        while (esperada5[len5] != 0) len5++;
        assertArrEqualsUC(valores5, esperada5, len5+1);
    
    
        // Caso 6: runs alternados, ninguna repetición consecutiva de más de 1
        unsigned char valores6[10] = {2,3,2,3,2,0};
        int vec6[5] = {0};
        int dim6 = comprimeArr(valores6, 2, vec6, 5);
        assert(dim6 == 3);  // tres apariciones separadas
        for (int i = 0; i < dim6; i++) {
            assert(vec6[i] == 0);
        }
        unsigned char esperada6[] = {2,3,2,3,2,0};
        int len6 = 0;
        while (esperada6[len6] != 0) len6++;
        assertArrEqualsUC(valores6, esperada6, len6+1);
    
    
        puts("¡Todos los tests pasaron correctamente!");
        return 0;
    }
    

    int comprimeArr(unsigned char valores[], unsigned char elemento, int resp[], int dimResp){
        int i = 0, j = 0, primerElemento = 1, eliminados = 0, cantSec = 0;
        
        while (valores[i] != 0 && cantSec < dimResp) {
            if (valores[i] == elemento) {
                if (primerElemento) {
                    valores[j++] = valores[i++];
                    primerElemento = 0;
                } else {
                    i++;
                    eliminados++;
                }
            } 
            else {
                if (!primerElemento) {
                    resp[cantSec++] = eliminados;
                    eliminados = 0;
                    primerElemento = 1;
                }
                valores[j++] = valores[i++];
            }
        }

        if(!primerElemento && cantSec < dimResp){
            resp[cantSec++] = eliminados;
        }

        while (valores[j] != 0){
            valores[j++] = valores[i++];
        }

        valores[j] = 0;    
        
        return cantSec;
    }
