#include"intlist.hpp"
#include <iostream>

IntList::IntList() 
{
	IntDeque();
    deq = NULL;
}

IntList::IntList(IntList& plist) 
{
    int counter, i, k;
    IntDequeElement* n0, n1;
    n0 = deq;
    deq = NULL;
    i = 1;
    counter = 0;
    IntDequeElement* fst = plist.GetLeft();
    IntDequeElement* ini = plist.deq;
    while (fst != NULL)
    {
        if (fst == ini)
        {
            IntDeque::AddRight(fst->GetElement());
            fst = fst->GetPrev();
            counter = i;
            this->deq = GetLeft();
        }
        else
        {
            IntDeque::AddRight(fst->GetElement());
            fst = fst->GetPrev();
            i++;
        }
    }
    for (i = 1; i < counter; i++)
    {
        this->deq = deq->GetPrev();
    }
}

IntDequeElement* IntList::GoToLeft()
{
    deq = GetLeft();
    return (deq);
}

IntDequeElement * IntList::GoToRight()
{
    deq = GetRight();
    return (deq);
}

IntDequeElement * IntList::GoToNext()
{
    if ((deq == GetRight()) || (deq == NULL))
    {
        return NULL;
    }
    else
    {
        deq = deq->GetPrev();
        return (deq);
    }
}

IntDequeElement * IntList::GoToPrev()
{
    if ((deq == GetLeft()) || (deq == NULL))
    {
        return NULL;
    }
    else
    {
        deq = deq->GetNext();
        return (deq);
    }
}

int* IntList::Fetch()
{
    if (deq == NULL)
    {
        return NULL;
    }
    else
    {
        IntDeque::AddBuffer(deq->GetElement());
        return &deq->GetElement();
    }
}

int * IntList::Store(int elem)
{
    if (deq != NULL)
    {
        deq->SetElement(elem);
        IntDeque::AddBuffer(deq->GetElement());
        return &deq->GetElement();
    }
    else
    {
        return NULL;
    }
}

int* IntList::operator--()
{
    int* tmp_int;
    tmp_int = IntDeque::operator--();
    deq = GetLeft();
    return tmp_int;
}

int* IntList::operator--(int)
{
    int* tmp_int;
    tmp_int = IntDeque::operator--(1);
    deq = GetRight();
    return tmp_int;
}


IntList& IntList::operator=(IntList& plist) 
{
    int count, count_temp, i;
    IntDeque::Start();
    deq = NULL;
    count = 1;
    count_temp = 0;
    IntDequeElement* fst = plist.GetLeft();
    IntDequeElement* ini = plist.deq;
    while (fst != NULL)
    {
        if (fst == ini)
        {
            IntDeque::AddRight(fst->GetElement());
            fst = fst->GetPrev();
            count_temp = count;
            this->deq = GetRight();
        }
        else
        {
            IntDeque::AddRight(fst->GetElement());
            fst = fst->GetPrev();
            count++;
        }
    }
    return *this;
}

int IntList::operator==(IntList& plist) 
{
    IntDequeElement* ini01 = plist.GetLeft();
    IntDequeElement* ini02 = GetLeft();
    /*
    if ((deq == GetLeft() && plist.deq != plist.GetLeft()) || (deq != GetLeft() && plist.deq == plist.GetLeft()))
    {
        return 0;
    }
    */
    if (ini01 != NULL && ini02 != NULL)
      {
        int itemp01, itemp02;
        itemp01 = plist.GetLeft()->GetElement();
        itemp02 = GetLeft()->GetElement();
        if (itemp01 == itemp02)
	  {
            while (ini01->GetPrev() != NULL && ini02->GetPrev() != NULL)
	      {
                ini01 = ini01->GetPrev();
                ini02 = ini02->GetPrev();
                if ((deq == ini02 && plist.deq != ini01) || (deq != ini02 && plist.deq == ini01))
		  {
                    return 0;
		  }
                itemp01 = ini01->GetElement();
                itemp02 = ini02->GetElement();
                if (itemp01 != itemp02)
		  {
                    return 0;
		  }
	      }
            if (ini01->GetPrev() == NULL && ini02->GetPrev() == NULL)
	      {
                return 1;
	      }
            else
	      {
                return 0;
	      }
	  }
        else
	  {
            return 0;
	  }
      }
    else if (ini01 == NULL && ini01 == NULL)
      {
        return 1;
      }
    else
      {
        return 0;
      }
}
