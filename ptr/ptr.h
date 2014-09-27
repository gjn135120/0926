#ifndef PTR_H
#define PTR_H 
#include <iostream>


class Test
{
    public:
        Test() { std::cout << "Test" << std::endl; }
        ~Test(){ std::cout << "~Test" << std::endl; }
        void run() { std::cout << "running" << std::endl; } 
};


class Ptr
{
    public:
        Ptr(Test *p = NULL);

        ~Ptr()
        { delete _ptr; }

        Test &operator* ()
        { return *_ptr; }

        const Test &operator* () const
        { return *_ptr; }

        Test *operator-> ()
        { return _ptr; }

        const Test *operator-> () const
        { return _ptr; }

        void reset(Test *p = NULL);
        
        const Test *getPtr() const
        { return _ptr; }

    private:

        Ptr(const Ptr &);
        void operator= (const Ptr &);

        Test *_ptr;
};


#endif  /*PTR_H*/
