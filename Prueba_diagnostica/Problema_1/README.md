# Problema 1: Validación de Notación FEN (Forsyth–Edwards Notation)

## Descripción
Este programa en C valida si una cadena ingresada corresponde a una notación **FEN (Forsyth–Edwards Notation)**, usada en ajedrez para representar el estado de una partida.  
Además, en caso de ser válida, muestra gráficamente el tablero correspondiente.

## Estructura del código

El programa está compuesto por varias funciones que validan cada campo de la notación FEN:

`validarPosicion()` | Comprueba que la estructura de piezas y filas sea válida (8x8) 
`validarTurno()` | Verifica si el turno es `w` (blancas) o `b` (negras)
`validarEnroques()` | Confirma los posibles enroques (`KQkq` o `-`)
`validarCapturaAlPaso()` | Valida si la casilla de captura al paso es correcta (columna a–h, fila 3 o 6)
`validarContadores()` | Revisa que los contadores numéricos sean válidos
`validarFEN()` | Integra todas las validaciones anteriores
`imprimirTablero()` | Dibuja el tablero correspondiente a la cadena FEN

## Requisitos de instalación
Instalar un compilador compatible (como GCC):

## Compilar y ejecutar:
```bash
gcc validación_FEN.c -o validacion_FEN
./validacion_FEN
.\validacion_FEN