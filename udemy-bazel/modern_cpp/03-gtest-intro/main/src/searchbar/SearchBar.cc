#include "SearchBar.h"

#include <cassert>
#include <sstream>

std::string
SearchBar::process(int left, int right, int op)
{
    assert(op > -1 && op < 4);
    std::stringstream ss;
    ss << left << " " << std::string("+-*/")[op] << " " << right << " = ";
    switch (op)
    {
    case 0:
        ss << calculator.plus(left, right);
        break;

    case 1:
        ss << calculator.minus(left, right);
        break;

    case 2:
        ss << calculator.multiply(left, right);
        break;

    case 3:
        ss << calculator.divide(left, right);
        break;

    default:
        break;
    }
    return ss.str();
}
