//Ejercicio 3.5.2.7* 
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;

int i, j, TC, xsize, ysize, n, x[11], y[11], dist[11][11], memo[11][1 << 11];

int tsp(int pos, int bitmask) {
  if (bitmask == (1 << (n + 1)) - 1)
    return dist[pos][0];
  if (memo[pos][bitmask] != -1)
    return memo[pos][bitmask];

  int ans = 2000000000;
  for (int nxt = 0; nxt <= n; nxt++)
    if (nxt != pos && !(bitmask & (1 << nxt)))
      ans = min(ans, dist[pos][nxt] + tsp(nxt, bitmask | (1 << nxt)));
  return memo[pos][bitmask] = ans;
}

int main() {
  TC = 1; // Número de casos de prueba
  xsize = 10; // Tamaño en x (no utilizado)
  ysize = 10; // Tamaño en y (no utilizado)

  n = 5; // Número de ubicaciones (cambiar según sea necesario)
  x[0] = 0; // Coordenada x de la ubicación 0
  y[0] = 0; // Coordenada y de la ubicación 0

  // Coordenadas de las ubicaciones, por ejemplo:
  x[1] = 1;
  y[1] = 2;
  x[2] = 3;
  y[2] = 4;
  x[3] = 5;
  y[3] = 6;
  x[4] = 7;
  y[4] = 8;
  x[5] = 9;
  y[5] = 10;

  for (i = 0; i <= n; i++) {
    for (j = i; j <= n; j++) {
      dist[i][j] = abs(x[i] - x[j]) + abs(y[i] - y[j]);
      dist[j][i] = dist[i][j];
    }
  }

  memset(memo, -1, sizeof memo);
  printf("La longitud del camino mas corto es %d\n", tsp(0, 1));

  return 0;
}
