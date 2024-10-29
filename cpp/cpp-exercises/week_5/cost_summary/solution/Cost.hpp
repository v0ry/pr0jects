//
// WG Costs overview
// Created by David K. (Tutor)
//

#ifndef COST_HPP
#define COST_HPP

#include <iostream>
#include <iomanip>

class Cost
{
  private:
    std::string description_;
    float price_;
  public:

    // Constructor, CCtor, Destructor
    Cost(const std::string& description, float price);
    Cost(const Cost &src) = delete;
    virtual ~Cost() = default;

    // Getter methods for private attributes
    float getPrice() const;

    // class methods
    void print() const;
};

#endif //COST_HPP
