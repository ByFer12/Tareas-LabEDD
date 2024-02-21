#include <iostream>
using namespace std;

int calcularPosicion(int indices[], int dimensiones[], int n) {
    int posicion = 0;
    int multiplicador = 1;

    for (int i = n - 1; i >= 0; i--) {
        if (indices[i] < 0 || indices[i] >= dimensiones[i]) {
            cout << "Error: Índices fuera de rango." << endl;
            return -1;
        }
        posicion += indices[i] * multiplicador;
        multiplicador *= dimensiones[i];
    }

    return posicion;
}

int main() {
    int indices[] = {2, 1, 3,4,1};  // Aqui van los indices de la posición deseada
    int dimensiones[] = {4, 3, 5,6,3};  // Aqui van las dimensiones de la matriz
    int n = sizeof(indices) / sizeof(indices[0]);  // Formula paa obtener la longitud del arreglo indice

    int posicion = calcularPosicion(indices, dimensiones, n);
    if (posicion != -1) {
        cout << "La posición en memoria es: " << posicion << endl;
    }

    return 0;
}