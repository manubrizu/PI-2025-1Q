#include <stdio.h>
#include <assert.h>
#include "utillist.h"

int sumAll(const TList list);

// Version donde la lista vacia retorna 1
int odds1(const TList list);

// Version donde la lista vacia retorna cero
int odds2(const TList list);

int 
main(void) {

	assert(sumAll(NULL) == 0);
	assert(odds1(NULL) == 1 );
	assert(odds2(NULL) == 0 );

	int v [] = {1, 3, 5, -1, 0, 2, 4, 3};
	TList l1 = fromArray(v, 8);
	assert(sumAll(l1) == 17);
	assert(odds1(l1) == 0);
	assert(odds2(l1) == 0);
	freeList(l1);

	l1 = fromArray(v, 4);
	assert(sumAll(l1) == 8);
	assert(odds1(l1) == 1);
	assert(odds2(l1) == 1);
	freeList(l1);

	l1 = fromArray(v+4, 3);
	assert(sumAll(l1) == 6);
	assert(odds1(l1) == 0);
	assert(odds2(l1) == 0);
	freeList(l1);
	
	puts("OK!");
	return 0;
}
