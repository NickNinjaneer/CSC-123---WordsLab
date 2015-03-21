//
//  main.cpp
//  WordsLab
//
//  Created by Nick Williams on 11/5/14.
//  Copyright (c) 2014 Ninjaneer. All rights reserved.
//
//  This Program asks for a User to input a Word, Converts it to all upper case
//  letters, and calls a procedure to determine the individual letter values based on
//  stored array values. Another procedure is then called to calculate the total value
//  of the User Word. 

#include <iostream>
#include <cstdlib>
#include <string> 

using namespace std;

int calculateValue(char *); //Calculates Total Word Value
int findLetterValue(char);  //Calculates Individual Letter Value



int main(int argc, const char * argv[]) {

    char userWord[16];
    
    do
    {
        cout << "Enter a Word!\n";
        cout << "Enter 1 to Quit\n\n";
        cout << "Your Word: ";
        
        cin >> userWord;
        
        if (toupper(userWord[0]) != '1')
        {
            cout << "Your Word is Worth ";
            cout << calculateValue(userWord) << " Points!\n\n";
        };
        
    } while (toupper(userWord[0]) != '1');
    
    cout << "Thank you for playing! Goodbye!\n\n";
    
    return 0;
}


int calculateValue(char *userWord)
{
    int i = 0;
    int totalValue = 0;
    int multiplier = 1;
    char letter;
    
    while (userWord[i] != '\0')
    {
        letter = toupper(userWord[i]);
        
        totalValue += findLetterValue(letter);
        
        if (toupper(userWord[i]) == toupper(userWord[i+1]))
        {
            multiplier += 1;
        }
        
        i++;
    };
    
    if (multiplier > 1)
    {
        multiplier = 2;
    }
    
    totalValue = totalValue * multiplier;
    
    return totalValue;
}

int findLetterValue(char letter)
{
    int letterValue = 0;
    
    char alphabet[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
        'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R',
        'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    const int alpha[26] = {1, 2, 3, 5, 1, 2, 3, 5, 1, 2, 3, 5, 1,
        2, 3, 5, 1, 2, 3, 5, 1, 2, 3, 5, 1, 2};
    
    int i = 0;
    
    while ((alphabet[i] != letter) && (i < 26))
    {
        i++;
    };
    
    letterValue = alpha[i];
    
    return letterValue;
}