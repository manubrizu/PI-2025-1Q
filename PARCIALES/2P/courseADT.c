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
    size_t idx = (id % 10000) - 1;

    if(idx >= course->dim){
        course->alumnos = realloc(course->alumnos, (idx + 1) * sizeof(alumno *));
        for (int i = course->dim; i <= idx; i++){
            course->alumnos[i]= NULL;
        }
        course->dim = idx + 1;
    }

    if(course->alumnos[idx] != NULL){
        return 0;
    }

    alumno * aux = malloc(sizeof(alumno));
    aux->legajo = id;
    aux->nombre = copyStr(name);
    aux->notas = calloc(course->cantMaterias, sizeof(int));
    course->alumnos[idx] = aux;
    course->cantAlumn++;
    return 1;
}

char * studentName(const courseADT course, size_t id){
    size_t digitos = course->anio % 100;    // ultimos 2
    size_t legajoDigitos = id / 10000;      // primeros 2
    size_t idx = (id % 10000) - 1;
    if(digitos != legajoDigitos || course->alumnos[idx] == NULL){
        return NULL;
    }

    return copyStr(course->alumnos[idx]->nombre);
}


size_t students(const courseADT course){
    return course->cantAlumn;
}

int setGrade(courseADT course, size_t id, size_t subject, unsigned char grade){
    size_t digitos = course->anio % 100;    // ultimos 2
    size_t legajoDigitos = id / 10000;      // primeros 2
    size_t idx = (id % 10000) - 1;
    size_t idxMat = (subject / 10) - 1;

    if(digitos != legajoDigitos || idx >= course->dim || course->alumnos[idx] == NULL || subject % 10 != 0 || idxMat>= course->cantMaterias || grade > 10){
        return 0;
    }
    
    course->alumnos[idx]->notas[idxMat] = grade;
    return 1;
}
