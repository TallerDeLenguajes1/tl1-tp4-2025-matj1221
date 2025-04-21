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
Tnodo *buscarDato(Tnodo *nodo, int idClave);
Tnodo *buscarPalabra(Tnodo *head, char *palabraClave);
void mostrarNodo(Tnodo *nodo);
Tnodo *quitarNodo(Tnodo **head, int idQuitar);

int main() {
    Tnodo *pendientes = crearLista();
    Tnodo *realizadas = crearLista();

    int id = 1000, duracion, idClave;
    char buffer[100], palabraClave[20];

    int opc, continuar, determinar, transferirTarea;
    do {
        printf("Ingrese la operacion a realizar: \n1) Ingresar tarea pendiente\n2) Transferir tarea pendiente a realizada\n3) Listar todas las tareas pendientes y realizadas\n4) Consultar tarea pendiente o realizada por id o palabra clave\n5) Salir\nSeleccion: ");
        scanf("%i", &opc);
        fflush(stdin);
        switch (opc) {
            case 1:
                do {
                    printf("Ingrese la descripcion de la tarea: ");
                    gets(buffer);
                    fflush(stdin);
                    do {
                        printf("Ingrese la duracion: ");
                        scanf("%i", &duracion);
                    } while (duracion < 10 || duracion > 100);

                    Tnodo *nodo1 = crearNodo(id, buffer, duracion);
                    insertarNodo(&pendientes, nodo1);
                    id++;

                    printf("Desea seguir agregando tareas? Ingrese 0 si quiere finalizar la carga de tareas.\n");
                    scanf("%i", &continuar);
                    fflush(stdin);
                } while (continuar != 0);

                break;
            case 2:

                printf("Ingrese el ID de la tarea pendiente que desea transferir a realizada: ");
                scanf("%i", &transferirTarea);

                Tnodo *tareaTransferida = quitarNodo(&pendientes, transferirTarea);

                if (tareaTransferida != NULL) {
                    insertarNodo(&realizadas, tareaTransferida);
                    printf("La tarea fue transferida existosamente.\n");
                } else {
                    printf("No se encontro un nodo con ese id.\n");
                }
                break;
            case 3:
                printf("Tareas pendientes\n");
                mostrarLista(pendientes);
                printf("Tareas realizadas\n");
                mostrarLista(realizadas);
                break;
            case 4:
                printf("Desea hacer la consulta por ID o con una palabra clave? (1 = ID, 2 = Palabra clave)\n");
                scanf("%i", &determinar);
                fflush(stdin);
                do {
                    switch (determinar) {
                        case 1:
                            printf("Ingrese el id para determinar si esta pendiente o realizada: ");
                            scanf("%i", &idClave);
                            if (buscarDato(pendientes, idClave) != NULL) {
                                printf("\nEl ID: %i si existe y corresponde a una tarea pendiente\n", idClave);
                                mostrarNodo(buscarDato(pendientes, idClave));
                            } else if (buscarDato(realizadas, idClave) != NULL) {
                                printf("\nEl ID: %i si existe y corresponde a una tarea realizada\n", idClave);
                            } else {
                                printf("\nEl ID: %i no existe.\n", idClave);
                            }
                            break;
                        case 2:
                            printf("Ingrese la palabra clave para determinar si esta pendiente o realizada: ");
                            gets(palabraClave);
                            if (buscarPalabra(pendientes, palabraClave) != NULL) {
                                printf("\nLa palabra clave %s si existe y corresponde a una tarea pendiente\n", palabraClave);
                                mostrarNodo(buscarPalabra(pendientes, palabraClave));
                            } else if (buscarPalabra(realizadas, palabraClave) != NULL) {
                                printf("\nLa palabra clave %s si existe y corresponde a una tarea realizada\n", palabraClave);
                            } else {
                                printf("\nLa palabra clave %s no existe.\n", palabraClave);
                            }
                            break;
                    }
                } while (determinar != 1 && determinar != 2);
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

Tnodo *quitarNodo(Tnodo **head, int idQuitar) {
    Tnodo **aux = head;
    while (*aux != NULL && (*aux)->T.TareaID != idQuitar) {
        aux = &(*aux)->Siguiente;  // VER ESTO!
    }

    if (*aux != NULL) {
        Tnodo *temp = *aux;
        *aux = (*aux)->Siguiente;
        temp->Siguiente = NULL;
        return temp;
    }
    return NULL;
}

Tnodo *buscarDato(Tnodo *head, int palabraClave) {
    Tnodo *aux = head;

    while (aux != NULL && aux->T.TareaID != palabraClave) {
        aux = aux->Siguiente;
    }
    return aux;
}

Tnodo *buscarPalabra(Tnodo *head, char *palabraClave) {
    Tnodo *aux = head;
    while (aux != NULL) {
        if (strstr(aux->T.Descripcion, palabraClave)) {
            return aux;
        }
        aux = aux->Siguiente;
    }
    return NULL;
}

void mostrarNodo(Tnodo *nodo) {
    if (nodo != NULL) {
        printf("Tarea ID: %i\n", nodo->T.TareaID);
        printf("Descripcion: %s\n", nodo->T.Descripcion);
        printf("Duracion: %i\n", nodo->T.Duracion);
    }
}

void liberarLista(Tnodo **liberar) {
    while (*liberar != NULL) {
        free(liberar);
        *liberar = *liberar->
    }
}
