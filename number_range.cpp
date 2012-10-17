#include "number_range.h"

/// @{ number_range_iterator implementation
number_range_iterator::number_range_iterator (const number_range* tgt, int pos):
    _pos(pos),
    _tgt(tgt)
{
}

const number_range_iterator& 
number_range_iterator::operator++ ()
{
    _pos = _tgt->increment(_pos);

    return *this;
}

int
number_range_iterator::operator* () const
{
    return _pos;
}

bool 
number_range_iterator::operator != (const number_range_iterator& other) const
{
    return (_pos != other._pos);
}

/// @}


/// @{ number_range implementation 

const int 
number_range::last() const
{
    return (_end - ((_end - _start) % _step));
}

int 
number_range::increment(int current) const
{
    int next = current + _step;

    if (next <= _end)
        return next;

    return current;
}

number_range_iterator 
number_range::begin () const
{
    return number_range_iterator(this, _start);
}

number_range_iterator 
number_range::end () const
{
    return number_range_iterator(this, last());
}

number_range::number_range(int end):
    _start(0),
    _end(end),
    _step(1)
{
}

number_range::number_range(int start, int end):
    _start(start),
    _end(end),
    _step(1)
{
}

number_range::number_range(int start, int end, int step):
    _start(start),
    _end(end),
    _step(step)
{
}

