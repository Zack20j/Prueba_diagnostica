#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char *clave;
    char *traduccion;
} Palabra;

int main() {
    // Lista de palabras reservadas y sus traducciones
    Palabra palabras[] = {
        {"int", "entero"}, {"float", "flotante"}, {"double", "doble"},
        {"char", "carácter"}, {"if", "si"}, {"else", "sino"},
        {"while", "mientras"}, {"for", "para"}, {"return", "retornar"},
        {"switch", "seleccionar"}, {"case", "caso"}, {"break", "romper"},
        {"continue", "continuar"}, {"void", "vacío"}, {"struct", "estructura"},
        {"typedef", "definir tipo"}, {"enum", "enumeración"}, {"NULL", "nulo"}
    };
    int numPalabras = sizeof(palabras) / sizeof(palabras[0]);

    // Lectura del texto en memoria dinámica
    char *codigo = malloc(1024 * sizeof(char)); // Ajustable
    if (!codigo) {
        printf("Error de memoria\n");
        return 1;
    }

    printf("Ingrese el codigo C (una linea):\n");
    fgets(codigo, 1024, stdin);

    // Tokenizar el texto por espacios y símbolos básicos
    char *delimitadores = " \t\n;(){}[],";
    char *token = strtok(codigo, delimitadores);

    while (token != NULL) {
        int encontrado = 0;
        for (int i = 0; i < numPalabras; i++) {
            if (strcmp(token, palabras[i].clave) == 0) {
                printf("%s -> %s\n", token, palabras[i].traduccion);
                encontrado = 1;
                break;
            }
        }
        if (!encontrado) {
            printf("%s -> (no es palabra reservada)\n", token);
        }
        token = strtok(NULL, delimitadores);
    }

    free(codigo);
    return 0;
}
