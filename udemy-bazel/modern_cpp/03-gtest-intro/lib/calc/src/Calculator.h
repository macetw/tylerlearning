#pragma once

class Calculator
{
public:
    Calculator();
    virtual ~Calculator();

    double
    plus(double left, double right);
    
    // returns left - right
    double
    minus(double left, double right);

    // return left / right
    double
    divide(double left, double right);
    
    double
    multiply(double left, double right);
};

