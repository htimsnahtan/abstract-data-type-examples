/*********************************************************************
** Program name: main.cpp
** Author: Nathan Smith
** Date: 8-11-18
** Description: Main driver for Queue() and Stack()
*********************************************************************/
#include "Queue.hpp"
#include "Stack.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "libraryFunctions.hpp"

int main()
{
    srand(time(NULL));
    
    // run Queue function
    Queue();
    
    std::string userInputString = getValidString("Please enter a valid string"
                                                    " to be printed to the console"
                                                    " as a palindrome.");
    // run Stack function
    Stack(userInputString);
    
}