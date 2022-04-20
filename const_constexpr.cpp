#include <iostream>
using namespace std;
int func() {return 20;}

int main()
{
	const int x1 = func();
	const int x2 = 10; //geçerli
	constexpr int cx1 = x1; //geçersiz. x1 sabit ifadesi değil
	constexpr int cx2 = x2; //geçerli, x2 sabit ifadesi
	constexpr int cx3 = func(); //geçersiz, func() sabit ifadesi değil
 
	int a[x1]; //geçersiz, dizi boyutu sabit ifadesi değil
	int b[x2]; //geçerli, dizi boyutu sabit ifadesi.
	int c[cx3]; //geçerli, dizi boyutu sabit ifadesi.

    cout << a[x1] << endl;
    cout << b[x2] << endl;
    cout << x2 << endl;
	return 0;
}
