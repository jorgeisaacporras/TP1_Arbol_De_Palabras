#include <iostream>
#include <fstream>
#include "Arbol.h"
using namespace std;

/**
 * Método que se encarga de agregar una línea al archivo recibido por parámetro.
 * @param archivo : El archivo en el que se quiere escribir.
 */
void insertarLinea(ofstream & archivo)
{
    string nuevaLinea;
    cout << "Escriba una línea para agregar al archivo: ";
    cin.ignore();
    getline(cin, nuevaLinea);
    archivo << nuevaLinea << endl;
}

/**
 * Método para definir un nuevo archivo de entrada.
 * Llama al método de la clase Arbol para leer cada palabra del archivo.
 * @param nombreArchivo : El nombre del archivo que se va a definir.
 */
void definirArchivoEntrada(string nombreArchivo, Arbol & arbol)
{
    ofstream archivo;
    archivo.open(nombreArchivo + ".txt");
    
    if (archivo.is_open())
    {
        bool terminar = false;        
        do
        {
            int opcion = 0;
            cout << "Nota: Caracteres especiales en español serán ignorados." << endl;
            cout << "¿Agregar una nueva línea al archivo?" << endl;
            cout << "1. Sí" << endl;
            cout << "2. No" << endl;
            cin >> opcion;
            
            switch (opcion)
            {
                case 1:
                    insertarLinea(archivo);
                    break;
                case 2:
                    terminar = true;
                    break;
                default:
                    cerr << "Escoja una opción válida del menú." << endl;
            }
        }
        while (!(terminar));
        archivo.close();
    }
    else
    {
        cerr << "Advertencia: No se pudo crear el archivo de entrada." << endl;
    }
    
    ifstream archivoLectura;
    archivoLectura.open(nombreArchivo + ".txt");
    string lineaActual;
    
    if (archivoLectura.is_open())
    {
        //Leer el archivo que acaba de ser creado.
        cout << "Su archivo creado:" << endl;
        while (getline(archivoLectura, lineaActual))
            cout << lineaActual << endl;
        
        arbol.leerPalabras(nombreArchivo + ".txt");
        archivoLectura.close();
    }
    else
    {
        cerr << "Archivo " << nombreArchivo << ".txt no existe." << endl;
    }
}

/**
 * Método que despliega un menú para el usuario para el manejo del archivo de excepciones.
 * Efe: Llama a los métodos necesarios de la clase Arbol para manejar el archivo de excepciones.
 * @param arbol : Referencia a un objeto de la clase Arbol.
 */
void menuExcepciones(Arbol & arbol)
{
    bool regresar = false;
    do
    {
        int opcion = 0;
        cout << "Menú del archivo de excepciones" << endl;
        cout << "1. Insertar nueva palabra" << endl;
        cout << "2. Modificar una palabra" << endl;
        cout << "3. Eliminar una palabra" << endl;
        cout << "4. Consultar lista de excepciones" << endl;
        cout << "5. Almacenar excepciones y volver al menú principal" << endl;
        cin >> opcion;

        switch (opcion)
        {
            case 1:
                arbol.insertarExcepcion("excepciones.txt");
                break;
            case 2:
                arbol.modificarExcepcion("excepciones.txt");
                break;
            case 3:
                arbol.eliminarExcepcion("excepciones.txt");
                break;
            case 4:
                arbol.consultarExcepciones("excepciones.txt");
                break;
            case 5:
                arbol.leerExcepciones("excepciones.txt");
                regresar = true;
                break;
            default:
                cerr << "Escoja una opción válida del menú." << endl;
        }
    }
    while (!(regresar));
}

/**
 * Método que despliega un menú para el usuario para manejar los archivos.
 * Efe: Crea el árbol y el archivo de excepciones. Llama a los métodos necesarios para manejar archivos.
 */
void menuPrincipal()
{
    Arbol arbol;
    ofstream archivoExcepciones;
    //Si el archivo de excepciones ya existe, estas líneas eliminan su contenido cada vez que se vuelve a iniciar el programa.
    //Esto se puede quitar si se desea conservar las palabras guardadas en alguna ejecución anterior.
    archivoExcepciones.open("excepciones.txt");
    archivoExcepciones.close();
    bool salir = false;

    do
    {
        int opcion = 0;
        cout << "Menú de archivos" << endl;
        cout << "¿Qué desea hacer?" << endl;
        cout << "1. Ir al menú del archivo de excepciones" << endl;
        cout << "2. Cargar el árbol guardado en una ejecución anterior" << endl;
        cout << "3. Definir un archivo de entrada y almacenarlo en el árbol" << endl;
        cout << "4. Crear y leer archivo de ocurrencias de palabras" << endl;
        cout << "5. Crear y leer archivo de ocurrencias de caracteres" << endl;
        cout << "6. Buscar una palabra específica del árbol" << endl;
        cout << "7. Guardar el árbol en un archivo para una próxima ejecución" << endl;
        cout << "8. Salir" << endl;
        cin >> opcion;
        
        string nombreArchivo;
        string aBuscar;
        switch (opcion)
        {
            case 1:
                menuExcepciones(arbol);
                break;
            case 2:
                arbol.cargarArbol("arbolGuardado.txt"); //Carga el árbol guardado en una ejecución anterior.
                cout << "Arbol cargado." << endl;
                break;
            case 3:                
                cout << "Escriba un nombre para el archivo txt (sin escribir la extensión): ";
                cin.ignore();
                getline(cin, nombreArchivo);
                definirArchivoEntrada(nombreArchivo, arbol);
                break;
            case 4:
                arbol.darPalabras("conteoPalabras.txt");
                break;
            case 5:
                arbol.contarCaracteres();
                arbol.darCaracteres("conteoCaracteres.txt");
                break;
            case 6:
                cout << "Escriba la palabra que desea encontrar: ";
                cin.ignore();
                getline(cin, aBuscar);
                arbol.buscarPalabra(aBuscar);
                break;
            case 7:
                arbol.guardarArbol("arbolGuardado.txt"); //Guarda el árbol para una próxima ejecución.
                cout << "Árbol guardado." << endl;
                break;
            case 8:
                salir = true;
                break;
            default:
                cerr << "Escoja una opción válida del menú." << endl;
        }
    }
    while (!(salir)); 
}

/*
 * Método principal
 */
int main()
{
    menuPrincipal();
    
    return 0;
}
