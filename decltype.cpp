// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     // Create a set of strings
//     set<string> st;
//     vector<string> kisiler;
//     kisiler.push_back("Niyazi");
//     kisiler.push_back("Oğuzhan");
//     kisiler.push_back("Gülşah");
//     kisiler.push_back("Mehmet");
//     st.insert({"geeks", "for", "geeks", "org","abc","ded"});

//     // 'it' evaluates to iterator to set of string
//     // type automatically
//     for (auto it = kisiler.begin(); it != kisiler.end(); it++)
//         cout << " " << *it << " \n"; // typeid(it).name() <<
//     for (auto it = st.begin(); it != st.end(); it++)
//         cout << " " << *it << " \n"; // typeid(it).name() <<

//     return 0;
// }

// C++ program to demonstrate use of decltype
#include <bits/stdc++.h>
using namespace std;
 
int fun1() { return 10; }
char fun2() { return 'g'; }
 
int main()
{
    // Data type of x is same as return type of fun1()
    // and type of y is same as return type of fun2()
    decltype(fun1()) x;
    decltype(fun2()) y;
    auto z(3.4);
    cout << typeid(x).name() << endl;
    cout << typeid(y).name() << endl;
    cout << typeid(z).name() << endl;
 

    int t = 5;
 
    // j will be of type int : data type of x
    decltype(t) j = t + 5;
    cout << typeid(j).name() << " " << j<< endl;
    return 0;
}