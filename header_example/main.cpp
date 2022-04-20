#include <iostream>
#include "head.hpp"
using namespace std;
int main()
{
cout<<"Merhaba faktoriyel programına hosgeldiniz!"<<endl<<endl;
int pozitif_sayi;
cout<<"Bir sayı girin: "<<endl;
cin>>pozitif_sayi;
cout<<"Sayı: " << pozitif_sayi<< " Faktoriyeli: " << faktoriyel(pozitif_sayi) << "toplam :" ;//<< topla(20,70)<<endl;
return 0;
}