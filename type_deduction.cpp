#include <iostream>

using namespace std;
int add(int x, int y)
{
    return x + y;
}
int main()
{
    auto d{5.0};   // 5.0 double değişken, derleyici double olarak algılar.
    auto i{1 + 2}; // 1+2 int değişken, derleyici int olarak algılar.
    auto x{i};     // i int değişken, derleyici int olarak algılar.

    auto sum{add(5, 6)}; // add() int değer döndürür, derleyici int olarak algılayacaktır.
    return 0;
}