#include <stdio.h>
#include <stdlib.h>


typedef struct _Nodo
{
  int dato;
  struct _Nodo *sig;
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
  if(cima !=NULL){
    cima = cima ->sig;
    free(aux);
  }
  return cima;
}

void verPila(Nodo *cima, int i){
  if(cima != NULL){
      while(cima != NULL){

          printf("Elemento %d del stack = %d\n",i, cima -> dato);
          cima = cima -> sig;
          i++;
      }
  }else{
      printf("UNDERFLOW");
  }
}

int main(){
  Nodo *pila = NULL;
  int i = 1;

  int seleccion;
  int valor_dato;

  do {
    puts("-----MENU------");
    puts("1.- Agregar Elemento");
    puts("2.- Eliminar Elemento");
    puts("3.- Ver Pila de Elementos");
    puts("4.- Salir");

    scanf("%d",&seleccion);

  switch (seleccion) {
    case 1:
    puts("Ingresa el valor del elemento: ");
    scanf("%d",&valor_dato);
    pila = altaPila(pila, valor_dato);


    break;

    case 2:
    pila = bajaPila(pila);

    break;

    case 3:
    verPila(pila, i);

    break;
  }
}
while(seleccion != 4);

}
