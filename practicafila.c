#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>




typedef struct _Nodo
{
	int id;
	struct _Nodo *sig;
}Fila;


Fila *crearNodo(int id)
{
	Fila *nuevo;
	nuevo = (Fila*)malloc(sizeof(Fila));
	nuevo -> id=id;
  nuevo -> sig=NULL;
  return nuevo;
}

Fila *altaFila(Fila *inicio, int id)
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
            printf("%d ",nodo->id);
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

<<<<<<< HEAD
void procesoImpresion(Fila *fila1, Fila* fila2, Fila *fila3, Fila *filaimpresion)
{
int i;
  for (int i = 0; i<10; i++){
    fila1 = altaFila(fila1,1);
    fila2 = altaFila(fila2,2);
    fila3 = altaFila(fila3,3);
}
for(i = 0; i<45; i++){
  if(rand()%4  == 1){
      if(fila1 == NULL){
        i--;
      }else{
    filaimpresion = altaFila(filaimpresion, fila1->id);
    fila1 = bajaFila(fila1);
  }
  }


if(rand()%4 == 2){

  if(fila2 == NULL){
    i--;
  }

else{
  filaimpresion = altaFila(filaimpresion, fila2->id);
=======
int main(){

int delay = 30;
Fila *fila1 = NULL;
Fila *fila2= NULL;
Fila *fila3 = NULL;
Fila *filaimpresion = NULL;
Fila *ptr1;
int inicio = 1;

srand(1);




for (int i = 0; i<10; i++){
  fila1 = altaFila(fila1,1);
  fila2 = altaFila(fila2,2);
  fila3 = altaFila(fila3,3);

}

//ptr1 = bajaFila(fila1);




for(int i = 0; i<10; i++){
  if(rand()%4 == 1){
filaimpresion = altaFila(filaimpresion, fila1->dato);
fila1 = bajaFila(fila1);

}if(rand()%4 == 2){
  filaimpresion = altaFila(filaimpresion, fila2->dato);
>>>>>>> parent of 45ce746... empezando con el char de la estructura
  fila2 = bajaFila(fila2);
}if(rand()%4 == 3){

<<<<<<< HEAD
if(rand()%4 == 3){

    if(fila3 == NULL){
  i--;
  }else{
    filaimpresion = altaFila(filaimpresion, fila3->id);
=======
    filaimpresion = altaFila(filaimpresion, fila3->dato);
>>>>>>> parent of 45ce746... empezando con el char de la estructura
    fila3 = bajaFila(fila3);
  }


}

<<<<<<< HEAD
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
char id1[4]= "P1_F";
char id2[4]= "P2_F";
char id3[4]= "P3_F";

srand(time(NULL));





//ptr1 = bajaFila(fila1);




procesoImpresion(fila1, fila2, fila3, filaimpresion);

printf("\nDespues de 30 segundos:\n");
=======

>>>>>>> parent of 45ce746... empezando con el char de la estructura
printf("Fila 1: ");
verFila(fila1);
printf("\nFila 2: ");
verFila(fila2);
printf("\nFila 3: ");
verFila(fila3);

printf("\n Fila impresion: " );
<<<<<<< HEAD

Tamano(filaimpresion);
=======
verFila(filaimpresion);
>>>>>>> parent of 45ce746... empezando con el char de la estructura






}
