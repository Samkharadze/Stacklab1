#pragma once
#include "OStack.h"

template<class T>
class StackT : public OsnStack<T>
{
public:
    template <typename ... Args>
    void push_emplace(Args&&... value)
	{
   auto *_next = OsnStack<T>::_head;
   OsnStack<T>::_head = new typename OsnStack<T>::Node{std::forward<Args>(value)..., _next};
    }

    T pop()
	{
      if (!OsnStack<T>::_head)
      throw std::exception();
      T data = StackMain<T>::_head->_data;
      OsnStack<T>::_head = OsnStack<T>::_head->next;
        return data;
    }
};