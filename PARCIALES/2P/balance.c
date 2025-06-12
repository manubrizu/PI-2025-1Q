#include <stdio.h>
#include <stdlib.h>

typedef struct docNode {
    int id;                     // identifica al cliente
    double amount;              // importe del comprobante (positivo o negativo)
    struct docNode * tail;
} docNode;

typedef docNode * docList;

typedef struct balanceNode {
    int id;                     // identifica al cliente
    double balance;             // cuánto debe o se le debe al cliente
    struct balanceNode * tail;
} balanceNode;

typedef balanceNode * balanceList;



balanceList balance(docList l1){
    if(l1 == NULL){
        return NULL;
    }

    balanceList lAux = balance(l1->tail);
    
    if(lAux == NULL || l1->id != lAux->id){
        balanceList aux = malloc(sizeof(docNode));
        aux->id = l1->id;
        aux->tail = lAux;
        aux->balance = l1->amount;      // como arranca el 0, directamente le asigno l1->amount
        return aux;
    }
    
    lAux->balance += l1->amount;
    return lAux;
}