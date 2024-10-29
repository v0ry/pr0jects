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
  for(int person_counter = 1; person_counter < argc; person_counter++)
  {
    // Usually, you would check if the allocation with new was successful.
    // However, we haven't learned yet how this is done, so let's just hope
    // that it will work ;)
    Person* p = new Person(argv[person_counter]);
    persons.push_back(p);
    // TODO: call 'readCosts` member function of each person
    p->readCosts();
  }

  // TODO: call 'printCosts' member function of each person
  for(Person* person : persons)
  {
    person->printCosts();
  }

  // TODO: delete objects on the heap
  for(Person* person : persons)
  {
    delete person;
  }

  return 0;
}
