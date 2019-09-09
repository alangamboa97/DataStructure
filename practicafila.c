#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>




typedef struct _Nodo
{
	char  id[6];
	int num;
	struct _Nodo *sig;
}Fila;


Fila *crearNodo(char id[])
{
	Fila *nuevo;
	nuevo = (Fila*)malloc(sizeof(Fila));
	strcpy(nuevo -> id, id);

  nuevo -> sig=NULL;
  return nuevo;
}

Fila *altaFila(Fila *inicio, char id[])
{
	Fila *nuevo, *aux;
	nuevo = crearNodo(id);
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
            printf("%s ", nodo->id);
            nodo = nodo->sig;
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
char id1[6] = "PF1";
char id2[6] = "PF2";
char id3[6] = "PF3";


char dest1[6];



strcat(dest1, id1);





srand(time(NULL));





for (int i= 1; i<11; i++){

	fila3 = altaFila(fila3, id3);
  fila1 = altaFila(fila1, id1);
	fila2 = altaFila(fila2, id2);


}



//ptr1 = bajaFila(fila1);

printf("Fila 1: ");
verFila(fila1);
printf("\nFila 2: ");
verFila(fila2);
printf("\nFila 3: ");
verFila(fila3);



for(int i = 0; i<49; i++){
  if(rand()%4 == 1){
		if(fila1 == NULL){
			i--;
		}else{
filaimpresion = altaFila(filaimpresion, fila1->id);
fila1 = bajaFila(fila1);
}

}if(rand()%4 == 2){
	if(fila2 == NULL){
		i--;
	}else{
  filaimpresion = altaFila(filaimpresion, fila2->id);
  fila2 = bajaFila(fila2);
}
}
if(rand()%4 == 3){

    if(fila3 == NULL){
  i--;
  }else{
    filaimpresion = altaFila(filaimpresion, fila3->id);
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


Tamano(filaimpresion);

verFila(filaimpresion);

}
