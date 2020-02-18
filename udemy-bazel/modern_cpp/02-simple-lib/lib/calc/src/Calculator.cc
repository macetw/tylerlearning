#include "calc/Calculator.h"

Calculator::Calculator() 
{
    adder = new Adder;
}

Calculator::~Calculator()
{
    delete adder;
    adder = nullptr;
}

double
Calculator::plus(double left, double right)
{
    return adder->plus(left, right);
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
