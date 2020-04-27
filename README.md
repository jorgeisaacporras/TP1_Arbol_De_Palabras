# Tarea Programada: Árbol de palabras.

---
##### Escuela de Ciencias de la Computación e Informática, UCR.

##### Curso del proyecto: Programación II.

##### Equipo de trabajo:

* ##### Jorge Isaac Porras
* ##### Gabriel Revillat

##### Año: 2020.

---

## Indicaciones del documento de referencia:

### Descripción General:

Se requiere hacer un programa que usando árboles binarios balanceados y archivos, permita contar la cantidad de veces que se da una palabra en al menos un archivo (eventualmente el usuario debería poder indicar de manera iterativa, varios archivos de texto como entrada). Para evitar contar palabras irrelevantes, se va a tener un archivo de excepciones, e.g. podría no contarse artículos, preposiciones y algunas otras palabras, como: y, o 

El árbol que contiene el contador de ocurrencias debe poderse guardar en un archivo, que quizás al inicio de sucesivas corridas del programa, se desee cargar como archivo de entrada para considerar la ocurrencias de palabras en otros archivos.

### Funcionalidad esperada:
    
    1. Definir en tiempo real y editar el archivo de excepciones
    2. cargar el árbol de ocurrencias creado en alguna sesión anterior
    3. {definir el archivo de entrada y almacenar en el árbol, las ocurrencias de las palabras en el archivo}. Es decir, el usuario debe poder incluir múltiples archivos
    4. Mostrar cuántas veces ocurre cada palabras. Listado de todas las palabras
    5. Indicar las veces que una palabra específica ocurre. Búsqueda de una palabra particular
    6. Definir archivo de salida y exportar el árbol de ocurrencias
    7. Calcular frecuencia de cada carácter en el archivo (carácter en la palabra * contador de veces de dicha palabra)
    8. Editar archivo de excepciones: Insertar, Modificar, Excluir, Consultar (IMEC / CRUD en  inglés)
    9. Transformar a minúscula cada palabra antes de usarla
    10. Los plurales manéjelos separados de los singulares (ej, casa y casas, pez y peces, cas y caces)
    11. Controlador con su menú, definición de clases y operaciones
    12. Documentación

### Pruebas:

    1. Archivo de entrada no existe
    2. Leer archivo que define excepciones
    3. Leer un archivo con una sola línea
    4. Leer un archivo con dos líneas
