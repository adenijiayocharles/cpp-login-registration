#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>

enum Actions
{
    Login,
    Register
};

using std::filesystem::current_path;
const std::string currentDirectory = current_path();

class Account
{
private:
    std::string username;
    std::string password;

public:
    Account()
    {
        std::cout << "Welcome to this Registration and Login System" << std::endl;
        std::cout << "Enter 0 to login and 1 to register: ";
    }

    void setUsername(std::string userName)
    {
        username = userName;
    }

    std::string getUsername()
    {
        return username;
    }

    void setPassword(std::string passWord)
    {
        password = passWord;
    }

    std::string getPassword()
    {
        return password;
    }

    void loginUser()
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
                if (lineContent.find(username) != -1)
                {
                    usernameFound = true;
                }

                if (lineContent.find(password) != -1)
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
                std::cout << "Haa haa" << std::endl;
            }

            myFile.close();
        }
    }

    void registerUser()
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