#include <iostream>

using namespace std;

class FenwickTree2D {
private:
    int** ft;
    int n, m;

public:
    FenwickTree2D(int rows, int cols) {
        n = rows;
        m = cols;
        ft = new int*[n + 1];
        for (int i = 0; i <= n; ++i) {
            ft[i] = new int[m + 1]();
        }
    }

    int rsq(int a, int b) {
        int sum = 0;
        for (int i = a; i > 0; i -= LSOne(i)) {
            for (int j = b; j > 0; j -= LSOne(j)) {
                sum += ft[i][j];
            }
        }
        return sum;
    }

    int rsq(int a, int b, int c, int d) {
        return rsq(c, d) - rsq(a - 1, d) - rsq(c, b - 1) + rsq(a - 1, b - 1);
    }

    void adjust(int a, int b, int v) {
        for (int i = a; i <= n; i += LSOne(i)) {
            for (int j = b; j <= m; j += LSOne(j)) {
                ft[i][j] += v;
            }
        }
    }

private:
    int LSOne(int S) {
        return S & -S;
    }
};

int main() {
    int n = 5; // Tamaño en la dimensión X
    int m = 6; // Tamaño en la dimensión Y

    FenwickTree2D ft(n, m);

    // Realizar ajustes en el árbol
    ft.adjust(2, 3, 5); // Añadir 5 a la posición (2, 3)
    ft.adjust(4, 6, 3); // Añadir 3 a la posición (4, 6)

    // Calcular suma de rangos
    cout << "RSQ(1, 1, 3, 3) = " << ft.rsq(1, 1, 3, 3) << endl;
    cout << "RSQ(2, 2, 5, 5) = " << ft.rsq(2, 2, 5, 5) << endl;
    cout << "RSQ(1, 1, 5, 6) = " << ft.rsq(1, 1, 5, 6) << endl;

    return 0;
}
