#pragma once
#include "OStack.h"

template<class T>
class Stack : public OsnStack<T>
{
public:
    void push(const T& value)
	{
   auto* newNode = new typename OsnStack<T>::Node{value, OsnStack<T>::_head};
      OsnStack<T>::_head = newNode;
    }
    void pop()
	{
      if (!OsnStack<T>::_head)
            throw std::exception();
      OsnStack<T>::_head = OsnStack<T>::_head->next;
    }
};
