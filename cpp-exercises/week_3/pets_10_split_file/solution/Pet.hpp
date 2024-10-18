#ifndef PET_HPP
#define PET_HPP

enum class Species {DOG, PIG, CAT, BUNNY, UNKNOWN};

// MUCH CLEANER NOW :D
struct Pet
{
  private:
    Species species_;
    unsigned age_;
    unsigned id_;
    inline static unsigned cumulative_number_of_pets_{ 0 }; // because of inline we may plae an initial value here ...
    inline static unsigned current_number_of_pets_{ 0 };    // ... and can omit the definition in Pet.cpp

  public:
    Pet();
    Pet(Species species);
    Pet(Species species, unsigned age);
    Pet(Pet& other);
    ~Pet() { current_number_of_pets_--; /* cout << "bye bye" << endl; */ }
    
    Species getSpecies() { return species_; }
    unsigned getAge() { return age_; }
    unsigned getId() { return id_; }

    static unsigned getCumulativeNumberOfPets() { return cumulative_number_of_pets_; }
    static unsigned getCurrentNumberOfPets() { return current_number_of_pets_; }
    
    void greet();
    void happy_birthday();
};

#endif // PET_HPP