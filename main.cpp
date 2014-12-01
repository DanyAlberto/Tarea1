// queue::push/pop
#include "Mascota.h"
#include "Evaluador.h"
#include <iostream>
#include <list>
#include <fstream>
using namespace std;

//Escribe los datos del objeto mascota dado en un archivo binario con el nombre dado en la posicion dada
//Nota: Se deben poder agregar varias mascotas en un solo archivo
void escribir(string nombre_archivo, Mascota*mascota, int posicion)
{
    ofstream Archivo(nombre_archivo.c_str(),ios::in | ios::binary);/*Creacion del archivo "Archivo", se abrira en modo lectura y escritura para conservar lo que hay en el*/
    Archivo.seekp(posicion*10);/*Se utiliza el .seekp para mover el puntero del archivo de salida en donde escribira la proxima vez y se multiplica la posicion por diez ya que es el tamaño que requiere nustro nuevo registro*/
    Archivo.write(mascota->nombre.c_str(),6);/*Se escribe el Nombre*/
    Archivo.write((char *)&mascota->edad,4);/*Se escribe la edad*/
    Archivo.close();/*Se cierra el archivo*/
}

//Devuelve una mascota previamente escrita (con la funcion escribir()) en un archivo binario con nombre dado en la posicion dada
//Nota: Se deben poder leer varias mascotas de un solo archivo
Mascota* leer(string nombre_archivo, int posicion)
{
    Mascota *mascota;/*Creacion de un apuntador de tipo mascota*/

    ifstream Archivo(nombre_archivo.c_str());/*Se abre el archivo en modo lectura*/

    Archivo.seekg(posicion*10);/*Se utiliza el seekg ya que mueve el puntero del archivo de entrada y se multiplica la posicion por diez ya que es el tamaño que requiere nuestro registro*/

    char nombre[6];/*Se declara la variable "nombre" para capturar el nombre de la mascota*/
    int edad;/*Se declara la variable "edad" para capturar la edad de la mascota*/

    Archivo.read(nombre,6);/*Se lee el nombre*/
    Archivo.read((char*)&edad,4);/*Se lee la edad*/
    mascota = new Mascota(edad,nombre);/*Se guarda en "mascota" el nuevo registro con su respectiva edad y nombre*/

    return mascota;/*Retornamos el registro creado*/
}

//Devuelve un vector que contenga todas las mascotas previamente escritas (con la funcion escribir()) en un archivo binario con nombre dado
//Nota: El vector debe contener las mascotas ordenadas de acuerdo a la posicion en la que se escribieron
vector<Mascota*> leerTodos(string nombre_archivo)
{
    vector<Mascota*>respuesta;/*Vector en el cual se guardara  c/u de los registros de mascota*/
    Mascota *mascota;/*Se crea una variable "mascota" de tipo mascosta*/

    ifstream Archivo(nombre_archivo.c_str());/*Se abre el archivo en modo de lectura*/

    Archivo.seekg(0,Archivo.end);/*Se ubica al final de archivo*/

    int tamano = Archivo.tellg()/10;/*Para conocer la posicion se utiliza el "tellg", se divide la posicion actual del archivo entre diez*/

    Archivo.seekg(0,Archivo.beg);/*Se ubica en la posicion inicial del archivo*/

    for(int inicio = 0 ; inicio < tamano; inicio++)/*Se crea un ciclo para recorrer el archivo.*/
    {
        char nombre[6];/*Se declara la variable "nombre" para capturar el nombre*/
        int edad;/*Se declara la variable "edad" para capturar la edad*/

        Archivo.read(nombre,6);/*Se lee el nombre*/
        Archivo.read((char*)&edad,4);/*Se lee la edad*/

        mascota = new Mascota(edad,nombre);/*Se agrega el nuevo registro con su edad y su nombre*/
        respuesta.push_back(mascota);/*Se agrega al vector*/
    }
    return respuesta;/*Retornamos mascota*/
}

int main ()
{
    //Funcion evaluadora
    evaluar();
    return 0;
}
