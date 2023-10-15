// Ejercicio 3.3.1.2* 
#include <iostream>
using namespace std;

bool isValid(int mid) {
    // Supongamos que la condición deseada es que mid sea mayor o igual a 42
    return mid >= 42;
}

int binarySearch(int low, int high) {
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (isValid(mid)) {
            // mid cumple con la condición, ajusta el rango hacia la izquierda
            high = mid;
        } else {
            // mid no cumple con la condición, ajusta el rango hacia la derecha
            low = mid + 1;
        }
    }
    return low; // low (o high) es la respuesta final
}

int main() {
    int low = 1;     // Valor mínimo posible del resultado
    int high = 100;  // Valor máximo posible del resultado
    int result = binarySearch(low, high);
    cout << "La respuesta es: " << result << endl;
    return 0;
}
