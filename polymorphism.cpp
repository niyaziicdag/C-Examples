#include <iostream>
#include <string_view>

class Hayvan
{
public:
    virtual std::string_view getName() const { return "Hayvan"; }
};
class Kopek : public Hayvan
{
public:
    virtual std::string_view getName() const { return "Kopek"; }
};
int main()
{
    Kopek max;
    Hayvan &cins{max};
    std::cout << "Cins : " << cins.getName() << '\n';
    return 0;
}