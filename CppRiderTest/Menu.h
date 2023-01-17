#pragma once
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "Maths.h"

struct Menu
{
    //doOperation(int opNum, long firstNumber, secondNumber)
    long DoOperation(int opNum, long fNum, long sNum)
    {
        Maths maths;
        long resultOfOperation = 0.0;

        if (opNum == 0)
        {
            resultOfOperation = maths.Add(fNum, sNum);
        }
        else if (opNum == 1)
        {
            resultOfOperation += maths.Subtract(fNum, sNum);
        }
        else if (opNum == 2)
        {
            resultOfOperation += maths.Multiply(fNum, sNum);
        }
        else if (opNum == 3)
        {
            resultOfOperation += maths.Divide(fNum, sNum);
        }

        return resultOfOperation;
    }

    int CheckOperator(char op)
    {
        char operators[4] = {'+', '-', '*', '/'};

        for (int x = 0; x < 4; x++)
        {
            if (operators[x] == op)
            {
                //std::cout << "checkOp return: " << x << std::endl;
                return x;
            }
        }
        return 0;
    }

    long FindResult(std::vector<std::string> expression)
    {
        char op = ' ';
        long firstDig = 0.0;
        long secDig = 0.0;
        long result = 0.0;

        for (int x = 0; x < expression.size(); x++)
        {
            if (firstDig != 0.0 && secDig != 0.0)
            {
                std::cout << "Does it reach here?" << std::endl;
                result = DoOperation(CheckOperator(op), firstDig, secDig);
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
                //std::cout << "First digit here: " << firstDig << std::endl;
            }
            else if (secDig == 0.0 && firstDig != 0.0)
            {
                secDig = std::stol(expression[x], nullptr, 10);
                //std::cout << "Second digit here: " << secDig << std::endl;
            }

            //If list is even, fill firstDig and secDig and add to the result.
            //If list is odd, add firstDig at the end to the result
        }
        
        if (secDig != 0.0 && firstDig != 0.0)
        {
            result = DoOperation(CheckOperator(op), firstDig, secDig);
        }
        
        if (secDig == 0.0 && firstDig != 0.0)
        {
            result = DoOperation(CheckOperator(op), result, firstDig);
        }

        return result;
    }

    std::vector<std::string> InputToVector(std::string s)
    {
        constexpr char operators[] = {'+', '-', '*', '/'}; //Used inside for loop to add operator inside the std::vector
        std::vector<std::string> sList;
        std::string value = "";
        //std::cout << "Size of string: " << s.size() << std::endl;
        for (int x = 0; x < s.size(); x++)
        {
            if (std::isdigit(s[x]) || s[x] == '.')
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
};
