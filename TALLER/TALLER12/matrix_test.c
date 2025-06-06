#include <stdio.h>
#include <assert.h>
#include "matrixADT.h"

int
main(void) {
	matrixADT m = newMatrix();
	int aux;
	setElement(m, 1, 2, 9);
	getElement(m, 1, 2, &aux);
	assert(aux == 9); // m[1][2] = 9
	setElement(m, 1, 3, 11);
	getElement(m, 1, 3, &aux);
	assert(aux == 11); // m[1][3] = 11
	setElement(m, 1, 3, 12);
	getElement(m, 1, 3, &aux);
	assert(aux == 12); // m[1][3] = 12
	setElement(m, 3, 3, 10);
	getElement(m, 3, 3, &aux);
	assert(aux == 10); // m[3][3] = 10
	setElement(m, 3, 4, 23);
	getElement(m, 3, 4, &aux);
	assert(aux == 23); // m[3][4] = 23
	assert(getElement(m,2,7,&aux) == 0);
	assert(rows(m) == 4); // 4 filas: [0, 1, 2, 3]
	freeMatrix(m);
	puts("OK!");
	return 0;
}
