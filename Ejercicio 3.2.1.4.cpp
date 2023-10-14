#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX_N = 20;

bool canPartition(int numbers[], int n, int X) {
    int half = n / 2;

    vector<int> sums_left; 
    vector<int> sums_right;

    // Búsqueda hacia la izquierda
    for (int mask = 0; mask < (1 << half); mask++) {
        int sum = 0;
        for (int i = 0; i < half; i++) {
            if (mask & (1 << i)) {
                sum += numbers[i];
            }
        }
        sums_left.push_back(sum);
    }

    // Búsqueda hacia la derecha
    for (int mask = 0; mask < (1 << (n - half)); mask++) {
        int sum = 0;
        for (int i = 0; i < (n - half); i++) {
            if (mask & (1 << i)) {
                sum += numbers[half + i];
            }
        }
        sums_right.push_back(sum);
    }

    // Ordenar el vector sums_right
    sort(sums_right.begin(), sums_right.end());

    // Verificar si se encuentra una suma igual a X
    for (int i = 0; i < sums_left.size(); i++) {
        if (binary_search(sums_right.begin(), sums_right.end(), X - sums_left[i])) {
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
        cin >> X >>n;
        int numbers[MAX_N];
        for (int i = 0; i < n; i++) {
            cin >> numbers[i];
        }

        if (canPartition(numbers, n, X)) {
            cout << "Si se encuentra en un Conjunto" << "\n *************************" <<endl;
        } else {
            cout << "NO se encuentra ninguno" << "\n *************************" <<endl;
        }
    }

    return 0;
}
