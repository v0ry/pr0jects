#ifndef CALCULATION_H
#define CALCULATION_H

#include <string>

using std::string;

class Calculation
{
  protected:
    int a_;
    int b_;
    char operator_symbol_;

  public:
    Calculation(int a, int b, char operator_symbol) : a_{a}, b_{b}, operator_symbol_{operator_symbol} {};
    virtual ~Calculation() = default;

    virtual int calculate() = 0;

    char getOperatorSymbol() {return operator_symbol_;};
    int getA() {return a_;};
    int getB() {return b_;};


};

#endif
