//Ejercicio 3.5.1.2 
#include <iostream>
#include <vector>

using namespace std;

const int MAX = 100;  // Tamaño máximo de la matriz cuadrada

int main() {
    int n = 5;  // Dimensión de la matriz cuadrada (cambia este valor según tus necesidades)
    int A[MAX][MAX] = {
        {1, 2, -3, 4, 5},
        {2, -1, 2, 3, -2},
        {3, 2, 1, -3, 2},
        {4, -3, -2, 1, 3},
        {5, 2, 3, -2, 1}
    };

    int maxSubRect = -127 * 100 * 100; // El valor mínimo posible en este problema

    for (int l = 0; l < n; l++) {
        for (int r = l; r < n; r++) {
            int subRect = 0;
            for (int row = 0; row < n; row++) {
                if (l > 0)
                    subRect += A[row][r] - A[row][l - 1];
                else
                    subRect += A[row][r];
                if (subRect < 0) subRect = 0; // Algoritmo de Kadane en las filas
                maxSubRect = max(maxSubRect, subRect);
            }
        }
    }

    cout << "La suma de rango bidimensional maxima es: " << maxSubRect << endl;

    return 0;
}
