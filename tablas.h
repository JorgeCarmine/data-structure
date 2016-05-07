
// Declaracion de funciones
void creartab(void);
void insertarTabla(void);
void lstab(void);
void eliminartab(void);
void tablavacia(void);
void seltab(void);
void actualizapunteroC();
void actualizapunteroR();
void actualRvacio();
// DECLARACION DE ESTRUCTURAS
struct dato{
    char nombre[50];
    char vector[15][50];
    struct dato *siguiente;
    struct dato *anterior;
    struct dato *siguienteD;
    struct dato *siguienteI;
};
// declaracion de variables
struct dato *inicio,*actual,*final,*aux,*aux2,*auxElimina, *raiz, *actualT;
//base de datos vacia
void tablavacia(void)
{
    inicio=NULL;
    actual=NULL;
    final=NULL;
    raiz=NULL;
    actualT=NULL;
    return;
}
// insertar primer dato
void creartab()
{
    if(actual == NULL && final == NULL && inicio == NULL && raiz == NULL)
    {
        actual= (struct dato *)malloc(sizeof(struct dato));
        actual->siguiente=NULL;
        actual->anterior=NULL;
        actual->siguienteD=NULL;
        actual->siguienteI=NULL; //agregamos este puntero
        inicio= actual;
        final=actual;
        raiz=actual;
        printf("nombre de la tabla=");
        fgets(actual->nombre,50,stdin);
        //fgets (nombre_de_la_variable, tamaño, stdin)
        //printf("inicio=%p actual=%p  final=%p actual->nombre=%s actual->siguiente=%p\n",inicio,actual,final,     actual->nombre,actual->siguiente);
    }
    else
        insertarTabla();
    return;
}
// insertar tabla al Final
void insertarTabla(void)
{
    aux=final;
    actual=(struct dato*) malloc(sizeof(struct dato));
    final=actual;
    aux->siguiente=actual;
    actual->anterior=aux;
    actual->siguiente=NULL;
    actual->siguienteD=NULL;
    actual->siguienteI=NULL; //agregamos este puntero
    printf("nombre de la tabla= ");
    fgets(actual->nombre,10,stdin);
    return;
}

// listar tabla
void lstab()
{
    actual=raiz;
    if (actual==NULL)
    {
        printf("    no hay tablas que listar\n");
    }
    while (actual != NULL)
    {
        printf("%s",actual->nombre);
        actual=actual->siguiente;
    }
    actual=final;
    return;
}

// seleccionar  tabla
void seltab()
{
    
    char opcion[50];
    printf("nombre de la tabla =");
    fgets(opcion, 50, stdin);
    actual=raiz;
    if (actual==NULL)
    {
        printf(" No hay tablas que seleccionar\n");
    }
    else
    {
        while (actual != NULL)
        {
            //printf("%s",actual->nombre);
            if(strcmp(opcion,actual->nombre)==0)
            {
                actualT=actual;
                //actualizar punteros
                actualizapunteroC();
                //actualizar registros
                actualizapunteroR();
                actualRvacio();
                printf(" tabla %s seleccionada\n", actualT->nombre);
               // actual = final;
                actual=actualT;
                break;
            }
            else{
                //printf("%d %s %s \n", strcmp(opcion,actual->nombre),opcion,actual->nombre);
                actual=actual->siguiente;
            }
        }
    }
    if(actual==NULL)
    {
        printf("No se encontro ninguna tabla con el nombre %s=\n", opcion);
    }
    actual=final;
    return;
}


void eliminartab()
{
    if(inicio == NULL && actual == NULL && final == NULL)
    {
        printf("No se han creado tablas\n");
    }else{
        char opcion[50];
        printf("nombre de la tabla a eliminar=");
        fgets(opcion, 50, stdin);
        actual = inicio;
        while (actual != NULL)
        {
            //printf("%s",actual->nombre);
            if(strcmp(opcion,actual->nombre)==0)
            {
                auxElimina = actual;
                printf(" tabla %s seleccionada para eliminar\n", auxElimina->nombre);
                break;
            }else{
                //printf("%d %s %s \n", strcmp(opcion,actual->nombre),opcion,actual->nombre);
                actual=actual->siguiente;
            }
        }
        
        if (auxElimina == NULL)
        {
            printf("No se ha encontrado la tabla con el nombre %s\n", opcion);
            return;
        }else{
            //borrar el unico dato
            printf("\nauxElimina: %p final: %p inicio: %p auxElimina->siguiente: %p auxElimina->anterior: %p\n",auxElimina,final,inicio,auxElimina->siguiente,auxElimina->anterior);
            
            if(auxElimina == final && auxElimina == inicio)
            {
                free (auxElimina);
                auxElimina=NULL;
                inicio=auxElimina;
                final=auxElimina;
                raiz = auxElimina;
                actual = auxElimina;
                printf("se borro el ultimo dato, lista vacia\n");
                
                return;
            }
            //eliminar dato final
            if(auxElimina == final)
            {
                aux=auxElimina->anterior;
                free (auxElimina);
                final = aux;
                actual = final;
                actual->siguiente=NULL;
                actual->siguienteD=NULL;
                actual->siguienteI=NULL;// agregamos este puntero
                //auxElimina=aux;
                //final=auxElimina;
                printf("se borro el dato final\n");
                return;
            }
            //eliminar dato inicial
            if(auxElimina == inicio)
            {
                aux=auxElimina->siguiente;
                free (auxElimina);
                auxElimina=aux;
                inicio=auxElimina;
                raiz = auxElimina;
                actual = final;
                printf("se borro el dato inicial\n");
                
                return;
            }
            //eliminar enmedio de dos dtos
            printf("\nauxElimina: %p final: %p inicio: %p auxElimina->siguiente: %p auxElimina->anterior: %p\n",auxElimina,final,inicio,auxElimina->siguiente,auxElimina->anterior);
            
            if(auxElimina->siguiente != NULL && auxElimina->anterior != NULL)
            {
                aux=auxElimina->siguiente;
                aux2=auxElimina->anterior;
                free (auxElimina);
                //auxElimina=aux;
                aux2->siguiente=aux;
                aux->anterior = aux2;
                printf("se borro el dato medio\n");
                return;
            }
        }
    }
}// termina funcion



void eliminartabs()
{
    actual=inicio;
    if(inicio == NULL && actual == NULL && final == NULL)
    {
        printf("No se han creado tablas\n");
    }else{
        while (actual != NULL)
        {
            auxElimina=actual;
            actual=actual->siguiente;
            free(auxElimina);
        }
        inicio = NULL;
        actual = NULL;
        final = NULL;
        raiz =NULL;
        printf("Se han eliminado todas las tablas\n");
    }
    
}
