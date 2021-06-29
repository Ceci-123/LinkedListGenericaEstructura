#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "estructura_generica.h"

int parser_FromText(FILE* pFile, LinkedList* pArrayLista)
{
    eEstructura* pEstructura = NULL;
    char nombre[50];
    char sexo[5];
    char id[10];
    char edad[10];
    char peso[10];
    char codigo[10];
    int todoOk = 0;

    if(pFile != NULL && pArrayLista != NULL)
    {
        fscanf(pFile,"%s\n",nombre);
       //lectura fantasma del encabezado

       while(!feof(pFile))
        {
            if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,edad,peso,sexo,codigo) == 6)
            {
                pEstructura = estructura_newParametros(id,nombre,edad,peso,sexo,codigo);
                ll_add(pArrayLista,pEstructura);
            }
            else
            {
               break;
            }

        }
        todoOk = 1;
    }

    return todoOk;
}

int parser_FromBinary(FILE* pFile, LinkedList* pArrayLista)
{
    eEstructura* pEstructura;
    int devolucionFread;

    fseek(pFile,33,SEEK_SET);
    while(!feof(pFile))
    {
        pEstructura = estructura_new();
        devolucionFread = fread(pEstructura,sizeof(eEstructura),1,pFile);
        if(devolucionFread != 1)
        {
            break;
        }
        ll_add(pArrayLista,pEstructura);

    }
    return 1;
}
