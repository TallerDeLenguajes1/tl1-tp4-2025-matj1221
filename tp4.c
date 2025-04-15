#include <stdio.h>
#include <string.h>

struct Tarea {
    int TareaID;        // Numérico autoincremental comenzando en 1000
    char *Descripcion;  //
    int Duracion;       // entre 10 – 100
} Tarea;

struct Nodo {
    Tarea T;
    struct Nodo *Siguiente;
} Nodo;

typedef struct Nodo *Lista;

Lista crearLista();

int main() {
    Lista pendientes;
    Lista realizadas;

    pendientes = crearLista();
    realizadas = crearLista();

    char buffer[100];

    printf("Interfaz de carga de tareas\n1) Ingresar descripcion de la tarea: \n2) Ingrese la duracion de la tarea: \n3) Salir.");
    int opc, i = 0;
    do {
        scanf("%i", &opc);
        switch (opc) {
            case 1:
                gets(buffer);
                pendientes->T.Descripcion = (char *)malloc(sizeof(char) * (strlen(buffer) + 1));  // primero asignar luego copiar
                strcpy(pendientes->T.Descripcion, buffer);
                break;
            case 2:
                scanf("%i", &pendientes);
                break;
            case 3:
                exit(1);
                break;
        }

        if (opc == 1 || opc == 2) {
            pendientes->T.TareaID = i + 1;
        }

    } while (opc < 3);

    return 0;
}

Lista crearLista() {
    return NULL;
}