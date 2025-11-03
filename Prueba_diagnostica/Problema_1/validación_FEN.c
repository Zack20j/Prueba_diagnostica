// Dado una cadena C, valide si C se encuentra en notación FEN 
// (Forsyth-Edwards Notation), Forsyth-Edwards Notation. FEN (Wikipedia, 2025).

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int validarPosicion(const char *campo);
int validarTurno(const char *campo);
int validarEnroques(const char *campo);
int validarCapturaAlPaso(const char *campo);
int validarContadores(const char *campo);
int validarFEN(const char *fen);
void imprimirTablero(const char *posicion);

void imprimirTablero(const char *posicion) {
    int fila = 8; 

    for (int i = 0; posicion[i]; i++) {
        char c = posicion[i];

        if (c == '/') {
            printf(" %d\n", fila--); 
        } else if (isdigit(c)) {
            int vacios = c - '0';
            for (int j = 0; j < vacios; j++)
                printf(". "); 
        } else {
            printf("%c ", c); 
        }
    }
    printf(" %d\n", fila--); 

    printf("a b c d e f g h\n");
}


int validarPosicion(const char *campo) {
    int filas = 1, columnas = 0;

    for (int i = 0; campo[i]; i++) {
        char c = campo[i];

        if (isdigit(c)) {
            columnas += c - '0';
        } else if (c == '/') {
            if (columnas != 8) return 0; 
            filas++;
            columnas = 0;
        } else if (strchr("prnbqkPRNBQK", c)) {
            columnas++;
        } else {
            return 0; 
        }

        if (columnas > 8) return 0;
    }

    return (filas == 8 && columnas == 8);
}

int validarTurno(const char *campo) {
    return (strcmp(campo, "w") == 0 || strcmp(campo, "b") == 0);
}

int validarEnroques(const char *campo) {
    if (strcmp(campo, "-") == 0) return 1; 

    int seen[4] = {0}; 

    for (int j = 0; campo[j]; j++) {
        char c = campo[j];
        switch (c) {
            case 'K': if (seen[0]++) return 0; break;
            case 'Q': if (seen[1]++) return 0; break;
            case 'k': if (seen[2]++) return 0; break;
            case 'q': if (seen[3]++) return 0; break;
            default: return 0; 
        }
    }
    return 1;
}

int validarCapturaAlPaso(const char *campo) {
    if (strcmp(campo, "-") == 0) return 1; 
    if (strlen(campo) != 2) return 0;

    char columna = campo[0];
    char fila = campo[1];
    return (columna >= 'a' && columna <= 'h' && (fila == '3' || fila == '6'));
}

int validarContadores(const char *campo) {
    for (int i = 0; campo[i]; i++)
        if (!isdigit(campo[i])) return 0;
    return 1;
}

int validarFEN(const char *fen) {
    char copia[128];
    strcpy(copia, fen);

    char *campos[6];
    int n = 0;

    char *token = strtok(copia, " ");
    while (token && n < 6) {
        campos[n++] = token;
        token = strtok(NULL, " ");
    }

    if (n != 6) return 0; 

    return validarPosicion(campos[0]) &&
           validarTurno(campos[1]) &&
           validarEnroques(campos[2]) &&
           validarCapturaAlPaso(campos[3]) &&
           validarContadores(campos[4]) &&
           validarContadores(campos[5]);
}

int main() {
    char fen[128];

    printf("Ingresa la cadena FEN: ");
    fgets(fen, 128, stdin);
    fen[strcspn(fen, "\n")] = 0;

    if (validarFEN(fen)) {
        printf("FEN valida\n");

        char copia[128];
        strcpy(copia, fen);
        char *campo1 = strtok(copia, " "); 

        imprimirTablero(campo1); 
    } else {
        printf("FEN invalida\n");
    }

    return 0;
}
