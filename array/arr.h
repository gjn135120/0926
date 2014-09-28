#ifndef ARRAY_H
#define ARRAY_H 
#include <iostream>


class Array
{
    friend std::ostream &operator<< (std::ostream &os, const Array &a);
    
    friend Array operator+ (const Array &a, const Array &b);

    friend bool operator< (const Array &a, const Array &b);
    friend bool operator<= (const Array &a, const Array &b);
    friend bool operator> (const Array &a, const Array &b);
    friend bool operator>= (const Array &a, const Array &b);
    friend bool operator== (const Array &a, const Array &b);
    friend bool operator!= (const Array &a, const Array &b);

public:

    Array(size_t cap);
    Array(int *arr, size_t cap);
    Array(const Array &other);
    ~Array();

    Array &operator= (const Array &a);
    Array &operator+= (const Array &a);

    int &operator[] (size_t index);
    int operator[] (size_t index) const;

    void put(int val);

    size_t getSize() const
    { return _size; }

    size_t getCap() const
    { return _cap; }

private:

    int compare(const Array &other) const;

    int *_arr;

    size_t _size;
    size_t _cap;

};


#endif  /*ARRAY_H*/
