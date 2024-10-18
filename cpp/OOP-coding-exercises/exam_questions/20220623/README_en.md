# Geometric Shapes

> **Note:** For this task, you may use an online IDE that you can access using the following link: <https://www.onlinegdb.com/>

> **Note:** In this example, all data members should be private and all member functions required by the specification should be public. If you want to add members that are not described in the specification, you are allowed to do so. (This might be even necessary.)

> **Note:** The classes must be written in such a way that memory leaks cannot occur.

> **Note:** For mathematical operations, the possibility of an overflow does not need to be considered.

## a) Base class for geometric shapes: `Shape` (5 points)

Write a class for geometric shapes. This class should be called Shape.
Data members

- `id_`: data member of type `size_t`.

### Member functions

- Constructor: Takes no parameters and sets the `id_` attribute of a `Shape` object. The first `Shape` object created should have ID 1. Each additional `Shape` object should have an ID that is 1 greater than that of the latest `Shape` object created.
- Copy constructor: Shall not copy the ID of the `Shape` object to be copied, but assign a new ID to the `Shape` object being created – just like the constructor.
- Copy assignment operator: Shall not be available.
- `area`: Pure virtual, public member function without parameters and a return type of `double`. This member function is intended to return the area of a geometric shape.
- `print`: Public member function without return value and parameters. It prints the text `Shape with ID <ID> is <AREA> units large.\n`, where `<ID>` is replaced by the value of the data member `id_` and `<AREA>` is replaced by the return value of the member function `area`.
- Operator `+`: If two Shape objects are added with `+`, then the sum of the two respective areas shall be returned.

## b) Subclass `Rectangle` (2 points)

`Rectangle` is a subclass of `Shape`.

### Data members

- `width_`: Data member of type `double` which specifies the width of a rectangle.
- `length_`: Data member of type `double` which specifies the length of a rectangle.

### Member functions

- Constructor: Takes two parameters. Sets the  width_ data member to the value of the first parameter and the length_ data member to the value of the second parameter.
- Copy constructor: copies the values of the data members width_ and length_.
- Copy assignment operator: Shall not be available.
- `area`: Returns a rectangle's area which is *w &sdot; l*, where *w* and *l* represent a rectangle's width and length, respectively.
- `print`: This member function works like the print member function in the base class. The only difference is that the first word in the output is not `Shape` but `Rectangle`. Your classes must support polymorphism regarding the print member function. This means that calling the print member function on a pointer to a `Rectangle` object that is stored in a `Shape*` variable shall lead to printing according to the subclass' implementation of the `print` member function (and not to the base class' implementation).