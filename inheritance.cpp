#include <iostream>
#include <string>
using namespace std;
class Person
{
public:
    std::string name{};
    int age{};

    Person(const std::string &name = "", int age = 0)
        : name{name}, age{age}
    {
    }

    const std::string &getName() const { return name; }
    int getAge() const { return age; }
};

// BaseballPlayer publicly inheriting Person
class BaseballPlayer : public Person
{
public:
    double m_battingAverage{};
    int m_homeRuns{};

    BaseballPlayer(double battingAverage = 0.0, int homeRuns = 0)
        : m_battingAverage{battingAverage}, m_homeRuns{homeRuns}
    {
    }
};
int main()
{

    BaseballPlayer mert{};          // Create a new BaseballPlayer object
    mert.name = "Mert Kilic";       // Assign it a name (we can do this directly because m_name is public)
    cout << mert.getName() << '\n'; // use the getName() function we've acquired from the Person base class

    return 0;
}