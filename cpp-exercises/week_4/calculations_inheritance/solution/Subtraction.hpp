#ifndef SUBTRACTION_H
#define SUBTRACTION_H

#include "Calculation.hpp"

class Subtraction : public Calculation
{
  private:

  public:
    Subtraction(int a, int b) : Calculation{a, b, '-'} {};
    ~Subtraction() = default;

    int calculate() override;

};


#endif
