#include <stdio.h>
#include <assert.h>

void ordena(int vec[]);

int main(void) {
    int vec[] = {1, 3, 12, 10, 11, -1};
    ordena(vec); // El vector no cambia

    int vec2[] = {-1};
    ordena(vec2); // El vector no cambia

    int vec3[] = {10, 10, 4, 8, 9, 7, 8, 6, -1};
    ordena(vec3);
    assert(vec3[0]==10 && vec3[1]==-1);

    int vec4[] = {10, 7, 6, 11, 2, 3, 4, 14, 12, -1};
    ordena(vec4);
    assert(vec4[0]==10 && vec4[1]==11 );
    assert(vec4[2]==14 && vec4[3]==-1 );

    printf("OK!\n");

    return 0;
}

void ordena(int vec[]){
    if (vec[0] == -1) return;
    
    int i = 0;  // índice del último elemento mantenido
    int j = 1;  // índice del elemento actual
    
    while (vec[j] != -1) {
        if (vec[j] > vec[i]) {
            i++;
            vec[i] = vec[j];
        }
        j++;
    }
    vec[i + 1] = -1;
}