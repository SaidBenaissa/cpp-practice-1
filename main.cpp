/* *
 * 1. inline function
 * 2. name hiding
 * 3. virtual function
 * 4. virtual destructor
 * */

#include <iostream>

using namespace std;

class A {
public:
    A() {};

    ~A() {

    };

    virtual void Func1() {
        cout << "A::Func1()" << endl;
    };

    virtual void func2() {
        cout << "A::func2()" << endl;
    };
};

class B : public A {
public:
    B() {};

    virtual ~B() {

    }

    using A::func2;

    void func2(int i) {

    }

    void Func1() override {
        cout << "B::Func1()" << endl;
    };
};

class C : public B {
public:
    C() {};

    ~C() {
    };

    void Func1() override {
        cout << "C::Func1()" << endl;
    };
};

int main(int argc, const char *argv[]) {

    A *objA = new C;

    A *a = new A;
    A *b = new B;
    A *c = new C;

    A aa;
    B bb;
    aa.func2();
    bb.func2();
    bb.func2(2);

    a->Func1();
    b->Func1();
    c->Func1();
    delete objA;

    return 0;
}