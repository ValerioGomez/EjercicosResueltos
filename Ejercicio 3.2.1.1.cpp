#include <iostream>

using namespace std;
int main() {
    int N = 62; 
    int count_fghij = 0;
    int count_abcde = 0;

    cout << "Iterando sobre fghij para N = " << N << endl;
    for (int fghij = 1234; fghij <= 98765 / N; fghij++) {
        for (int abcde = fghij * N; abcde <= 98765; abcde++) {
            count_fghij++;
            int tmp, used = (fghij < 10000);
            tmp = abcde;
            while (tmp) {
                used |= 1 << (tmp % 10);
                tmp /= 10;
            }
            tmp = fghij;
            while (tmp) {
                used |= 1 << (tmp % 10);
                tmp /= 10;
            }
            if (used == (1 << 10) - 1) {
                //cout << abcde << " / " << fghij << " = " << N << endl;
            }
        }
    }
    cout << "Total de iteraciones para fghij: " << count_fghij << endl;

    cout << "\nIterando sobre abcde para N = 62" << endl;
    for (int abcde = 1234; abcde <= 98765; abcde++) {
        for (int fghij = 1234; fghij <= 98765 / N; fghij++) {
            count_abcde++;
            int tmp, used = (fghij < 10000);
            tmp = abcde;
            while (tmp) {
                used |= 1 << (tmp % 10);
                tmp /= 10;
            }
            tmp = fghij;
            while (tmp) {
                used |= 1 << (tmp % 10);
                tmp /= 10;
            }
            if (used == (1 << 10) - 1 && fghij * N == abcde) {
                cout << abcde << " / " << fghij << " = " << N << endl;
            }
        }
    }
    cout << "Total de iteraciones para abcde: " << count_abcde << endl;

    return 0;
}
