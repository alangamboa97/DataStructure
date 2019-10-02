#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include"Listas.h"
int main(){
	int opc,dato,pos;
	Lista*top;
	top=NULL;
	do{ system("cls");
	printf("-----------MENU--------------\n");
	printf("1.-Insertar dato al inicio\n");
	printf("2.-Insertar dato al final\n");
	printf("3.-Insertar dato en una posicion especifica\n");
	printf("4.-Eliminar dato al inicio\n");
	printf("5.-Eliminar dato al final\n");
	printf("6.-Eliminar dato en un posicion especifica\n");
	printf("7.-Mostrar lista\n");
	printf("8.-Tamanio de lista\n");
	printf("9.-Salir\n");
	scanf("%d",&opc);
	switch(opc){
		case 1:
			printf("Ingresa el dato a guardar\n");
			scanf("%d",&dato);
			top=InsertarInicio(dato,top);
			break;
		case 2:
			printf("Ingresa el dato a guardar\n");
			scanf("%d",&dato);
			top=InsertarFinal(dato,top);
			break;
		case 3:
			printf("Ingresa el dato a guardar:\n");
			scanf("%d",&dato);
			printf("Ingresa la posicion:\n");
			scanf("%d",&pos);
			top=Insertarpos(dato,top,pos);
			break;
		case 4:
			top=EliminarInicio(top);
			break;
		case 5:
			top=Eliminarfinal(top);
			break;
		case 6:
			printf("Ingresa la posicion a eliminar\n");
			scanf("%d",&pos);
			top=Eliminarpos(top,pos);
			break;
		case 7:
			Mostrar(top);
			break;
		case 8:
			printf("Tamano de lista: %d",Tam(top));
			getche();
			break;
		case 9:
			printf("BAI");
			return 0;
			break;
		default:
			printf("Ingresa una opcion valida\n");
	}
	fflush(stdin);
	}while(opc!=9);
	getche();
	return 0;
}
