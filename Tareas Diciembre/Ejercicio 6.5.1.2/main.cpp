#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int main() {
  char A[20] = "ACAATCC", B[20] = "AGCATGC";
  int n = (int)strlen(A), m = (int)strlen(B);
  int i, j, table[20][20]; 
  memset(table, 0, sizeof table);
  for (i = 1; i <= n; i++)
    table[i][0] = i * -1;
  for (j = 1; j <= m; j++)
    table[0][j] = j * -1;

  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++) {

      table[i][j] = table[i - 1][j - 1] + (A[i - 1] == B[j - 1] ? 2 : -1); 
      if (table[i][j] < table[i - 1][j] - 1) table[i][j] = table[i - 1][j] - 1; 
      if (table[i][j] < table[i][j - 1] - 1) table[i][j] = table[i][j - 1] - 1; 
    }
  i = n;
  j = m;
  while (i > 0 || j > 0) {
    if (i > 0 && j > 0 && table[i][j] == table[i - 1][j - 1] + (A[i - 1] == B[j - 1] ? 2 : -1)) {
      printf("Coincidencia/No Coincidencia: %c %c\n", A[i - 1], B[j - 1]);
      i--;
      j--;
    } else if (i > 0 && table[i][j] == table[i - 1][j] - 1) {
      printf("Borrar: %c\n", A[i - 1]);
      i--;
    } else {
      printf("Insertar: %c\n", B[j - 1]);
      j--;
    }
  }
  return 0;
}

