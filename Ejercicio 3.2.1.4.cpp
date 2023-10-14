#include <iostream>

using namespace std;
const int MAX_N = 20;
bool contains(int arr[], int size, int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            return true; 
        }
    } //si se encuentra o no en la lista
    return false; 
}

bool canPartition(int numbers[], int n, int X) {
    int half = n / 2;

    int sums_left[MAX_N * MAX_N] = {0}; 
    int sums_right[MAX_N * MAX_N] = {0};

    // Búsqueda hacia la izquierda
    for (int mask = 0; mask < (1 << half); mask++) {
        int sum = 0;
        int index = 0;
        for (int i = 0; i < half; i++) {
            if (mask & (1 << i)) {
                sum += numbers[i];
                sums_left[index++] = sum;
            }
        }
    }

    // Búsqueda hacia la derecha
    for (int mask = 0; mask < (1 << (n - half)); mask++) {
        int sum = 0;
        int index = 0;
        for (int i = 0; i < (n - half); i++) {
            if (mask & (1 << i)) {
                sum += numbers[half + i];
                sums_right[index++] = sum;
            }
        }
    }

    // Verificar si se encuentra una suma igual a X
    for (int i = 0; i < MAX_N * MAX_N; i++) {
        if (sums_left[i] == 0) break;
        if (contains(sums_right, MAX_N * MAX_N, X - sums_left[i])) {
            return true;
        }
    }

    return false;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int X, n;
        cin >> X >> n;

        int numbers[MAX_N];
        for (int i = 0; i < n; i++) {
            std::cin >> numbers[i];
        }

        if (canPartition(numbers, n, X)) {
            cout << "Si se encuentra en un Conjunto" << std::endl;
        } else {
            cout << "NO se encuentra ninguno" << std::endl;
        }
    }

    return 0;
}
