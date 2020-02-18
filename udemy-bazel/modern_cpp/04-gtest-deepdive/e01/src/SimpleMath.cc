#include "SimpleMath.h"

#include <cassert>

int
SimpleMath::Factorial(int n)
{
    assert(n > -1);
    int result = 1;
    for ( ; n > 0; --n ) {
        result *= n;
    }
    return result;
}
