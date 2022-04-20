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

    Myclass(Myclass &&other)
    {
        cout << "Move Constructor(MC)" << endl;
        cout << "MA = " << this << endl;
        cout << "C = " << &other << endl;
    }

    Myclass &operator=(Myclass &&other)
    {

        cout << "Move Assignment(MA)" << endl;
        cout << "MA = " << this << endl;
        cout << "C = " << &other << endl;
        return *this;
    }
};

int main()
{
    Myclass a;           // Constructor Çağrılır
    Myclass b = move(a); // Move Constructor Çağrılır
    Myclass c;           //
    c = move(a);         // Move Assignment Çağrılır
    cout << "&a  = " << &a << endl;
    cout << "&b  = " << &b << endl;
    cout << "&c  = " << &c << endl;
    return 0;
}
