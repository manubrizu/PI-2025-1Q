#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "courseADT.h"

typedef struct alumno {
    size_t legajo;
    char * nombre;
    int * notas;
} alumno;

typedef struct courseCDT {
    alumno ** alumnos;
    size_t cantMaterias;
    size_t cantAlumn;
    size_t dim;
    size_t anio;
} courseCDT;

courseADT newCourse(size_t year, size_t subjects){
    courseADT aux = calloc(1, sizeof(courseCDT));
    aux->anio = year;
    aux->cantMaterias = subjects;
    return aux;
}

static char * copyStr(const char * s){
    return strcpy(malloc(strlen(s)), s);
}

int addStudent(courseADT course, size_t id, const char * name){
    size_t digitos = course->anio % 100;    // ultimos 2
    size_t legajoDigitos = id / 10000;      // primeros 2

    if(digitos != legajoDigitos) {
        return 0;
    }

    size_t idx = (id % 1000) - 1;

    if(idx >= course->dim){
        course->alumnos = realloc(course->alumnos, (idx + 1) * sizeof(alumno *));
        for (int i = course->dim; i < idx; i++){
            course->alumnos[i]= NULL;
        }
        course->dim = idx + 1;
    }

    if(course->alumnos[idx] != NULL){
        return 0;
    }

    course->alumnos[idx]->legajo = id;
    course->alumnos[idx]->nombre = copyStr(name);
    course->alumnos[idx]->notas = NULL;
    return 1;
}