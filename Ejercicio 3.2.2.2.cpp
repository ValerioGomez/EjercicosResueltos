// Ejercicio 3.2.2.2*
#include <iostream>
#include <bitset>
using namespace std;

int n, solutions;
bitset<30> rw, ld, rd;

void backtrack(int c) {
    if (c == n) {
        solutions++;
        return;
    }
    for (int r = 0; r < n; r++) {
        if (!rw[r] && !ld[r - c + n - 1] && !rd[r + c]) {
            rw[r] = ld[r - c + n - 1] = rd[r + c] = 1;
            backtrack(c + 1);
            rw[r] = ld[r - c + n - 1] = rd[r + c] = 0;
        }
    }
}

int main() {
    n = 8; // Tamaño del tablero
    solutions = 0;
    rw.reset();
    ld.reset();
    rd.reset();
    backtrack(0);
    cout << "Número de soluciones para un tablero " << n << "x" << n << ": " << solutions << endl;
    return 0;
}
