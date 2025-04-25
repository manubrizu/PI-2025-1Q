#include <stdio.h>
#include <assert.h>

void diferencia(int v1[], int v2[]);

int main(void) {
    int v1[] = {10, 15, 18, 20, 3000, -1};
    int v2[] = {10, 12, 13, 14, 15, 20, -1};
    diferencia(v1, v2); // Se eliminan de ambos 10, 15, 20

    assert(v1[0]==18 && v1[1]==3000 && v1[2]==-1);
    assert(v2[0]==12 && v2[1]==13 && v2[2]==14 && v2[3]==-1);

    diferencia(v1, v2); // No hay cambios en ninguno de los dos

    int v3[] = {-1};
    diferencia(v1, v3); // No hay cambios en ninguno de los dos

    int v4[] = {12, 13, 14, -1};
    // Son iguales, se eliminan de ambos todos los valores
    diferencia(v2, v4);
    assert(v2[0]==-1);
    assert(v4[0]==-1);

    puts("OK!");
    return 0;
}
   

void diferencia(int v1[], int v2[]){
    int i = 0, j = 0, k = 0, l = 0;
    while(v1[i] != -1 && v2[j] != -1){
        if (v1[i] < v2[j]){
            v1[k++] = v1[i++];
        }
        else if(v1[i] > v2[j]){
            v2[l++] = v2[j++];
        }
        else{
            i++;
            j++;
        }        
    }   

    while (v1[i] != -1){
        v1[k++] = v1[i++];
    }
    
    while (v2[j] != -1){
        v2[l++] = v2[j++];
    }

    v1[k] = -1;
    v2[l] = -1;
}