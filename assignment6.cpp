//  Assignment_6
//
//  This program lets user enter 4 of judges score and after dropping lowest
//  and highest returns the average of the two.
//  Created by Natálie Stepankevyčová on 11/7/18.
//  Copyright © 2018 Natálie Stepankevyčová. All rights reserved.
//




#include <iostream>
#include <iomanip>
using namespace std;

void GetJudgeData(double &);
void CalcScore(double, double, double, double);
double findHighest(double, double, double, double);
double findLowest(double, double, double, double);



int main()
{
    
    double score1, score2, score3, score4;
        // function GetJudgeData called once for every of four judges
    GetJudgeData(score1);
    GetJudgeData(score2);
    GetJudgeData(score3);
    GetJudgeData(score4);
    
    
    cout << "The average score is: ";

    CalcScore( score1, score2, score3, score4);
    
    return 0;
}




void GetJudgeData(double &inputScore)  // storing score in reference value
{
    do
    {
        cout << "Enter a judge's score: ";      //asking user for a score
        cin >> inputScore;
        
        while (inputScore < 0 || inputScore > 20)   // validating score
        {
            cout << "Please enter valid score: ";
            cin >> inputScore;
        }
    
    }
    while (inputScore < 0 || inputScore > 20);
   
}


void CalcScore (double score1, double score2,
                double score3, double score4)
{
    double low;
    double high;
    double average = 0.0;
    
    low = findLowest(score1, score2, score3, score4);
    high = findHighest(score1, score2, score3, score4);
    
    
    if (high == score1)     // if highest equals 1
    {
        if (low == score2)
            average = (score3 + score4) / 2.0;
        else if (low == score3)
            average = (score2 + score4) / 2.0;
        else if (low == score4)
            average = (score2 + score3) / 2.0;
    }
    
    if (high == score2)     // if highest equals 2
    {
        if (low == score1)
            average = (score3 + score4) / 2.0;
        else if (low == score3)
            average = (score1 + score4) / 2.0;
        else if (low == score4)
            average = (score1 + score3) / 2.0;
        
    }
    
    if (high == score3)     // if highest equals 3
    {
        if (low == score1)
            average = (score2 + score4) / 2.0;
        else if (low == score2)
            average = (score1 + score4) / 2.0;
        else if (low == score4)
            average = (score1 + score2) / 2.0;
        
    }
    
    else            // if highest equals 4
    {
        if (low == score1)
            average = (score2 + score3) / 2.0;
        else if (low == score2)
            average = (score1 + score3) / 2.0;
        else if (low == score3)
            average = (score1 + score2) / 2.0;
        
    }
    
    // printing out average
    cout << setprecision(1) << fixed << average << endl;
}

double findLowest(double score1, double score2,
                  double score3, double score4)
{
    
    // finding lowest value of four
    
    if (score1 < score2 && score1 < score3 && score1 < score4)
    {
        return score1;
    }
    else if (score2 < score1 && score2 < score3 && score2 <score4)
    {
        return score2;
    }
    else if (score3 < score1 && score3 < score2 && score3 < score4)
    {
        return score3;
    }
    else return score4;

    
}

double findHighest (double score1, double score2,
                    double score3, double score4)
{
    
    // finding highest value of four
    if (score1 > score2 && score1 > score3 && score1 > score4)
    {
        return score1;
    }
    else if (score2 > score1 && score2 > score3 && score2 > score4)
    {
        return score2;
    }
    else if (score3 > score1 && score3 > score2 && score3 > score4)
    {
        return score3;
    }
    else return score4;



}


/* TEST RUN
 
 Enter a judge's score: Program ended with exit code: 010
 Enter a judge's score: 11
 Enter a judge's score: 12
 Enter a judge's score: 13
 The average score is: 11.5


 
*/
