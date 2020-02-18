#include "Utils.h"

#include<cassert>

int
SumFrom1To(int n)
{
    assert(n > 0);
    return n * (n + 1) / 2;
}

bool
Negate(bool input)
{
    return !input;
}

bool
CheckEvenOdd(bool checkEven, int element)
{
    return checkEven == (element % 2 == 0);
}
