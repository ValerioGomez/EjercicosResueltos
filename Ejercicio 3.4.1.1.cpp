#include <iostream>

using namespace std;

bool canMakeChange(int denominations[], int numDenominations, int S) {
    int dp[S + 1];
    for (int i = 0; i <= S; i++) {
        dp[i] = S + 1;
    }
    dp[0] = 0;

    for (int i = 1; i <= S; i++) {
        for (int j = 0; j < numDenominations; j++) {
            int coin = denominations[j];
            if (coin <= i) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    return dp[S] <= S;
}

int main() {
    int S = 0;
    int numDenominations = 5; // Número de denominaciones en ??1
    int denominations[] = {10, 7, 5, 4, 1}; // ??1 = {10, 7, 5, 4, 1}

    cout << "Ingrese la cantidad S: ";
    cin >> S;

    if (canMakeChange(denominations, numDenominations, S)) {
        cout << "Es posible representar " << S << " con las denominaciones proporcionadas." << endl;
    } else {
        cout << "No es posible representar " << S << " con las denominaciones proporcionadas." << endl;
    }

    return 0;
}
