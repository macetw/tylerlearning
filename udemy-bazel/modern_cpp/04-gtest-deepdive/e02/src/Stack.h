#pragma once

#include <vector>

class Stack
{
public:
    void
    push(int element);

    int
    pop();

    int
    size();

private:
    std::vector<int> _stack;
};
