#include <iostream>
#include "Arbol.h"
using namespace std;

int main()
{
    Arbol arbol;
    //arbol.cargarArbol("arbolGuardado.txt");
    arbol.leerExcepciones("excepciones.txt");
    arbol.leerPalabras("palabras.txt");
    arbol.leerPalabras("palabras1.txt");
    arbol.leerPalabras("palabras2.txt");
    arbol.darPalabras("conteoPalabras.txt");
    arbol.contarCaracteres();
    arbol.darCaracteres("conteoCaracteres.txt");
    arbol.guardarArbol("arbolGuardado.txt");
    return 0;

}
