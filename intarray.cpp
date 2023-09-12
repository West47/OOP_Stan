#include "intarray.hpp"
#include <iostream>

IntArray::IntArray() 
{
    IntList();
    first = 1;
    last = 0;
}

IntArray::IntArray(int lb) 
{
    IntList();
    first = lb;
    last = lb - 1;
}

IntArray::IntArray(IntArray& b) :IntList(b)
{
    first = b.first;
    last = b.last;
}

IntArray::IntArray(int lb, int cnt, int val) 
{
    int i;
    IntList();
    first = lb;
    last = lb - 1;
    for (i = 0; i <= cnt - 1; i++) {
        *this + val;
    }
}

int IntArray::First() 
{
    return first;
}

int IntArray::Last() {
    return last;
}

int IntArray::Size() {
    int i = 0;
    IntArray ini(*this);
    if (ini.GoToLeft()) {
        i = 1;
        while (ini.GoToNext()) {
            i++;
        }
    }
    return i;
}

//удаление слева
int* IntArray::operator--() {
    IntDequeElement* ini = NULL;
    IntDequeElement* l, * r;
    l = GetLeft();
    r = GetRight();
    while (IsEmpty() == 0) {
        if (l == r) {
            IntDeque::AddBuffer((GetLeft()->GetElement()));
            IntDeque::DeleteLeft();
            IntDeque::Start();
            deq = NULL;
            last = first - 1;
            return &(GetLeft()->GetElement());
        }
        else {
            IntDequeElement* ini= NULL;
            ini = GetLeft();
            GoToNext();
            IntDeque::AddBuffer(ini->GetElement());
            IntDeque::SaveLeft(ini->GetPrev());
            GetLeft()->SetNext(NULL);
            first++;
            delete ini;
            GoToLeft();
            return  &(GetLeft()->GetElement());
        }
    }
    return 0;
}

//удаление справа
int* IntArray::operator--(int) {
    IntDequeElement* ini = NULL;
    IntDequeElement* l, * r;
    l = GetLeft();
    r = GetRight();
    while (IsEmpty() == 0) {
        if (l == r) {
            IntDeque::AddBuffer((GetRight()->GetElement()));
            IntDeque::DeleteRight();
            IntDeque::Start();
            deq = NULL;
            last = first - 1;
            return &(GetRight()->GetElement());
        }
        else {
            ini = GetRight();
            IntDeque::AddBuffer((GetRight()->GetElement()));
            IntDeque::SaveRight(ini->GetNext());
            GetRight()->SetPrev(NULL);
            last--;
            delete ini;
            return &GetRight()->GetElement();
        }
    }
    return 0;

}

IntArray& IntArray::operator=(IntArray& parray) {
    IntList::operator=(parray);
    first = parray.First();
    last = parray.Last();
    return *this;
}

int& IntArray::operator [](int index) {
    int i;
    i = first;
    GoToLeft();
    while (i != index) {
        GoToNext();
        i++;
    }
    return deq->GetElement();
}

