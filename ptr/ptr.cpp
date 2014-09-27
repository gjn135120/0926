#include "ptr.h"
using namespace std;

Ptr::Ptr(Test *p)
    :_ptr(p)
{ }

void Ptr::reset(Test *p)
{
    if(_ptr != p)
    {
        delete _ptr;
        _ptr = p;
    }

}
