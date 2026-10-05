#include <stdio.h>
#include <string.h>

#define MAX_ESTUDIANTES 50

struct Estudiante {
    int id;
    char nombre[50];
    char carrera[50];
    float promedio;
};

struct Estudiante estudiantes[MAX_ESTUDIANTES];
int cantidad = 0;
int siguienteId = 1;

void agregarEstudiante() {
    if (cantidad >= MAX_ESTUDIANTES) {
        printf("\nNo se pueden agregar mas estudiantes.\n");
        return;
    }

    struct Estudiante e;
    e.id = siguienteId++;

    printf("\n--- Agregar Estudiante ---\n");
    printf("Nombre: ");
    getchar(); // limpiar buffer
    fgets(e.nombre, 50, stdin);
    e.nombre[strcspn(e.nombre, "\n")] = 0; // quitar el salto de linea

    printf("Carrera: ");
    fgets(e.carrera, 50, stdin);
    e.carrera[strcspn(e.carrera, "\n")] = 0;

    printf("Promedio: ");
    scanf("%f", &e.promedio);

    estudiantes[cantidad] = e;
    cantidad++;

    printf("\nEstudiante agregado exitosamente con ID: %d\n", e.id);
}

void mostrarEstudiantes() {
    if (cantidad == 0) {
        printf("\nNo hay estudiantes registrados.\n");
        return;
    }

    printf("\n--- Lista de Estudiantes ---\n");
    printf("ID\tNombre\t\t\tCarrera\t\t\tPromedio\n");
    printf("---------------------------------------------------------------\n");

    for (int i = 0; i < cantidad; i++) {
        printf("%d\t%-20s\t%-20s\t%.2f\n", 
               estudiantes[i].id, 
               estudiantes[i].nombre, 
               estudiantes[i].carrera, 
               estudiantes[i].promedio);
    }
}

void buscarEstudiante() {
    int id;
    printf("\nIngrese el ID del estudiante a buscar: ");
    scanf("%d", &id);

    for (int i = 0; i < cantidad; i++) {
        if (estudiantes[i].id == id) {
            printf("\n--- Estudiante encontrado ---\n");
            printf("ID: %d\n", estudiantes[i].id);
            printf("Nombre: %s\n", estudiantes[i].nombre);
            printf("Carrera: %s\n", estudiantes[i].carrera);
            printf("Promedio: %.2f\n", estudiantes[i].promedio);
            return;
        }
    }
    printf("\nEstudiante no encontrado.\n");
}

void eliminarEstudiante() {
    int id;
    printf("\nIngrese el ID del estudiante a eliminar: ");
    scanf("%d", &id);

    for (int i = 0; i < cantidad; i++) {
        if (estudiantes[i].id == id) {
            // Mover los elementos hacia atras
            for (int j = i; j < cantidad - 1; j++) {
                estudiantes[j] = estudiantes[j + 1];
            }
            cantidad--;
            printf("\nEstudiante eliminado exitosamente.\n");
            return;
        }
    }
    printf("\nEstudiante no encontrado.\n");
}

int main() {
    int opcion;

    do {
        printf("\n===== SISTEMA DE GESTION DE ESTUDIANTES =====\n");
        printf("1. Agregar estudiante\n");
        printf("2. Mostrar todos los estudiantes\n");
        printf("3. Buscar estudiante por ID\n");
        printf("4. Eliminar estudiante\n");
        printf("5. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: agregarEstudiante(); break;
            case 2: mostrarEstudiantes(); break;
            case 3: buscarEstudiante(); break;
            case 4: eliminarEstudiante(); break;
            case 5: printf("\nSaliendo del sistema...\n"); break;
            default: printf("\nOpcion no valida.\n");
        }
    } while (opcion != 5);

    return 0;
}
