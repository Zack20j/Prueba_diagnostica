// Dado un número entero no negativo n, a) genere los coeficientes del polinomio 
// (x+1)", muestre el resultado del polinomio y b) muestre por pasos el cálculo para x dado, f(x) = (x+1)" 
// según el polinomio generado. Implemente el algoritmo utilizando memoria dinámica. 
// Para generar los polinomios de (x+1) utilice el triangulo de pascal:

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

long double **generarTrianguloPascal(int n) {

    long double **triangulo = (long double **)malloc((n + 1) * sizeof(long double *));
    if (triangulo == NULL) {
        printf("Error al asignar memoria.\n");
        exit(1);
    }

    for (int i = 0; i <= n; i++) {
        triangulo[i] = (long double *)malloc((i + 1) * sizeof(long double));
        if (triangulo[i] == NULL) {
            printf("Error al asignar memoria.\n");
            exit(1);
        }

        triangulo[i][0] = 1;       
        triangulo[i][i] = 1;       

        // Fila 0:      0 0 0 0 1 0 0 0 0
        // Fila 1:      0 0   1   1
        // Fila 2:          1   2   1
        // Fila 3:        1   3   3   1
        // Fila 4:      1   4   6   4   1

        for (int j = 1; j < i; j++) {
            triangulo[i][j] = triangulo[i - 1][j - 1] + triangulo[i - 1][j];
        }
    }

    return triangulo;
}

int main() {
    int n, x;

    printf("Ingrese un numero entero positivo: ");
    scanf("%d", &n);
    if (n < 0) {
        printf("El numero debe ser positivo.\n");
        return 0;
    }

    printf("Ingrese el valor de x: ");
    scanf("%d", &x);

    clock_t inicio = clock();

    FILE *archivo = fopen("resultado.txt", "w");
    if (archivo == NULL) {
        printf("Error al crear el archivo.\n");
        return 1;
    }

    long double **coeficientes = generarTrianguloPascal(n);

    // fprintf(archivo, "=== TRIANGULO DE PASCAL HASTA n = %d ===\n", n);
    //     for (int i = 0; i <= n; i++) {
    //         for (int k = 0; k < n - i; k++) {
    //             fprintf(archivo, " ");
    //         }
    //         for (int j = 0; j <= i; j++) {
    //             fprintf(archivo, "%.0Lf ", coeficientes[i][j]);
    //         }
    //         fprintf(archivo, "\n");
    //     }
    // fprintf(archivo, "\n");

    fprintf(archivo, "=== CÁLCULO DE f(x) = (x + 1)^%d ===\n", n);

    fprintf(archivo, "paso 1: f(x) = ");
    for (int j = 0; j <= n; j++) {
        fprintf(archivo, "%.0Lf*x^%d", coeficientes[n][j], n - j);
        if (j < n)
            fprintf(archivo, " + ");
    }
    fprintf(archivo, "\n");

    fprintf(archivo, "paso 2: f(%d) = ", x);
    for (int j = 0; j <= n; j++) {
        fprintf(archivo, "%.0Lf*(%d)^%d", coeficientes[n][j], x, n - j);
        if (j < n)
            fprintf(archivo, " + ");
    }
    fprintf(archivo, "\n");

    fprintf(archivo, "paso 3: f(%d) = ", x);
    for (int j = 0; j <= n; j++) {
        fprintf(archivo, "%.0Lf*(%.0f)", coeficientes[n][j], pow(x, n - j));
        if (j < n)
            fprintf(archivo, " + ");
    }
    fprintf(archivo, "\n");

    fprintf(archivo, "paso 4: f(%d) = ", x);
    for (int j = 0; j <= n; j++) {
        fprintf(archivo, "%.0Lf", coeficientes[n][j] * pow(x, n - j));
        if (j < n)
            fprintf(archivo, " + ");
    }
    fprintf(archivo, "\n");

    long double resultado = 0;
    for (int j = 0; j <= n; j++) {
        resultado += coeficientes[n][j] * pow(x, n - j);
    }
    fprintf(archivo, "paso 5: f(%d) = %.0Lf\n", x, resultado);

    for (int i = 0; i <= n; i++) {
        free(coeficientes[i]);
    }
    free(coeficientes);

    fclose(archivo);

    clock_t fin = clock();

    double tiempo_segundos = (double)(fin - inicio) / CLOCKS_PER_SEC;
    double tiempo_milisegundos = tiempo_segundos * 1000.0;

    printf("Tiempo de ejecucion: %.6f segundos (%.3f ms)\n", tiempo_segundos, tiempo_milisegundos);

    return 0;
}
