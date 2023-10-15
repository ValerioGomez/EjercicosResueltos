#include <iostream>

using namespace std;
const int MAXN = 100000; // Tamaño máximo del arreglo
int tree[MAXN + 1];

int LSOne(int S) {
    return (S & -S);
}
void update(int index, int value) {
    for (; index <= MAXN; index += LSOne(index)) {
        tree[index] += value;
    }
}

int query(int index) {
    int sum = 0;
    for (; index > 0; index -= LSOne(index)) {
        sum += tree[index];
    }
    return sum;
}

int rangeQuery(int left, int right) {
    return query(right) - query(left - 1);
}

int main() {
    int n = 100000; // Tamaño máximo del rango

    int intervals[][2] = {
        {1, 10},
        {5, 15},
        {12, 20},
        {8, 18}
    };

    for (int i = 0; i < sizeof(intervals) / sizeof(intervals[0]); i++) {
        update(intervals[i][0], 1);
        update(intervals[i][1] + 1, -1);
    }

    int indexToQuery = 6; // Índice para consultar
    int includedIntervals = query(indexToQuery);

    cout << "Numero de intervalos que incluyen el Indice " << indexToQuery << ": " << includedIntervals << endl;

    return 0;
}
