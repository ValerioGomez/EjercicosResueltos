#include <iostream>

using namespace std;
const int MAXN = 10; //según el cuadro

class FenwickTree {
private:
    int ft[MAXN + 1];

public:
    FenwickTree(int n) {
        for (int i = 0; i <= n; i++) {
            ft[i] = 0;
        }
    }

    void adjust(int k, int v) {
        for (; k < MAXN; k += (k & -k)) {
            ft[k] += v;
        }
    }

    int rsq(int b) {
        int sum = 0;
        for (; b; b -= (b & -b)) {
            sum += ft[b];
        }
        return sum;
    }

    int rsq(int a, int b) {
        return rsq(b) - rsq(a - 1);
    }

    int funcionRequerida(int freq) {
        int lo = 1, hi = MAXN;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (rsq(mid) >= freq) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
    }
};

int main() {
    int f[] = {0, 1, 0, 1, 2, 3, 2, 1, 1, 0};
    int n = 10; // Número de estudiantes

    FenwickTree ft(n);

    // Construir el árbol de Fenwick
    for (int i = 1; i <= n; i++) {
        ft.adjust(i, f[i]);
    }

    int frecuenciaDeseada = 7; // Frecuencia deseada

    int minIndex = ft.funcionRequerida(frecuenciaDeseada);

    cout << "El Indice minimo para tener al menos " << frecuenciaDeseada << " estudiantes es: " << minIndex << endl;

    return 0;
}
