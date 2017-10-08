//
//  main.cpp
//  PRG-7-5-Monkey-Business
//
//  Created by Keith Smith on 10/8/17.
//  Copyright © 2017 Keith Smith. All rights reserved.
//
//  A local zoo wants to keep track of how many pounds of food each of its three monkeys
//  eats each day during a typical week. Write a program that stores this information in a
//  two-dimensional 3x5 array, where each row represents a different monkey, and each
//  column represents a different day of the week. The program should first have the user
//  input the data for each monkey. Then, it should create a report that includes the following
//  information:
//
//  * Average amount of food eaten per day by the whole family of monkeys
//  * The least amount of food eaten during the week by any one monkey
//  * The greatest amount of food eaten during the week by any one monkey
//
//  Input Validation: Do not accept negative numbers for pounds of food eaten.

#include <iostream>

using namespace std;

const int INT_DAYS_OF_THE_WEEK = 7;
const int INT_TOTAL_NUMBER_OF_MONKEYS = 3;
const int INT_MEALS_PER_DAY = 3;

const string STR_DAYS_OF_THE_WEEK[INT_DAYS_OF_THE_WEEK] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday",                                  "Friday", "Saturday"};

// NOTE: I created a three-dimensional array that includes
// total number of meals the monkeys ate per day (3)
float fltArrayMonkey[INT_TOTAL_NUMBER_OF_MONKEYS][INT_DAYS_OF_THE_WEEK][INT_MEALS_PER_DAY];

void gatherData();
void generateReport();

int main()
{
    gatherData();
    
    generateReport();
    
    return 0;
}

void gatherData()
{
    float fltTempFoodPerMeal;
    
    for(int i = 0; i < INT_TOTAL_NUMBER_OF_MONKEYS; i++)
    {
        for(int j = 0; j < INT_DAYS_OF_THE_WEEK; j++)
        {
            for(int k = 0; k < INT_MEALS_PER_DAY; k++)
            {
                cout << "Please enter the food monkey " << i + 1 << " ate on " << STR_DAYS_OF_THE_WEEK[j] << " for meal " << k + 1 << " : ";
                cin >> fltTempFoodPerMeal;
                while(!cin || fltTempFoodPerMeal <= 0 || fltTempFoodPerMeal > 100)
                {
                    cout << "Please enter a number greater than 0 and less than 100: ";
                    cin.clear();
                    cin.ignore();
                    cin >> fltTempFoodPerMeal;
                }
                
                fltArrayMonkey[i][j][k] = fltTempFoodPerMeal;
            }
        }
    }
}

void generateReport()
{
    float fltTempTotal;
    float fltAverage;
    float fltMinimum;
    float fltMaximum;
    
    fltTempTotal = 0; //Initialize accumulators
    fltMinimum = 100;
    fltMaximum = 0;
    
    for(int i = 0; i < INT_TOTAL_NUMBER_OF_MONKEYS; i++)
    {
        for(int j = 0; j < INT_DAYS_OF_THE_WEEK; j++)
        {
            for(int k = 0; k < INT_MEALS_PER_DAY; k++)
            {
                fltTempTotal += fltArrayMonkey[i][j][k];
                
                if(fltArrayMonkey[i][j][k] < fltMinimum)
                {
                    fltMinimum = fltArrayMonkey[i][j][k];
                }
                if(fltArrayMonkey[i][j][k] > fltMaximum)
                {
                    fltMaximum = fltArrayMonkey[i][j][k];
                }
            }
        }
    }
    
    fltAverage = (fltTempTotal) / (INT_DAYS_OF_THE_WEEK * INT_TOTAL_NUMBER_OF_MONKEYS);
    
    cout << "The family of monkey's average food consumption per day was: " << fltAverage
    << endl;
    cout << "The least amount of food eaten was: " << fltMinimum << endl;
    cout << "The greatest amount of food eaten was: " << fltMaximum << endl;
}

