//
// Created by bihonda on 1/02/2024.
//

#ifndef HW_DISJOINTSET_DISJOINSETTREE_H
#define HW_DISJOINTSET_DISJOINSETTREE_H

#include "ds.h"
// no se override las fucniones pq hicimos la logica de DS.h con la de arbol
template <typename T>
class DisjoinSetTree : public DisjoinSet<T> {
public:
    DisjoinSetTree(T* data, int n) : DisjoinSet<T>(vector<T>(data, data + n)) {
        this->makeset();
    }

};




#endif //HW_DISJOINTSET_DISJOINSETTREE_H
