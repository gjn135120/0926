#ifndef INT_H
#define INT_H 
#include <iostream>

class INT
{
    friend std::ostream &operator<< (std::ostream &os, const INT &a);
    friend std::istream &operator>> (std::istream &is, INT &a);

    public:
        INT(int num = 0);
        INT &operator= (int num);
        
        INT &operator++ ();
        INT operator++ (int);
        
        operator int()
        { return _num; }

    private:
        int _num;
};


#endif  /*INT_H*/
