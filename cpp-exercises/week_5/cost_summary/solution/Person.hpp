//
// WG Costs overview
// Created by David K. (Tutor)
//

#ifndef PERSON_HPP
#define PERSON_HPP


#include <string>
#include <vector>
#include "Cost.hpp"

class Person
{
  private:
    // member variables
    const std::string name_;
    std::vector<Cost*> costs_;
    
    // private member function
    static bool isEqual(const std::string& a, const std::string& b);

  public:
    // Constructor, Copy-Constructor, Destructor
    Person(const std::string &name);
    Person(const Person &p) = delete;
    virtual ~Person();

    // other member functions
    std::string getName() const { return name_; }
    std::vector<Cost*> getCosts() const { return costs_; }

    void addCost(Cost* new_cost);
    void addCost(const std::string& description, size_t price);
    void readCosts();
    void printCosts() const;
    float getFullCosts() const;
};


#endif //PERSON_HPP
