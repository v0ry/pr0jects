//
// WG Costs overview
// Created by David K. (Tutor)
//

#include "Person.hpp"


Person::Person(const std::string &name) : name_(name)
{
}

Person::~Person()
{
  for(Cost* cost : costs_)
    delete cost;
}

void Person::addCost(Cost* new_cost)
{
  costs_.push_back(new_cost);
}

void Person::addCost(const std::string& description, size_t price)
{
  Cost* new_cost = new Cost(description, price);
  costs_.push_back(new_cost);
}

void Person::readCosts()
{
  std::cout << "Add new costs for " << name_ << ":  (type 'exit' in description if finished)" << std::endl;
  while(1)
  {
    std::cout << "Description: ";
    std::string description;
    getline(std::cin, description);
    if(isEqual(description, "exit"))
      break;
    std::cout << "Price: ";
    float price{ 0.0f };
    std::cin >> price;

    while (!std::cin.good())
    {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "[ERROR] Enter Price: ";
      std::cin >> price;
    }

    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // ------------------------------------------------------
    // TODO: create Cost object on heap and add the cost to the 'costs_'-vector of the person

    // this can be done like this
    Cost* newcost = new Cost(description, price);
    addCost(newcost);

    // or like this
    //addCost(description, price);
    // ------------------------------------------------------
  }
}

void Person::printCosts() const
{
  std::cout << "----------------------------------" << std::endl;
  std::cout << "Costs of " << name_ << std::endl;

  // TODO: call the print member function for each cost
  for(Cost* cost : costs_)
  {
    cost->print();
  }
  std::cout << "Total costs of " << name_ << ": " << getFullCosts() << std::endl;
}

float Person::getFullCosts() const
{
  float total_costs{ 0.0f };
  for(const Cost* const c : costs_)
  {
    total_costs += c->getPrice();
  }
  return total_costs;
}



// taken form https://stackoverflow.com/questions/11635/case-insensitive-string-comparison-in-c
// begin
bool Person::isEqual(const std::string& a, const std::string& b)
{
  return std::equal(a.begin(), a.end(),b.begin(), b.end(),[](char a, char b)
  {
    return tolower(a) == tolower(b);
  });
}
// end