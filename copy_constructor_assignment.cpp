#include <iostream>
using namespace std;

class Myclass
{
public:
    Myclass()
    {
        cout << "Constructor(C)" << endl;
        cout << "C = " << this << endl;
    }

    Myclass(const Myclass &r)
    {

        cout << "copy constructor(CC)" << endl;
        cout << "CC  = " << this << endl;
        cout << "C    = " << &r << endl;
    }
    Myclass &operator=(const Myclass &r)
    {
        cout << "Copy Assignment(CA)" << endl;
        cout << "CA  = " << this << endl;
        cout << "C    = " << &r << endl;

        return *this;
    }
};

int main()
{
    Myclass m1;                   // Constructor Çağrılır
    cout << "**********" << endl; //
    Myclass m2{m1};               // Copy Constructor Çağrılır
    cout << "**********" << endl; //
    Myclass m3;                   // Constructor Çağrılır
    cout << "**********" << endl; //
    m3 = m1;                      // Copy Assignment Çağrılır
    cout << "**********" << endl; //

    cout << "&m1  = " << &m1 << endl;
    cout << "&m2  = " << &m2 << endl;
    cout << "&m3  = " << &m3 << endl;

    return 0;
}