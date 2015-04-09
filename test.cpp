#include <iostream>

/// \file test.cpp example uses of the number_range iterator.

#include "number_range.h"

int
main(int argc, const char *argv[])
{
    for (auto i : number_range(10))
    {
        std::cerr << i << std::endl;
    }

    std::cerr << "-------" << std::endl;

    for (auto i : number_range(5,10))
    {
        std::cerr << i << std::endl;
    }

    std::cerr << "-------" << std::endl;

    int i_check = 0;
    for (auto i : number_range(5,10,2))
    {
        std::cerr << i << std::endl;

        i_check++;
        if (i_check>10)
        {
            std::cerr << "broke" << std::endl;
            return 1;
        }
    }

    std::cerr << "-------" << std::endl;

    auto thing = number_range(10);
    auto start = thing.begin();
    std::cerr << "start:" << *start << std::endl;
    auto end   = thing.end();
    std::cerr << "start != end: " << (start != end) << std::endl;

    std::cerr << "end:" << *end << std::endl;

    return 0;
}
