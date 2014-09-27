#include "string.h"
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

String::String()
    :_str(new char[1])
{
    *_str = 0;
}

String::String(const char *s)
    :_str(new char[strlen(s) + 1])
{
    ::strcpy(_str, s);
}

String::String(const String &s)
    :_str(new char[s.size() + 1])
{
    ::strcpy(_str, s._str);
}

String::~String()
{
    delete[] _str;
}

String &String::operator= (const String &s)
{
    if(this != &s)
    {
        delete[] _str;
        _str = new char[s.size() + 1];
        ::strcpy(_str, s._str);
    }

    return *this;
}

String &String::operator= (const char *s)
{
    if(_str != s)
    {
        delete _str;
        _str = new char[strlen(s) + 1];
        ::strcpy(_str, s);
    }

    return *this;
}

void String::debug() const
{
    cout << _str << endl;
}

String &String::operator+= (const String &s)
{
    char *t = new char[size() + s.size() + 1];
    ::strcpy(t, _str);
    ::strcat(t, s._str);
    
    delete[] _str;
    _str = t;
    return *this;
}


String &String::operator+= (const char *s)
{
    char *t = new char[size() + strlen(s) + 1];
    ::strcpy(t, _str);
    ::strcat(t, s);
    delete[] _str;
    _str = t;

    return *this;
}


String operator+ (const String &a, const String &b)
{
    String t(a);
    t += b;

    return t;
}

String operator+ (const String &a, const char *b)
{
    return a + String(b);
}



String operator+ (const char *a, const String &b)
{
    return String(a) + b;
}


bool operator< (const String &a, const String &b)
{
    return ::strcmp(a._str, b._str) < 0;
}

bool operator<= (const String &a, const String &b)
{
    return !(a > b);
}

bool operator> (const String &a, const String &b)
{
    return b < a;
}

bool operator>= (const String &a, const String &b)
{
    return !( a < b);
}

bool operator== (const String &a, const String &b)
{
    return ::strcmp(a._str, b._str) == 0;
}

bool operator!= (const String &a, const String &b)
{
    return !(a == b);
}


char &String::operator[] (size_t index)
{
    return _str[index];
}


char String::operator[] (size_t index) const
{
    return _str[index];
}


void String::swap(String &other)
{
    std::swap(_str, other._str);
}






