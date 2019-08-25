
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void borrar(char []);

//DECLARAMOS LAESTRUCTURA DE NUESTRA Nodo
typedef struct _Nodo{
	char frase;
	struct _Nodo *sig;
}Nodo;


//Declaramos la Funcion de Palindromo
int compararNodos(Nodo *pila1, Nodo *pila2,int n)
{
	int i;
	int c=0;

	for(i=0; i<n; i++){
		if (pila1->frase==pila2->frase){
			pila1=pila1->sig;
			pila2=pila2->sig;
		}else{
			c=1;
			return c;
		}
	}
		return c;
}

//CREAMOS EL CUERPO DE RESERVAR DE MEMORIA
Nodo *crearNodo(char frase){
	Nodo *nuevo;
	nuevo = (Nodo*)malloc(sizeof(Nodo));
	nuevo -> frase=frase;
    nuevo -> sig=NULL;
    return nuevo;
}

//CREAMOS EL CUERPO DE DE UN NODO
Nodo *altaPila(char frase, Nodo *pila1){
     Nodo *nuevo;
     nuevo=crearNodo(frase);
     if(pila1!=NULL){
	 	nuevo->sig=pila1;
	 }
     return nuevo;
}

//CREAMOS EL CUERPO DE verPila UNA Nodo
void verPila(Nodo *pila1)
{
	int i=0;
    if(pila1==NULL)
	{
    	printf("\n Tu pila se encuentra vacia");
	}else
		{
          while(pila1!=NULL)
		  {
            printf("%c",pila1->frase);

            pila1=pila1->sig;
          }
        }

}



int main()
{
	system("color 0b");
	FILE *in;
	FILE *out;

	in = fopen("practica_1_tm.txt", "r");
	out = fopen("practica_1_res.txt", "w+");
	char cadena[200];
	char cadena1[200];
	Nodo *pila1 = NULL;
	Nodo *pila2 = NULL;
	int n,i,j;
	int x;
	int contador;
	short a=0;
	int c;
	char *acentos;
	printf("\t\t\tDetectar si es palindromo\n\n");

for(x =0; x<17; x++){

	fgets(cadena,200,in);

	borrar(cadena);

		cadena[strlen(cadena)] = '\0'; // eliminamos el salto de linea
		n = strlen(cadena);

			for(i=0; i<n; i++){
                cadena[i] = tolower(cadena[i]);
                acentos=&cadena[i];
                if(acentos=='á')
                    acentos='a';
                if(acentos=='é')
                    acentos='e';
                if(acentos=='í')
                    acentos='i';
                if(acentos=='ó')
                    acentos='o';
                if(acentos=='ú')
                    acentos='u';

			}
			strcpy(cadena1,cadena);

	for(i =j = 0;cadena1[i] != '\0';i++)
		if(cadena1[i]!=' ')
			cadena1[j++] = cadena1[i];

	for(j=n; j>-1; --j)
	pila2 = altaPila(cadena1[j],pila2);

	for(i=0; i<n; i++)
		pila1 = altaPila(cadena1[i],pila1);

	//Lamamoos a la funcion comparar para comparar frase a frase de cada Nodo
	contador = compararNodos(pila1,pila2,n);

	//Validamos si la palabra es palindroma, segun el resultado regresado de nuestra funcion
	if(contador==1){
		printf("La palabra no es un palindromo\n");
		fprintf(out, "\n%s no es palindromo\n", cadena1);}
	else
		{
			printf("La palabra es un palindromo\n");
			fprintf(out, "\n%s es palindromo\n", cadena1);
		}
}
	getche();
	return 0;
}

void borrar(char cadena[]){
	int n,i,j;
		for(i = 0; cadena[i] != '\0'; ++i){
		while (!( (cadena[i] >= 'a' && cadena[i] <= 'z') || (cadena[i] >= 'A' && cadena[i] <= 'Z') ||(cadena[i] >= '0' && cadena[i] <= '9')|| cadena[i] == '\0'||cadena[i]=='�')){
				for(j = i; cadena[j] != '\0'; ++j){
						cadena[j] = cadena[j+1];
				}
				cadena[j] = '\0';
        }
        }
}
