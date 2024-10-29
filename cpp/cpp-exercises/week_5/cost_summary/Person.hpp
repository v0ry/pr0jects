//
// WG Costs overview
// Created by David K. (Tutor)
//

#ifndef PERSON_HPP
#define PERSON_HPP


#include <string>
#include <vector>
#include "Cost.hpp"

// TODO: there might be a few members missing
class Person
{
  private:


    // private member function
    static bool isEqual(const std::string& a, const std::string& b);

  public:


    void readCosts();
    void printCosts() const;

};


#endif //PERSON_HPP
