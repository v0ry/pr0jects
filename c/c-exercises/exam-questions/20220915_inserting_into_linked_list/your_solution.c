typedef struct _Item_ {
  char name_[30];
  char brand_[30];
  int price_in_cents_;
  struct _Item_* next_;
} Item;


// TODO: implement the function insertItem here


int main(void)
{
  // we define items and an empty list
  Item cheap = {"Fairphone 4", "Fairphone", 57900, NULL};
  Item middle = {"Pixel 6 Pro", "Google", 89900, NULL};
  Item expensive = {"iPhone 14 Pro Max", "Apple", 157900, NULL};
  
  Item* list = NULL;

  // we call insertItem to insert the smartphones into the list
  insertItem(&middle, &list); // after this call, the list looks like this:
                              // middle --> NULL

  insertItem(&cheap, &list); // after this call, the list looks like this:
                             // cheap --> middle --> NULL

  insertItem(&expensive, &list); // after this call, the list looks like this:
                                 // cheap --> middle --> expensive --> NULL
  
  // TODO: for exercising purposes, define more items and add them to the list.
  //       This way, you can check for example if your program can handle
  //       insertions in the middle of the list correctly.
 
  return 0;
}
