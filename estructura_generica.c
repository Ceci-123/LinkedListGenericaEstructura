#include "estructura_generica.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

eEstructura* estructura_new()
{
    eEstructura* pEstructura = NULL;
    pEstructura = malloc(sizeof(eEstructura));
    if(pEstructura == NULL)
    {
        printf("No hay espacio suficiente en memoria\n");

    }
    return pEstructura;
}

int estructura_setId(eEstructura* pEstructura, int id)
{
    int todoOk = 0;

    if(pEstructura !=NULL && id > 0)
    {
       pEstructura->id = id;
       todoOk = 1;
    }
    return todoOk;

}

eEstructura* estructura_newParametros(char* idStr, char* nombreStr,char* edadStr,char* pesoStr,char* sexoStr,char* codigoStr)
{
    eEstructura* pEstructura = estructura_new();

    if(pEstructura != NULL)
    {
        estructura_setId(pEstructura,atoi(idStr));
        estructura_setNombre(pEstructura, nombreStr);
        estructura_setEdad(pEstructura,atoi(edadStr));
        estructura_setPeso(pEstructura, atof(pesoStr));
        estructura_setSexo(pEstructura, sexoStr[0]);
        estructura_setCodigo(pEstructura, atoi(codigoStr));

    }
    return pEstructura;
}

int estructura_getId(eEstructura* pEstructura,int* id)
{
    int todoOk = 0;
    if(pEstructura !=NULL && id != NULL)
    {
        *id = pEstructura->id;
        todoOk = 1;
    }
    return todoOk;

}

int estructura_setNombre(eEstructura* pEstructura,char* nombre)
{
    int todoOk= 0;
    if(pEstructura !=NULL && nombre != NULL)
    {
       strcpy(pEstructura->nombre, nombre);
       todoOk = 1;
    }
    return todoOk;
}

int estructura_getNombre(eEstructura* pEstructura, char* nombre)
{
    int todoOk = 0;
    if(pEstructura !=NULL && nombre != NULL)
    {
       strcpy(nombre,pEstructura->nombre);
       todoOk = 1;
    }
    return todoOk;

}

int estructura_getEdad(eEstructura* pEstructura,int* edad)
{
    int todoOk = 0;

    if(pEstructura != NULL && edad != NULL)
    {
       *edad = pEstructura->edad;
        todoOk = 1;
    }
    return todoOk;
}

int estructura_setEdad(eEstructura* pEstructura,int edad)
{
    int todoOk = 0;

    if(pEstructura != NULL && edad > 0)
    {
       pEstructura->edad = edad;
       todoOk = 1;
    }
    return todoOk;

}

int estructura_setPeso(eEstructura* pEstructura,float peso)
{
    int todoOk = 0;

    if(pEstructura != NULL && peso > 0)
    {
       pEstructura->peso = peso;
       todoOk = 1;
    }
    return todoOk;

}

int estructura_getPeso(eEstructura* pEstructura,float* peso)
{
    int todoOk = 0;

    if(pEstructura != NULL && peso != NULL)
    {
       *peso = pEstructura->peso;
        todoOk = 1;
    }
    return todoOk;
}

int estructura_setSexo(eEstructura* pEstructura,char sexo)
{
    int todoOk= 0;
    if(pEstructura !=NULL && (sexo == 'm' || sexo =='f' ))
    {
       pEstructura->sexo = sexo;
       todoOk = 1;
    }
    return todoOk;
}

int estructura_getSexo(eEstructura* pEstructura,char* sexo)
{
   int todoOk = 0;

    if(pEstructura != NULL && sexo != NULL)
    {
       *sexo = pEstructura->sexo;
        todoOk = 1;
    }
    return todoOk;
}

int estructura_getCodigo(eEstructura* pEstructura,int* codigo)
{
    int todoOk = 0;

    if(pEstructura != NULL && codigo != NULL)
    {
       *codigo = pEstructura->codigo;
        todoOk = 1;
    }
    return todoOk;
}

int estructura_setCodigo(eEstructura* pEstructura,int codigo)
{
    int todoOk = 0;

    if(pEstructura != NULL && codigo > 0)
    {
       pEstructura->codigo = codigo;
       todoOk = 1;
    }
    return todoOk;

}

int estructura_CompareByName(eEstructura* primera, eEstructura* segunda)
{
    int resultado;

    if(primera != NULL && segunda != NULL)
    {
        resultado = strcmp(primera->nombre, segunda->nombre);
    }
    return resultado;
}

int estructura_CompareById(eEstructura* primera, eEstructura* segunda)
{
    int resultado;

    if(primera != NULL && segunda != NULL)
    {
       if(primera->id > segunda->id)
    {
        resultado = 1;
    }
    else
    {
        if(primera->id < segunda->id)
        {
            resultado = -1;
        }
        else
        {
            resultado = 0;
        }
    }

    }
   return resultado;
}

int estructura_CompareByEdad(eEstructura* primera, eEstructura* segunda)
{
    int resultado;

    if(primera != NULL && segunda != NULL)
    {
       if(primera->edad > segunda->edad)
    {
        resultado = 1;
    }
    else
    {
        if(primera->edad < segunda->edad)
        {
            resultado = -1;
        }
        else
        {
            resultado = 0;
        }
    }

    }
   return resultado;
}

int estructura_CompareByPeso(eEstructura* primera, eEstructura* segunda)
{
    int resultado;

    if(primera != NULL && segunda != NULL)
    {
       if(primera->peso > segunda->peso)
    {
        resultado = 1;
    }
    else
    {
        if(primera->peso < segunda->peso)
        {
            resultado = -1;
        }
        else
        {
            resultado = 0;
        }
    }

    }
   return resultado;
}

int estructura_CompareBySexo(eEstructura* primera, eEstructura* segunda)
{
    int resultado;

    if(primera != NULL && segunda != NULL)
    {
       if(primera->sexo > segunda->sexo)
    {
        resultado = 1;
    }
    else
    {
        if(primera->sexo < segunda->sexo)
        {
            resultado = -1;
        }
        else
        {
            resultado = 0;
        }
    }

    }

    return resultado;
}

int estructura_CompareByCodigo(eEstructura* primera, eEstructura* segunda)
{
    int resultado;

    if(primera != NULL && segunda != NULL)
    {
       if(primera->codigo > segunda->codigo)
    {
        resultado = 1;
    }
    else
    {
        if(primera->codigo < segunda->codigo)
        {
            resultado = -1;
        }
        else
        {
            resultado = 0;
        }
    }

    }
   return resultado;
}

