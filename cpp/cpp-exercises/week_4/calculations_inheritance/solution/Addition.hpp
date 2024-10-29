#ifndef ADDITION_H
#define ADDITION_H

#include "Calculation.hpp"


class Addition : public Calculation
{
  private:

  public:
    Addition(int a, int b) : Calculation{a, b, '+'} {};
    ~Addition() = default;

    int calculate() override;

};

#endif
