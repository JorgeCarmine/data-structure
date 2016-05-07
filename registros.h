#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Declaracion de funciones
void crearR(void);
void lsR(void);
void registrovacio(void);
void insertarRegistros(void);
void actualizapunteroR();
void eliminarR();
void eliminarregistros();
void buscarR();
void selR();
void actualRvacio();
void modificarR();
void ordenarR(void);
void ordenar(void);
void burbuja(char A[15][50], int n);

// declaracion de variables
struct dato *inicior,*actualr,*finalr,*auxr,*auxr2,*opcioneliminar,*opcionmodificar;
char datos[15][50];
//base de datos vacia
void registrovacio(void)
{
    inicior=NULL;
    actualr=NULL;
    finalr=NULL;
    return;
}

void crearR()
{
    if(actualT == NULL){
        printf("No has seleccionado ninguna tabla\n");
        return;
    }else if (actualT->siguienteD==NULL){
        printf("No hay campos registrados en esta tabla\n");
        return;
    }
    else
    {
    
    if(actualT->siguienteI == NULL)
        {
            int i = 0;
            //printf("entra");
            actualr= (struct dato *)malloc(sizeof(struct dato));
            actualr->siguienteD=actualT;
            actualr->siguiente=NULL;
            actualr->anterior=NULL;
            actualr->siguienteI=NULL;
            actualT->siguienteI = actualr;
            inicior=actualr;
            finalr=actualr;
            
            actualC=actualT->siguienteD; //poner puntero al inicio de la estructura
            while (actualC != NULL)
            {
                printf("%s",actualC->nombre);
                fgets(actualr->vector[i],50,stdin);
                //scanf("%s",actualr->vector[i]);
                actualC=actualC->siguiente;
                i++;
            }
            
            return;
            
            }else{
                insertarRegistros();
                return;
            }
    }
}

void insertarRegistros(void)
{
    int i = 0;
    auxr=finalr;
    actualr=(struct dato*) malloc(sizeof(struct dato));
    actualr->siguienteD=auxr;
    actualr->siguienteI=NULL;
    actualr->siguiente=NULL;
    actualr->anterior=NULL;
    auxr->siguienteI=actualr;
    finalr=actualr;
    
    actualC=actualT->siguienteD; //poner puntero al inicio de la estructura
    while (actualC != NULL)
    {
        printf("%s",actualC->nombre);
        fgets(actualr->vector[i],50,stdin);
        actualC=actualC->siguiente;
        i++;
    }
    
    return;
    
}




// listar registros
void lsR()
{
    int i;
    int contador_registros=1;
    printf("ActualT->nombre: %s\n",actualT->nombre);
    if(actualT==NULL)
    {
        printf("No se selecciono tabla\n");
        return;
    }else{
        
        if (actualT->siguienteI==NULL)
        {
            printf("No hay registros que listar\n");
            return;
        }else{
            auxr=actualT->siguienteI;
            while (auxr != NULL)
            {
                printf("%d \t",contador_registros);
                for (i=0; i<15; i++) {
                   printf("%s\t",auxr->vector[i]);
                }
                printf("\n");
                auxr=auxr->siguienteI;
                contador_registros++;
            }
            auxr=actualT->siguienteI;
            
            return;
        }
    }
}


void actualizapunteroR(){
    
    if (actualT->siguienteI==NULL) {
        return;
    }else{
        inicior = actualT->siguienteI;
        actualr = actualT->siguienteI;
        while (actualr != NULL)
        {
            if (actualr->siguienteI==NULL) {
                finalr = actualr;
            }
            actualr=actualr->siguienteI;
        }
        //finalC = actualC->anterior;
        return;
    }
    
}



void eliminarR()
{
    int valor;
    int contador_elimina=1;
    if(actualT==NULL){
        printf("No has seleccionado ninguna tabla");
        return;
        }else{
            if(inicioC == NULL && actualC == NULL && finalC == NULL)
            {
                printf("No se han creado campos en la tabla\n");
                return;
            }else{
                if (actualT->siguienteI==NULL) {
                    printf("No hay registros guardados");
                    return;
                }else{
                
                char opcion[50];
                printf("numero del registro a eliminar=");
                fgets(opcion, 50, stdin);
                actualr = actualT->siguienteI;
                valor = atoi(opcion);
                while (actualr != NULL)
                {
                    
                    
                    //printf("%s",actual->nombre);
                    if(valor!=0 && valor == contador_elimina)
                    {
                        opcioneliminar = actualr;
                        printf(" tabla %s seleccionada para eliminar\n", opcioneliminar->nombre);
                        break;
                    }else{
                    //printf("%d %s %s \n", strcmp(opcion,actual->nombre),opcion,actual->nombre);
                    actualr=actualr->siguienteI;
                    
                    }
                    contador_elimina++;
                }
            
            if (opcioneliminar == NULL)
            {
                
                printf("No se ha encontrado el resgistro solicitado %s\n", opcion);
                return;
            }else{
                //borrar el unico dato
               
                
                if(opcioneliminar == finalr && opcioneliminar == inicior)
                {
                    free (opcioneliminar);
                    //opcioncampo=NULL;
                    inicior=NULL;
                    finalr=NULL;
                    actualr = NULL;
                    actualT->siguienteI=NULL;
                    printf("se borro el ultimo registro, tabla vacia\n");
                    
                    return;
                }
                //eliminar dato final
                if(opcioneliminar == finalr)
                {
                    auxr=opcioneliminar->siguienteD;
                    finalr = auxr;
                    free (opcioneliminar);
                    actualr = finalr; //ubicamos de nuevo ha actualC
                    actualr->siguienteI=NULL;
                    actualr->anterior=NULL;
                    actualr->siguiente=NULL;
                    auxr= auxr->siguienteD;
                    actualr->siguienteD=auxr;
                    
                    printf("se borro el campo final\n");
                    
                    return;
                }
                //eliminar dato inicial
                if(opcioneliminar == inicior)
                {
                    auxr=opcioneliminar->siguienteI;
                    inicior=auxr;
                    free (opcioneliminar);
                    actualT->siguienteI=auxr;
                    auxr->anterior=NULL;
                    auxr->siguiente=NULL;
                    auxr->siguienteD=actualT;
                    actualr = finalr; //Actualr se va al finalr
                    printf("se borro el campo inicial\n");
                    
                    return;
                }
                //eliminar enmedio de dos campos
                if(opcioneliminar->siguienteI != NULL && opcioneliminar->siguienteD != NULL)
                {
                    auxr=opcioneliminar->siguienteD;
                    auxr2=opcioneliminar->siguienteI;
                    free (opcioneliminar);
                    //auxElimina=aux;
                    auxr->siguienteI=auxr2;
                    auxr2->siguienteD = auxr;
                    printf("se borro el dato medio\n");
                    
                    return;
                }
                
            }
                    
            }
        }
        
    }
    
    
}// termina funcion


void eliminarregistros()
{
    if (actualT==NULL) {
        printf("No has seleccionado ninguna tabla");
        return;
    }else{
        actualr=finalr;
        if(inicior == NULL && actualr == NULL && finalr == NULL)
        {
            printf("No se han creado registros\n");
            return;
        }else{
            while (actualr != actualT)
            {
                //printf("Entro while");
                opcioneliminar=actualr;
                actualr=actualr->siguienteD;
                free(opcioneliminar);
            }
            inicior = NULL;
            actualr = NULL;
            finalr = NULL;
            actualT->siguienteI = NULL;
            //raiz =NULL;
            printf("Se han eliminado todos los registros\n");
            return;
        
        }
        
    }
    
}

void buscarR(){
    int i,j;
    int contador_total=1;
    if (actualT==NULL) {
        printf("No has seleccionado ninguna tabla");
        return;
    }else{
        actualr=actualT->siguienteI;
        if(inicior == NULL && actualr == NULL && finalr == NULL)
        {
            printf("No se han creado registros\n");
            return;
        }else{
            char opcion[50];
            printf("ingresa criterio de busqueda=");
            fgets(opcion, 50, stdin);
            while (actualr != NULL)
            {
                //printf("entra a W\n");
                j=0;
                for (i=0; i<15; i++) {
                    //printf("%s",opcion);
                    if (strcmp(opcion, actualr->vector[i])==0) {
                        //printf("%s", actualr->vector[i]);
                        j=1;
                        }
                    }
                if (j==1) {
                    printf("-> %d\t",contador_total);
                    for (i=0; i<15; i++){
                        printf("%s\t",actualr->vector[i]);
                    }
                    
                }
                actualr=actualr->siguienteI;
                contador_total++;
            }
            
            return;
            }
            
        return;
        }
    }

void selR()
{
    if (actualT->siguienteI==NULL) {
        printf("No hay registros que seleccionar");
    }else{
    char opcion[50];
    int valor;
    int contador_modifica=1;
    printf("numero del registro a seleccionar= ");
    fgets(opcion, 50, stdin);
    valor = atoi(opcion);
    actualr = actualT->siguienteI;
    while (actualr != NULL)
    {
        
        if(valor!=0 && valor == contador_modifica)
        {
            opcionmodificar = actualr;
            printf(" El registro %s ha sido seleccionado\n", opcionmodificar->vector[0]);
            break;
        }else{

            actualr=actualr->siguienteI;
            
        }
        contador_modifica++;
    }
    return;
    }// termina else cuando no hay registros
}



void modificarR(){
    int cuenta=0;
    if (actualT==NULL) {
        printf("No has seleccionado ninguna tabla");
        return;
    }
    if (opcionmodificar==NULL) {
        printf("No has seleccionado ningun registro");
        return;
    }
    char opcion[50];
    printf("ingresa campo a modificar = ");
    fgets(opcion, 50, stdin);
    actualC = actualT->siguienteD;
    while (actualC!=NULL) {
        
        if (strcmp(opcion, actualC->nombre)==0) {
            char opciondos[50];
            printf("Dame el nuevo valor = ");
            fgets(opciondos, 50, stdin);
            strcpy(opcionmodificar->vector[cuenta], opciondos);
            actualC=actualC->siguiente;
        }else{
            actualC=actualC->siguiente;
        }
        cuenta++;
    }
    actualC = actualT->siguienteD;
    return;
    
}

void actualRvacio(){
    opcionmodificar = NULL;
    return;
}

void ordenarR(){
    char opcion[50];
    int contador = 1, i = 0;
    if (actualT==NULL) 
    {
        printf("No has seleccionado ninguna tabla");
        return;
    }
    printf("Ordenar por: ");
    fgets(opcion, 50, stdin);
    auxr=actualT->siguienteD;
    auxr2=actualT->siguienteI;
    while(auxr != NULL)
    {
        if (strcmp(opcion, auxr->nombre)==0)
        {
            break;
        }
        auxr = auxr->siguiente;
        auxr2=auxr2->siguienteI;
        contador++;
    }

    auxr2=actualT->siguienteI;
    if (auxr != NULL)
    {
        while(auxr2 != NULL)
        {
            //printf("%s\n", auxr2->vector[contador-1]);
            strcpy(datos[i], auxr2->vector[contador-1]);
            auxr2=auxr2->siguienteI;
            i++;
        }
        burbuja(datos, i);
    }

    if (auxr == NULL)
    {
        printf("No existe el campo %s en la tabla %s\n",opcion, actualT->nombre);
        return;
    }
}

void burbuja(char A[15][50], int n)
{
    int temp2, j, i;
    char temp[10];
    for(i = (n-1); i >= 0; i--)
    {
        temp2= n-1;
        for(j = 1; j <= temp2; j++)
        {
            if(strcmp(A[j-1],A[j]) > 0)
            {
                strcpy(temp, A[j-1]);
                strcpy(A[j-1], A[j]);
                strcpy(A[j], temp);
            }
        }
    }

    for(i = (n-1); i >= 0; i--)
    {
        printf("%s\n", datos[i]);
    }
}

