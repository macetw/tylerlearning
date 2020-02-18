#include "Calculator.h"

#include <exception>

Calculator::Calculator() {}

Calculator::~Calculator() {}

double
Calculator::plus(double left, double right)
{
    return left + right;
}

double
Calculator::minus(double left, double right)
{
    return left - right;
}

double
Calculator::divide(double left, double right)
{
    if (right == 0) {
        throw std::exception();
    }
    return left / right;
}

double
Calculator::multiply(double left, double right)
{
    return left * right;
}
