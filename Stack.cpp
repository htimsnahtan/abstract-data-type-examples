/*********************************************************************
** Program name: Stack.cpp
** Author: Nathan Smith
** Date: 8-11-18
** Description: Stack function implimentation file
*********************************************************************/

#include "Stack.hpp"
#include <stack>
#include <iterator>
#include <iostream>

// given a string, function prints a palindrome of string to the console
void Stack(std::string stringIn) // creates a palindrome
{
    std::string str = stringIn;
    
    std::stack<char>s;
    
    // add the values of the original string sequentially to the stack
    for (std::string::iterator i = str.begin(); i != str.end(); i++)
    {
        std::cout << *i;
        s.push(*i);
    }
    
    // pop off characters one by one and print the character
    while (!s.empty())
    {
        std::cout << s.top();
        s.pop();
    }
    
    // insert end line into stream
    std::cout << std::endl;
    
    return;
}