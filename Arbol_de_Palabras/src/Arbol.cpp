#include "Arbol.h"
/*USO DE MAPA COMO SUBSTITUTO DE UN AVL:
LA ESTRUCTURA MAP EN LA LIBRERIA STL ES UNA IMPLEMENTACIÓN DE UN ARBOL BINARIO BALANCEADO DE TIPO ROJO-NEGRO.
EN ESTA IMPLEMENTACIÓN SE HA DECIDIDO UTILIZAR LA ESTRUCTURA DE MAPA COMO UN SUBTITUTO DE UN ARBOL AVL POR SU FACILIDAD DE USO
REDUCCIÓN DE CODIGO Y FACILIDAD DE LECTURA. NOTESE QUE AL SER UNA ARBOL BINARIO BALANCEADO, LAS FUNCIONES DE BUSQUEDA TIENEN UN
RENDIMIENTO SIMILAR A OTROS TIPOS DE ARBOL BB COMO EL AVL, SIN EMBARGO LA ESTRUCTURA DE AVL ES MAS RAPIDA. LA VENTAJA DEL ARBOL
ROJO-NEGRO RESIDE EN UNA INSERCIÓN MÁS RÁPIDA.
*/


Arbol::Arbol(){

}

Arbol:: ~Arbol(){
}

/*
Efectúa: Lee el archivo de excepciones y almacena en un conjunto las palabras que no se quieren almacenar en el arbol de palabras
Requiere: Una cadena que represente el nombre del archivo de excepciones
Modifica: El conjunto que almacena las excepciones
*/
void Arbol::leerExcepciones(string entradaExcepciones){
    ifstream ifs;
    ifs.open(entradaExcepciones);
    string palabraActual;
    while (ifs >> palabraActual){ //cuando no encuentra más palabras, el ciclo se detiene
        set<string>::iterator it = excepciones.find(palabraActual); //un iterador para almacenar la localización del elemento
        if (it == excepciones.end()){ //si no se encuentra la palabra, la añade al mapa
            excepciones.insert(palabraActual);
        }
        else{
        }
    }
    ifs.close();
    return;
}

void Arbol::leerPalabras(string entradaPalabras){
    ifstream ifs;
    ifs.open(entradaPalabras);
    string palabraActual;
    while (ifs >> palabraActual){
        map<string, int>::iterator it = palabras.find(palabraActual); //un iterador para la localización del par del mapa de palabras
        set<string>::iterator itExc = excepciones.find(palabraActual); //un iterador para la localización del elemento en el conjunto de excepciones
        if (itExc == excepciones.end()){ //si la palabra no se encuentra en el conjunto de excepciones
            if (it == palabras.end()){ //y no se encuentra en la lista de palabras
                palabras[palabraActual] = 1; //se añade la palabra y un contador de 1
            }
            else{
                it->second += 1; //si ya se encuentra, se aumenta ese contador
            }
        }
    }
    ifs.close();
    return;
}

void Arbol::leerCaracteres(string palabra, int ocurrencias){
    for(string::iterator caracterActual = palabra.begin(); caracterActual != palabra.end(); ++caracterActual) { //recorrido del string
        map<char, int>::iterator it = caracteres.find(*caracterActual); //un iterador para la localizacion del caracter en el mapa de caracteres
        if (it == caracteres.end()){ //si no se encuentra el caracter en el mapa
            caracteres[*caracterActual] = ocurrencias; //las ocurrencias del caracter por ahora son las ocurrencias de la palabra que se está analizando
        }
        else{ //si ya está el caracter en el mapa
            it->second = it->second + ocurrencias; /*las ocurrencias actuales son iguales a las ya registradas más 1, multiplicadas por las
            ocurrencias de esa palabra*/
        }
    }
    return;
}

void Arbol::darPalabras(string salidaPalabras){
    ofstream ofs;
    ofs.open(salidaPalabras);
    ofs << "| " << setw(20) << left << "Palabra";
    ofs << "| " << setw(20) << left << "Frecuencia" << " |" << endl; //formateo de la fila superior
    for (map<string, int>::iterator it = palabras.begin(); it != palabras.end(); it++){
        ofs << "| " << setw(20) << left << it->first;
        ofs << "| " << setw(20) << left << it->second << " |" <<endl; //formateo de los datos
    }
    cout << "\n\n\n";
    ofs.close();
    return;
}

void Arbol::darCaracteres(string salidaCaracteres){
    ofstream ofs;
    ofs.open(salidaCaracteres);
    ofs << "| " << setw(20) << left << "Caracter";
    ofs << "| " << setw(20) << left << "Frecuencia" << " |" << endl; //formateo de la fila superior
    for (map<char, int>::iterator it = caracteres.begin(); it != caracteres.end(); it++){
        ofs << "| " << setw(20) << left << it->first;
        ofs << "| " << setw(20) << left << it->second << " |" <<endl; //formateo de los datos
    }
    ofs.close();
    return;
}

void Arbol::cargarArbol(string entradaArbol){
    ifstream ifs;
    ifs.open(entradaArbol);
    string palabraActual;
    int ocurrenciasActuales;
    while (ifs >> palabraActual >> ocurrenciasActuales){ //lee el archivo del arbol que viene guardado en un formato de una palabra por linea con sus ocurrencias separadas por un espacio
        palabras[palabraActual] = ocurrenciasActuales;
    }
    ifs.close();
    return;
}

void Arbol::guardarArbol(string salidaArbol){//guarda el arbol en un formato de una palabra por linea con sus ocurrencias separadas por un espacio
    ofstream ofs;
    ofs.open(salidaArbol);
    for (map<string, int>::iterator it = palabras.begin(); it != palabras.end(); it++){ //recorre el archivo
        ofs << it->first << " ";
        ofs << it->second << endl;
    }
    return;
}

void Arbol::contarCaracteres(){
    for (map<string, int>::iterator it = palabras.begin(); it != palabras.end(); it++){ //para cada palabra en el mapa de palabras
        leerCaracteres(it->first, it->second); //realiza una lectura caracter por caracter que cuenta sus ocurrencias
    }
    return;
}

map<string, int> Arbol::getPalabras(){

    return palabras;

}

map<char, int> Arbol::getCaracteres(){

    return caracteres;

}

set<string> Arbol::getExcepciones(){

    return excepciones;

}
