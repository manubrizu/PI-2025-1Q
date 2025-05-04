#include <stdio.h>
#include <assert.h>
#include <string.h>

#define ERROR 0
#define EXITO 1
#define CANT_VOCAL 5


int elimVocales(char * s, int m[][CANT_VOCAL], unsigned int n);

int main(void) {
    int m[6][CANT_VOCAL];
    memset(m, -1, sizeof(m)); // Inicializar la matriz con -1

    char s[] = "las buenas ideas escasean, si";

    // Test 1
    assert(elimVocales(s, m, 6) == EXITO);
    puts(s);
    assert(strcmp(s, "ls bns ds scsn, s") == 0);
    assert(m[0][0] == 1);
    assert(m[1][0] == 8);
    assert(m[2][0] == 14);
    assert(m[3][0] == 20);
    assert(m[4][0] == 23);
    assert(m[5][0] == -1);

    assert(m[0][1] == 6);
    assert(m[1][1] == 13);
    assert(m[2][1] == 17);
    assert(m[3][1] == 22);
    assert(m[4][1] == -1);

    assert(m[0][2] == 11);
    assert(m[1][2] == 28);
    assert(m[2][2] == -1);

    assert(m[0][3] == -1);

    assert(m[0][4] == 5);
    assert(m[1][4] == -1);

    // Test 2: No hay suficiente espacio en la matriz
    memset(m, -1, sizeof(m));
    strcpy(s, "las buenas ideas escasean, si");
    assert(elimVocales(s, m, 1) == ERROR);
    assert(strcmp(s, "las buenas ideas escasean, si") == 0);

    // Test 3: Espacio limitado pero suficiente
    memset(m, -1, sizeof(m));
    strcpy(s, "las buenas ideas escasean, si");
    assert(elimVocales(s, m, 5) == ERROR);
    assert(strcmp(s, "ls bns ds scsan, s") == 0);

    printf("OK!\n");
    return 0;
}

int elimVocales(char *s, int m[][CANT_VOCAL], unsigned int n) {
    const char *vocales = "aeiouAEIOU";
    int cantPorVocal[CANT_VOCAL] = {0}; // Contador de vocales por columna
    char copia[1000]; // String temporal para almacenar el resultado sin vocales
    int j = 0; // Índice para el string `copia`

    // Inicializar la matriz `m` con -1
    for (unsigned int i = 0; i < n; i++) {
        for (int k = 0; k < CANT_VOCAL; k++) {
            m[i][k] = -1;
        }
    }

    // Recorrer el string `s`
    for (int i = 0; s[i]; i++) {
        char *cp = strchr(vocales, s[i]); // Verificar si el carácter es una vocal
        if (cp) {
            int col = (cp - vocales) % CANT_VOCAL; // Determinar la columna de la vocal

            // Verificar si hay espacio suficiente en la columna
            if (cantPorVocal[col] >= n) {
                return ERROR; // No hay más espacio: devolver ERROR
            }

            // Almacenar la posición de la vocal en la matriz
            m[cantPorVocal[col]][col] = i;
            cantPorVocal[col]++;
        } else {
            // Si no es vocal, copiar el carácter al string `copia`
            copia[j++] = s[i];
        }
    }

    // Terminar el string `copia` con '\0'
    copia[j] = '\0';

    // Actualizar el string original `s` con el contenido de `copia`
    strcpy(s, copia);

    return EXITO; // Todo se realizó correctamente
}