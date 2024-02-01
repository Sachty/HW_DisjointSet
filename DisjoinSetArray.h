//
// Created by bihonda on 1/02/2024.
//

#ifndef HW_DISJOINTSET_DISJOINSETARRAY_H
#define HW_DISJOINTSET_DISJOINSETARRAY_H

#include "ds.h"

template<typename T>
class DisjoinSetArray : public DisjoinSet<T> {
public:
    DisjoinSetArray(T* data, int n) : DisjoinSet<T>(vector<T>(data, data + n)) {
        this->makeset();
    }

    void makeset() override {
        vector<T>& dataVector = this->getData();
        int* parentsArray = this->getParents();
        int* rankArray = this->getRank();

        for (int i = 0; i < dataVector.size(); ++i) {
            parentsArray[i] = i;
            rankArray[i] = 0;
        }
    }

    int Find(int index) override {
        return this->getParents()[index];
    }

    void Union(int x, int y) override {
        int parentX = this->Find(x);
        int parentY = this->Find(y);

        int* parentsArray = this->getParents();
        for (int i = 0; i < this->getData().size(); ++i) {
            if (parentsArray[i] == parentY) {
                parentsArray[i] = parentX;
            }
        }
    }

    bool isConnected(int x, int y) override {
        return this->Find(x) == this->Find(y);
    }

};



#endif //HW_DISJOINTSET_DISJOINSETARRAY_H
