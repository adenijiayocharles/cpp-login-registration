#ifndef ACCOUNT_CLASS
#define ACCOUNT_CLASS
#include <string>

class Account
{
public:
    Account();
    void setUsername(const std::string userName);
    void setPassword(const std::string userPassword);
    std::string getPassword();
    std::string getUsername();
    void loginUser();
    void registerUser();

private:
    std::string username;
    std::string password;
};
#endif