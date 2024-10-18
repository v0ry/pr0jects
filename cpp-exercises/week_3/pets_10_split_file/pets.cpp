#include <iostream>

using std::cout;
using std::endl;

enum class Species {DOG, PIG, CAT, BUNNY, UNKNOWN};

struct Pet
{
  private:
    Species species_;
    unsigned age_;
    unsigned id_;
    static unsigned cumulative_number_of_pets_;
    static unsigned current_number_of_pets_;

  public:
    Pet() : species_{Species::UNKNOWN}, age_{0}, id_{cumulative_number_of_pets_}
    {
      cumulative_number_of_pets_++;
      current_number_of_pets_++;
    }

    Pet(Species species) : species_{species}, age_{0}, id_{cumulative_number_of_pets_}
    {
      cumulative_number_of_pets_++;
      current_number_of_pets_++;
    }

    Pet(Species species, unsigned age)
      : species_{species}, age_{age}, id_{cumulative_number_of_pets_}
    {
      cumulative_number_of_pets_++;
      current_number_of_pets_++;
    }

    Pet(Pet& other)
      : species_{other.species_}, age_{other.age_}, id_{cumulative_number_of_pets_}
    {
      cumulative_number_of_pets_++;
      current_number_of_pets_++;
    }

    ~Pet() { current_number_of_pets_--; /* cout << "bye bye" << endl; */ }
    
    unsigned getId() { return id_; }

    static unsigned getCumulativeNumberOfPets() { return cumulative_number_of_pets_; }
    static unsigned getCurrentNumberOfPets() { return current_number_of_pets_; }
    
    void greet()
    {
      if (species_ == Species::DOG)
      {
        cout << "[Dog] Woof woof" << endl;
      }
      else if (species_ == Species::PIG)
      {
        cout << "[Pig] Oink oink" << endl;
      }
      else if (species_ == Species::CAT)
      {
        cout << "[Cat] (silence)" << endl; // cats just ignore others...
      }
      else if (species_ == Species::BUNNY)
      {
        cout << "[Bunny] (silence)" << endl; // bunnies are not that talkative...
      }
      else if (species_ == Species::UNKNOWN)
      {
        cout << "Hmm, what kind of animal is that?" << endl;
      }
      else
      {
        // If we add new possible values to the species type, but forget to consider these values
        // in this function, we will get an error message (if the function is called with such a new value).
        cout << "ERROR: seems like we forgot to consider this species in this function" << endl;
      }
    }

    void happy_birthday()
    {
      cout << "Happy birthday to me :D I am now " << ++age_ << " years old." << endl;
    }
};

unsigned Pet::cumulative_number_of_pets_{ 0 };
unsigned Pet::current_number_of_pets_{ 0 };


int main()
{
  Pet bunny{ Species::BUNNY,   3 };
  bunny.greet();
 
  Pet dog{   Species::DOG,     5 };
  dog.greet();

  {
    Pet pig{   Species::PIG,     0 };
    pig.greet();
    cout << "We currently have " << Pet::getCurrentNumberOfPets() << " pets." << endl;
    cout << "We have seen " << Pet::getCumulativeNumberOfPets() << " pets so far." << endl;
    cout << "... about to call destructor of pet with ID " << pig.getId() << " ..." << endl;
  } // destructor of pig is called because our pig's lifetime ends here :(

  Pet cat{   Species::CAT,     7 };
  cat.greet();

  Pet sheep{ Species::UNKNOWN, 8 };
  sheep.greet();

  Pet dolly{ sheep };
  dolly.greet();

  cout << "We currently have " << Pet::getCurrentNumberOfPets() << " pets." << endl;
  cout << "We have seen " << Pet::getCumulativeNumberOfPets() << " pets so far." << endl;
  cout << "Last pet has the ID " << dolly.getId() << "." << endl;

  if (cat.species_ == Species::CAT) // TODO: use getter to access species_
  {
    cout << "The cat with ID " << cat.getId() << " is " << cat.age_ << " years old.\n"; // TODO: use getter to access age_
  }
  cat.greet();
  cat.happy_birthday();
  
  return 0;
}
