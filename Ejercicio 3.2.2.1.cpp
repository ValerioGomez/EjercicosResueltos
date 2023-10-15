#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;

int row[8], lineCounter;

bool place(int r, int c) {
  for (int prev = 0; prev < c; prev++) {
    if (row[prev] == r || (abs(row[prev] - r) == abs(prev - c))) {
      return false; // share the same row or same diagonal -> infeasible
    }
  }
  return true;
}

void backtrack(int c, int a, int b) {
  if (c == 8) {
    if (row[b] == a) { // candidate solution, (a, b) has 1 queen
      printf("%2d      %d", ++lineCounter, row[0] + 1);
      for (int j = 1; j < 8; j++) {
        printf(" %d", row[j] + 1);
      }
      printf("\n");
    }
  } else if (c == b) {
    if (place(a, c)) { // If we can place the queen in the specified column 'b'
      row[c] = a;
      backtrack(c + 1, a, b);
    }
  } else {
    for (int r = 0; r < 8; r++) {
      if (place(r, c)) {
        row[c] = r;
        backtrack(c + 1, a, b);
      }
    }
  }
}

int main() {
  int a, b;
  printf("Ingrese la fila: ");
  scanf("%d", &a);
  printf("Ingrese la columna: ");
  scanf("%d", &b);
  a--;
  b--; // switch to 0-based indexing
  memset(row, 0, sizeof row);
  lineCounter = 0;
  printf("SOLN       COLUMN\n");
  printf(" #      1 2 3 4 5 6 7 8\n\n");
  backtrack(0, a, b); // generate all possible 8! candidate solutions
  return 0;
}
