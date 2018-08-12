/*********************************************************************
** Program name: Queue.cpp
** Author: Nathan Smith
** Date: 8-11-18
** Description: Queue function implimentation file
*********************************************************************/

#include "Queue.hpp"
#include <queue>
#include "libraryFunctions.hpp"
#include <algorithm>
#include <vector>
#include <iostream>
#include <numeric>

// given 3 int values collected from user, console runs a series of buffer
// simulations using the queue datatype
// for each simulation stats are printed to the console
void Queue()
{
    std::queue<int> q;
    // how many rounds will be simulated
    int numberOfSimulatedRounds;
    // the percentage chance to put a randomly generated number at the end of 
    // buffer
    int percentageChanceAdd;
    // percentage chance to take out a randomly generated number at the front 
    // of buffer
    int percentageChanceRemove;
    // keep track of average length of container
    std:: vector<int>vb; // vb= vector buffer
    
    numberOfSimulatedRounds = getValidNumber("How many rounds will be simulated?",
                                                "Please enter a valid positive int"
                                                );
                                                
    percentageChanceAdd = getValidNumber("How many times out of 100 should a randomly"
                                            " generated number be added at the end of"
                                            " the buffer?",
                                            "Please enter a valid number.",
                                            -1,
                                            101
                                            );
    percentageChanceRemove = getValidNumber("How many times out of 100 should a randomly"
                                            " generated number be removed from the start of"
                                            " the buffer?",
                                            "Please enter a valid number.",
                                            -1,
                                            101
                                            );
    
    int roundsLeft = numberOfSimulatedRounds;
    // start buffer simulation
    while (roundsLeft--)
    {
        std::cout << "Round: " << numberOfSimulatedRounds - roundsLeft 
                    << ":" << std::endl;
        // represents 1 round
        // Generate a random number from 1 – 1000 called N
        int N = getRandIntInRange(0,1001);
        
        // appending number: Generate another random number from 1 – 100, 
        // if the outcome is less than or equal to the user specified percentage 
        // for adding value (Ex: 25), then append the number N into the queue
        
        int N2 = getRandIntInRange(0,101);
        if (N2 <= percentageChanceAdd)
        {
            q.push(N);
        }
        
        // Removing numbers: Generate another random number from 1 – 100, if 
        // the outcome is less than or equal to the user specified percentage 
        // for removing value (Ex: 25), then remove a number from the front of 
        // queue.
        
        int N3 = getRandIntInRange(0, 101);
        if (N3 <= percentageChanceRemove && !q.empty())
        {
            q.pop();
        }
        
        // Output the values in the buffer, and then output the length of the buffer.
        std::queue<int> tempQ = q;
        int qLength = 0;
        std::cout << "Values in buffer: " << std::endl;
        while (!tempQ.empty())
        {  
            int qElement = tempQ.front();
            std::cout << qElement << "\n";
            qLength++;
            tempQ.pop();
        }
        std::cout << "Buffer Length: " << qLength << std::endl;
        
        // add buffer length to array then calculate average buffer size
        vb.push_back(qLength);
        
        // Output the average length of buffer.
        //ALi = (ALi-1 * (i – 1) + Li ) / i
        float averageBL = std::accumulate( vb.begin(), vb.end(), 0.0)/vb.size();
        
        std::cout << "Average Buffer Length: " << averageBL << std::endl;
    }
}
