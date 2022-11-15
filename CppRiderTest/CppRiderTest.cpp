
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

long doOperation(char op, long firstDig, long secDig)
{
    Maths maths;
    char operators[] = {'+', '-', '*', '/'};
    std::cout << *(&operators + 1) - operators << std::endl;
    long resultOfOperation = 0.0;
    
    for (int x = 0; x < *(&operators + 1) - operators ; x++)
    {
        switch (operators[x])
        {
        case '+':
            resultOfOperation += maths.add(firstDig, secDig);
            break;

        case '-':
            resultOfOperation += maths.subtract(firstDig, secDig);
            break;

        case '*':
            resultOfOperation += maths.multiply(firstDig, secDig);
            break;

        case '/':
            resultOfOperation += maths.divide(firstDig, secDig);
            break;
            
        default: ;
        }
    }

    return resultOfOperation;
}

long findResult(std::vector<std::string> expression)
{;
    char op;
    long firstDig = NULL;
    long secDig = NULL;
    long result = 0.0;

    for (int x = 0; x < expression.size(); x++)
    {
        if (firstDig != NULL && secDig != NULL)
        {
            result = doOperation(op, firstDig, secDig);
            firstDig = NULL;
            secDig = NULL;
        }
        //TODO: Make sure it checks if the value indexed is an operator. Can possibly use std::isDigit()
        if (x == 0 || x % 2 == 1)
        {
            firstDig = std::stol(expression[x]);
        }
        else if (x % 2 == 0)
        {
            secDig = std::stol(expression[x]);
        }
        
        //If list is even, fill firstDig and secDig and add to the result.
        //If list is odd, add firstDig at the end to the result
    }

    if (secDig == NULL) { result = doOperation(op, firstDig, secDig); }

    return result; 
}

void toVector(std::string s)
{
    char operators[] = {'+', '-', '*', '/'}; //Used inside for loop to add operator inside the std::vector
    std::vector<std::string> sList;
    std::string value = "";
    std::cout << "Size of string: " << s.size() << std::endl;
    for (int x = 0; x < s.size(); x++)
    {
        if (std::isdigit(s[x]))
        {
            //If s[x] is a digit it will add to the std::string value.
            value += s[x];
            std::cout << "Value = " << value << std::endl;
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
}


int main(int argc, char* argv[])
{
    menu();
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

