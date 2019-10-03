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

int id = 1;
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
	
Lista* aux;
    Lista* nuevo;
    aux = top;
    nuevo = Crear(n,cantidad, descripcion);
    if(aux == NULL){
        top = nuevo;
    }else{
        while(aux->sig != NULL){
            aux = aux->sig;
        }
        aux->sig = nuevo;
    }
    return top;
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
	
	Lista*aux;
	aux=top;
	if(aux==NULL){
		printf("Lista vacia\n");
		getche();
	}
	else{
		while(aux!=NULL){
			printf("%d %d %s\n",aux-> id, aux->cantidad ,aux->descripcion);
			aux=aux->sig;
			
		}
		getche();
	}
}

void Guardar(Lista*top){
	int i=1;
	Lista*aux;
	aux=top;
	FILE* fp = fopen("inventario.txt","w+");
	if(aux==NULL){
		printf("Lista vacia\n");

	}
	else{
		while(aux!=NULL){

			fprintf(fp, "%d-%d-%s",aux-> id, aux -> cantidad, aux-> descripcion);
			aux=aux->sig;
			i++;
		}

	}
	fclose(fp);
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

Lista *leerInventario(Lista *lista)
{
	Lista *aux;
	aux = lista;
	int cantidad;
	char descripcion[20];
	
FILE *archivo=fopen("inventario.txt","r");
				if(archivo==NULL){
				printf("Error al abrir el archivo txt");
			}
			
			
			while(fscanf(archivo,"%s %d",descripcion,&cantidad)!=EOF){
			int id=Tam(lista);
			id=id+1;
			if(aux == NULL){
			
			aux=InsertarInicio(id,cantidad,descripcion, lista);
			}
			else{
				aux=InsertarFinal(id,cantidad,descripcion, lista);
			}
			printf("\n\n\n");
			Mostrar(aux);
			
			return aux;
		}
			
}

Lista* iniInventario(){
	int i=0;
	int cantidad;
	char delimitador[] = "-";
	char *line = (char*)malloc(100*(sizeof(char)));
	Lista* aux = NULL;
	char descripcion[20];
	FILE* pf = fopen("inventario.txt","r+t");
	while(fgets(line,1000,pf)){


    	char *token = strtok(line, delimitador);
        // S?lo en la primera pasamos la cadena; en las siguientes pasamos NULL

        id = atoi(token);
        token = strtok(NULL, delimitador);

    	

		cantidad = atoi(token);
		token = strtok(NULL, delimitador);
		
		strcpy(descripcion,token);
		token = strtok(NULL, delimitador);

	
		aux = InsertarFinal(id,cantidad,descripcion,aux);

	}
	fclose(pf);
	return aux;
}

Lista *abrirarchivo(int contadorid,Lista *cima)
{
	Lista *aux = cima;
	char buffer[100];
	int contadoraux;
	int i,j;
	char auxiliarc;
	int cantidadaux;
	char platilloaux[30];
		FILE * inventario = fopen("inventario.txt","r");

        	if(inventario == NULL)
     		{
     		 perror("error al abrir el archivo");
     		}

				 if(contadorid>contadoraux)
				 {

				 }else {

     		while(!feof(inventario))
     		{
     			fgets(buffer,100,inventario);
     			contadorid ++;
     			contadoraux = contadorid;
     			contadorid++;
     		}


     		rewind(inventario);
     		printf("%d\n",contadoraux);

     		while(!feof(inventario))
            {


     			fscanf (inventario,"%d\t%d\t%s",&contadorid,&cantidadaux,&platilloaux);
     			
                   aux = InsertarInicio(contadorid,cantidadaux,platilloaux,cima);

                if(aux != NULL){

                   aux = InsertarFinal(contadorid,cantidadaux,platilloaux,cima);
                }


            }





					   }


		    rewind(inventario);
			printf("%d\n",contadoraux);













			




     		fclose(inventario);
     		return aux;
}


	

#endif
