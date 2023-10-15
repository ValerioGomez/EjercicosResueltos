//Ejercicio
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAXN = 101;
int A[MAXN], dp[MAXN][MAXN], cost[MAXN][MAXN], next_cut[MAXN][MAXN];

void knuth_yao(int n) {
    // Inicialización
    for (int i = 0; i <= n; i++) {
        dp[i][i + 1] = 0;
        next_cut[i][i + 1] = i + 1;
    }

    for (int len = 2; len <= n; len++) {
        for (int i = 0; i + len <= n; i++) {
            int j = i + len;
            dp[i][j] = 1e9;
            for (int k = next_cut[i][j - 1]; k <= next_cut[i + 1][j]; k++) {
                int val = dp[i][k] + dp[k][j] + cost[i][j];
                if (val < dp[i][j]) {
                    dp[i][j] = val;
                    next_cut[i][j] = k;
                }
            }
        }
    }
}

int main() {
    int l, n;
    while (true) {
        cin >> l;
        if (l == 0) break;
        cin >> n;

        A[0] = 0;
        for (int i = 1; i <= n; i++) {
            cin >> A[i];
        }
        A[n + 1] = l;

        // Calcular costos
        for (int i = 0; i <= n; i++) {
            for (int j = i + 1; j <= n + 1; j++) {
                cost[i][j] = A[j] - A[i];
            }
        }

        memset(dp, 0, sizeof(dp));
        knuth_yao(n + 1);

        cout << "The minimum cutting is " << dp[0][n + 1] << "." << endl;
    }

    return 0;
}
