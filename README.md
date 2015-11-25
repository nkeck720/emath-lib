# emath-lib
A library of C functions to calculate values in electronic circuits.

# How do I use emath-lib?
You simply place in your source code an include statement to emath.h, and compile emath.c into your program. That's it. An
example:

    foo.c:
    
    #include <stdio.h>
    #include "emath.h"
    
    int main(void) {
      printf("Insert some values to confirm Ohm's law. Format: <current> <voltage> <resistance> \n");
      int i,v,r;
      scanf("%i %i %i", &i, &v, &r);
      int temp = confohmslaw(i, v, r);
      if(temp == -1) {
        printf("Not correct \n");
      } else {
        printf("Correct \n");
      }
      return(0);
    }

And your compile command (in Makefile syntax):

    $(CC) foo.c emath.c $(OBJ)/foo.o -Wall -Wextra
  
This library can also be used in C++ programs.

# What are these strange variable types?

This library also comes with some typedefs: current, voltage, resistance, and power. These are used in place of ints so that
the devs can quickly change variable types. They are also in emath.h, so you can use these types within your program! It
doesn't matter if you use a single function in the library, the typedefs are there for your use. In the case that you need
a value for say, voltage of a node, all you have to do is use the voltage typedef:

    #include "emath.h"
    ...
    int foo(int foobar) {
      ...
      voltage node = ohmslaw(foobar, NULL, 20);
      ...
    }
    ...
    

# Issues and fixes

If you notice a problem with this library, feel free to post an issue, or even start a pull request with a possible fix. As
of the time of this writing, I am still the only developer on this project, so any help at all will be much appreciated.

# Liscense agreement

Please see the LISCENSE file for more info. This library is liscensed under the GNU GPL Version 2.
