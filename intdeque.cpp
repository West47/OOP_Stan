#include <iostream>
#include"intdeque.hpp"

//Конструктор дека
IntDeque::IntDeque()
{
	left = NULL;
	right = NULL;
	buffer = 0;
}

IntDequeElement::IntDequeElement()
{
    element = 0;
    next = NULL;
    prev = NULL;
}

IntDequeElement::IntDequeElement(int _element) {
    element = _element;
    next = NULL;
    prev = NULL;
}

IntDequeElement::IntDequeElement(int _element, IntDequeElement* _prev, IntDequeElement* _next) {
    element = _element;
    next = _next;
    prev = _prev;
}

void IntDequeElement::SetElement(int _element) {
    element = _element;
}


int& IntDequeElement::GetElement() {
    return element;
}

void IntDequeElement::SetNext(IntDequeElement* _next) {
    next = _next;
}

IntDequeElement* IntDequeElement::GetNext() {
    return next;
}

void IntDequeElement::SetPrev(IntDequeElement* _prev) {
    prev = _prev;
}

IntDequeElement* IntDequeElement::GetPrev() {
    return prev;
}

IntDequeElement* IntDeque::GetLeft()
{
    return left;
}

IntDequeElement* IntDeque::GetRight()
{
    return right;
}

IntDequeElement IntDeque::GetBuffer()
{
    return buffer;
}

void IntDeque::Start()
{
    left = NULL;
    right = NULL;
}

void IntDeque::AddBuffer(int i)
{
    buffer = i;
}

void IntDeque::SaveLeft(IntDequeElement* x) 
{
    left = x;
}

void IntDeque::SaveRight(IntDequeElement* i) 
{
    right = i;
}

void IntDeque::DeleteLeft() 
{
    delete left;
}

void IntDeque::DeleteRight() 
{
    delete right;
}

//Конструктор копирования
IntDeque::IntDeque(IntDeque& _deque) 
{
  buffer = 0;
  left = NULL;
  right = NULL;
  IntDequeElement* ini = _deque.right;
  while (ini != NULL)
    {
      AddLeft(ini->GetElement());
      ini = ini->GetNext();
    }
}

//Добавление элемента слева
int* IntDeque::AddLeft(int element)
{
  IntDequeElement* ini=NULL;
  int k;

  if (left == NULL)
 
    k = 1;
  else
    {
      k = 0;
      ini = left;
    }
  try
    {
      left = new IntDequeElement(element);
    }
  catch (const std::bad_alloc& e)
    {
      std::cout << "Allocation failed: " << e.what() << '\n';
      return NULL;
    }

  buffer = left->GetElement();
  left->SetNext(NULL);

  if (k == 1)
    {
      left->SetPrev(NULL);
      right = left;
    }
  else
    {
      left->SetPrev(ini);
      ini->SetNext(left);
    }
  return &(buffer);
}
//Добавление элемента справа
int* IntDeque::AddRight(int element)
{
  IntDequeElement* ini=NULL;
  int k;

  if (right == NULL)
    k = 1;
  else
    {
      k = 0;
      ini = right;
    }
  try
    {
      right = new IntDequeElement(element);
    }
  catch (const std::bad_alloc& e)
    {
      std::cout << "Allocation failed: " << e.what() << '\n';
      return NULL;
    }

  buffer = right->GetElement();
  right->SetPrev(NULL);

  if (k == 1)
    {
      right->SetNext(NULL);
      left = right;
    }
  else
    {
      right->SetNext(ini);
      ini->SetPrev(right);
    }
  return &(buffer);
}

//Удаление элемента слева
int* IntDeque::RemoveLeft()
{
  IntDequeElement* ini = NULL;
  while (IsEmpty() == 0)
    {
      if (left == NULL)
	return NULL;
      else if (left == right)
	{
	  buffer = right->GetElement();
	  left = NULL;
	  right = NULL;
	  delete (left);
	  return &(buffer);
	}
      else
	{
	  ini = left;
	  left = ini->GetPrev();
	  left->SetNext(NULL);
	  buffer = ini->GetElement();
	  free(ini);
	  return(&buffer);
	}
      return NULL;
    }
}
//Удаление элемента справа
int* IntDeque :: RemoveRight()
{
  IntDequeElement* ini = NULL;
  while (IsEmpty() == 0)
    {
      if (left == NULL)
	return NULL;
      else if (left == right)
	{
	  buffer = right->GetElement();
	  left = NULL;
	  right = NULL;
	  delete (left);
	  return &(buffer);
	}
      else
	{
	  ini = right;
	  right = ini->GetNext();
	  right->SetPrev(NULL);
	  buffer = ini->GetElement();
	  free(ini);
	  return(&buffer);
	}
      return NULL;
    }
};
//Получение элемента из буффера
int IntDeque::GetElement()
{
  return (buffer);
}
//Проверка пустоты дека
int IntDeque::IsEmpty()
{
  if (left!= NULL)
    {
      return 0;
    }
  return 1;
}
//Деструктор дека
IntDeque::~IntDeque()
{
  IntDequeElement* ini;
  while ((left) != (right))
    {
      ini = left;
      left = left->GetPrev();
      delete(ini);
    }
  ini = left;
  delete(ini);
}
int* operator+(int element, IntDeque& deque)

{
  return deque.AddLeft(element);
};
int* operator+ (IntDeque& deque , int _element)
{
    return deque.AddRight(_element);
};
int* IntDeque::operator--()
{
  IntDequeElement* ini = NULL;
  while (IsEmpty() == 0)
    {
      if (left == NULL)
	return NULL;
      else if (left == right)
	{
	  buffer = right->GetElement();
	  left = NULL;
	  right = NULL;
	  delete (left);
	  return &(buffer);
	}
      else
	{
	  ini = left;
	  left = ini->GetPrev();
	  left->SetNext(NULL);
	  buffer = ini->GetElement();
	  free(ini);
	  return(&buffer);
	}
      return NULL;
    }
};
int* IntDeque::operator--(int)
{
  IntDequeElement* ini = NULL;
  while (IsEmpty() == 0)
    {
      if (left == NULL)
	return NULL;
      else if (left == right)
	{
	  buffer = right->GetElement();
	  left = NULL;
	  right = NULL;
	  delete (left);
	  return &(buffer);
	}
      else
	{
	  ini = right;
	  right = ini->GetNext();
	  right->SetPrev(NULL);
	  buffer = ini->GetElement();
	  free(ini);
	  return(&buffer);
	}
      return NULL;
    }
}
IntDeque& IntDeque::operator=(IntDeque& _deque)
{
  IntDequeElement * ini = _deque.right;
  buffer = 0;
  while (IsEmpty() == 0)
    RemoveRight();
  while (ini != NULL)
    {
      AddLeft(ini->GetElement());
      ini = ini->GetNext();
    }
  return *this; 
}
int IntDeque::operator==(IntDeque& _deque)
{
  IntDequeElement* ini01 = _deque.right;
  IntDequeElement* ini02 = right;
  if ((ini01 != NULL)&& (ini02!=NULL))
    {
      if ((ini01->GetElement()) == (ini02->GetElement()))
	{
	  while ((ini01->GetNext() != NULL) && (ini02->GetNext()!=NULL))
	    {
	      ini01 = ini01 -> GetNext();
	      ini02 = ini02->GetNext();
	      if (ini01->GetElement()!=ini02->GetElement())
		return 0;
	    }
	
	  if ((ini01->GetNext() == NULL) && (ini02->GetNext() ==NULL))
	    return 1;
	  else
	    return 0;
	}
    
      else
	return 0;
    }
  else if (ini01 == NULL && ini02 == NULL)
    {
      return 1;
    }
  else
    return 0;
}

