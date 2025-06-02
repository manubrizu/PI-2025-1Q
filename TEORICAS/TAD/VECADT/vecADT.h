#include <stdlib.h>

typedef struct vectorCDT * vectorADT;

// Definición de tipo, reemplazar por el deseado
typedef int elemType;

// Construye un TAD de un vector
vectorADT newVector();

// Retorna la cantidad de elementos presentes en el vector
int elementCount(const vectorADT v);

// Agrega el elemento elem en la posición index
// Si ya existe un elemento en esa posición, lo pisa
void addElement(vectorADT v, elemType elem, size_t index);

// Retorna 1 si existe un elemento en la posición index y deja en elem el elemento
// Retorna 0 si no existe un elemento en la posición index
int getElement(const vectorADT v, size_t index, elemType * elem);

// Retorna 1 si existe un elemento en la posición index y lo elimina de la colección
// Retorna 0 si no existe un elemento en la posición index
int deleteElement(vectorADT v, size_t index);

// Libera todos los recursos utilizados por el TAD
void freeVector(vectorADT v);