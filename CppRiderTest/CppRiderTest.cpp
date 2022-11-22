#include <iostream>
#include <regex>
#include <string>
#include <valarray>
#include <vector>

#include "Maths.h"

void menu()
{
    std::cout << "Welcome to the console C++ Calculator app." << std::endl <<
        "Please enter your mathematical problem below." << std::endl << std::endl;
}

void basicMaths()
{
    Maths maths;
    int count = 0;
    long sum = 0;
    long sNum = 0;
    while (true)
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

long doOperation(int opNum, long firstDig, long secDig)
{
    Maths maths;
    long resultOfOperation = 0.0;

    if (opNum == 0)
    {
        resultOfOperation = maths.add(firstDig, secDig);
    }
    else if (opNum == 1)
    {
        resultOfOperation += maths.subtract(firstDig, secDig);
    }
    else if (opNum == 2)
    {
        resultOfOperation += maths.multiply(firstDig, secDig);
    }
    else if (opNum == 3)
    {
        resultOfOperation += maths.divide(firstDig, secDig);
    }

    return resultOfOperation;
}

int checkOp(char op)
{
    char operators[4] = {'+', '-', '*', '/'};

    for (int x = 0; x < 4; x++)
    {
        if (operators[x] == op)
        {
            std::cout << "checkOp return: " << x << std::endl;
            return x;
        }
    }
    return 0;
}

long findResult(std::vector<std::string> expression)
{
    char op;
    long firstDig = 0.0;
    long secDig = 0.0;
    long result = 0.0;

    for (int x = 0; x < expression.size(); x++)
    {
        if (firstDig != 0.0 && secDig != 0.0)
        {
            std::cout << "Does it reach here?" << std::endl;
            result = doOperation(checkOp(op), firstDig, secDig);
            firstDig = 0.0;
            secDig = 0.0;
        }
        
        else if (!std::all_of(expression[x].begin(), expression[x].end(), ::isdigit))
        {
            op = expression[x][0];
        }
        else if (firstDig == 0.0)
        {
            firstDig = std::stol(expression[x], nullptr, 10);
            std::cout << "First digit here: " << firstDig << std::endl;
        }
        else if (secDig == 0.0 && firstDig != 0.0)
        {
            secDig = std::stol(expression[x], nullptr, 10);
            std::cout << "Second digit here: " << secDig << std::endl;
        }

        //If list is even, fill firstDig and secDig and add to the result.
        //If list is odd, add firstDig at the end to the result
    }
    
    if (secDig != 0.0 && firstDig != 0.0)
    {
        result = doOperation(checkOp(op), firstDig, secDig);
    }
    
    if (secDig == 0.0 && firstDig != 0.0)
    {
        result = doOperation(checkOp(op), result, firstDig);
    }

    return result;
}

std::vector<std::string> toVector(std::string s)
{
    char operators[] = {'+', '-', '*', '/'}; //Used inside for loop to add operator inside the std::vector
    std::vector<std::string> sList;
    std::string value = "";
    //std::cout << "Size of string: " << s.size() << std::endl;
    for (int x = 0; x < s.size(); x++)
    {
        if (std::isdigit(s[x]))
        {
            //If s[x] is a digit it will add to the std::string value.
            value += s[x];
            //std::cout << "Value = " << value << std::endl;
        }
        else if (std::find(std::begin(operators), std::end(operators), s[x]) != std::end(operators))
        {
            //std::cout << s[x] << std::endl;
            sList.push_back(value);
            value = "";
            value += s[x];
            sList.push_back(value);
            value = "";
        }
    }
    sList.push_back(value);

    /*
    Testing:
    - Outputs the values inside the vector
    std::cout << "Size of the vector: " << sList.size() << std::endl;
    for (int y = 0; y < sList.size(); y++)
    {
        std::cout << sList.at(y) << std::endl;
    }
    */
    return sList;
}


int main(int argc, char* argv[])
{
    menu();
    //Maths maths;
    int count = 0;
    std::string uInput = "";
    //Idea: User enters a problem, split into array and attempt to parse the values (long). Basic calc
    while (true)
    {
        count++;
        std::getline(std::cin, uInput);
        std::cout << "This is the user input: " << uInput << std::endl;
        
        if (uInput == "break")
        {
            break;
        }
        std::vector<std::string> userInput = toVector(uInput);
        std::cout << findResult(userInput) << std::endl;
    }

    return 0;
}

//Basic calculator finished
