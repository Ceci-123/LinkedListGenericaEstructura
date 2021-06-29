#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "validaciones.h"
#include "Controller.h"

int main()
{
    int opcion;
    int resultado;
    char nombreArchivo[15];

    LinkedList* miLista = ll_newLinkedList();


    opcion = menuOpciones();


    for(;;)
    {

        if(opcion==11)
        {
            opcion = obtenerNumero("Desea salir ? 1.SI // 2. NO");
            if(opcion==1) break;
            opcion = 0;

        }
    switch(opcion)
    {
    case 1:
        pedirNombreArchivoTexto(nombreArchivo);
        resultado = controller_loadFromText(nombreArchivo, miLista);
        if(resultado == 1)
        {
            printf("Archivo cargado con exito\n");
        }
        else
        {
            printf("Error en la carga del archivo\n");
        }
        break;
    case 2:
        pedirNombreArchivoBinario(nombreArchivo);
        resultado = controller_loadFromBinary(nombreArchivo,miLista);
        if(resultado == 1)
        {
           printf("Archivo cargado con exito\n");
        }
        else
        {
           printf("Error en la carga del archivo\n");
        }
        break;
    case 3:
        resultado = controller_addEstructura(miLista);
        if(resultado == 1)
        {
           printf("Agregado!!\n");
        }
        else
        {
           printf("Error al agregar\n");
        }
        break;
    case 4:
        resultado = controller_edit(miLista);
        if(resultado == 1)
        {
            printf("Editado!!!!\n");
        }
        else
        {
            printf("Error al editar\n");
        }
        break;
    case 5:
        resultado = controller_remove(miLista);
        if(resultado == 1)
        {
            printf("Eliminado de la lista!!!!\n ");
        }
        else
        {
           printf("Error, no se pudo eliminar\n");
        }
        break;
    case 6:
        resultado = controller_List(miLista);
        if(resultado != 1)
        {
          printf("No se puede mostrar la lista\n");
        }
        break;
    case 7:
        resultado = controller_sort(miLista);
        controller_List(miLista);
        if(resultado != 1)
        {
           printf("Error al ordenar la lista\n");
        }
        break;
    case 8:
        resultado = controller_saveAsText("data.csv",miLista);
        if(resultado == 1)
        {
          printf ("Archivo guardado con exito\n");
        }
        else
            printf("Error en el guardado del archivo\n");
        break;
    case 9:
        resultado = controller_saveAsBinary("dataBIN.bin",miLista);
        if(resultado == 1)
        {
           printf("Archivo guardado con exito\n");
        }
        else
        {
            printf("Error en el guardado del archivo\n");
        }
        break;
    case 10:
        resultado = controller_map(miLista);
        if(resultado == 1)
        {
           printf("Archivo mapeado con exito\n");
        }
        else
        {
            printf("Error en el mapeado del archivo\n");
        }
        break;
    }
    opcion = reCall();
    }
    ll_deleteLinkedList(miLista);
    return 0;
}

