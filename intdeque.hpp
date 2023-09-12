#include <iostream>

class IntDequeElement
{
    int element;
    IntDequeElement* next;
    IntDequeElement* prev;
public:
    IntDequeElement();
    IntDequeElement(int _element);
    IntDequeElement(int _element, IntDequeElement* _prev, IntDequeElement* _next);
    void SetElement(int _element);
    int& GetElement();
    void SetNext(IntDequeElement* _next);
    IntDequeElement* GetNext();
    void SetPrev(IntDequeElement* _prev);
    IntDequeElement* GetPrev();

};
class IntDeque
{
private:
    IntDequeElement* left;
    IntDequeElement* right;
    int buffer;

protected:
        IntDequeElement* GetLeft();
        IntDequeElement* GetRight();
        IntDequeElement GetBuffer();
        void Start();
        void AddBuffer (int x);
        void SaveLeft(IntDequeElement* x);
        void SaveRight(IntDequeElement* x);
        void DeleteLeft();
        void DeleteRight();
public:
    IntDeque();

    IntDeque(IntDeque& _deque);

    virtual int* AddLeft(int element);

    virtual int* AddRight(int element);

    int* RemoveLeft();

    int* RemoveRight();

    int GetElement();

    int IsEmpty();

    //int* operator+(int element, IntDeque& deque);

    //int* operator+(int _element);

    int* operator--();

    int* operator--(int);

    IntDeque& operator=(IntDeque& _deque);

    int operator==(IntDeque& _deque);



    ~IntDeque();

};

int* operator+(int element, IntDeque& deque);
int* operator+(IntDeque& deque,int _element);