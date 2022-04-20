#include <iostream>
#include <vector>    // Vector
#include <algorithm> // Sıralama (sort) algoritması
using namespace std;

int main()
{

    vector<string> kisiler;
    kisiler.push_back("Niyazi");
    kisiler.push_back("Oğuzhan");
    kisiler.push_back("Gülşah");
    kisiler.push_back("Mehmet");

    for (auto current : kisiler)
    {
        cout << current << endl;
    }

    sort(kisiler.begin(), kisiler.end());

    for (auto current : kisiler)
    {
        cout << current << endl;
    }

    return 0;
}