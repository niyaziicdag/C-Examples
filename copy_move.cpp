#include <iostream>

using namespace std;
class A
{
    public:
    int a;
    A &operator=(A &&other)
    {
        this->a = other.a;
        other.a = 5;
        return *this;
    }
};
int main()
{
    A a;
    a.a = 1;
    cout << a.a << endl; // 1
    A b;
    b = move(a);         // calling A& operator= (A&& other)
    cout << a.a << endl; // 0
    cout << b.a << endl; // 1
}