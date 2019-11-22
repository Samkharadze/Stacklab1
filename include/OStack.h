#pragma once

#include <iostream>
#include <type_traits>
#include <exception>
#include <utility>

template<class T>
class OsnStack 
{
protected:
    struct Node
	{
        T _data;
        Node *next;
    };
    Node *_head;
public:
    OsnStack() = default;
 OsnStack(const OsnStack &stack) = delete;
    OsnStack(OsnStack &&stack) noexcept = default;

    OsnStack &operator=(const OsnStack &stack) = delete;
    OsnStack &operator=(OsnStack &&stack) noexcept = default;

    void push(T&& value)
	{
        Node *newNode = new Node{std::forward<T>(value), _head};
        _head = newNode;
    }

    const T& head() const
	{
        if(!_head)
            throw std::exception();
        return _head->_data;
    }
    ~OsnStack()
	{
        while (_head)
		{
            auto *curr = _head;
            _head = curr->next;

            delete curr;
        }
    }
};