#include <iostream>

using namespace std;

class Base {
public:
    Base () {
        cout << "Base's constructor" << endl;
    }

    virtual void f() {
        cout << "Base f()\n" << endl;
    }

    virtual ~Base () {
        cout << "Base's destructor" << endl;
    }
};

class Derived: public Base {
public:
    Derived () {
        cout << "Derived's constructor" << endl;
    }
    
    void f() {
        cout << "Derived f()\n" << endl;
    }

    ~Derived () {
        cout << "Derived's destructor" << endl;
    }
};

class Derived1: public Derived {
public:
    Derived1 () {
        cout << "Derived1's constructor" << endl;
    }
    
    void f() {
        cout << "Derived1 f()\n" << endl;
    }

    ~Derived1 () {
        cout << "Derived1's destructor" << endl;
    }
};

int main() {
   Derived *p = new Derived1(); 
   
   p->f();

   delete p;

   return 0;
}