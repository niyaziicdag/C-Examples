#include <iostream>
using namespace std;

class Dikdortgen
{
    // Class'ın global değişkenlerini tanımladık.
    int en, boy;

public:
    // Class ile aynı isimli Constructor'ı oluşturuyoruz.
    Dikdortgen(int e, int b)
    {
        en = e;
        boy = b;
    }
    // Global değişkenlerle alanı hesaplayacak fonksiyon.
    int alan()
    {
        return en * boy;
    }
};
int main()
{
    // Nesneyi başlatalım.
    Dikdortgen x(5, 10);
    // X nesnenesinin alanını hesaplayalım.
    cout << "Dikdörtgenin Alanı: " << x.alan() << endl;
    return 0;
}