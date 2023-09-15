#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include "Account.h"

using std::filesystem::current_path;
const std::string currentDirectory = current_path();

Account::Account()
{
    std::cout << "Welcome to this Registration and Login System" << std::endl;
    std::cout << "Enter 0 to login and 1 to register: ";
}

void Account::setUsername(const std::string username)
{
    this->username = username;
}

void Account::setPassword(const std::string password)
{
    this->password = password;
}

std::string Account::getPassword()
{
    return this->password;
}

std::string Account::getUsername()
{
    return this->username;
}

void Account::loginUser()
{
    std::string filePath = currentDirectory + "/users.txt";
    std::ifstream myFile;

    myFile.open(filePath);
    if (myFile.is_open())
    {
        std::string lineContent;
        bool usernameFound = false;
        bool passwordFound = false;

        while (getline(myFile, lineContent))
        {
            if (lineContent.find(this->username) != -1)
            {
                usernameFound = true;
            }

            if (lineContent.find(this->password) != -1)
            {
                passwordFound = true;
            }
        }

        if (usernameFound && passwordFound)
        {
            std::cout << "Login successful" << std::endl;
        }
        else
        {
            std::cout << "Failed login" << std::endl;
        }

        myFile.close();
    }
}

void Account::registerUser()
{
    std::string filePath = currentDirectory + "/users.txt";
    std::ofstream myFile;

    myFile.open(filePath, std::ios::app);

    if (myFile.is_open())
    {
        myFile << "username: " << username << std::endl;
        myFile << "password: " << password << std::endl;
        std::cout << "=====";
        std::cout << "Registration successful";
        myFile.close();
    }
    else
    {
        std::cout << "Unable to open file";
    }
}