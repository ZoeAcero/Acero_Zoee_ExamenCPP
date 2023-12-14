#include <iostream>
#include <vector>
#include <cstring>
#include <string>

//estructura estudiante
struct estudiante{
    std::string nombre;
    int edad;
    float promedio;
    std::vector<std::string> materias;
};

//funcion para imprimir los datos de un estudiante

void mostrarEstudiante(const Estudiante& estudiante) {
    std::cout << "Nombre: " << estudiante.nombre << std::endl;
    std::cout << "Edad: " << estudiante.edad << std::endl;
    std::cout << "Promedio: " << estudiante.promedio << std::endl;

    //imprimir materias
    std::cout << "Materias: ";
    for (const auto& materia : estudiante.materias) {
        std::cout << materia << std::endl;
    }
}

//estructura asistencia

struct asistencia{
    std::string fecha;
    std::string materia;
    std::string estado;
};

//clase estudiante con gestion de asistencia

class EstudianteConAsistencia {
public:
    estudiante estudiante;
    std::vector<asistencia> asistencias;

    //registrar y mostrar asistencia
    void registrarAsistencia(const asistencia& asistencia) {
        asistencias.push_back(asistencia);
    }

    void mostrarAsistencias() const {
        for (const auto& asistencia : asistencias) {
            std::cout << "Fecha: " << asistencia.fecha << " | Materia: " << asistencia.materia
                      << " | Estado: " << asistencia.estado << std::endl;
        }
    }
};

//excepcion personalizada para mensajes de error

class Excepcion : public std::exception {
public:
    const char* what() const noexcept override {
        return "Error en el formato de la fecha: ";
    }
};

int main() {

    EstudianteConAsistencia estudianteAsistencia;

    //datos del estudiante

    estudianteAsistencia.estudiante.nombre = "Zoe";
    estudianteAsistencia.estudiante.edad = 18;
    estudianteAsistencia.estudiante.promedio = 7.0;
    estudianteAsistencia.estudiante.materias = {"Matemáticas", "Programación"};

    asistencia asistencia1 = {"2023-13-12", "Matemáticas", "Asistió"};
    asistencia asistencia2 = {"2023-7-1", "Programación", "Falta"};

}