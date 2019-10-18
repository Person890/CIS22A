//  Assignment_7
//
//  Program grades driver's license exam. It stores correct answers in an
//  array, asks user for student's answers, compares input with correct
//  answers and displays if the student passed exam or not and number of
//  correct and incorrect answers.
//
//  Created by Natálie Stepankevyčová on 11/26/18.
//  Copyright © 2018 Natálie Stepankevyčová. All rights reserved.
//

#include <iostream>

using namespace std;

// prototypes of functions
void input(char [], int);
void checkAnswers(const char[], char[], int &, int &, int, int);


int main() {
    
    // variables definition
    const int CORRECT2PASS = 15;
    const int SIZE = 20;
    int correct = 0;
    int incorrect = 0;
    
    // constant for correct answers
    const char CORRECT_ANSWERS[SIZE] = {'A','D','B','B','C',
        'B','A','B','C','D',
        'A','C','D','B','D',
        'C','C','A','D','B'};
    
    // prompting user to enter answers
    char studentAnswer[SIZE];
    cout << "Please enter the student's answers for each "
    "of the questions."
    "\nPress Enter after typing each answer."
    "\nPlease enter only an A, B, C, D or a, b, c, d "
    "for each question. " << endl;
    
    // calling functions
    input(studentAnswer, SIZE);
    checkAnswers((char*) CORRECT_ANSWERS, studentAnswer,
                 correct, incorrect, SIZE, CORRECT2PASS);
    
    return 0;
}


// function for storing student answers
void input(char studentAnswer[], int SIZE)
{
    for (int i = 0; i < SIZE; i++)
    {
        cout << "\nEnter answer for question number " << i+1 << " : ";
        cin >> studentAnswer[i];
        
        // validation loop
        while (studentAnswer[i] != 'a' && studentAnswer[i] != 'A' &&
               studentAnswer[i] != 'b' && studentAnswer[i] != 'B' &&
               studentAnswer[i] != 'c' && studentAnswer[i] != 'C' &&
               studentAnswer[i] != 'd' && studentAnswer[i] != 'D')
        {
            cout << "Please enter valid answer: ";
            cin >> studentAnswer[i];
            
        }
    }
}


// function for comparing student answers with correct ones
void checkAnswers(const char CORRECT_ANSWERS[], char studentAnswer[],
                  int & correct, int & incorrect, int SIZE,
                  int CORRECT2PASS)
{
    
    for (int i = 0; i < SIZE; i++)
    {
        
        // putting all input to uppercase and counting correct answers
        if (toupper(studentAnswer[i]) == toupper(CORRECT_ANSWERS[i]))
            correct++;
        else incorrect++;
    }
    
    
    if (correct >= CORRECT2PASS)
    {
        cout << "Congratulations! Student passed!" << endl;
    }
    else cout << "Student failed the exam. " << endl;
    
    
    // displaying correct / incorrect answers
    cout << "Correct answers: " << correct << endl;
    cout << "Incorrect answers: " << incorrect << endl;
    
    
}


/*  TEST RUN
 
 Please enter the student's answers for eachof the questions.
 Press Enter after typing each answer.
 Please enter only an A, B, C, D or a, b, c, d for each question.
 
 Enter answer for question number 1 : a
 
 Enter answer for question number 2 : v
 Please enter valid answer: b
 
 Enter answer for question number 3 : a
 
 Enter answer for question number 4 : a
 
 Enter answer for question number 5 : b
 
 Enter answer for question number 6 : d
 
 Enter answer for question number 7 : c
 
 Enter answer for question number 8 : d
 
 Enter answer for question number 9 : b
 
 Enter answer for question number 10 : c
 
 Enter answer for question number 11 : a
 
 Enter answer for question number 12 : c
 
 Enter answer for question number 13 : d
 
 Enter answer for question number 14 : c
 
 Enter answer for question number 15 : b
 
 Enter answer for question number 16 : c
 
 Enter answer for question number 17 : b
 
 Enter answer for question number 18 : c
 
 Enter answer for question number 19 : a
 
 Enter answer for question number 20 : b
 Student failed the exam.
 Correct answers: 6
 Incorrect answers: 14
 Program ended with exit code: 0
 
 
 */


