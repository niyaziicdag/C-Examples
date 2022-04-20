#include <iostream>
using namespace std;
class Cicekler // Abtstract Class
{
public:
    string tur = "a";
    int yaprakSayisi = 0;
    virtual int Cesit() = 0; // Abstract fonksiyon
};
class Papatya : public Cicekler
{
public:
    int Cesit()
    {
        yaprakSayisi = 4;
        cout << "Papatya Yaprak Sayisi 4" << endl;
        return 0;
    }
};
int main()
{
    Papatya p;
    p.Cesit();
    return 0;
}