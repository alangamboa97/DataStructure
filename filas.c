#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _Nodo
{
	char dato;
	struct _Nodo *sig;
}Fila;

//RESERVAMOS MEMORIA PARA LA FILA
Fila *Crear(char dato)
{
	Fila *nuevo_nodo;
	nuevo_nodo = (Fila*)malloc(sizeof(Fila));
	nuevo_nodo -> dato=dato;
  nuevo_nodo -> sig=NULL;
    return nuevo_nodo;
}

//DAMOS DE ALTA LA FILA
Fila *Alta(Fila *inicio, int dato)
{
	Fila *nuevafila, *aux;
	nuevafila = Crear(dato);
	if(inicio==NULL)
	{
		inicio = nuevafila;
	 }else
	 	{
	 		aux = inicio;

	 		while(aux->sig != NULL)
	 		{
	 			aux = aux->sig;
			 }

			 aux -> sig = nuevafila;

		}

		return inicio;
}


//DAMOS DE BAJA LA FILA
Fila *pop(Fila *inicio)
{
	Fila *aux;

	if(inicio != NULL)
	{
		aux = inicio;
		inicio = inicio -> sig;
		free(aux);
	}

	return inicio;
}


//CREAMOS EL CUERPO DE MOSTRAR UNA FILA
void Mostrar(Fila *top)
{
	int i=0;
    if(top==NULL)
	{
    	printf("\n TU FILA SE ENCUENTRA VACIA");
	}else
		{
          while(top!=NULL)
		  {
            printf("%c",top->dato);
            top=top->sig;
          }
        }

}

//TAMA�O DE LA FILA

void Tamano(Fila *cima){
    int t=0;
    if(cima!=NULL){
        do{
            t++;
            cima=cima->sig;
        }while(cima!=NULL);
    }
    printf("Tama�o: %d\n",t);
}


int main()
{
	Fila *top;//Puntero que apunta a la estructura pila

    top=NULL;//Declaramos en nulo al puntero
    char dato;
    int opc=1, tam;

    printf("1. Insertar\n");
    printf("2. Borrar\n");
    printf("3. Mostrar tama�o\n");
    printf("4. Mostrar fila\n");

    do{
        switch(opc){
            case 1:
                printf("\n inserta un dato ");
                scanf("%c",&dato);
                top = Alta(top,dato);
                //Mostrar(top);
                fflush(stdin);
            break;
            case 2:
                top = pop(top);
                Mostrar(top);
            break;
            case 3:
                Tamano(top);
            break;
            case 4:
                Mostrar(top);
            break;
        }

        printf("\nElige una opcion: ");
        scanf("%d",&opc);
        fflush(stdin);
    }while(opc==1 || opc==2 || opc==3 || opc==4);

    return 0;
}
