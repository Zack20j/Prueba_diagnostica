import math
import time

def generar_triangulo_pascal(n):
    triangulo = []
    for i in range(n + 1):
        fila = [1] * (i + 1)
        for j in range(1, i):
            fila[j] = triangulo[i - 1][j - 1] + triangulo[i - 1][j]
        triangulo.append(fila)
    return triangulo

def main():
    n = int(input("Ingrese un numero entero positivo: "))
    if n < 0:
        print("El numero debe ser positivo.")
        return

    x = int(input("Ingrese el valor de x: "))

    # Iniciar conteo de tiempo
    inicio = time.time()

    coeficientes = generar_triangulo_pascal(n)

    with open("resultado.txt", "w", encoding="utf-8") as archivo:
        # archivo.write(f"=== TRIANGULO DE PASCAL HASTA n = {n} ===\n")
        # for fila in coeficientes:
        #     archivo.write(" ".join(str(int(c)) for c in fila) + "\n")
        # archivo.write("\n")

        # Paso 1
        archivo.write("paso 1: f(x) = ")
        archivo.write(" + ".join([f"{int(coeficientes[n][j])}*x^{n-j}" for j in range(n+1)]))
        archivo.write("\n")

        # Paso 2
        archivo.write(f"paso 2: f({x}) = ")
        archivo.write(" + ".join([f"{int(coeficientes[n][j])}*({x})^{n-j}" for j in range(n+1)]))
        archivo.write("\n")

        # Paso 3
        archivo.write(f"paso 3: f({x}) = ")
        archivo.write(" + ".join([f"{int(coeficientes[n][j])}*({int(math.pow(x, n-j))})" for j in range(n+1)]))
        archivo.write("\n")

        # Paso 4
        archivo.write(f"paso 4: f({x}) = ")
        archivo.write(" + ".join([f"{int(coeficientes[n][j] * math.pow(x, n-j))}" for j in range(n+1)]))
        archivo.write("\n")

        # Paso 5 (resultado final)
        resultado = sum(coeficientes[n][j] * math.pow(x, n-j) for j in range(n+1))
        archivo.write(f"paso 5: f({x}) = {int(resultado)}\n")

    # Fin del conteo de tiempo
    fin = time.time()
    tiempo_segundos = fin - inicio
    tiempo_milisegundos = tiempo_segundos * 1000

    print("Resultados guardados en 'resultado.txt'")
    print(f"Tiempo de ejecución: {tiempo_segundos:.6f} segundos ({tiempo_milisegundos:.3f} ms)")

if __name__ == "__main__":
    main()
