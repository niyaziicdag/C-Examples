#include <iostream>
using namespace std;

struct Calisan
{
    int id{};
    int age{};
    double wage{};
};
void calisanYazdir(const Calisan &personel)
{
    cout << "ID:   " << personel.id << '\n';
    cout << "Yaş:  " << personel.age << '\n';
    cout << "Maaş: " << personel.wage << '\n';
}
int main()
{
    Calisan metin{14, 32, 8000};
    Calisan kemal{15, 28, 12000};
    calisanYazdir(metin);
    cout << endl;
    calisanYazdir(kemal);
    return 0;
}

