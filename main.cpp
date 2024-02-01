#include <iostream>
#include <vector>
using namespace std;

#include "ds.h"
#include "DisjoinSetArray.h"
#include "DisjoinSetTree.h"

int main() {
// Datos de prueba
    vector<int> data = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    // Prueba con DisjoinSet
    DisjoinSet<int> disjointSet(data);
    disjointSet.Union(0, 1);
    disjointSet.Union(2, 3);

    cout << "DisjoinSet - Is 1 connected to 2? " << disjointSet.isConnected(1, 2) << endl;
    cout << "DisjoinSet - Is 3 connected to 4? " << disjointSet.isConnected(3, 4) << endl;

    // Prueba con DisjoinSetTree
    int data1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int dataSize2 = sizeof(data1) / sizeof(data1[0]);
    DisjoinSetTree<int> disjointSetTree(data1, dataSize2);
    disjointSetTree.Union(0, 1);
    disjointSetTree.Union(2, 3);

    cout << "DisjoinSetTree - Is 1 connected to 2? " << disjointSetTree.isConnected(1, 2) << endl;
    cout << "DisjoinSetTree - Is 3 connected to 4? " << disjointSetTree.isConnected(3, 4) << endl;

    // Prueba con DisjoinSetArray
    DisjoinSetArray<int> disjointSetArray(data1, dataSize2);
    disjointSetArray.Union(0, 1);
    disjointSetArray.Union(2, 3);

    cout << "DisjoinSetArray - Is 1 connected to 2? " << disjointSetArray.isConnected(1, 2) << endl;
    cout << "DisjoinSetArray - Is 3 connected to 4? " << disjointSetArray.isConnected(3, 4) << endl;

    return 0;
}
