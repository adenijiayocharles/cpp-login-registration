#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include "Account.h"

enum Actions
{
    Login,
    Register
};

int main()
{
    Account account;

    int options;
    std::cin >> options;

    if (options == Actions::Login)
    {
        std::string username;
        std::cout << "Enter your username: ";
        std::cin >> username;

        std::string password;
        std::cout << "Enter your password: ";
        std::cin >> password;

        account.setUsername(username);
        account.setPassword(password);

        account.loginUser();
    }
    else if (options == Actions::Register)
    {
        std::string username;
        std::cout << "Enter your username: ";
        std::cin >> username;

        std::string password;
        std::cout << "Enter your password: ";
        std::cin >> password;

        account.setUsername(username);
        account.setPassword(password);

        account.registerUser();
    }

    return 0;
}