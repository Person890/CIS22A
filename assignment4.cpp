
//  main.cpp
//  Assignment_4
//
//  Program asks which package the customer has purchased
//  and how many minutes were used. Then, it displays the
//  customer’s monthly bill and how much money the customer
//  would save if she purchased the other two packages.
//  If there would be no savings, "No Saving" is printed.
//
//
//  Created by Natálie Stepankevyčová on 10/17/18.
//  Copyright © 2018 Natálie Stepankevyčová. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    
    // constants for rates
    const double PACKAGE_A_COST = 39.99;
    const double PACKAGE_B_COST = 59.99;
    const double PACKAGE_C_COST = 69.99;
    
    // constants for additional minute rates
    const double RATE_A = 0.45;
    const double RATE_B = 0.40;
    
    // constants for menu choices
    const int PACKAGE_A_OPTION = 1;
    const int PACKAGE_B_OPTION = 2;
    const int PACKAGE_C_OPTION = 3;
    const int EXIT_OPTION = 4;
    
    // contstants for minutes provided
    const int minA = 450;
    const int minB = 900;
    
    int minutes = 0;
    double total = 0.0;
    double totalA = 0.0;
    double totalB = 0.0;
    double totalC = 0.0;
    int package;
    
    // prompts user to choose package
    cout << "Which package did you use? \n"
    << "1. Package A for $39.99 per month\n"
    << "2. Package B for $59.99 per month\n"
    << "3. Package C for $69.99 per month\n"
    << "4. Quit\n";
    cin >> package;
    
    
    // validation of input
    while (true)
    {
        if (!(package >=PACKAGE_A_OPTION && package <=EXIT_OPTION))
        {
            cout << "Invalid package." << endl;
            cout << "Please enter a number from 1 to 4." << endl;
            cin.clear();
            cin.ignore(100, '\n');
            cin >> package;
        }
        if (package >= 1 && package <= 4)
            break;
    }
    
    //  exit
    if (package == EXIT_OPTION)
    {
        cout << "You exited program.\n";
        return 0;
    }
    
    // menu
    switch (package)
    {
        case PACKAGE_A_OPTION:
            cout << "How many minutes were were  used? ";
            cin >> minutes;
            if (minutes <= minA && minutes >= 0)
            {
                totalA = PACKAGE_A_COST;
                total = totalA;
                cout << "Your total is: " << total << endl;
                break;
            }
            else if (minutes > minA)
            {
                int extra_minutesA;
                extra_minutesA = minutes - minA;
                totalA = (extra_minutesA * RATE_A) + PACKAGE_A_COST;
                total = totalA;
                cout << "Your total is: " << total << endl;
                break;
            }
            else
            {
                cout << "Enter valid number of minutes: ";
                cin >> minutes;
            }
            
        case PACKAGE_B_OPTION:
            cout << "How many minutes were were  used? ";
            cin >> minutes;
            if (minutes <= minB && minutes >= 0)
            {
                totalB = PACKAGE_B_COST;
                total = totalB;
                cout << "Your total is: " << total << endl;
                break;
            }
            else if (minutes > minB && minutes >= 0)
            {
                int extra_minutesB;
                extra_minutesB = minutes - minB;
                totalB = (extra_minutesB * 0.40) + PACKAGE_B_COST;
                total = totalB;
                cout << "Your total is: " << total << endl;
                break;
            }
            else
            {
                cout << "Enter valid number of minutes: ";
                cin >> minutes;
            }
            
            
        case PACKAGE_C_OPTION:            //  package C
            cout << "How many minutes were were  used? ";
            cin >> minutes;
            
            if (minutes >= 0)
            {
                totalC = PACKAGE_C_COST;
                total = totalC;
                cout << "Your total is: " << total << endl;
            }
            else if (minutes < 0)
            {    cout << "Enter valid number of minutes: ";
                 cin >> minutes;
            }
            break;
    }
    
    
    // calculating cost for individual packages
    // and displaying customer’s monthly bill
    if (package == 1)
    {
        if (minutes < minA) // package A
        {
            totalA = PACKAGE_A_COST;
        }
        else
        {
            int extra_minutesA;
            extra_minutesA = minutes - minA;
            totalA = (extra_minutesA * RATE_A) + PACKAGE_A_COST;
        }
        
        
        if (package == 2) {     //package B
            if (minutes <= minB)
            {
                totalB = PACKAGE_B_COST;
            }
            else
            {
                int extra_minutesB;
                extra_minutesB = minutes - minB;
                totalB = (extra_minutesB * RATE_B) + PACKAGE_B_COST;
            }
        }
    }
    
    if (package == 3)       // package C
    {
        totalC = PACKAGE_C_COST;
    }
    
    // calculating savings
    if (minutes < minA)
    {
        totalA = PACKAGE_A_COST;
    }
    else
    {
        totalA = PACKAGE_A_COST + (RATE_A * (minutes - minA));
    }
    
    if (minutes < minB)
        totalB = PACKAGE_B_COST;
    else
    {
        totalB = PACKAGE_B_COST + (RATE_B * (minutes - minB));
    }
    totalC = PACKAGE_C_COST;
    
    
    // printing out savings.
    if ((totalA < total) && (!(package == 1)))
        cout << "Savings with package A: $" << total - totalA << endl;
    else if (!(package == 1))
        cout << "No savings with package A." << endl;
    
    if (totalB < total)
        cout << "Savings with package B: $" << total - totalB << endl;
    else if (!(package == 2))
        cout << "No savings with package B." << endl;
    if (totalC < total)
        cout << "Savings with package C: $" << total - totalC << endl;
    else if (!(package == 3))
        cout << "No savings with package C." << endl;
    
    return 0;
}


/* TEST
 
 Which package did you use?
 1. Package A for $39.99 per month
 2. Package B for $59.99 per month
 3. Package A for $39.99 per month
 4. Quit
 Program ended with exit code: 01
 How many minutes were used?
 500
 Savings with package B: $2.5
 No savings with package C.

 
 */
