// Urheber: Manuel Hofer (Original-Abgabe von der Prüfung)
// Der übernommene Code befindet sich zwischen dem begin- und end-Kommentar.
// Der Code wurde lediglich um Kommentare von Aleksandar Karakaš ergänzt, um
// ihn für alle, die noch wenig Erfahrung im Umgang mit verketteten Listen
// haben, noch verständlicher zu machen.

typedef struct _Item_ {
  char name_[30];
  char brand_[30];
  int price_in_cents_;
  struct _Item_* next_;
} Item;


// TODO: implement the function insertItem here
// begin
void insertItem(Item* new_item, Item** list)
{   // if the list is empty, then new_item shall be the first item in the list
    if ((*list) == NULL)
    {
        (*list) = new_item;
        return;
    }
    // if new_item is the cheapest item, then it shall be inserted at the start of the list
    if ((*list)->price_in_cents_ > new_item->price_in_cents_)
    {
        new_item->next_ = (*list);
        (*list) = new_item;
        return;
    }
    
    Item* next_item = (*list);  
    while (next_item->next_ != NULL) // iterate until the end of the list
    {   // if the correct position for new_item is found ...
        if (next_item->next_->price_in_cents_ > new_item->price_in_cents_)
        {   // then insert new_item at this position and return.
            new_item->next_ = next_item->next_;
            next_item->next_ = new_item;
            return;
        }
        // otherwise go to the next item in the list.
        next_item = next_item->next_;
    }
    // if we rached the end of the list, insert new_item at the end of the list.
    if (next_item->next_ == NULL) // (this check is not necessary, but maybe helps to understand what the code does)
        next_item->next_ = new_item;
}
// end

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
