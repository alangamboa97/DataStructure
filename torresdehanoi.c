#include <stdio.h>
#include <stdlib.h>

typedef struct _Nodo{

  int dato;
  struc _Nodo sig*;

}Nodo;

Nodo* crearNodo(int dato){
  Nodo *nuevo;
  nuevo = (Nodo*)malloc(sizeof(Nodo));
  nuevo -> dato = dato;
  nuevo -> sig = NULL;
  return nuevo;
}

Nodo* altaPila(Nodo *cima, int dato){
  Nodo *cajita;
  cajita = crearNodo(dato);
  if(cima != NULL){
    cajita -> sig = cima;
  }
  cima = cajita;
  puts("Elemento Agregado");
  return cajita;
}

Nodo *bajaPila(Nodo *cima){
  Nodo *aux;
  aux = cima;
  if(cima != NULL){
    cima = cima -> sig;
  }

  a
}

int main(){

}
