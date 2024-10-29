//
// WG Costs overview
// Created by David K. (Tutor)
//

#include "Cost.hpp"

Cost::Cost(const std::string& description, float price) : description_{description}, price_{price}
{
}


void Cost::print() const
{
  std::cout << std::fixed << std::setprecision(2) << price_ << " '" << description_ << "'" << std::endl;
}

float Cost::getPrice() const
{
  return price_;
}