#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Tarea {
    int TareaID;        // Numérico autoincremental comenzando en 1000
    char *Descripcion;  //
    int Duracion;       // entre 10 – 100
} Tarea;

typedef struct Tnodo {
    Tarea T;
    struct Tnodo *Siguiente;
} Tnodo;

Tnodo *crearLista();
Tnodo *crearNodo(int id, char *descripcion, int duracion);
void insertarNodo(Tnodo **pendiente, Tnodo *insertar);
void mostrarLista(Tnodo *nodo);
Tnodo *buscarDato(Tnodo *nodo, int palabraClave);
void mostrarNodo(Tnodo *nodo);
Tnodo *quitarNodo(Tnodo *nodo);

int main() {
    Tnodo *pendientes = crearLista();
    Tnodo *realizadas = crearLista();

    int id = 1000, duracion, palabraClave;
    char buffer[100];

    int opc;
    do {
        printf("Ingrese la operacion a realizar: \n1) Ingresar tarea pendiente\n2) Transferir tarea pendiente a realizada\n3) Listar todas las tareas pendientes y realizadas\n4) Consultar tarea pendiente o realizada por id o palabra clave\n5) Salir\nSeleccion: ");
        scanf("%i", &opc);
        fflush(stdin);
        switch (opc) {
            case 1:
                printf("Ingrese la descripcion de la tarea: ");
                gets(buffer);
                fflush(stdin);

                printf("Ingrese la duracion: ");
                scanf("%i", &duracion);

                Tnodo *nodo1 = crearNodo(id, buffer, duracion);
                insertarNodo(&pendientes, nodo1);
                id++;
                break;
            case 2:
                /*
                    El usuario ingresa el ID de la tarea pendiente que quiere transferir a realizada.
                    El programa busca esa tarea en la lista de pendientes.
                    Si la tarea se encuentra, se elimina de la lista de pendientes y se agrega a la lista de realizadas.
                */
                break;
            case 3:
                printf("Tareas pendientes\n");
                mostrarLista(pendientes);
                printf("Tareas realizadas\n");
                mostrarLista(realizadas);
                break;
            case 4:
                printf("Ingrese el id para determinar si esta pendiente o realizada: ");
                scanf("%i", &palabraClave);
                if (buscarDato(pendientes, palabraClave) != NULL) {
                    printf("\nEl ID: %i si existe y corresponde a una tarea pendiente\n", palabraClave);
                    mostrarNodo(buscarDato(pendientes, palabraClave));
                } else if (buscarDato(realizadas, palabraClave) != NULL) {
                    printf("\nEl ID: %i si existe y corresponde a una tarea realizada\n", palabraClave);
                } else {
                    printf("\nEl ID: %i no existe.\n");
                }
                break;
            case 5:
                printf("Saliendo...\n");
                break;
        }

    } while (opc != 5);

    return 0;
}

Tnodo *crearLista() {
    return NULL;
}

Tnodo *crearNodo(int id, char *descripcion, int duracion) {
    Tnodo *nuevoNodo = (Tnodo *)malloc(sizeof(Tnodo));
    nuevoNodo->T.TareaID = id;
    nuevoNodo->T.Descripcion = (char *)malloc(strlen(descripcion) + 1);
    strcpy(nuevoNodo->T.Descripcion, descripcion);
    nuevoNodo->T.Duracion = duracion;
    nuevoNodo->Siguiente = NULL;

    return nuevoNodo;
}

void insertarNodo(Tnodo **pendiente, Tnodo *insertar) {
    insertar->Siguiente = *pendiente;
    *pendiente = insertar;
}

void mostrarLista(Tnodo *nodo) {
    while (nodo != NULL) {
        printf("Informacion de la tarea\n");
        printf("ID: %i\n", nodo->T.TareaID);
        printf("Descripcion: %s\n", nodo->T.Descripcion);
        printf("Duracion: %i\n", nodo->T.Duracion);
        printf("\n-----\n");
        nodo = nodo->Siguiente;
    }
}

Tnodo *quitarNodo(Tnodo *nodo, ) {
}

Tnodo *buscarDato(Tnodo *head, int palabraClave) {
    Tnodo *aux = head;

    while (aux != NULL && aux->T.TareaID != palabraClave) {
        aux = aux->Siguiente;
    }
    return aux;
}

void mostrarNodo(Tnodo *nodo) {
    if (nodo != NULL) {
        printf("Tarea ID: %i\n", nodo->T.TareaID);
        printf("Descripcion: %s\n", nodo->T.Descripcion);
        printf("Duracion: %i\n", nodo->T.Duracion);
    }
}