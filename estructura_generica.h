#ifndef ESTRUCTURA_GENERICA_H_INCLUDED
#define ESTRUCTURA_GENERICA_H_INCLUDED

typedef struct
{
    int id;
    char nombre[20];
    int edad;
    float peso;
    char sexo;
    int codigo;
}eEstructura;

/** \brief Crea un espacio en memoria dinámica para la estructura, pasandole los parámetros que quiero agregar
 *
 * \param Un puntero a char, el id
 * \param Un puntero a char, el nombre
 * \param Un puntero a char, la edad
 * \param Un puntero a char, el peso
 * \param Un puntero a char, el sexo
 * \param Un puntero a char, el codigo
 * \return Puntero a la estructura creada
 **/
 eEstructura* estructura_newParametros(char* idStr, char* nombreStr,char* edadStr,char* pesoStr,char* sexoStr,char* codigoStr);


/** \brief Crea un espacio en memoria dinámica para la estructura
 *
 * \return Puntero a la estructura
 **/
eEstructura* estructura_new();

/** \brief Escribe la variable parámetro en el campo ID de la estructura
 *
 * \param Puntero a la estructura
 * \param Un entero, el id
 * \return Un entero, 1 si lo pudo escribir y 0 si hubo error
 **/
int estructura_setId(eEstructura* pEstructura, int id);

/** \brief Escribe la variable pasada como parámetro en el campo NOMBRE de la estructura
 *
 * \param Puntero a la estructura
 * \param Un puntero a char, el nombre a escribir
 * \return Un entero, 1 si lo pudo escribir y 0 si hubo error
 **/
int estructura_setNombre(eEstructura* pEstructura,char* nombre);

/** \brief Escribe la variable pasada como parámetro en el campo edad de la estructura
 *
 * \param Puntero a la estructura
 * \param Un entero, la edad
 * \return Un entero, 1 si lo pudo escribir y 0 si hubo error
 **/
int estructura_setEdad(eEstructura* pEstructura,int edad);

/** \brief Escribe la variable pasada como parámetro en el campo peso de la estructura
 *
 * \param Puntero a la estructura
 * \param Un entero, el peso
 * \return Un entero, 1 si lo pudo escribir y 0 si hubo error
 **/
int estructura_setPeso(eEstructura* pEstructura,float peso);

/** \brief Escribe la variable pasada como parámetro en el campo sexo de la estructura
 *
 * \param Puntero a la estructura
 * \param Un char, el sexo
 * \return Un entero, 1 si lo pudo escribir y 0 si hubo error
 **/
int estructura_setSexo(eEstructura* pEstructura,char sexo);

/** \brief Escribe la variable pasada como parámetro en el campo codigo de la estructura
 *
 * \param Puntero a la estructura
 * \param Un char, el sexo
 * \return Un entero, 1 si lo pudo escribir y 0 si hubo error
 **/
int estructura_setCodigo(eEstructura* pEstructura,int codigo);

/** \brief Lee el valor del campo NOMBRE de la estructura y lo copia en la variable pasada como parametro
 *
 * \param Puntero a la estructura
 * \param Un puntero a char, el nombre a leer
 * \return Un entero, 1 si lo pudo escribir y 0 si hubo error
 **/
int estructura_getNombre(eEstructura* pEstructura, char* nombre);

/** \brief Lee el valor del campo edad de la estructura y lo copia en la variable pasada como parametro
 *
 * \param Puntero a la estructura
 * \param Un entero, la edad
 * \return Un entero, 1 si lo pudo escribir y 0 si hubo error
 **/
int estructura_getEdad(eEstructura* pEstructura,int* edad);

/** \brief Lee el valor del campo peso de la estructura y lo copia en la variable pasada como parametro
 *
 * \param Puntero a la estructura
 * \param Un flotante, el peso
 * \return Un entero, 1 si lo pudo escribir y 0 si hubo error
 **/
int estructura_getPeso(eEstructura* pEstructura,float* peso);

/** \brief Lee el valor del campo sexo de la estructura y lo copia en la variable pasada como parametro
 *
 * \param Puntero a la estructura
 * \param Un char, el sexo
 * \return Un entero, 1 si lo pudo escribir y 0 si hubo error
 **/
int estructura_getSexo(eEstructura* pEstructura,char* sexo);

/** \brief Lee el valor del campo id de la estructura y lo copia en la variable pasada como parametro
 *
 * \param Puntero a la estructura
 * \param Un entero, el id
 * \return Un entero, 1 si lo pudo escribir y 0 si hubo error
 **/
int estructura_getId(eEstructura* pEstructura,int* id);

/** \brief Lee el valor del campo codigo de la estructura y lo copia en la variable pasada como parametro
 *
 * \param Puntero a la estructura
 * \param Un entero, el id
 * \return Un entero, 1 si lo pudo escribir y 0 si hubo error
 **/
int estructura_getCodigo(eEstructura* pEstructura,int* codigo);

/** \brief Compara el campo nombre de ambas estructuras y devuelve el resultado
 *
 * \param  Puntero a la primer estructura
 * \param  Puntero a la segunda estructura
 * \return Un entero, si las cadenas son iguales retornara un valor 0, si la primera cadena es mayor
 *         retornara un valor positivo y si es menor retornara un valor negativo.
 **/
int estructura_CompareByName(eEstructura* primera, eEstructura* segunda);

/** \brief Compara el campo id de ambas estructuras y devuelve el resultado
 *
 * \param Puntero a la primer estructura
 * \param Puntero a la segunda estructura
 * \return Un entero, devuelve 1(si el primero es mayor que el segundo),
 *        -1 (si el primero es menor que el segundo) o 0 si son iguales
 **/
int estructura_CompareById(eEstructura* primera, eEstructura* segunda);

/** \brief Compara el campo peso de ambas estructuras y devuelve el resultado
 *
 * \param Puntero a la primer estructura
 * \param Puntero a la segunda estructura
 * \return Un entero, devuelve 1(si el primero es mayor que el segundo),
 *        -1 (si el primero es menor que el segundo) o 0 si son iguales
 **/
int estructura_CompareByPeso(eEstructura* primera, eEstructura* segunda);

/** \brief Compara el campo sexo de ambas estructuras y devuelve el resultado
 *
 * \param Puntero a la primer estructura
 * \param Puntero a la segunda estructura
 * \return Un entero, devuelve 1(si el primero es mayor que el segundo),
 *        -1 (si el primero es menor que el segundo) o 0 si son iguales
 **/
int estructura_CompareBySexo(eEstructura* primera, eEstructura* segunda);

/** \brief Compara el campo codigo de ambas estructuras y devuelve el resultado
 *
 * \param Puntero a la primer estructura
 * \param Puntero a la segunda estructura
 * \return Un entero, devuelve 1(si el primero es mayor que el segundo),
 *        -1 (si el primero es menor que el segundo) o 0 si son iguales
 **/
int estructura_CompareByCodigo(eEstructura* primera, eEstructura* segunda);

/** \brief Compara el campo edad de ambas estructuras y devuelve el resultado
 *
 * \param Puntero a la primer estructura
 * \param Puntero a la segunda estructura
 * \return Un entero, devuelve 1(si el primero es mayor que el segundo),
 *        -1 (si el primero es menor que el segundo) o 0 si son iguales
 **/
int estructura_CompareByEdad(eEstructura* primera, eEstructura* segunda);

#endif // ESTRUCTURA_GENERICA_H_INCLUDED
