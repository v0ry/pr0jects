//
// WG Costs overview
// Created by David K. (Tutor)
// if you found an error pls contact me directly or via TeachCenter
//

#include <iostream>
#include "Person.hpp"


int main(int argc, char* argv[])
{
  if(argc < 3)
  {
    printf("Usage ./<filename> [Person1] [Person2] ...");
    return -1;
  }

  // TODO: create Person objects on the heap using the names
  // contained in argv. Put pointers to these newly created
  // Person objects into an std::vector called persons.
  std::vector<Person*> persons;
  for (int arg_index{ 1 }; arg_index < argc; arg_index++)
  {
    persons.push_back( new Person(argv[arg_index]) );
  }
  // TODO: call 'readCosts` member function of each person
  for (Person* p : persons)
  {
    p->readCosts();
  }

  // TODO: call 'printCosts' member function of each person
  for (const Person* p : persons)
  {
    p->printCosts();
  }

  // TODO: delete objects on the heap
  for (auto& p : persons)
  {
    delete p;
  }

  return 0;
}
