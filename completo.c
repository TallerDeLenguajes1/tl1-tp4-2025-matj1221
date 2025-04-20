#include <stdio.h>
#include <stdlib.h>

typedef struct Tnodo {
    int dato;
    struct Tnodo* siguiente;
} Tnodo;

Tnodo* crearLista();
Tnodo* crearNodo(int valor);
Tnodo* crearNodo(int valor);
void insertarNodo(Tnodo** head, Tnodo* insertar);
void mostrarNodo(Tnodo* head);
Tnodo* buscarNodo(Tnodo* head, int valor);
Tnodo* quitarNodo(Tnodo** head, int valor);
void eliminarNodo(Tnodo* borrar);

int main() {
    Tnodo* head;
    head = crearLista();

    Tnodo* nodo1 = crearNodo(20);
    Tnodo* nodo2 = crearNodo(30);
    Tnodo* nodo3 = crearNodo(40);

    insertarNodo(&head, nodo1);
    insertarNodo(&head, nodo2);
    insertarNodo(&head, nodo3);

    mostrarNodo(head);

    if (buscarNodo(head, 30)) {
        printf("\nSe encontro el valor buscado.\n");
    } else {
        printf("\nNO se encontro el valor buscado.\n");
    }

    eliminarNodo(quitarNodo(&head, 30));

    mostrarNodo(head);

    return 0;
}

Tnodo* crearLista() {
    return NULL;
}

Tnodo* crearNodo(int valor) {
    Tnodo* nuevoNodo;
    nuevoNodo = (Tnodo*)malloc(sizeof(Tnodo));
    nuevoNodo->dato = valor;
    nuevoNodo->siguiente = NULL;
    return nuevoNodo;
}

void insertarNodo(Tnodo** head, Tnodo* insertar) {
    insertar->siguiente = *head;
    *head = insertar;
}

void mostrarNodo(Tnodo* head) {
    while (head != NULL) {
        printf("%i -> ", head->dato);
        head = head->siguiente;
    }
    printf("NULL");
}

Tnodo* buscarNodo(Tnodo* head, int valor) {
    Tnodo* aux = head;

    while (aux != NULL && aux->dato != valor) {
        aux = aux->siguiente;
    }
    return aux;
}

Tnodo* quitarNodo(Tnodo** head, int valor) {
    Tnodo** aux = head;

    while (*aux != NULL && (*aux)->dato != valor) {
        aux = &(*aux)->siguiente;
    }

    if (*aux != NULL) {
        Tnodo* temp = *aux;
        *aux = (*aux)->siguiente;
        temp->siguiente = NULL;
        return temp;
    }
    return NULL;
}

void eliminarNodo(Tnodo* borrar) {
    if (borrar != NULL) {
        free(borrar);
    }
}