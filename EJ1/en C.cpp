#include <iostream>
#include <string>
#include <cstring>

//Estructura estudiante
struct Estudiante {
    char nombre[50];
    int edad;
    float promedio;
    char** materias;
    int numMaterias;
};

//Funcion para imprimir los datos de un estudiante
void mostrarEstudiante(const struct Estudiante* estudiante) {
    printf("Nombre: %s\n", estudiante->nombre);
    printf("Edad: %d\n", estudiante->edad);
    printf("Promedio: %.2f\n", estudiante->promedio);

    //Imprimir materias
    printf("Materias: ");
    for (int i = 0; i < estudiante->numMaterias; i++) {
        printf("%s ", estudiante->materias[i]);
    }
    printf("\n");
}

//Estructura asistencia
struct Asistencia {
    char fecha[11];
    char materia[50];
    char estado[10];
};

//Estructura estudiante con gestion de asistencia
struct EstudianteConAsistencia {
    struct Estudiante estudiante;
    struct Asistencia* asistencias;
    int numAsistencias;
};

//Registrar y mostrar asistencia
void registrarAsistencia(struct EstudianteConAsistencia* estudianteConAsistencia, const struct Asistencia* asistencia) {
    estudianteConAsistencia->asistencias[estudianteConAsistencia->numAsistencias] = *asistencia;
        estudianteConAsistencia->numAsistencias++;
}

void mostrarAsistencias(const struct EstudianteConAsistencia* estudianteConAsistencia) {
    printf("\n Registro de Asistencia:\n");
    for (int i = 0; i < estudianteConAsistencia->numAsistencias; i++) {
        printf("Fecha: %s | Materia: %s | Estado: %s\n", estudianteConAsistencia->asistencias[i].fecha,
               estudianteConAsistencia->asistencias[i].materia, estudianteConAsistencia->asistencias[i].estado);
    }
}




