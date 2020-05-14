#ifndef ARBOL_H
#define ARBOL_H
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <set>
#include <iomanip>
using namespace std;
class Arbol
{
    public:
        map<string, int> palabras;
        map<char, int> caracteres;
        set<string> excepciones;
        Arbol();
        virtual ~Arbol();
        void insertarExcepcion(string salidaExcepciones);
        void modificarExcepcion(string entradaExcepciones);
        void eliminarExcepcion(string entradaExcepciones);
        void consultarExcepciones(string archivoExcepciones);
        void leerExcepciones(string entradaCaracteres);
        void leerPalabras(string entradaCaracteres);
        void depurarPalabra(string & palabraActual);
        void buscarPalabra(string palabra);
        void leerCaracteres(string palabra, int ocurrencias);
        void darPalabras(string entradaCaracteres);
        void darCaracteres(string entradaCaracteres);
        void cargarArbol(string entradaCaracteres);
        void guardarArbol(string entradaCaracteres);
        void contarCaracteres();
        map<string, int> getPalabras();
        map<char, int> getCaracteres();
        set<string> getExcepciones();
    protected:
    private:
};

#endif // ARBOL_H
