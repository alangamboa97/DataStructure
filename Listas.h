#ifndef _Listas_h
#define _Listas_h

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Nodo{
	int dato;
	struct Nodo* sig;
}Lista;

Lista* Crear(int dato){
	Lista * nuevo;
	nuevo= (Lista*)malloc(sizeof(Lista));
	nuevo->dato=dato;
	nuevo->sig=NULL;
	return nuevo;
}
int Tam(Lista*top){
	int tam=0;
	if(top!=NULL){
	do{
	tam++;
	top=top->sig;	
	}while(top!=NULL);
}
return tam;
}
Lista*InsertarInicio(int n,Lista*top){ //pilas
	 Lista*nuevo;
     nuevo=Crear(n);
     if(top!= NULL)
     nuevo -> sig= top;
     return nuevo;
}

Lista*InsertarFinal(int n, Lista*top){ //Filas
	Lista*aux,*aux2;
	aux=Crear(n);
	if(top==NULL){
	printf("No se puede insertar al final en una lista vacia, llame a insertar al inicio");
	getche();
		return aux;
	}
	else{
		aux2=top;
		while(aux2 ->sig != NULL){
		aux2=aux2->sig;
		}
		aux2->sig=aux;
		return top;
	}
}

Lista*Insertarpos(int n, Lista*top,int pos){
	int tam,i;
	Lista*aux,*NodoNuevo;
	if(top==NULL){
		printf("Lista vacía, no insertado\n");
		return top;
	}
	else{
		tam=Tam(top);//FUNCION PARA CALCULAR TAMAÑO
		if(pos>tam){ //Si se pasa del tamaño de la lista
			printf("Posicion invalida, llame a insertar al final\n");
			getche();
			return top;
		}
		else{ //Si está dentro de los valores
			aux=top;
			NodoNuevo=Crear(n);
			for(i=0;i<pos;i++){ //Llegar hasta una antes de la posicion deseada
			aux=aux->sig; //Recorremos
			}
			NodoNuevo->sig=aux->sig; //Apuntamos el nuevo nodo a su continuacion
			aux->sig=NodoNuevo;
			return top;
		}
	}
}
Lista *Eliminarfinal(Lista*top){//Filas
	if(top==NULL){
		printf("Lista vacia\n");
		getche();
	}
	else{
		Lista *aux;
		aux=top;
		top=top->sig;
		free(top);
	}
	return top;
}

Lista *Eliminarpos(Lista*top,int pos){
	int tam,i;
	char opc;
	Lista*aux,*aux1;
	if(top==NULL){ //Si está vacía
		printf("Lista Vacía");
		getche();
	}
	else{ //Si no está vacía
		tam=Tam(top);
		if(pos>tam){ //Si se pasa alv
			printf("Posicion invalida,excede el tamaño de la  lista\n");
			printf("¿Desea eliminar el final?(s/n)\n");
			scanf("%c",&opc);
			if(opc=='s')
			Eliminarfinal(top);
			else{
				printf("Ninguna accion realizada\n");
				return top;
			}	
		}
		else{ //Si está dentro de la longitud de la lista
		aux=top;
		for(i=0;i<pos;i++){ //Llegar antes de la posicion a borrar
			aux=aux->sig;
		}
		aux1=aux->sig;
		aux->sig=aux1->sig;
		free(aux1);
		return top;
	}
	}
}
Lista*EliminarInicio(Lista*top){//Pilas
	Lista*aux;
     aux=top;
     if(top!= NULL){
              top=top -> sig;
              free(aux);
              }
    else{
    	printf("Vacia\n");
    	getche();
	}
              return top;
}
void Mostrar(Lista*top){
	int i=1;
	Lista*aux;
	aux=top;
	if(aux==NULL){
		printf("Lista vacia\n");
		getche();
	}
	else{
		while(aux!=NULL){
			printf("Dato %d: %d\n",i,aux->dato);
			aux=aux->sig;
			i++;
		}
		getche();
	}
}


#endif
