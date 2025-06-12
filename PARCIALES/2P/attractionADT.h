#include <stdio.h>

typedef struct attractionCDT * attractionADT;

/* Inicializa un sistema para administrar los visitantes de una atracción para un día */
attractionADT newAttraction(void);

/* La persona #visitor estará esperando a entrar a la atracción en la hora #hour
* Si #hour es mayor o igual a 24 no hace nada */
void addVisitor(attractionADT att, size_t hour, const char * visitor); /* NO IMPLEMENTAR */

/* Retorna la cantidad de personas esperando a entrar en la hora #hour
* Retorna 0 si no hay personas esperando a entrar en la hora #hour
* Retorna -1 si la hora es inválida */
int pendingVisitorsCount(const attractionADT att, size_t hour); /* NO IMPLEMENTAR */

/* Entra a la atracción un visitante que estaba esperando a entrar a la atracción
* en la hora #hour (respetando el orden en que llegaron) y retorna el nombre de ese visitante
* Retorna NULL si no había nadie esperando a entrar en la hora #hour
* Retorna NULL si la hora es inválida */
char * rideVisitor(attractionADT att, size_t hour);

/* Retorna la cantidad de personas que entraron a la atracción en la hora #hour
* Retorna 0 si nadie entró en la hora #hour o la hora es inválida */
int rideVisitorsCount(const attractionADT att, size_t hour); /* NO IMPLEMENTAR */

/* Retorna un arreglo con las personas que están esperando a entrar en la hora #hour
* (respetando el orden en que llegaron)
* esto es, el primer elemento del arreglo debe coincidir con el valor de retorno de
* una invocación a rideVisitor y deja en #dim la cantidad de elementos
* Si la hora es inválida o no hay personas para esa hora retorna NULL */
char ** pendingVisitors(const attractionADT att, size_t hour, size_t * dim);

/* Libera todos los recursos utilizados por el TAD */
void freeAttraction(attractionADT att); /* NO IMPLEMENTAR */
