#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define CAPACITY_STEP 8

typedef struct
{
  void* start_;
  size_t element_size_;

  size_t length_;
  size_t capacity_;
} DynArray;

//------------------------------------------------------------------------------
///
/// ... initialises the DynArray with the following values: 
/// start_ will be set to a nullpointer. 
/// element_size_ will be initialised with data_size. 
/// length_ will be set to 0. 
/// capacity_ will be set to 0 as well. 
///
/// Every DynArray has to be initialised before it can be used, otherwise 
/// the results are undefined. Initialising an array twice without destroying 
/// it before, will result in undefined behaviour. 
///
/// @param array pointer to the dynamic array
/// @param data_size the memory size of one data element (e.g. 1 for char...)
//
void dynArray_init(DynArray* array, size_t data_size)
{
  // TODO
  return;
}

//------------------------------------------------------------------------------
///
/// ... destroys the DynArray. By this all remaining resources are freed. In 
/// addition the element_size_ will be reset. After destroying a DynArray it 
/// can be initialised again. 
///
/// Not destroying a DynArray can lead to a memory leak. 
///
/// @param array pointer to the dynamic array
//
void dynArray_destroy(DynArray* array)
{
  // TODO
  return;
}

//------------------------------------------------------------------------------
///
/// ... adds one element to the end of the DynArray. If the remaining capacity 
/// is too small, the array increases its size dynamically. 
///
/// If no memory can be allocated, the array stays untouched. In this case 
/// the function will return -1. 
///
/// @param array pointer to the dynamic array
/// @param object pointer to the element, which should be inserted
/// @return 0 on success, -1 on memory failure
//
int dynArray_push_back(DynArray* array, void* object)
{
  // TODO
  return -1;
}

//------------------------------------------------------------------------------
///
/// ... removes the last element from the end of the DynArray. If the array 
/// has too much unused capacity afterwards, the size of the array will be 
/// reduced. 
///
/// If no memory for the shrinking can be allocated, the array stays untouched. 
/// In this case the function will return -1. 
///
/// If the array is empty, the array stays untouched. In this case the function 
/// will return -2. 
///
/// @param array pointer to the dynamic array
/// @return 0 on success, -1 on memory failure, -2 when the array was empty
//
int dynArray_pop_back(DynArray* array)
{
  // TODO
  return -1;
}

//------------------------------------------------------------------------------
///
/// ... returns a pointer to the element at the given position. 
///
/// If the position is out of range, the function will return NULL. 
///
/// If the array changes its size, the returned pointer might get invalidated 
/// as the array might get repositioned in the memory. 
///
/// @param array pointer to the dynamic array
/// @param position position of the element in the array
/// @return pointer to the position on success, NULL on failure
//
void* dynArray_at(DynArray* array, size_t position)
{
  // TODO
  return NULL;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
// Testcases

void test1(void)
{
  printf("Starting testcase 1!\n");
  
  DynArray my_array;
  int* ret_value;
  
  dynArray_init(&my_array, sizeof(int));
  assert(my_array.start_ == NULL && "init: not setting nullptr");
  assert(my_array.element_size_ == 4 && "init: wrong element size");
  assert(my_array.length_ == 0 && "init: no reset of lenght");
  assert(my_array.capacity_ == 0 && "init: not reset of capacity");

  for (size_t i = 0; i < 1025; i++)
  {
    assert(dynArray_push_back(&my_array, &i) == 0 && "Out of memory!");
  }
  assert(my_array.start_ != NULL && "push: not setting ptr properly");
  assert(my_array.length_ == 1025 && "push: lenght incorrect");
  assert(my_array.capacity_ == 1032 && "push: wrong capacity calc");

  ret_value = dynArray_at(&my_array, 1024);
  assert(ret_value != NULL && "at: nullptr when not out of range");
  assert(*ret_value == 1024 && "at: wrong value stored in array");

  for (size_t i = 0; i < 256; i++)
  {
    assert(dynArray_pop_back(&my_array) == 0 && "Out of memory!");
  }
  assert(my_array.start_ != NULL && "pop: not setting ptr properly");
  assert(my_array.length_ == 769 && "pop: lenght incorrect");
  assert(my_array.capacity_ == 776 && "pop: wrong capacity calc");

  assert(dynArray_at(&my_array, 769) == NULL && "at: out of range no nullptr");

  ret_value = dynArray_at(&my_array, 768);
  assert(ret_value != NULL && "at: nullptr when not out of range");
  assert(*ret_value == 768 && "at: wrong value stored in array");

  dynArray_destroy(&my_array);
  assert(my_array.start_ == NULL && "destroy: not setting nullptr");
  assert(my_array.element_size_ == 0 && "destroy: wrong element size");
  assert(my_array.length_ == 0 && "destroy: no reset of lenght");
  assert(my_array.capacity_ == 0 && "destroy: not reset of capacity");

  printf("Testcase 1 passed!\n\n");
}

//------------------------------------------------------------------------------
// TODO write your own testcases to the your implementation here and call
// them in the main function

void test2(void)
{
  // TODO...
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
int main(void)
{
  test1();
  test2();

  return 0;
}
