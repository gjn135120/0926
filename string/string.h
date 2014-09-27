#ifndef STRING_H
#define STRING_H
#include <string.h>
#include <iostream>


class String
{
    friend std::ostream &operator<< (std::ostream &os, const String &a);
    friend std::istream &operator>> (std::istream &is, String &a);

    friend String operator+ (const String &a, const String &b);
    friend String operator+ (const String &a, const char *b);
    friend String operator+ (const char *a, const String &b);

    friend bool operator< (const String &a, const String &b);
    friend bool operator<= (const String &a, const String &b);
    friend bool operator> (const String &a, const String &b);
    friend bool operator>= (const String &a, const String &b);
    friend bool operator== (const String &a, const String &b);
    friend bool operator!= (const String &a, const String &b);


public:
    String();
    String(const char *s);
    String(const String &s);
    ~String();

    String &operator= (const String &s);
    String &operator= (const char *s);
    String &operator+= (const String &s);
    String &operator+= (const char *s);

    void swap(String &other);

    char &operator[] (size_t index);
    char operator[] (size_t index) const;

    size_t size() const
    { return strlen(_str); }

    const char *c_str() const
    { return _str; }

    void debug() const;

private:
    char *_str;
};

inline std::ostream &operator<< (std::ostream &os, const String &a)
{
    return os << a._str;
}

inline std::istream &operator>> (std::istream &is, String &a)
{
    char tmp[1024];
    if(is >> tmp)
        a = tmp;
    return is;
}

#endif  /*STRING_H*/
