#include "Calculator.h"

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
    return left / right;
}

double
Calculator::multiply(double left, double right)
{
    return left * right;
}
