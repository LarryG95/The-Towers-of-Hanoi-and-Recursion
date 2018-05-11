//Project 6 The Towers of Hanoi and Recursion
/*
Given n (=3) discs: disc1, disc2, diskc3 stacked on the leftmost peg in order of size with the largest disc at the bottom and a disc is always smaller than the disc below.

Move all three (n) discs from leftmost Peg A to rightmost Peg C with the following rules:

Only one disc may be moved at a time.

A disc can not be placed on the top of a smaller disc.

There are only three pegs: A, B, C

Write the program to display every move and indicate the position of each disc:

Beginning position of three discs: (A, A, A) (Position of disc 1, Position of disc 2, position of disc 3)

Disc 1 is smaller than disc 2 and disc 2 is smaller than disc 3.

Move disc 1 from Peg A to Peg C (C, A, A)

Move disc 2 from Peg A to Peg B (C, B, A)

Move disc 1 from Peg C to Peg B (B, B, A)

Etc. ………………..

Last move

Move disc 1 from Peg A to Peg C (C, C, C)

Do the same for n=4 discs.

Do the same for n= 5 discs.

Your program output must show proper information to be understood well
by the reader/viewer.
*/
//  main.cpp
//  program6
//  CHWANG DATA STRUCTURES
//  Created by Lawrence Miles Gomez on Oct/29/17.
//  Copyright © 2017 Lawrence Miles Gomez. All rights reserved.
//


#include <iostream>
#include <vector>
#include <string>

using namespace std;

// void moveDisks(disks, Starting peg, end peg, temp peg, position of array);
void moveDisks(int n, string a, string c, string b, vector<string> discsVector);

int main()
{
    string a = "A";
    string b = "B";
    string c = "C";
    int numDiscs;
    

    do
    {
        cout << "Enter the amount of discs you want in the tower: ";
        cin >> numDiscs;
        
        if(numDiscs <= 0)
        {
            cout << "Enter a positive number of disc greater than 0" << endl;
            cin >> numDiscs;
        }
        
    }while(numDiscs <= 0);
    
        
        vector<string> discsVector(numDiscs, "A"); //vector for dynamic size and to keep track off each disc and it's movements
        
        moveDisks(numDiscs, a, c, b, discsVector);  // starts game
        
    
    return 0;
}

void moveDisks(int num, string a, string c, string b, vector<string> discsVector)
{
    // catches the disc position and displays it
    int VecSize = (discsVector.size() - 1);
    
    if(num > 0)
    {
        moveDisks(num-1, a, b, c, discsVector);
        
        // shows each movement and the end location in format (X, X, X)
        cout << "Move disk " << num << " from peg " << a << " to " << c << endl;
        
        discsVector[num-1] = c;
        cout << "(" ;
        for(int i = 0; i < VecSize; i++)
            cout << discsVector[i] << ", " ;
        cout << discsVector[VecSize];
        cout << ")" << endl;
        
        moveDisks(num-1, b, c, a, discsVector);
    }
    
}
