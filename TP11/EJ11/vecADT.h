#include <stdlib.h>

typedef struct vectorCDT * vectorADT;

// Definición de tipo, reemplazar por el deseado
typedef int elemType;

typedef int (*compare) (elemType e1, elemType e2);

// Construye un TAD de un vector
vectorADT newVector();

// Agrega el elemento elem en la posición index
// Si ya existe un elemento en esa posición, lo pisa
void addElement(vectorADT v, elemType elem, size_t index);

// Retorna 1 si existe un elemento en la posición index y deja en elem el elemento
// Retorna 0 si no existe un elemento en la posición index
int getElement(const vectorADT v, size_t index, elemType * elem);

// Retorna 1 si existe un elemento en la posición index y lo elimina de la colección
// Retorna 0 si no existe un elemento en la posición index
void deleteElement(vectorADT v, size_t index);

// Libera todos los recursos utilizados por el TAD
void freeVector(vectorADT v);

/* Almacena los elementos de elems a partir de la posición index,
** donde elems es un vector de dim elementos.
** En caso de ser necesario agranda el vector.
** El resto de los elementos del vector no se modifican y permanecen
** en la misma posición.
** Si se recibe NULL o no se pudo insertar retorna cero.
** Si alguna posición está ocupada, la deja como estaba.
** Retorna cuántos elementos pudo almacenar.
** Ejemplo:
** Si v tiene ocupadas las posiciones 1,3 y 6
** Se invoca con index=2, dim=5
** El vector actual quedará con los mismos elementos en las
** posiciones 1, 3 y 6
** Pero además v[2]=elems[0], v[4]=elems[2], v[5]=elems[3]
** y la función retorna 3
*/
int put(vectorADT v, elemType * elems, size_t dim, size_t index);

int elementCount(vectorADT v);

int getIdx(vectorADT v, elemType elem, compare cmp);
