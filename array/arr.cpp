#include "arr.h"
#include <string.h>
#include <stdexcept>

using namespace std;

Array::Array(size_t cap)
    :_arr(new int[cap]),
     _size(0),
     _cap(cap)
{}

Array::Array(int *arr, size_t cap)
    :_arr(new int[cap]),
     _size(cap),
     _cap(cap)
{
    ::memcpy(_arr, arr, cap * sizeof(int));
}

Array::Array(const Array &other)
    :_arr(new int[other._cap]),
     _size(other._size),
     _cap(other._cap)
{
    ::memcpy(_arr, other._arr, _size * sizeof(int));
}

Array::~Array()
{
    delete[] _arr;
}

ostream &operator<< (ostream &os, const Array &a)
{
    os << "[ ";
    for(size_t i = 0; i != a._size - 1; ++ i)
        os << a._arr[i] << ", ";
    os << a._arr[a._size - 1] << " ]";

    return os;
}


Array &Array::operator= (const Array &a)
{
    if(this != &a)
    {
        delete[] _arr;
        _arr = new int[a._cap];
        _size = a._size;
        _cap = a._cap;
        ::memcpy(_arr, a._arr, _size * sizeof(int));
    }

    return *this;
}


Array &Array::operator+= (const Array &a)
{
    int *p = new int[_size + a._size];
    ::memcpy(p, _arr, _size * sizeof(int));
    ::memcpy(p + _size, a._arr, a._size * sizeof(int));

    delete _arr;
    _arr = p;
    _size += a._size;
    _cap = _size;

    return *this;
}


int &Array::operator[] (size_t index)
{
    if(index >= _size)
        throw out_of_range("越界!!");
    return _arr[index];
}


int Array::operator[] (size_t index) const
{
    if(index >= _size)
        throw out_of_range("越界!!");
    return _arr[index];
}

Array operator+ (const Array &a, const Array &b)
{
    Array c(a);
    c += b;
    return c;
}

void Array::put(int val)
{
    if(getSize() == getCap())
        throw out_of_range("数组已满!!");
    _arr[_size ++] = val;
}

int Array::compare(const Array &other) const
{
    size_t i = 0;

    int ret;
    size_t size = (_size < other._size) ? _size : other._size;

    while(i < size)
    {
        ret = _arr[i] - other._arr[i];
        if(ret != 0)
            return ret;
        ++ i;
    }

    if(i != _size)
        return 1;
    if(i != other._size)
        return -1;

    return 0;
}

bool operator< (const Array &a, const Array &b)
{
    return a.compare(b) < 0;
}


bool operator<= (const Array &a, const Array &b)
{
    return a.compare(b) <= 0;
}


bool operator> (const Array &a, const Array &b)
{
    return a.compare(b) > 0;
}


bool operator>= (const Array &a, const Array &b)
{
    return a.compare(b) >= 0;
}


bool operator== (const Array &a, const Array &b)
{
    return a.compare(b) == 0;
}


bool operator!= (const Array &a, const Array &b)
{
    return !(a == b) ;
}
