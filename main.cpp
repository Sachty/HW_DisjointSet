#include <iostream>
#include <vector>
using namespace std;

#include "ds.h"

int main() {
    // Crear un conjunto disjunto con elementos del 0 al 6
    vector<int> elements = {0, 1, 2, 3, 4, 5, 6};
    DisjoinSet<int> disjointSet(elements);

    // imprimir el numero inicial de conjuntos
    cout << "Numero inicial de conjuntos: " << disjointSet.getNumSets() << endl;

    // Unir algunos elementos para formar conjuntos
    disjointSet.Union(0, 1);
    disjointSet.Union(2, 3);
    disjointSet.Union(4, 5);
    disjointSet.Union(1, 2);

    // imprimir el numero actual de conjuntos
    cout << "Numero actual de conjuntos: " << disjointSet.getNumSets() << endl;

    // verificar la conexion entre algunos elementos
    cout << "Estan 0 y 3 conectados: " << (disjointSet.isConnected(0, 3) ? "Si" : "No") << endl;
    cout << "Estan 1 y 4 conectados: " << (disjointSet.isConnected(1, 4) ? "Si" : "No") << endl;

    // Obtener los elementos en el conjunto al que pertenece el elemento 1
    vector<int> elementsSet1 = disjointSet.getElementsSet(1);
    cout << "Elementos en el conjunto al que pertenece el elemento '1': ";
    for (int element : elementsSet1) {
        cout << element << " ";
    }
    cout << endl;

    // Obtener los elementos en el conjunto al que pertenece el elemento 4
    elementsSet1 = disjointSet.getElementsSet(4);
    cout << "Elementos en el conjunto al que pertenece el elemento '4': ";
    for (int element : elementsSet1) {
        cout << element << " ";
    }
    cout << endl;


    // Obtener los elementos en el conjunto al que pertenece el elemento 6
    elementsSet1 = disjointSet.getElementsSet(6);
    cout << "Elementos en el conjunto al que pertenece el elemento '6': ";
    for (int element : elementsSet1) {
        cout << element << " ";
    }
    cout << endl;

    return 0;
}
