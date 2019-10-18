//  Assignment_3
//  Created by Natálie Stepankevyčová on 10/13/18.
//  Program that calculates the retroactive pay due to employees with
//  a 7.6% salary increase. Effective six months retroactively.
//  Copyright © 2018 Natálie Stepankevyčová. All rights reserved.
//

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    
    //prompts the worker to enter his first and last names
    cout << "Enter your first and last name, please: ";
    string name;
    getline(cin, name);
    //displays a welcome letter with the employee's first and last names
    cout << "Welcome, " << name << ", to our program.\n";
    
    double oldSalary;
    //prompts the employee to enter the old salary
    cout << "Enter your old annual salary, please.\n";
    cout << "I'll return new annual salary, "
            "monthly salary, and retroactive pay: ";
    cout << setprecision(2) << fixed;
    cin >> oldSalary;
    
    double increase = 0.076;
    //calculates the new salary
    double newSalary = (oldSalary * ( 1 + increase));
    //calculates the monthly Salary
    double monthlySalary = newSalary / 12;
    //calculates the retroactive Salary
    double retroactiveSalary = (newSalary - oldSalary) / 2;
    
    //display the new yearly Salary
    cout << "Your old annual salary was: " <<  oldSalary << endl;
    cout << "The new annual salary is: " << newSalary << endl;
    //monthly salary
    cout << "The new monthly salary is: " << monthlySalary << endl;
    //retroactive salary
    cout << "The retroactive salary due: " << retroactiveSalary << endl;
    

    return 0;
}



/* TEST
 
 Enter your first and last name, please: Program ended with exit code: 0Natalie S
 Welcome, Natalie S, to our program.
 Enter your old annual salary, please.
 I'll return new annual salary, monthly salary, and retroactive pay: 8439
 Your old annual salary was: 8439.00
 The new annual salary is: 9080.36
 The new monthly salary is: 756.70
 The retroactive salary due: 320.68

 */
