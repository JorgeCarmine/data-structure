// Declaracion de funciones
void crearC(void);
void insertarC(void);
void lsC(void);
void eliminarC(void);
void campovacio(void);
void selC(void);
int contador_campos();
void actualizapunteroC();

// declaracion de variables 
struct dato *inicioC,*actualC,*finalC,*auxC,*aux2C,*camposeleccionado,*opcioncampo;
//base de datos vacia
void campovacio(void)
{
    inicioC=actualT->siguienteD;
    actualC=actualT->siguienteD;
    finalC=actualT->siguienteD;
    camposeleccionado = NULL;
    
    return;
}
// insertar primer campo
void crearC()
{
 
  if(actualT==NULL)
  {
      printf("   No se selecciono tabla\n");
     return;
  }
   
    if(actualT->siguienteD==NULL)
    {
       campovacio();
       actualC = (struct dato *)malloc(sizeof(struct dato));
       actualT->siguienteD=actualC;
       actualC->anterior=actualT;
       actualC->siguiente=NULL;
       actualC->siguienteD=NULL;
       finalC=actualC;
       inicioC=actualC;
       printf("nombre del campo = ");
       fgets(actualC->nombre,50,stdin);
     }
      else
      {
         insertarC();
      }
return;
}
// insertar campo al Final
void insertarC(void)
{
    auxC=finalC;
    actualC=(struct dato*) malloc(sizeof(struct dato));
    actualC->siguienteD=NULL;
    actualC->siguiente=NULL;
    actualC->anterior=auxC;
    auxC->siguiente=actualC;
    finalC=actualC;
    printf("3)nuevo ActualC: %p\n",actualC);
    printf("nombre del campo = ");
    fgets(actualC->nombre,50,stdin);
    printf("actualT->nombre: %s",actualT->nombre);
    return;   
}
// listar campo
void lsC()
{
  if(actualT==NULL)
  {
     printf("No se selecciono tabla\n");
     return;
  }else{

  if (actualT->siguienteD==NULL)
    {
     printf("    no hay campos que listar\n");
     return;
    }else{
    actualC=actualT->siguienteD;
    while (actualC != NULL)
    {
        printf("%s",actualC->nombre);
        actualC=actualC->siguiente;
    }
    actualC=actualT->siguienteD;
    return;
    }
  }
}

// seleccionar  campo
void selC()
{
  char opcion[50];
  printf("nombre del campo = ");
  fgets(opcion, 50, stdin);
  actualC=actualT->siguienteD;
  if (actualC==NULL)
     printf("    no hay campos que seleccionar\n");
  else
     {   
        while (actualC != NULL)
        {
          if(strcmp(opcion,actualC->nombre)==0)
           {
             camposeleccionado=actualC;
             printf(" campo %s seleccionado\n", camposeleccionado->nombre);
             break;
           }
           else{
                 actualC=actualC->siguiente;
               } 
        }
     }
      if(camposeleccionado==NULL)
         printf("no se selecciono ningun campo\n");
           
      actualC=actualT->siguienteD; //lo ponemos al inicio de la tabla
return;
}

void eliminarC()
{
    if(actualT==NULL){
        printf("No has seleccionado ninguna tabla");
        return;
    }else{
    if(inicioC == NULL && actualC == NULL && finalC == NULL)
    {
        printf("No se han creado campos en la tabla\n");
    }else{
        char opcion[50];
        printf("nombre del campo a eliminar=");
        fgets(opcion, 50, stdin);
        actualC = inicioC;
        while (actualC != NULL)
        {
            //printf("%s",actual->nombre);
            if(strcmp(opcion,actualC->nombre)==0)
            {
                opcioncampo = actualC;
                printf(" tabla %s seleccionada para eliminar\n", opcioncampo->nombre);
                break;
            }else{
                //printf("%d %s %s \n", strcmp(opcion,actual->nombre),opcion,actual->nombre);
                actualC=actualC->siguiente;
                
            }
        }
        
        if (opcioncampo == NULL)
        {
            
            printf("No se ha encontrado el campo con el nombre %s\n", opcion);
            return;
        }else{
            //borrar el unico dato
            printf("\nauxElimina: %p finalC: %p inicioC: %p opcioncampo->siguiente: %p opcioncampo->anterior: %p\n",opcioncampo,finalC,inicioC,opcioncampo->siguiente,opcioncampo->anterior);
            
            if(opcioncampo == finalC && opcioncampo == inicioC)
            {
                free (opcioncampo);
                //opcioncampo=NULL;
                inicioC=NULL;
                finalC=NULL;
                actualC = NULL;
                actualT->siguienteD=NULL;
                printf("se borro el ultimo campo, tabla vacia\n");
                
                return;
            }
            //eliminar dato final
            if(opcioncampo == finalC)
            {
                auxC=opcioncampo->anterior;
                free (opcioncampo);
                finalC = auxC;
                actualC = finalC; //ubicamos de nuevo ha actualC
                actualC->siguiente=NULL;
                actualC->siguienteD=NULL;
                
                printf("se borro el campo final\n");
                
                return;
            }
            //eliminar dato inicial
            if(opcioncampo == inicioC)
            {
                auxC=opcioncampo->siguiente;
                inicioC=auxC;
                free (opcioncampo);
                actualT->siguienteD=auxC;
                auxC->anterior=actualT;
                actualC = finalC; //ActualC se va al final
                printf("se borro el campo inicial\n");
                
                return;
            }
            //eliminar enmedio de dos campos
            printf("\nauxElimina: %p final: %p inicio: %p auxElimina->siguiente: %p auxElimina->anterior: %p\n",opcioncampo,finalC,inicioC,opcioncampo->siguiente,opcioncampo->anterior);
            
            if(opcioncampo->siguiente != NULL && opcioncampo->anterior != NULL)
            {
                auxC=opcioncampo->siguiente;
                aux2C=opcioncampo->anterior;
                free (opcioncampo);
                //auxElimina=aux;
                aux2C->siguiente=auxC;
                auxC->anterior = aux2C;
                printf("se borro el dato medio\n");              
                return;
            }            
        }
    }
  }    
}// termina funcion


void eliminarcampos()
{
    if (actualT==NULL) {
        printf("No has seleccionado ninguna tabla");
    }else{
    actualC=finalC;
    if(inicioC == NULL && actualC == NULL && finalC == NULL)
    {
        printf("No se han creado campos\n");
    }else{
        while (actualC != actualT)
        {
            opcioncampo=actualC;
            actualC=actual->anterior;
            free(opcioncampo);
        }
        inicioC = NULL;
        actualC = NULL;
        finalC = NULL;
        actualT->siguienteD = NULL;
        //raiz =NULL;
        printf("Se han eliminado todas las tablas\n");
        }
    
    }
    
}

int contador_campos(){
    int cuenta=0;
    actualC=actualT->siguienteD;
    while (actualC != NULL)
    {
        actualC=actualC->siguiente;
        cuenta++;
    }
    return cuenta;
}

void actualizapunteroC()
{ 
    if (actualT->siguienteD==NULL) {
        return;
    }else{
    inicioC = actualT->siguienteD;
    actualC=actualT->siguienteD;
    while (actualC != NULL)
    {
        if (actualC->siguiente==NULL) {
            finalC = actualC;
        }
        actualC=actualC->siguiente;
    }
    //finalC = actualC->anterior;
    return;
    }   
}
