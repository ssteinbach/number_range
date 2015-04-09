number_range
============

C++11 implementation/approximation of the python range() function, currently 
implemented only for integers.

C++11 allows for the nice range-for syntax:
```cpp
for (auto i : some_list)
{
    // do stuff
}
```

I liked the range() function from python, so I wrote this to be able to do 
something similar in C++:
```cpp
for (auto i : number_range(start, end, stride))
{
    // do stuff
}
```

contents
========

Includes:
- wscript for building with the waf build system (@TODO: add a makefile)
- wscript builds a pkg-config file
- example/test program (test.cpp)
- small number_range library.

 
example usage
=============

For a lengthier examples, see test.cpp.  The basic calls are:
```cpp
number_range(end); // start=0, stride=1
number_range(start, end); // stride=1
number_range(start, end, stride);
```

Or a bigger example block:
```cpp
#include "number_range.h"

for (auto i : number_range(5,10,2))
{
    std::cerr << i << std::endl;
}

// will print 5, 7, 9
```

Notes
======

This library only makes sense if you prefer this to the standard c++ style loop:

```cpp
for (auto i = 0; i < end ; i++)
{
    // do stuff
}
```

I also use this library as a reference for how to implement iterable things in 
c++.
