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

/**
 * Método que se encarga de insertar una nueva palabra excepción en el archivo de excepciones.
 * @param salidaExcepciones
 */
void Arbol::insertarExcepcion(string salidaExcepciones)
{
    string nuevaPalabra;
    ofstream archivoExcepciones;
    archivoExcepciones.open(salidaExcepciones, ios::app);
    
    if (archivoExcepciones.is_open())
    {
        cout << "Digite la palabra que desea insertar: ";
        cin.ignore();
        cin >> nuevaPalabra;
        
        //Para cada caracter de nuevaPalabra hacer
        for (unsigned int charActual = 0; charActual < nuevaPalabra.size(); ++charActual)
        {
            //Si el caracter actual es una letra entonces convertirlo en minúscula.
            if (isalpha(nuevaPalabra[charActual]))
                nuevaPalabra[charActual] = tolower(nuevaPalabra[charActual]);
        }
        //Insertar la nueva palabra en el archivo.
        archivoExcepciones << nuevaPalabra << endl;
        archivoExcepciones.close();
    }
    else
    {
        cerr << "Avertencia: No se pudo abrir el archivo de excepciones." << endl;
    }
}

/**
 * Método que se encarga de modificar una palabra en el archivo de excepciones.
 * @param entradaExcepciones
 */
void Arbol::modificarExcepcion(string entradaExcepciones)
{
    string lineaActual;
    string aModificar;
    string nuevaPalabra;
    cout << "Digite la palabra que desea modificar: ";
    cin.ignore();
    cin >> aModificar;
    
    for (unsigned int charActual = 0; charActual < aModificar.size(); ++charActual)
    {
        if (isalpha(aModificar[charActual]))
            aModificar[charActual] = tolower(aModificar[charActual]);
    }
    
    cout << "Digite la nueva palabra para reemplazarla: ";
    cin.ignore();
    cin >> nuevaPalabra;
    
    for (unsigned int charActual = 0; charActual < nuevaPalabra.size(); ++charActual)
    {
        if (isalpha(nuevaPalabra[charActual]))
            nuevaPalabra[charActual] = tolower(nuevaPalabra[charActual]);
    }
    
    ifstream archivoExcepciones;
    archivoExcepciones.open(entradaExcepciones);
    ofstream archivoTemporal;
    archivoTemporal.open("tempExcepciones.txt"); //Archivo de salida temporal.
    
    if (archivoExcepciones.is_open() && archivoTemporal.is_open())
    {
        //Mientras haya una línea actual en el archivo de excepciones hacer
        while (getline(archivoExcepciones, lineaActual))
        {
            //Si la palabra que se quiere modificar se encuentra en la línea actual entonces
            if (lineaActual.compare(aModificar) == 0)
                lineaActual = nuevaPalabra; //Cambiarla por la nueva palabra.
            //Insertar la línea actual en el archivo temporal.
            archivoTemporal << lineaActual << endl;
        }
        
        //Cerrar ambos archivos.
        archivoExcepciones.close();
        archivoTemporal.close();
        //Reemplazar el archivo original por el archivo temporal.
        remove("excepciones.txt");
        rename("tempExcepciones.txt", "excepciones.txt");
    }
    else
    {
        cerr << "Avertencia: No se pudo abrir el archivo de excepciones." << endl;
    }
}

/**
 * Método que se encarga de eliminar una palabra del archivo de excepciones.
 * @param entradaExcepciones
 */
void Arbol::eliminarExcepcion(string entradaExcepciones)
{
    string lineaActual;
    string aEliminar;
    cout << "Digite la palabra que desea eliminar: ";
    cin.ignore();
    cin >> aEliminar;
    
    for (unsigned int charActual = 0; charActual < aEliminar.size(); ++charActual)
    {
        if (isalpha(aEliminar[charActual]))
            aEliminar[charActual] = tolower(aEliminar[charActual]);
    }
    
    ifstream archivoExcepciones;
    archivoExcepciones.open(entradaExcepciones);
    ofstream archivoTemporal;
    archivoTemporal.open("tempExcepciones.txt"); //Archivo de salida temporal.
    
    if (archivoExcepciones.is_open() && archivoTemporal.is_open())
    {
        while (getline(archivoExcepciones, lineaActual))
        {
            //Si la palabra que se quiere modificar se encuentra en la línea actual entonces
            if (lineaActual.compare(aEliminar) == 0)
                lineaActual = ""; //Cambiarla por una cadena vacía.
            //Insertar la línea actual en el archivo temporal.
            archivoTemporal << lineaActual << endl;
        }
        
        //Cerrar ambos archivos.
        archivoExcepciones.close();
        archivoTemporal.close();
        //Reemplazar el archivo original por el temporal.
        remove("excepciones.txt");
        rename("tempExcepciones.txt", "excepciones.txt");
    }
    else
    {
        cerr << "Avertencia: No se pudo abrir el archivo de excepciones." << endl;
    }
}

/**
 * Método que se encarga de leer el archivo de excepciones.
 * Efectúa: Lee el archivo de excepciones e imprime cada una de las palabras almacenadas.
 */
void Arbol::consultarExcepciones(string archivoExcepciones)
{
    ifstream lecturaExcepciones;
    lecturaExcepciones.open(archivoExcepciones);
    string lineaActual;
    
    cout << "Lista de excepciones:" << endl;
    while (getline(lecturaExcepciones, lineaActual))
        cout << lineaActual << endl;
    lecturaExcepciones.close();
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
        
        depurarPalabra(palabraActual); //Convierte la palabra en minúscula, elimina caracteres especiales.
        
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

/**
 * Método que convierte los caracteres de una hilera a minúscula y elimina caracteres especiales.
 * @param palabraActual : Palabra recibida por referencia.
 */
void Arbol::depurarPalabra(string & palabraActual)
{
    //Para cada caracter de la palabra actual
    for (unsigned int charPos = 0; charPos < palabraActual.size(); ++charPos)
    {
        //Si el caracter actual es una letra entonces
        if (isalpha(palabraActual[charPos]))
        {
            //Convertirla en minúscula.
            palabraActual[charPos] = tolower(palabraActual[charPos]);
        }
        else //De lo contrario
        {
            int contador = 1; //Contador de caracteres.
            int tempPos = charPos+1; //Posición temporal.
            //Mientras el caracter siguiente tampoco sea una letra
            while (!(isalpha(palabraActual[tempPos])))
            {
                //Aumentar el contador y la posición.
                contador++;
                tempPos++;
            }
            //Eliminar los n caracteres desde la posición actual.
            palabraActual.erase(charPos, contador);
        }
    }
}

/**
 * Método que se encarga de buscar una palabra guardada en el mapa de palabras.
 * Efectúa: Recorre el mapa hasta encontrar la palabra y la imprime en consola junto con su frecuencia.
 * @param palabra : La palabra que se quiere encontrar.
 */
void Arbol::buscarPalabra(string palabra)
{
    map<string, int>::iterator it = palabras.find(palabra);
    if (it == palabras.end())
    {
        cout << "La palabra ingresada no se encuentra en el árbol." << endl;
    }
    else
    {
        cout << "| " << setw(20) << left << "Palabra";
        cout << "| " << setw(20) << left << "Frecuencia" << " |" << endl;
        cout << "| " << setw(20) << left << it->first;
        cout << "| " << setw(20) << left << it->second << " |" <<endl;        
    }
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
    
    ifstream ifs; //Leer el archivo e imprimirlo
    ifs.open(salidaPalabras);
    string lineaActual;
    
    if (ifs.is_open()) {
        cout << "Archivo de conteo de palabras:" << endl;
        while (getline(ifs, lineaActual))
            cout << lineaActual << endl;
        
        ifs.close();
    }    
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
    
    ifstream ifs; //Leer el archivo en imprimirlo
    ifs.open(salidaCaracteres);
    string lineaActual;
    
    if (ifs.is_open()) {
        cout << "Archivo de conteo de caracteres:" << endl;
        while (getline(ifs, lineaActual))
            cout << lineaActual << endl;
        
        ifs.close();
    }
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
