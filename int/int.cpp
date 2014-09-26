#include "int.h"
using namespace std;

INT::INT(int num)
    :_num(num)
{

}

ostream &operator<< (ostream &os, const INT &a)
{
    return os << a._num;
}


istream &operator>> (istream &is, INT &a)
{
    int tmp = a._num;
    is >> a._num;
    if(!is)
        a._num = tmp;
    return is;
}

INT &INT::operator= (int num)
{
    _num = num;
    return *this;
}


INT &INT::operator++()
{
    ++ _num;
    return *this;
}

INT INT::operator++ (int)
{
    INT tmp(*this);
    ++ _num;
    return tmp;
}
