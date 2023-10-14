#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    map<string, int> indexMap;
    int currentIndex = 0;  // Remove the extra '.' at the end of this line.
    string cities[] = {"Puno", "Ilave", "Juliaca", "Juli", "Acora"};
    int numCities = sizeof(cities) / sizeof(cities[0]);
    for (int i = 0; i < numCities; i++) {
        const string& city = cities[i];
        // Verificamos si la ciudad ya est� en el mapa.
        if (indexMap.find(city) == indexMap.end()) {
            // Si no est�, le asignamos un nuevo �ndice y la almacenamos en el mapa.
            indexMap[city] = currentIndex++;
        }
    }
    // Ahora puedes acceder al �ndice de cada ciudad de forma eficiente.
    for (int i = 0; i < numCities; i++) {
        const string& city = cities[i];
        int index = indexMap[city];
        cout << city << " tiene el Indice " << index << endl;
    }
    return 0;
}

