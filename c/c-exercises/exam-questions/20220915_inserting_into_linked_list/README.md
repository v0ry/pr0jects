# Inserting into a Linked List

> **Note:** For this task, you may use an online IDE that you can access using the following link: <https://www.onlinegdb.com/>

In the program below, items (in this example the items are smartphones) are saved in a singly linked list. An item is represented as a struct called `Item` which contains the following members:

- `char name_[30]`: the name of the item
- `char brand_[30]`: the maker of the item
- `unsigned price_in_cents_`: the price of the item (in Euro cents instead of Euros, to prevent rounding errors)
- `Item* next_`: a pointer to the next item in the list

In the program, the list of items must always be sorted in ascending order according to the items' price. This means that a list with items always starts with the cheapest item and each further item fulfills the requirement that it is at least as expensive as the preceding item in the list.

Your task: Write a function called `insertItem` which inserts a new item into a list.

The function `insertItem` has two parameters:

- `Item* new_item`: A pointer to the item to insert. `insertItem` can use this pointer for the insertion. In particular, it is not necessary to reserve memory (for example using `malloc`).
- `Item** list`: The list in which the new item is to be inserted.

The function `insertItem` has no return value.

In the function `insertItem` it can be assumed that the list `list` – in case it is not empty – is sorted correctly. The insertion of a new item must be performed in such a way that the list stays sorted. (The case that the item that is being inserted is as expensive as an item that is already in the list, does not have to be considered. This case will not affect your grade.)

In the `main` function, three items (smartphones produced by Fairphone (variable `cheap`), Google (variable `middle`) und Apple (variable `expensive`)) as well as an empty list (variable `list`) are defined. The three items are inserted into the list by calling `insertItem` three times. (First, the smartphone produced by Google is added. Then, the Fairphone is inserted followed by the Apple smartphone.)

> **Attention:** Please note that the function `insertItem` does not only have to work correctly with the items in the program below. The function must also work correctly when given other items or when being called an arbitrary number of times.

```c
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
 
  return 0;
}
```