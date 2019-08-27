#include <stdio.h>
#include <stdlib.h>

typedef struct _Nodo
{
	int dato;
	struct _Nodo *sig;
}Fila;


Fila *Crear(int dato)
{
	Fila *nuevo;
	nuevo = (Fila*)malloc(sizeof(Fila));
	nuevo -> dato=dato;
  nuevo -> sig=NULL;
  return nuevo;
}

Fila *Alta(Fila *inicio, int dato)
{
	Fila *nuevo, *aux;
	nuevo = Crear(dato);
	if(inicio==NULL)
	{
		inicio = nuevo;
	 }else
	 	{
	 		aux = inicio;

	 		while(aux->sig != NULL)
	 		{
	 			aux = aux->sig;
			 }

			 aux -> sig = nuevo;
	   }

		return inicio;
}



Fila *bajaFila(Fila *inicio)
{
	Fila *aux;

	if(inicio != NULL)
	{
		aux = inicio;
		inicio = inicio -> sig;
		free(aux);
	}else{
    printf("UNDERFLOW");
  }

	return inicio;
}


void verFila(Fila *nodo)
{
    if(nodo==NULL)
	{
    	printf("\nTu fila esta vacia");
	}else
		{
          while(nodo!=NULL)
		  {
            printf("%d\t",nodo->dato);
            nodo=nodo->sig;
          }
        }

}



void Tamano(Fila *cima){
    int contador=0;
    if(cima!=NULL){
        do{
            contador++;
            cima=cima->sig;
        }while(cima!=NULL);
    }
    printf("Tamanio: %d\n",contador);
}


int main()
{
	Fila * fila = NULL;

    int dato,opc, tam;


    do{
      printf("\n1. Insertar\n");
      printf("2. Borrar\n");
      printf("3. Mostrar tamano\n");
      printf("4. Mostrar fila\n");
      printf("5. Salir\n");
      printf("\nElige una opcion: ");
      scanf("%d",&opc);

        switch(opc){

            case 1:
                printf("\nInserta un entero: ");
                scanf("%d",&dato);
                fila = Alta(fila,dato);
                fflush(stdin);
            break;
            case 2:
                fila = bajaFila(fila);
                verFila(fila);
            break;
            case 3:
                Tamano(fila);
            break;
            case 4:
                verFila(fila);
            break;
        }


        fflush(stdin);
    }while(opc != 5);
    return 0;
}
