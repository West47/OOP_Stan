#include"intdeque.hpp" 
class IntList : public IntDeque
{
  protected:
    IntDequeElement* deq;
  
    virtual int* AddLeft(int element)
    {
        int* _buffer;
        _buffer = IntDeque::AddLeft(element);
        GoToLeft();
        return _buffer;
    }
    virtual int* AddRight(int element)
    {
        int* _buffer;
        _buffer = IntDeque::AddRight(element);
        GoToRight();
        return _buffer;
    }
  
  public:

  IntList();
    IntList(IntList& plist);
    IntDequeElement* GoToLeft(); 
    IntDequeElement* GoToRight();
    IntDequeElement* GoToNext();
    IntDequeElement* GoToPrev();
    int* Fetch();
    int * Store(int elem);
    int* operator--();
    int* operator--(int); 
    IntList& operator=(IntList& plist);
    int operator==(IntList& plist);
    virtual ~IntList() {};
};
