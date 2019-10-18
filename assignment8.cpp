//  main.cpp
//  Assignment_8
//
//  This program stores variables from file into array,
//  asks user for integer.Sorts the array and applies binary search
//  to find the integer in the array.
//
//  Created by Natálie Stepankevyčová on 12/3/18.
//  Copyright © 2018 Natálie Stepankevyčová. All rights reserved.


#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

// function prototypes
void sortArray(int [], int);
int binarySearch (int [], int, int);
double meanOfArray (int [], int);


int main() {
    
    // declaring variables
    const int SIZE = 12;
    int numberToSearch;
    int array[SIZE];
    double mean;
    int position;
    
    // opening file
    ifstream inFile;
    inFile.open("nums-1.txt");
    
    // opening file validation
    if (!inFile)
    cout << "File open failure!";
    
    // saving file variables into array
    for (int i = 0; i < SIZE; i++)
        inFile >> array[i];
    
    cout << "Enter an integer to search for: ";
    cin >> numberToSearch;
    
    ofstream outfile;
    outfile.open("output.txt"); // opens file named "output" for output
    
 
    
    outfile << "\nThis array has " << SIZE << " items." << endl;
    outfile << "\nThe array entered by the user is as follows: " << endl;
    
    // original array
    for (int i = 0; i < SIZE; i++)
        outfile << array[i] << " ";
    outfile << endl;
    
    // sorted array
    sortArray((int*) array, SIZE);
    outfile << "\nThe sorted array is as follows: " << endl;
    for (int i = 0; i < SIZE; i++)
        outfile << array[i] << " ";
    outfile << endl;
    
    outfile << "\nThe item searched for: " << numberToSearch << endl;
    
    position = binarySearch((int*) array, SIZE, numberToSearch);
    
    if (position != -1)
    {
        outfile << "\nThe value " << numberToSearch << " is in a position "
        << position + 1 << endl;
    }
    // if integer not found
    else outfile << "Integer not found in array." << endl;
    
    mean = meanOfArray((int*) array, SIZE);
    outfile << "\nThe mean of all the elements in the array is "
            << setprecision(1) << fixed << mean << endl;
    
    inFile.close();     // closing file
    outfile.close();
    
    return 0;
}


// bubble sort function
void sortArray(int array[], int size)
{
    bool swap;
    int temp;
    do
    {
        swap = false;
        for (int i = 0; i < (size-1); i++)
        {
            if (array[i] > array[i + 1])
            {
                temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                swap = true;
            }
        }
    }
    while (swap);
}


int binarySearch (int array[], int size, int numberToSearch)
{
    int firstElement = 0;
    int lastElement = size - 1;
    int middleElement;
    int position = -1;
    bool found = false;
    
    while (!found && firstElement <= lastElement)
    {
        middleElement = (firstElement + lastElement) / 2;
        if (array[middleElement] == numberToSearch)
        {
            numberToSearch = true;
            position = middleElement;
        }
        
        else if (array[middleElement] > numberToSearch)
        {
            lastElement = middleElement - 1;
        }
        else firstElement = middleElement + 1;
    }
    return position;
}

double meanOfArray (int array[], int SIZE)
{
    int sum = 0;
    double mean;
    for (int i = 0; i < SIZE; i++)
    {
        sum += array[i];
    }
    mean = static_cast<double> (sum) / SIZE;
    return mean;
}



/*   TEST RUN
 Enter an integer to search for: 2
 
 This array has 12 items.
 
 The array entered by the user is as follows:
 22 -4 5 100 39 20 88 10 55 3 10 78
 
 The sorted array is as follows:
 -4 3 5 10 10 20 22 39 55 78 88 100
 
 The item searched for: 2
 Integer not found in array.
 
 The mean of all the elements in the array is 35.5
 Program ended with exit code: 0
 
 
 */
