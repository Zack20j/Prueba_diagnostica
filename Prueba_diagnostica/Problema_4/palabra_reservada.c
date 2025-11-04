// Para un programa escrito en lenguaje C, cargado en una memoria de forma dinámica 
// verifique si existen palabras reservadas en C y tradúzcalas a su equivalente en español

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char *clave;
    char *traduccion;
} Palabra;

Palabra palabras[] = {
    {"auto", "automático"}, {"break", "romper"}, {"case", "caso"}, {"char", "carácter"},
    {"const", "constante"}, {"continue", "continuar"}, {"default", "predeterminado"},
    {"do", "hacer"}, {"double", "doble"}, {"else", "sino"}, {"enum", "enumeración"},
    {"extern", "externo"}, {"float", "flotante"}, {"for", "para"}, {"goto", "ir a"},
    {"if", "si"}, {"int", "entero"}, {"long", "largo"}, {"register", "registro"},
    {"return", "retornar"}, {"short", "corto"}, {"signed", "con signo"},
    {"sizeof", "tamaño de"}, {"static", "estático"}, {"struct", "estructura"},
    {"switch", "seleccionar"}, {"typedef", "definir tipo"}, {"union", "unión"},
    {"unsigned", "sin signo"}, {"void", "vacío"}, {"volatile", "volátil"},
    {"while", "mientras"}, {"NULL", "nulo"}
};

int numPalabras = sizeof(palabras) / sizeof(palabras[0]);

const char* traducirPalabra(const char *token) {
    for (int i = 0; i < numPalabras; i++) {
        if (strcmp(token, palabras[i].clave) == 0) {
            return palabras[i].traduccion;
        }
    }
    return NULL; 
}

int main() {
    char nombreArchivo[100];
    FILE *archivo;
    long tamano;
    char *codigo;

    printf("Ingrese el nombre del archivo C a analizar (ejemplo: codigo.c): ");
    scanf("%99s", nombreArchivo);

    archivo = fopen(nombreArchivo, "r");
    if (!archivo) {
        perror("Error al abrir el archivo");
        return 1;
    }

    fseek(archivo, 0, SEEK_END);
    tamano = ftell(archivo);
    rewind(archivo);

    codigo = (char *)malloc(tamano + 1);
    if (!codigo) {
        printf("Error de memoria\n");
        fclose(archivo);
        return 1;
    }

    fread(codigo, 1, tamano, archivo);
    codigo[tamano] = '\0';
    fclose(archivo);

    printf("\n--- Palabras reservadas encontradas y su traducción ---\n\n");

    const char *delimitadores = " \t\n;(){}[],<>+-*/=%\"\'";
    char *token = strtok(codigo, delimitadores);

    while (token != NULL) {
        const char *trad = traducirPalabra(token);
        if (trad != NULL) {
            printf("%s -> %s\n", token, trad);
        }
        token = strtok(NULL, delimitadores);
    }

    free(codigo);
    return 0;
}
