#ifndef __NUMBER_RANGE_H__
#define __NUMBER_RANGE_H__

/** \file number_range.h python style range() function for C++11
 *  \author stephan steinbach
 */

// forward declaration
class number_range;

/** number_range_iterator an stl style iterator for number range objects */
class number_range_iterator
{
    public:
        number_range_iterator (const number_range* tgt, int pos);

        // operators
        bool operator != (const number_range_iterator& other) const;
        int  operator *  ()                                   const;
        const number_range_iterator& operator++ ();

    private:
        int _pos;
        const number_range* _tgt;
};

/** this class is an iterable object that generates a sequence of numbers
 * example usage:
 * for (auto i : number_range(100))
 *  // i will be a sequence of ints from 0 to 99
 */
class number_range
{
    public:
        // constructors
        number_range(int end);
        number_range(int start, int end);
        number_range(int start, int end, int step);

        number_range_iterator begin () const;
        number_range_iterator end () const;
        int last() const;
        int increment(int current) const;

    private:
        int _start, _end, _step;
};


#endif /* end of include guard: __NUMBER_RANGE_H__ */
