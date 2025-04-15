#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Tarea {
    int TareaID;
    char *Descripcion;
    int Duracion;
} Tarea;

typedef struct Nodo {
    Tarea T;
    struct Nodo *Siguiente;
} Nodo;

typedef Nodo Lista;

Lista *crearLista();
Nodo *crearNodo(int id, char *buffer, int duracion);
void insertarNodo(Lista **L, Nodo *nuevo);
void cargarLista(Lista **L);
void mostrarLista (Lista *L);

int main() {
    Lista *pendientes = crearLista();
    Lista *realizadas = crearLista();

    cargarLista(&pendientes);
    mostrarLista (pendientes);

    liberarLista(pendientes);
    liberarLista(realizadas);
    return 0;
}

Lista *crearLista() {
    return NULL;
}

void cargarLista(Lista **L) {
    char buffer[100];
    int opc, id = 1000, duracion;

    printf("Interfaz de carga de tareas\n");

    do {
        printf("1) Agregar nueva tarea pendiente\n\n2) Transferir tarea a realizada\n3) Ver todas las tareas pendientes y realizadas\n4) Consultar tareas por ID o palabra clave\n5) Salir\n");
        printf ("Seleccion: ");
        scanf("%d", &opc);
        getchar(); // limpia '\n' del buffer

        switch (opc) {
            case 1:
                printf("Ingrese la descripcion: ");
                gets(buffer);
                do {
                    printf("Ingrese la duracion (entre 10 y 100): ");
                    scanf("%d", &duracion);
                    getchar();
                } while (duracion < 10 || duracion > 100);

                Nodo *nuevo = crearNodo(id, buffer, duracion);
                id++;
                insertarNodo(L, nuevo);
                break;

            case 5:
                printf("Saliendo...\n");
                break;
        }
    } while (opc != 5);
}

Nodo *crearNodo(int id, char *buffer, int duracion) {
    Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));
    nuevo->T.TareaID = id;
    nuevo->T.Descripcion = (char *)malloc(strlen(buffer) + 1);
    strcpy(nuevo->T.Descripcion, buffer);
    nuevo->T.Duracion = duracion;
    nuevo->Siguiente = NULL;

    return nuevo;
}

void insertarNodo(Lista **L, Nodo *nuevo) {
    nuevo->Siguiente = *L;
    *L = nuevo;
}

void mostrarLista (Lista *L){
    while (L != NULL){
        printf ("Descripcion: %s\n", L->T.Descripcion);
        printf ("Duracion: %i\n", L->T.Duracion);
        printf ("Tarea ID: %i\n", L->T.TareaID);
        L = L->Siguiente;
        printf ("\n----------\n");
    }
}

Nodo * QuitarNodo(Nodo * L, int dato) {
    
    Nodo ** aux = L;
    while (*aux != NULL && (*aux)-> != dato) {
    aux = &(*aux)->Siguiente;

}

    if (*aux) {
        Nodo *temp = *aux;
        *aux = (*aux)->siguiente;
        temp->siguiente =NULL;
        return temp;
    }
    return NULL;
}

void liberarLista (Lista *L){
    Lista *temp;
    while (L != NULL){
        *temp = *L;
        *L = *(L->Siguiente);
        free(temp);
    }
    free(L);
}