#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>




typedef struct _Nodo
{
	int dato;
	struct _Nodo *sig;
}Fila;


Fila *crearNodo(int dato)
{
	Fila *nuevo;
	nuevo = (Fila*)malloc(sizeof(Fila));
	nuevo -> dato=dato;
  nuevo -> sig=NULL;
  return nuevo;
}

Fila *altaFila(Fila *inicio, int dato)
{
	Fila *nuevo, *aux;
	nuevo = crearNodo(dato);
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
            printf("%d ",nodo->dato);
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

int main(){

int delay = 30;
Fila *fila1 = NULL;
Fila *fila2= NULL;
Fila *fila3 = NULL;
Fila *filaimpresion = NULL;
Fila *ptr1;
int inicio = 1;
int i;

srand(time(NULL));




for (int i = 0; i<10; i++){
  fila1 = altaFila(fila1,1);
  fila2 = altaFila(fila2,2);
  fila3 = altaFila(fila3,3);

}

//ptr1 = bajaFila(fila1);
printf("ANTES DE impresion");
printf("\nFila 1: ");
verFila(fila1);
printf("\nFila 2: ");
verFila(fila2);
printf("\nFila 3: ");
verFila(fila3);


for(i = 0; i<45; i++){
  if(rand()%4  == 1){
      if(fila1 == NULL){
        i--;
      }else{
    filaimpresion = altaFila(filaimpresion, fila1->dato);
    fila1 = bajaFila(fila1);
  }
  }


if(rand()%4 == 2){
  if(fila2 == NULL){
    i--;
  }

else{
  filaimpresion = altaFila(filaimpresion, fila2->dato);
  fila2 = bajaFila(fila2);
}
}

if(rand()%4 == 3){
    if(fila3 == NULL){
  i--;
  }else{
    filaimpresion = altaFila(filaimpresion, fila3->dato);
    fila3 = bajaFila(fila3);
  }
  }


}

printf("\nDespues de 30 segundos:\n");
printf("Fila 1: ");
verFila(fila1);
printf("\nFila 2: ");
verFila(fila2);
printf("\nFila 3: ");
verFila(fila3);


printf("\n Fila impresion: " );
verFila(filaimpresion);
Tamano(filaimpresion);






}
