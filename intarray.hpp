#include "intlist.hpp"

class IntArray :public IntList {
    int first;
    int last;
protected:
    int* AddLeft(int element) {
        if (first > last)
            last = first;
        else first--;
        return IntList::AddLeft(element);
    }
    int* AddRight(int element) {
        last++;
        return IntList::AddRight(element);
    }
public:
    IntArray();
    IntArray(int lb);
    IntArray(IntArray& b);
    IntArray(int lb, int cnt, int val);
    int First();
    int Last();
    int Size();
    IntArray& operator=(IntArray& _array);
    int* operator--();
    int* operator--(int);
    int& operator [](int index);
    virtual ~IntArray() {};
};