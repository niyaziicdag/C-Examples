// #include <iostream>
// using namespace std;

// enum Color
// {
//     red,
//     green,
//     blue,
// };
// int main()
// {
//     Color apple{red};
//     Color shirt{green};
//     Color cup{blue};
//     Color socks{white}; // HATA
//     Color hat{2};       // HATA

//     return 0;
// }
#include <iostream>

enum Color
{
    black=5, // assigned 0
    red, // assigned 1
    blue, // assigned 2
    green, // assigned 3
    white, // assigned 4
    cyan, // assigned 5
    yellow=20, // assigned 6
    magenta, // assigned 7
};

int main()
{
    Color shirt{ white };

    std::cout << "Your shirt is " << shirt; // what does this do?

    return 0;
}

