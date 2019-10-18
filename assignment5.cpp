//  main.cpp
//  Assignment_5
//  This program calculates ideal body weitght from the names-1. txt file.
//  Created by Natálie Stepankevyčová on 11/5/18.
//  Copyright © 2018 Natálie Stepankevyčová. All rights reserved.
//

#include <iostream>
#include <fstream>

using namespace std;

int main() {
    
    ifstream infile;                   // opening the file
    infile.open("names-1.txt");
    
    // displaying an error message if the file can't be open
    if (!infile)
        cout << "File open failure!";
    
    string firstName;                   // declaring variables from file
    string lastName;
    int feet;
    int inches;
    int idealBodyWeight;
    
    // reading the file
    while (infile >> firstName >> lastName >> feet >> inches)
    {
        if (feet >= 5)
        {
            // calculating ideal body weight with formula
            idealBodyWeight = 110 + ((feet - 5) * 12 + inches  ) * 5;
            cout << "The body weight for " << firstName << " "
                 << lastName << " is " << idealBodyWeight
                 << " pounds." << endl;
        }
            // if the body height is less than 5 inches
        else cout << "Couldn't calculate the body weight for "
                  << firstName << " " << lastName << "." << endl;
    }
    
    infile.close();         // closing file
    
    
    
    return 0;
}


/* TEST run
 
 The body weight for Tom Atto is 185 pounds.
 The body weight for Eaton Wright is 135 pounds.
 The body weight for Cary Oki is 165 pounds.
 Couldn't calculate the body weight for Omar Ahmed.
 Program ended with exit code: 0
 
 */
