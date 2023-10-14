#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    map<string, int> indexMap;
    int contador = 0;  
    string ciudades[] = {"Puno", "Ilave", "Juliaca", "Juli", "Acora"};
    int numciudades = sizeof(ciudades) / sizeof(ciudades[0]);
    for (int i = 0; i < numciudades; i++) {
        const string& ciudad = ciudades[i];
        // Verificamos si la ciudad ya está en el mapa.
        if (indexMap.find(ciudad) == indexMap.end()) {
            // Si no está, le asignamos un nuevo Indice y la almacenamos en el mapa.
            indexMap[ciudad] = contador++;
        }
    }
    // Ahora puedes acceder al Indice de cada ciudad de forma eficiente.
    for (int i = 0; i < numciudades; i++) {
        const string& ciudad = ciudades[i];
        int index = indexMap[ciudad];
        cout << ciudad << " tiene el Indice " << index << endl;
    }
    return 0;
}

