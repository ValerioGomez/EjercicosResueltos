#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int digits[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    do {
        int abcde = 0;
        for (int i = 0; i < 5; i++) {
            abcde = abcde * 10 + digits[i];
        }
        int fghij = 0;
        for (int i = 5; i < 10; i++) {
            fghij = fghij * 10 + digits[i];
        }

        if (abcde % fghij == 0 && abcde / fghij >= 2 && abcde / fghij <= 79) {
            cout << abcde << " / " << fghij << " = " << abcde / fghij << endl;
        }
    } while (next_permutation(digits, digits + 10));

    return 0;
}
