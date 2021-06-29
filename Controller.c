#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "parser.h"
#include "validaciones.h"
#include "Controller.h"
#include "estructura_generica.h"

int controller_setId(LinkedList* pArrayLista)
{
    eEstructura* pEstructura = NULL;
    int tamanio;
    int mayor = 0;
    int idObtenido = 0;
    int auxiliarResultado = 0;

    if(pArrayLista != NULL)
    {
        tamanio = ll_len(pArrayLista);
        if(tamanio == 0)
        {
            auxiliarResultado = 100;

        }
        else
        {
            for(int i=0;i<tamanio;i++)
            {
                pEstructura = ll_get(pArrayLista,i);
                estructura_getId(pEstructura,&idObtenido);

                if(i==0 || idObtenido>mayor)
                {

                   mayor = idObtenido;
                   auxiliarResultado = mayor + 1;

                }

            }
        }

    }
    else
    {
        auxiliarResultado = 100;
    }
    return auxiliarResultado;
}

int controller_loadFromText(char* path, LinkedList* pArrayLista)
{
    FILE* pFile;
    //ll_clear(pArrayLista);
    pFile = fopen(path,"r");
    int auxiliarRetorno = 1;

    if(pArrayLista != NULL)
    {
        if(pFile == NULL)
        {
            printf("No se encontro el archivo\n");
            system("pause");
            auxiliarRetorno = 0;
        }
        parser_FromText(pFile,pArrayLista);
    }
    else
    {
        printf("Error en la lista\n");
        system("pause");
        auxiliarRetorno = 0;
    }
    fclose(pFile);
    return auxiliarRetorno;
}

int controller_loadFromBinary(char* path, LinkedList* pArrayLista)
{
    FILE* pFile;
    //ll_clear(pArrayLista);
    pFile = fopen(path,"rb");
    int auxiliarRetorno = 1;

    if(pArrayLista != NULL)
    {
        if(pFile == NULL)
        {
            printf("No se encontro el archivo\n");
            auxiliarRetorno = 0;
        }
        parser_FromBinary(pFile,pArrayLista);
        fclose(pFile);
        auxiliarRetorno = 1;
    }
    else
    {
        printf("Error en la lista");
        auxiliarRetorno =  0;
    }
    return auxiliarRetorno;
}


int controller_addEstructura(LinkedList* pArrayLista)
{
    eEstructura* pEstructura;
    char nombre[20];
    int edad;
    float peso;
    int id;
    int codigo;
    char sexo;
    int devuelve;
    int todoOk = 0;

    pEstructura = (eEstructura*)estructura_new();
    if(pEstructura == NULL)
    {
        printf("No hay suficiente espacio en memoria para guardar un elemento nuevo\n");
    }
    else
    {
        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(nombre);
        devuelve = sonLetras(nombre);
        if(devuelve == -1)
        {
            printf("Ingreso erroneo, reingrese nombre");
            fflush(stdin);
            gets(nombre);
            devuelve = sonLetras(nombre);
        }

        printf("Ingrese sexo m o f: ");
        fflush(stdin);
        scanf("%c", &sexo);
        devuelve = validacionSexo(sexo);
        while(devuelve == 0)
        {
            printf("Ingreso erroneo, reingrese sexo");
            fflush(stdin);
            scanf("%c", &sexo);
            devuelve = validacionSexo(sexo);
        }
        printf("Ingrese edad entre 0 y 20: ");
        scanf("%d", &edad);
        edad = validacionDeNumero(edad,0,20);
        printf("Ingrese codigo entre 1 y 4: ");
        printf("1 cuidado de la ropa, 2 limpieza automotor,3 cuidado personal,4 limpieza del hogar");
        scanf("%d", &codigo);
        codigo = validacionDeNumero(codigo,1,4);
        printf("Ingrese peso entre 0 y 100 kg: ");
        scanf("%f", &peso);
        peso = validacionDeNumeroFloat(peso,0,100);
        id = controller_setId(pArrayLista);
        estructura_setNombre(pEstructura,nombre);
        estructura_setEdad(pEstructura,edad);
        estructura_setPeso(pEstructura,peso);
        estructura_setId(pEstructura,id);
        estructura_setCodigo(pEstructura,codigo);
        estructura_setSexo(pEstructura,sexo);
        ll_add(pArrayLista,pEstructura);
        todoOk = 1;
    }
    return todoOk;
}

int controller_getIndexById(LinkedList* pArrayLista,int idBuscado)
{
    eEstructura* pEstructura;
    int tamanio;
    int idObtenido;
    int auxiliarRetorno = -1;

    tamanio = ll_len(pArrayLista);
    for(int i=0;i<tamanio;i++)
    {
        pEstructura = ll_get(pArrayLista,i);
        estructura_getId(pEstructura,&idObtenido);
        if(idObtenido == idBuscado)
        {
          auxiliarRetorno = i;
        }

    }
    return auxiliarRetorno;
}

int controller_edit(LinkedList* pArrayLista)
{
    eEstructura* pEstructura;
    int id;
    int indice = -1;
    int continuar = 1;
    int opcion;
    int nuevoNumero;
    char nuevaCadena[20];
    char nuevoChar;
    float nuevoFlotante;
    int todoOk= 0;
    int devuelve;

    controller_List(pArrayLista);
    while(indice == -1)
    {
        id = obtenerNumero("\nIngrese el id del elemento que quiere modificar");
        indice = controller_getIndexById(pArrayLista,id);
        if(indice == -1)
        {
            printf("El id ingresado es incorrecto\n");
            indice = -1;
        }
        else
            break;
    }
    pEstructura = ll_get(pArrayLista,indice);
    while(continuar == 1)
    {
        opcion = obtenerNumero("Ingrese 1 para modificar nombre\n Ingrese 2 para modificar edad\n ingrese 3 para modificar peso\n ingrese 4 para modificar sexo\n ingrese 5 para modificar codigo\n");
        switch(opcion)
        {
            case 1:
                printf("Ingrese nuevo nombre: ");
                fflush(stdin);
                gets(nuevaCadena);
                devuelve = sonLetras(nuevaCadena);
                if(devuelve == -1)
                {
                    printf("Ingreso erroneo, reingrese nombre");
                    fflush(stdin);
                    gets(nuevaCadena);
                    devuelve = sonLetras(nuevaCadena);
                }
                estructura_setNombre(pEstructura,nuevaCadena);
                todoOk = 1;
                break;
            case 2:
                nuevoNumero = obtenerNumero("Ingrese nueva edad entre 1 y 20:");
                nuevoNumero = validacionDeNumero(nuevoNumero,1,20);
                estructura_setEdad(pEstructura,nuevoNumero);
                todoOk = 1;
                break;
            case 3:
                nuevoFlotante = obtenerNumeroFlotante("Ingrese nuevo peso entre 1 y 100");
                nuevoFlotante = validacionDeNumeroFloat(nuevoFlotante,1,100);
                estructura_setPeso(pEstructura,nuevoFlotante);
                todoOk = 1;
                break;
            case 4:
                printf("Ingrese nuevo sexo: ");
                fflush(stdin);
                scanf("%c", &nuevoChar);
                devuelve = validacionSexo(nuevoChar);
                while(devuelve == 0)
                {
                     printf("Ingreso erroneo, reingrese sexo");
                     fflush(stdin);
                     scanf("%c", &nuevoChar);
                     devuelve = validacionSexo(nuevoChar);
                }
                estructura_setSexo(pEstructura,nuevoChar);
                todoOk = 1;
                break;
            case 5:
                nuevoNumero = obtenerNumero("Ingrese nuevo codigo entre 1 y 4:");
                printf("1 cuidado de la ropa, 2 limpieza automotor,3 cuidado personal,4 limpieza del hogar");
                nuevoNumero = validacionDeNumero(nuevoNumero,1,4);
                estructura_setCodigo(pEstructura,nuevoNumero);
                todoOk = 1;
                break;
            default:
                printf("Opcion no valida\n");
                break;
        }
        continuar = obtenerNumero("Desea modificar otro dato?\n1.SI 2.NO");
    }

    return todoOk;
}


int controller_remove(LinkedList* pArrayLista)
{
    int id;
    int indice = -1;
    int continuar = 1;
    int todoOk = 0;

    controller_List(pArrayLista);
    while(continuar == 1)
    {
        while(indice == -1)
        {
            id = obtenerNumero("Ingrese el numero de id del que desea borrar");
            indice = controller_getIndexById(pArrayLista,id);
            if(indice == -1)
            {
                printf("El id ingresado es incorrecto\n");
            }
            else
                continue;
        }
        ll_remove(pArrayLista,indice);
        todoOk = 1;
        continuar = obtenerNumero("Desea borrar otro?\n 1.SI 2.NO");
        if(continuar==1)
        {
            indice = -1;
        }
        else
            break;
    }

    return todoOk;
}


int controller_List(LinkedList* pArrayLista)
{
    eEstructura* auxiliar;
    int tamanio;
    int id;
    char nombre[128];
    int edad;
    float peso;
    int codigo;
    char sexo;
    char descripcionCodigo[50];

    int todoOk = 0;

    printf("    ID     NOMBRE       EDAD PESO SEXO   CODIGO  DESCRIPCION CODIGO \n");
    tamanio = ll_len(pArrayLista);
    for(int i=0;i< tamanio;i++)
    {
        auxiliar = ll_get(pArrayLista,i);
        estructura_getId(auxiliar,&id);
        estructura_getNombre(auxiliar,nombre);
        estructura_getEdad(auxiliar,&edad);
        estructura_getPeso(auxiliar,&peso);
        estructura_getSexo(auxiliar,&sexo);
        estructura_getCodigo(auxiliar, &codigo);
        getDescripcionCodigo(codigo, descripcionCodigo);
        printf("%3d %20s %2d %2.2f %c %3d %s\n",id,nombre,edad,peso, sexo, codigo, descripcionCodigo);
        todoOk = 1;
    }
    return todoOk;
}


int controller_sort(LinkedList* pArrayLista)
{
    int opcion;
    int upOrDown;
    int todoOk= 0;

    opcion = obtenerNumero("Ingrese 1 si desea ordenar por nombre\n Ingrese 2 si desea ordenar por ID\n Ingrese 3 si desea ordenar por edad\n Ingrese 4 si desea ordenar por peso\nIngrese 5 si desea ordenar por sexo\nIngrese 6 si desea ordenar por codigo\nELECCION");
    opcion = validacionDeNumero(opcion,1,6);
    upOrDown = obtenerNumero("Ingrese 0 para ordenar de forma descendente\n Ingrese 1 para ordenar de forma ascendente\n ELECCION");
    upOrDown = validacionDeNumero(upOrDown,0,1);
    switch(opcion)
    {
    case 1:
        ll_sort(pArrayLista,estructura_CompareByName,upOrDown);
        todoOk = 1;
        break;
    case 2:
        ll_sort(pArrayLista,estructura_CompareById,upOrDown);
        todoOk = 1;
        break;
    case 3:
        ll_sort(pArrayLista,estructura_CompareByEdad,upOrDown);
        todoOk = 1;
        break;
    case 4:
        ll_sort(pArrayLista,estructura_CompareByPeso,upOrDown);
        todoOk = 1;
        break;
    case 5:
        ll_sort(pArrayLista,estructura_CompareBySexo,upOrDown);
        todoOk = 1;
        break;
    case 6:
        ll_sort(pArrayLista,estructura_CompareByCodigo,upOrDown);
        todoOk = 1;
        break;
    }
    return todoOk;
}


int controller_saveAsText(char* path, LinkedList* pArrayLista)
{
    FILE* pFile;
    eEstructura* auxiliarEstructura;
    int tamanio;
    char nombre[20];
    int id;
    int edad;
    float peso;
    char sexo;
    int codigo;
    int auxiliarRetorno;

    if(pArrayLista == NULL)
    {
       printf("Direccion de memoria de la lista incorrecta");
       auxiliarRetorno = 0;
    }

    if(pArrayLista != NULL)
    {
        pFile = fopen(path,"w");
        if(pFile == NULL)
        {
           printf("No se pudo abrir el archivo\n");
           auxiliarRetorno = 0;
        }
        else
        {
            tamanio = ll_len(pArrayLista);
            fprintf(pFile,"id,nombre,edad,peso,sexo,codigo\n");
            for(int i=0;i<tamanio;i++)
            {
                auxiliarEstructura = (eEstructura*)ll_get(pArrayLista,i);
                estructura_getId(auxiliarEstructura, &id);
                estructura_getNombre(auxiliarEstructura,nombre);
                estructura_getEdad(auxiliarEstructura,&edad);
                estructura_getPeso(auxiliarEstructura, &peso);
                estructura_getSexo(auxiliarEstructura, &sexo);
                estructura_getCodigo(auxiliarEstructura,&codigo);
                fprintf(pFile,"%d,%s,%d,%f,%c,%d\n",id,nombre,edad,peso,sexo,codigo);
            }
        }
    fclose(pFile);
    auxiliarRetorno = 1;
    }

    return auxiliarRetorno;
}


int controller_saveAsBinary(char* path, LinkedList* pArrayLista)
{
    FILE* pFile;
    eEstructura* pEstructura;
    int tamanio;
    int i;
    char cabecera[33]={"id,nombre,edad,peso,sexo,codigo\n"};
    int auxiliarRetorno;

    if(pArrayLista == NULL)
    {
        printf("Direccion de memoria de la lista incorrecta");
        auxiliarRetorno = 0;
    }

    if(pArrayLista != NULL)
    {
         pFile = fopen(path,"wb");
         if(pFile == NULL)
         {
             printf("No se pudo abrir el archivo\n");
             auxiliarRetorno = 0;
         }
    else
    {
        fwrite(cabecera,sizeof(char[33]),1,pFile);
        tamanio = ll_len(pArrayLista);
        for(i=0;i<tamanio;i++)
        {
                pEstructura = (eEstructura*)ll_get(pArrayLista,i);
                fwrite(pEstructura,sizeof(eEstructura),1,pFile);
        }
    }
    fclose(pFile);
    auxiliarRetorno = 1;
    }

    return auxiliarRetorno;
}

int controller_map(LinkedList* pArrayLista)
{
    int todoOk = 0;
//    int resultado;
//
//    //resultado = ll_map(pArrayLista,contadorPerrosAdultos);
//    if(resultado == 1)
//    {
//        todoOk = 1;
//    }
    return todoOk;
}

void getDescripcionCodigo(int codigo, char* descripcionCodigo)
{
    char nombres[4][30] = {"cuidado de la ropa","limpieza automotor","cuidado personal","limpieza del hogar"};
    int auxiliarCodigo = codigo -1;

    for(int i = 0; i < 4; i ++)
    {
       if(auxiliarCodigo == i)
       {
          strcpy(descripcionCodigo,nombres[i]);
          break;
       }
    }


}
