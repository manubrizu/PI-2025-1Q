#include <stdio.h>
#include <stdlib.h>

typedef struct collectionCDT * collectionADT;

typedef int elemType;

typedef elemType (* compare) (elemType e1, elemType e2); 

/* Crea una colección vacía de elementos */
collectionADT newCollection(compare cmp);

/* Inserta el elemento #elem, que pasa a ocupar la posición #idx en la colección,
* desplazando una posición hacia atrás a todos los elementos que estaban a partir de la
* posición #idx.
* Si #idx es 0, será el primer elemento de la colección
* Si #idx es mayor o igual a la cantidad de elementos, lo inserta al final
*/
void addElement(collectionADT collection, elemType elem, size_t idx);

/* Retorna la cantidad de elementos presentes en la colección */
size_t sizeCollection(const collectionADT collection);

/* Devuelve la posición de la primer aparición del elemento,
* o -1 si el elemento no está */
int positionFirst(const collectionADT collection, elemType elem);

/* Funciones de iteración para que se puedan consultar todos los elementos
** registrados en forma ordenada por posición
*/
void toBegin(collectionADT collection);

size_t hasNext(const collectionADT collection);

elemType next(collectionADT collection);

/* Libera todos los recursos utilizados por el TAD */
void freeCollection(collectionADT collection);
