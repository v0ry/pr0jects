#include <stdio.h>

typedef struct _Item_
{
  char name_[20];
  char brand_[20];
  unsigned price_in_cents_;
  struct _Item_ *next_;
} Item;

// TODO: implement the function insertItem here
void insertItem(Item* new_item, Item** list)
{
  Item* current_item = *list;
  Item* previous_item = NULL;
  while (current_item != NULL && current_item->price_in_cents_ <= new_item->price_in_cents_)
  {
    previous_item = current_item;
    current_item = current_item->next_;
  }
  if (previous_item == NULL) // insert at the start of the list
  {
    new_item->next_ = *list;
    *list = new_item;
  }
  else // insert in the middle or at the end of the list
  {
    previous_item->next_ = new_item;
    new_item->next_ = current_item;
  }
}

int main()
{
  // define items and form the list
  Item cheap = {"Fairphone 4", "Fairphone", 57900, NULL};
  Item middle = {"Pixel 6 Pro", "Google", 89900, NULL};
  Item upper = {"Galaxy S22", "Samsung", 100000, NULL}; // one more item compared to the exam
  Item expensive = {"iPhone 14 Pro Max", "Apple", 157900, NULL};

  Item *list = NULL;

  insertItem(&middle, &list); // after this call, list looks like this:
                              // middle --> NULL

  insertItem(&cheap, &list); // after this call, list looks like this:
                             // cheap --> middle --> NULL

  insertItem(&expensive, &list); // after this call, list looks like this:
                                 // cheap --> middle --> expensive --> NULL

  insertItem(&upper, &list); // after this call, list looks like this:
                             // cheap --> middle --> upper --> expensive --> NULL

  while (list)
  {
    printf("%6d - %s\n", list->price_in_cents_, list->name_);
    list = list->next_;
  }

  return 0;
}
