//Ejercicio 3.5.1.1 

#include <cstdio>
#include <cstring>
using namespace std;

int main() {
  int i, j, k, TC, M, C;
  int precio[25][25];                     
  bool alcanzable[25][210];    
  TC = 1; // Establece el número de casos de prueba en 1 para el caso de prueba proporcionado
  M = 25; // Establece M en 25 para el caso de prueba proporcionado
  C = 3;  // Establece C en 3 para el caso de prueba proporcionado

  // Precios de las 3 prendas
  precio[0][0] = 3;
  precio[0][1] = 6;
  precio[0][2] = 4;
  precio[0][3] = 8;

  precio[1][0] = 2;
  precio[1][1] = 10;
  precio[1][2] = 6;

  precio[2][0] = 4;
  precio[2][1] = 7;
  precio[2][2] = 3;
  precio[2][3] = 1;
  precio[2][4] = 5;

  memset(alcanzable, false, sizeof alcanzable);         

  for (i = 1; i <= precio[0][0]; i++)       
    if (M - precio[0][i] >= 0)      
      alcanzable[0][M - precio[0][i]] = true;  

  for (i = 1; i < C; i++)                   
    for (j = 0; j < M; j++) if (alcanzable[i - 1][j]) 
      for (k = 1; k <= precio[i][0]; k++) if (j - precio[i][k] >= 0)
        alcanzable[i][j - precio[i][k]] = true;   

  for (j = 0; j <= M && !alcanzable[C - 1][j]; j++);

  if (j == M + 1) printf("no hay solución\n");         
  else            printf("%d\n", M - j);

  return 0;
}
