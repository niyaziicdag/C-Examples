#include <iostream>
#include <string>
using namespace std;
class User
{
private:
    string name;
    string surname;
    string username;
    string password;

public:
    User(string name,string surname,string username,string password):name(name),surname(surname),username(username),password(password) {}
    void setName(string name) { this->name = name; }
    string getName() { return name; }
    void setSurname(string surname) { this->surname = surname; }
    string getSurname() { return surname; }
    void setUsername(string username) { this->username = username; }
    string getUsername() { return username; }
    void setPassword(string password) { this->password = password; }
    string getPassword() { return password; }
};

int main()
{
    User user1("","","","");
    user1.setName("Niyazi");
    user1.setSurname("İçdağ");
    user1.setUsername("niyaziicdag");
    user1.setPassword("123456");
    cout << "İsim: " << user1.getName()
         << "\nSoyisim: " << user1.getSurname()
         << "\nKullanıcı Adı: " << user1.getUsername()
         << "\nŞifre: " << user1.getPassword() << endl;
}