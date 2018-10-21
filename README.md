# Bitvector
C++ bitvector class that allocates as few bytes as possible to cover specified amount of bools

I had some issues trying to allow both of these lines to work:

myList[i] = true;

myBool = myList[i];

Because of the Operator Overload not noticing a difference between the 2 functions (prototype is the same except for return type), so in the end, I decided to keep the GETTER and not the SETTER.
