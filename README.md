# Bitvector
C++ bitvector class that allocates as few bytes as possible to cover specified amount of bools

### Usage
// Allocate 20 bools
BitVector myList(20);

// Set a bool
myList.set(5, true);
// Get a bool
bool myBool = myList[5];

// Has .size() loop support
for(int ii = 0; ii < myList.size(); ++ii);

### Issues

I had some issues trying to allow both of these lines to work:

myList[i] = true;

myBool = myList[i];

Because of the Operator Overload not noticing a difference between the 2 functions (prototype is the same except for return type), so in the end, I decided to keep the GETTER and not the SETTER. So to set a bool, you have to use the set(int, bool) function.
