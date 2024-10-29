#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NR_AIRPORTS 7
#define ASCII_OFFSET 48
#define MAX_NAME_SIZE 64

typedef struct _Airport_
{
  char name_[MAX_NAME_SIZE];
  struct _Airport_* next_;
} Airport;

Airport* createAirport(char* name)
{
  Airport* new_airport = (Airport*) malloc(sizeof(Airport));
  strcpy(new_airport->name_, name);
  new_airport->next_ = NULL;
  return new_airport;
}

void printFlightroute(Airport* start)
{
  Airport* iterator = start->next_;
  printf("Pilot starts at %s\n", start->name_);
  while(iterator->next_ != NULL)
  {
    printf("Current city %s\n", iterator->name_);
    iterator = iterator->next_;
  }
  printf("Pilot finish travel at %s\n", iterator->name_);
}

void deleteAirports(Airport* start)
{
  Airport* old_iterator = start;
  Airport* new_iterator = start->next_;
  while(new_iterator != NULL)
  {
    free(old_iterator);
    old_iterator = new_iterator;
    new_iterator = new_iterator->next_;
  }
  free(old_iterator);
}

int main(int argc, char** argv)
{
  if(argc != 2)
  {
    printf("Wrong parameter count\n");
    return 1;
  }
  char* airport_names[] = {"Graz","Wien","Berlin","Frankfurt","Miami","Kapstadt","Tokyo"};

  int len = strlen(argv[1]);

  if(len < 2)
  {
    printf("Endpoint required\n");
    return 3;
  }
  int first_airport_id = argv[1][0] - ASCII_OFFSET; // to get from ASCII character to value
  Airport* start_airport = createAirport(airport_names[first_airport_id]);
  Airport* current_airport = start_airport;
  Airport* previous_airport = start_airport;
  for(int counter = 1; counter < len; counter++)
  {
    int new_airport_id = argv[1][counter] - ASCII_OFFSET; // to get from ASCII character to value
    if(new_airport_id >= MAX_NR_AIRPORTS || new_airport_id < 0)
    {
      printf("Only airport IDs from 0 to 6 are valid\n");
      deleteAirports(start_airport);
      return 2;
    }
    current_airport = createAirport(airport_names[new_airport_id]);
    previous_airport->next_ = current_airport; // set the new created airport as next at the previous airport
    previous_airport = current_airport;
  }
  printFlightroute(start_airport);

  deleteAirports(start_airport);
  return 0;
}
