#include <string>
#include <cmath>
#include <iostream>
#include "Fraction.hpp"
#include "DivideByZeroException.hpp"

Fraction::Fraction(int nominator, int denominator) :
  nominator_(nominator), denominator_(denominator)
{
  if (denominator_ == 0)
  {
    throw DivideByZeroException("0 in the denominator invalid!\n");
  }
  reduceFraction();
}

Fraction::Fraction(const Fraction& rhs) :
  nominator_(rhs.nominator_), denominator_(rhs.denominator_)
{
}

Fraction& Fraction::operator=(const Fraction& rhs)
{
  if (this != &rhs)
  {
    nominator_ = rhs.nominator_;
    denominator_ = rhs.denominator_;
  }

  return *this;
}

void Fraction::reduceFraction()
{
  int divisor_save = 1;
  for (int divisor = 1; divisor <= std::abs(nominator_) && divisor <= std::abs(denominator_); divisor++)
  {
    if (nominator_ % divisor == 0 && denominator_ % divisor == 0)
    {
      divisor_save = divisor;
    }
  }
  nominator_ /= divisor_save;
  denominator_ /= divisor_save;

  if (denominator_ < 0)
  {
    nominator_ = -nominator_;
    denominator_ = -denominator_;
  }
  if (nominator_ == 0)
  {
    denominator_ = 1;
  }
}

Fraction Fraction::operator+(const Fraction& rhs) const
{
  return Fraction(nominator_ * rhs.denominator_ + rhs.nominator_ * denominator_, denominator_ * rhs.denominator_);
}

Fraction& Fraction::operator+=(const Fraction& rhs)
{
  nominator_ = nominator_ * rhs.denominator_ + rhs.nominator_ * denominator_;
  denominator_ = denominator_ * rhs.denominator_;
  reduceFraction();
  return *this;
}

Fraction Fraction::operator+(const int rhs) const
{
  return Fraction(nominator_ + rhs * denominator_, denominator_);
}

Fraction& Fraction::operator++()
{
  nominator_ += denominator_;
  return *this;
}

Fraction Fraction::operator++(int)
{
  Fraction return_value = *this;
  nominator_ += denominator_;
  return return_value;
}

Fraction Fraction::operator-() const
{
  return Fraction(-nominator_, denominator_);
}

Fraction Fraction::operator~() const
{
  return Fraction(denominator_, nominator_);
}

Fraction& Fraction::operator/=(const Fraction& rhs)
{
  if (rhs.nominator_ == 0)
  {
    throw DivideByZeroException("Dividing by 0 not valid!\n");
  }

  int new_nominator = nominator_ * rhs.denominator_;
  denominator_ = denominator_ * rhs.nominator_;
  nominator_ = new_nominator;
  reduceFraction();

  return *this;
}

Fraction::operator bool() const
{
  return nominator_ != 0;
}

bool Fraction::operator!() const
{
  return nominator_ == 0;
}

bool Fraction::operator==(const Fraction& rhs) const
{
  return nominator_ == rhs.nominator_ && denominator_ == rhs.denominator_;
}

bool Fraction::operator!=(const Fraction& rhs) const
{
  return nominator_ != rhs.nominator_ || denominator_ != rhs.denominator_;
}

bool Fraction::operator<(const Fraction& rhs) const
{
  return value() < rhs.value();
}

bool Fraction::operator<=(const Fraction& rhs) const
{
  return value() <= rhs.value() || operator==(rhs);
}

std::ostream& operator<<(std::ostream& out, const Fraction& rhs)
{
  out << rhs.getNominator() << " / " << rhs.getDenominator() << std::endl;
  return out;
}

Fraction operator+(const int lhs, const Fraction& rhs)
{
  return Fraction(lhs * rhs.getDenominator() + rhs.getNominator(), rhs.getDenominator());
}
