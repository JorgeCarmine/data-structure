// SQL Elaborado por Jorge Gomez Dominguez y Víctor Ludwig Escalante
// Fecha 7 de Diciembre 2015
// Proyecto SQL evaluación de estructura de datos.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tablas.h"
#include "campos.h"
#include "registros.h"

// Declaracion de funciones
void insertar(void);
void insertarF(void);
void insertarI(void);
void listar(void);
void listarD(void);
void menu(void);
void avanza(void);
void retrocede(void);
void borrar(void);
void veractual();
void veractualC();
void veractualT();
void eliminarregistros();
void buscarR();
void selR();
void modificarR();


int main()
{
    tablavacia();
    menu();
    return 0;
}

//menu
void menu(void)
{
    char opcion[20],quit[20];
    strcpy(quit,"quit");
    
    while (strcmp(opcion, quit) != 0)
    {
        printf("#SQL:  ");
        //  fgets(opcion,20,stdin );
        gets(opcion);
        //    printf("opcion=%d\n",strcmp(opcion,"insertar"));
        if(strcmp(opcion,"creartab")==0) creartab(); //crear tabla
            else
        if(strcmp(opcion,"seltab")==0) seltab(); //seleccionar tabla
            else
        if(strcmp(opcion,"actualT")==0) veractualT(); //muestra la tabla actual seleccionada
            else
        if(strcmp(opcion,"lstab")==0) lstab();  //mostrar la lista de tablas();
            else
        //menu de campos
        if(strcmp(opcion,"crearC")==0) crearC(); //crear campo
            else
        if(strcmp(opcion,"selC")==0) selC(); //seleccionar Campo
            else
        if(strcmp(opcion,"lsC")==0) lsC();  //mostrar la lista de campos
            else
        if(strcmp(opcion,"eliminartab")==0) eliminartab();  //Elimina tabla
            else
        if(strcmp(opcion,"eliminartabs")==0) eliminartabs();  //Elimina todas las tablas
            else
        if(strcmp(opcion,"eliminarC")==0) eliminarC();  //Elimina todas las tablas
            else
        if(strcmp(opcion,"actual")==0) veractual();  //ver actual
            else
        if(strcmp(opcion,"actualC")==0) veractualC();  //ver actual
            else
        if(strcmp(opcion,"eliminarcampos")==0) veractualC();  //ver actual
            else
        if(strcmp(opcion,"crearR")==0) crearR();
            else
        if(strcmp(opcion,"lsR")==0) lsR(); //ver actual
            else                                    
        if(strcmp(opcion,"eliminarR")==0) eliminarR(); //ver actual
            else
        if(strcmp(opcion,"eliminarregistros")==0) eliminarregistros(); //ver actual
            else
        if(strcmp(opcion,"buscarregistro")==0) buscarR(); //ver actual
            else
        if(strcmp(opcion,"selR")==0) selR(); //ver actual
            else
        if(strcmp(opcion,"modificarR")==0) modificarR(); //ver actual
            else
        if(strcmp(opcion, "ordenarR")==0) ordenarR();
            else
        if(strcmp(opcion,"clear")==0) system("clear"); //system( "clear" )
            else 
            printf("comando no reconocido\n");
    } //end while
}

void veractual(){
    printf("actual-> %s",actual->nombre);
}
void veractualC(){
    if (actualC==NULL) {
        printf("No hay un campo seleccionado\n");
    }else{
    printf("actual-> %s",actualC->nombre);
    }
}

void veractualT(){
    if (actualT==NULL) {
        printf("No hay una tabla seleccionada\n");
    }else{
        printf("actual-> %s",actualT->nombre);
    }
}
