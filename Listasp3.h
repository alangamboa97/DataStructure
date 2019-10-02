#ifndef _Listasp3_h
#define _Listasp3_h

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


typedef struct Nodo{
	int id;
	int cantidad;
	char descripcion[20];
	struct Nodo* sig;
}Lista;

Lista* Crear(int id, int cantidad, char descripcion	[]){
	Lista * nuevo;
	nuevo= (Lista*)malloc(sizeof(Lista));
	nuevo->id=id;
	nuevo-> cantidad = cantidad;
	strcpy(nuevo -> descripcion, descripcion);
	nuevo->sig=NULL;
	return nuevo;
}
int Tam(Lista*top){
	int tam=0;
	if(top != NULL){
		while (top != NULL) {
			top = top -> sig;
			tam++;
		}
	}
	return tam;
}
Lista*InsertarInicio(int n,int cantidad, char descripcion[],Lista*top){ //pilas
	 Lista*nuevo;
	 int i = 1;
     nuevo=Crear(i, cantidad, descripcion);
     if(top!= NULL)
     nuevo -> sig= top;
		 i++;
		 return nuevo;

}

Lista*InsertarFinal(int n,int cantidad,char descripcion[] ,Lista*top){ //Listas
	Lista*aux,*aux2;
	aux=Crear(n, cantidad, descripcion);
	if(top==NULL){
	printf("No se puede insertar al final en una lista vacia, llamando a funcion insertar al inicio1");
	aux = InsertarInicio(n,cantidad,descripcion, top);
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


Lista *Eliminarfinal(Lista*top){//Listas
	Lista *aux = NULL, *borrar = NULL;
	int i = 0;
	int tam = Tam(top);
	if(top != NULL){
	aux = top;
	if(tam != 1){
		for(i; i<(tam-2); i++){
			aux = aux -> sig;
			}
			borrar = aux -> sig;
			aux -> sig = NULL;
			free(borrar);
	}

	else{
		aux = EliminarInicio(aux);
	}
	return top;

}
}

Lista *Eliminarinterdato(Lista *lista, char descripcion[])
{
    Lista *aux,*borrar;
    aux = lista;
    int tam = Tam(lista);
		int iguales = strcmp(aux-> descripcion, descripcion);
    if (lista != NULL)
    {
        if (tam==1)
        {
            lista = EliminarInicio(lista);
            return lista;
        }
        else
        {
            while(aux->sig != NULL)
            {
                if (iguales == 0)
                {
                    borrar = aux->sig;
                    aux->sig = borrar->sig;
                    free(borrar);
                    break;
                }else{
                    aux = aux->sig;
                }
            }
        }
    }
    puts("Elmininado\n");
    return lista;
}

Lista *InsertarMismoProducto(Lista *lista, char descripcion[])
{
	Lista *aux;
	aux = lista;
	int iguales;

	int tam;
	tam = Tam(lista);
	while(aux != NULL){

			iguales = strcmp(aux -> descripcion, descripcion);
			if(iguales == 0){
			aux -> cantidad = aux -> cantidad + 1;
			getche();
		}
			aux = aux ->sig;
	}
		return lista;
}

Lista *EliminarMismoProducto(Lista *lista, char descripcion[]){
	Lista *aux;
	aux = lista;
	int iguales;

	int tam;
	tam = Tam(lista);
	while(aux != NULL){

			iguales = strcmp(aux -> descripcion, descripcion);
			if(iguales == 0){
			aux -> cantidad = aux -> cantidad - 1;
			getche();
		}
			aux = aux ->sig;
	}
		return lista;
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
			printf("Dato %d: %d  %s\n",aux-> id, aux->cantidad ,aux->descripcion);
			aux=aux->sig;
			i++;
		}
		getche();
	}
}

void Guardar(Lista*top, FILE *out){
	int i=1;
	Lista*aux;
	aux=top;
	if(aux==NULL){
		printf("Lista vacia\n");

	}
	else{
		while(aux!=NULL){

			fprintf(out, "%d\t%d\t%s\n",aux-> id, aux -> cantidad, aux-> descripcion);
			aux=aux->sig;
			i++;
		}

	}
}




Lista *agregarcantidad(Lista *lista, int cantidad, char descripcion[]){
	Lista *aux;
	aux = lista;
	int iguales;

	int tam;
	tam = Tam(lista);
	while(aux != NULL){

			iguales = strcmp(aux -> descripcion, descripcion);
			if(iguales == 0){
			aux -> cantidad = aux -> cantidad + cantidad;
			getche();
		}
			aux = aux ->sig;
	}
		return lista;
}

Lista *eliminarcantidad(Lista *lista, int cantidad, char descripcion[]){
	Lista *aux;
	aux = lista;
	int iguales;

	int tam;
	tam = Tam(lista);
	while(aux != NULL){

			iguales = strcmp(aux -> descripcion, descripcion);
			if(iguales == 0){
				if(aux -> cantidad > cantidad){
						aux -> cantidad = aux -> cantidad - cantidad;
				}
				if(aux->cantidad < cantidad){
					lista = Eliminarinterdato(lista, descripcion);
				}


			getche();
		}
			aux = aux ->sig;
	}
		return lista;
}
Lista *modificardescripcion(Lista *top, char descripcion[], int pos){
	int i;
    Lista *aux;
    if (top != NULL){
        aux = top;
        for (i = 0; i < pos-1 ; i++) {
            aux = aux -> sig;
        }
        strcpy(aux -> descripcion, descripcion);
    }
    puts("Modificado");
    return top;
}

Lista *leerInventario(Lista *lista,FILE *file){
	Lista *aux;
	FILE *out;
	char* buffer[200];
	int id, cantidad;
	char descripcion[30];

	if(file == NULL){
		puts("Error al abrir el archivo");
		out = fopen("inventario.txt", "w+");
		

	}else{

		if(file != NULL){
			puts("Archivo previamente creado");

		while(!feof(file))
		{
			fscanf(file, "%d\t%d\t%s", id, cantidad,descripcion);
			if(lista == NULL){

			lista = InsertarInicio(id,cantidad,descripcion,lista);
		}else{
			lista = InsertarFinal(id, cantidad, descripcion, lista);
		}
		}
		aux = lista;


	}
}
getche();
return aux;
}

#endif
