//
// Created by allxs on 31/01/2024.
//

#ifndef HW_DISJOINTSET_DS_H
#define HW_DISJOINTSET_DS_H

#include <iostream>
#include <vector>
using namespace std;

template<typename T>

class DisjoinSet{
protected:
    vector<T>& getData() {
        return data;
    }

    int* getParents() {
        return parents;
    }

    int* getRank() {
        return rank;
    }

private:
    vector<T> data;
    int* parents;
    int* rank;
    int numSets;
public:
    DisjoinSet(vector<T> data){
        this->data = data;
        this->parents = new int[data.size()];
        this->rank = new int[data.size()];
        this->numSets = data.size();  // Inicialmente, cada elemento está en su propio conjunto
        makeset();
    }

    // METODOS -----------------
    // Inicializa los conjuntos, asignando a cada elemento su propio conjunto
    virtual void makeset(){
        for(int i=0;i<data.size();i++){
            this->parents[i] = i;
            this->rank[i] = 0;
        }
    }

    // Encuentra el representante (raíz) del conjunto al que pertenece el elemento en la posición 'index'
    virtual int Find(int index){
        if(index == parents[index]) return index;
        else return Find(parents[index]);
    }

    // Une los conjuntos a los que pertenecen 'x' e 'y'
    virtual void Union(int x, int y){
        int rootX = Find(x);
        int rootY = Find(y);

        if(rootX != rootY){
            // Uniéndolos según la altura (rank) para mantener el árbol equilibrado
            if(rank[rootX] < rank[rootY])
                parents[rootX] = rootY;
            else if(rank[rootX] > rank[rootY])
                parents[rootY] = rootX;
            else {
                // Ambos tienen la misma altura, incrementamos la altura de 'rootX'
                // y unimos 'rootY' bajo 'rootX'
                parents[rootY] = rootX;
                rank[rootX]++;
            }

            numSets--;  // Reducir el número de conjuntos después de la unión
        }
    }

    // Verifica si 'x' e 'y' están en el mismo conjunto
    virtual bool isConnected(int x, int y){
        return Find(x) == Find(y);
    }

    // Obtiene todos los elementos en el conjunto al que pertenece el elemento en la posición 'index'
    vector<T> getElementsSet(int index){
        vector<T> resultSet;
        int root = Find(index);

        // Iterar sobre todos los elementos y agregar aquellos que tienen el mismo representante (raíz)
        for (int i = 0; i < data.size(); ++i) {
            if (Find(i) == root) {
                resultSet.push_back(data[i]);
            }
        }

        return resultSet;
    }

    // obtiene el número actual de conjuntos
    int getNumSets(){
        return numSets;
    }

    // DESTRUCTOR -----------------
    // liberar la memoria asignada dinámicamente
    virtual ~DisjoinSet(){
        delete[] parents;
        delete[] rank;
    }



};

#endif //HW_DISJOINTSET_DS_H
