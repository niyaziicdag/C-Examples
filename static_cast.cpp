#include <iostream>
using namespace std;
int main()
{
    float f = 3.5;
    cout << "f değeri: " << f << endl;
    int x = f; 
    cout << "x değeri: " << x << endl;
    int b = static_cast<int>(f);
    cout << "b değeri: " << b << endl;
}
