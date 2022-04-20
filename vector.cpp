#include <vector>
#include <iostream>
int main()
{
    std::vector<int> array{};
    array = {0, 1, 2, 3, 4}; // dizi boyutu 5
    std::cout << "Uzunluk: " << array.size() << "  Kapasite: " << array.capacity() << '\n';

    array = {9, 8, 7}; // dizi boyutu 3
    std::cout << "Uzunluk: " << array.size() << "  Kapasite: " << array.capacity() << '\n';

    //  OUTPUT
    //      Uzunluk: 5  Kapasite: 5
    //      Uzunluk: 3  Kapasite: 5
    return 0;
}

