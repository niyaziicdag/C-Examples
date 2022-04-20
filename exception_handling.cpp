#include <iostream>

using namespace std;

int main(void)
{
    int id;
    cout << "1-100 arasında bir sayı giriniz: ";
    cin >> id;

    try
    {
        if (id >= 1 && id <= 100)
        {
            cout << endl
                 << "Girdiğiniz sayı 1-100 arasındadır!" << endl;
        }
        else
        {
            throw id;
        }
    }
    catch (int idc)
    {
        cout << endl
             << "Girdiğiniz sayı 1-100 arasında değildir!" << endl;
        cout << "Girdiğiniz sayı: " << idc;
    }

    return 0;
}