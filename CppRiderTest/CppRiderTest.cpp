
#include <iostream>
#include <string>
#include <vector>

#include "Maths.h"

static void basicMaths()
{
    Maths maths;
    int count = 0;
    long sum = 0;
    long sNum = 0;
    while(true)
    {
        //Below works for addition. Can be changed for different basic mathematical operations
        count++;
        std::cout << count << std::endl;
        if (count > 1)
        {
            std::cout << "Enter a number: ";
            std::cin >> sNum;
            std::cout << std::endl;
            sum = maths.add(sum, sNum);
            std::cout << sum << std::endl; //Prints results
            //TODO: Create a stack inside the loop and constantly add until there is a break
        }
        else
        {
            std::cout << "Enter a number: ";
            std::cin >> sum;
            std::cout << "Here";
            //std::cout << std::endl;
        }
    }
}

static void toVector(std::string s)
{
    std::vector<std::string> sList;
    std::string value = "";
    std::cout << "Size of string: " << s.size() << std::endl;
    for (int x = 0; x < s.size(); x++)
    {
        if (s[x] != ' ')
        {
            value += s[x];
            //std::cout << value << std::endl;
        }
        else
        {
            sList.push_back(value);
            value = "";
        }
    }
    sList.push_back(value);

    /*
    Testing:
    */
    std::cout << "Size of the vector: " << sList.size() << std::endl;
    for (int y = 0; y < sList.size(); y++)
    {
        std::cout << sList.at(y) << std::endl;
    }
    
}


int main(int argc, char* argv[])
{
    std::cout << "Welcome to the console C++ Calculator app." << std::endl <<
        "Please enter your mathematical problem below." << std::endl << std::endl;
    //TODO: Create menu method to display different operations
    //Maths maths;
    int count = 0;
    std::string uInput = "";
    //Idea: User enters a problem, split into array and attempt to parse the values (long). Basic calc
    long firstNumber = 0;
    long otherNumber = 0;
    while (true)
    {
        count++;
        std::getline(std::cin, uInput);
        std::cout << "This is the user input: " << uInput << std::endl;
        toVector(uInput);
        //TODO: Iterate through vector, parse (long) values and search for operators
        if (uInput == "break") {break;}
    }
    
    return 0;
}

