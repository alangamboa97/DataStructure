#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Listasp3.h"

Lista* inventarioInicial(Lista *lista){

  char producto1[20] = "Paletas $1";
  char producto2[20] = "Paletas $5";
  char producto3[20] = "Refresco 1.5lt";
  char producto4[20] = "Yogurt 1lt";
  char producto5[20] = "Papitas 30gr";
  char producto6[20] = "Hojas Blancas(500)";

  lista = NULL;

  lista = InsertarInicio(1,9,producto1,lista);
  lista = InsertarFinal(2,3, producto2, lista);
  lista = InsertarFinal(3,2,producto3, lista);
  lista = InsertarFinal(4,1,producto4, lista);
  lista = InsertarFinal(5,8, producto5, lista);
  lista = InsertarFinal(6,10, producto6, lista);
  return lista;
}



int main(){


  FILE *in = fopen("inventario.txt", "r+");
  Lista *lista1 = NULL;

  int opc;

  long fsize = 0;










do {

  int id;
  int id_ingresar;
  int cantidad, posicion;
  char descripcion_lista[30];
  system("cls");
  printf("-----------MENU--------------\n");
	printf("1.-Insertar producto\n");
  printf("2.-Eliminar producto\n");
	printf("3.-Tamanio\n");
	printf("4.- Ver\n");
  printf("5.- Insertar Cantidades de Productos\n");
  printf("6.- Eliminar Cantidades de Productos\n");
  printf("7.- Agregar nuevo producto a inventario\n");
  printf("8.- Guardar en archivo de texto\n");
  lista1 = leerInventario(lista1, in);
  Mostrar(lista1);

  scanf("%d",&opc);
  switch (opc) {
    case 1:
    printf("%Ingresa la descripcion:\n");
    scanf(" %[^\n]", descripcion_lista);
    lista1 = InsertarMismoProducto(lista1, descripcion_lista);
    break;

    case 2:
    printf("%Ingresa la descripcion:\n");
    scanf(" %[^\n]", descripcion_lista);
    lista1 = EliminarMismoProducto(lista1, descripcion_lista);
    break;

    case 3:
    Tam(lista1);
    getche();
    break;
    case 4:
    Mostrar(lista1);

    break;
    case 5:

    printf("Ingresa la descripcion del dato a agregar");
    scanf(" %[^\n]", descripcion_lista);
    printf("Ingresar la cantidad a agregar");
    scanf("%d",&cantidad);
    lista1 = agregarcantidad(lista1, cantidad, descripcion_lista);
    break;

    case 6:
    printf("Ingresa la descripcion del dato a eliminar");
    scanf(" %[^\n]", descripcion_lista);
    printf("Ingresar la cantidad a eliminar");
    scanf("%d",&cantidad);
    lista1 = eliminarcantidad(lista1,cantidad, descripcion_lista);

    break;
    case 7:
    id = 1;
    printf("Inserta la descripcion del producto\n");
    scanf(" %[^\n]", descripcion_lista);
    printf("%Ingresa la cantidad del producto\n");
    scanf("%d",&cantidad);
    lista1 = InsertarFinal(id, cantidad, descripcion_lista, lista1);
    id++;
    break;

    case 8:

    break;

  }
} while(opc != 8);{
  Guardar(lista1,in);


}





  fclose(in);












}
