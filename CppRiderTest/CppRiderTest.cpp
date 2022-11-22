#include <iostream>
#include <string>

#include "Menu.h"

void GenerateWelcome()
{
    std::cout << "Welcome to the console C++ Calculator app." << std::endl <<
        "Please enter your mathematical problem below." << std::endl << std::endl;
}

int main(int argc, char* argv[])
{
    GenerateWelcome();
    Menu menu;
    int count = 0;
    std::string uInput = "";
    //Idea: User enters a problem, split into array and attempt to parse the values (long). Basic calc
    while (true)
    {
        count++;
        std::getline(std::cin, uInput);
        //std::cout << "This is the user input: " << uInput << std::endl;

        if (uInput == "break")
        {
            break;
        }
        
        //std::vector<std::string> userInput = toVector(uInput);
        //std::cout << findResult(userInput) << std::endl;
        std::cout << menu.FindResult(menu.InputToVector(uInput)) << std::endl << std::endl;
        uInput = "";
    }

    return 0;
}

//Basic calculator finished
