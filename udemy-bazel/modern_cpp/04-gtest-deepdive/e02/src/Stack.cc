#include "Stack.h"

void
Stack::push(int element)
{
    _stack.push_back(element);
}

int
Stack::pop()
{
    int data = _stack.back();
    _stack.pop_back();
    return data;
}

int
Stack::size()
{
    return _stack.size();
}