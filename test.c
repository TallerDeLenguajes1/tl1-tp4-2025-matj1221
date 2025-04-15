void mostrarLista (Lista *L){
    while (L != NULL){
        printf("Tarea ID: %d\n", L->T.TareaID);
        printf("Descripción: %s\n", L->T.Descripcion);
        printf("Duración: %d minutos\n", L->T.Duracion);
        printf("------------------------\n");
        L = L->Siguiente;
    }
}
