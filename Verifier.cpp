/*****************************************************************
PROGRAMMER:	Andrew Krutke
PROGRAM: 	3
FILE:      	Verifier.cpp
DUE DATE:  	2/27/2015 
 
PURPOSE:  	 will read from the input files to file the
	   	sudoko grid and then verify if it is a valid
	   	sudoko soltion
*****************************************************************/

#include  "Verifier.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <iomanip>
#include <fstream>
using namespace std;

/***********************************************************
Default Constructor: Initilizes the sudoko grid to 0
***********************************************************/
Verifier::Verifier()
{
    MyGrid[0][0] = '0';
}
/***********************************************************
readGrid(); meathod:	takes the inputfile as an argument
		 	and points to an array of char that 
			contains the name of the input file.
***********************************************************/
void Verifier::readGrid(const char* inputFile)
{
    ifstream myReadFile(inputFile);
    
    while (!myReadFile.eof()) //loop while not at the end of the input file
    {
        for (int c=0; c < 9; c++) //c=column, while c less than 9; loop and incriment
        {
            for (int r = 0; r < 9; r++)//r=row, while r less than 9; loop and incriment
            {
                myReadFile >> MyGrid[r][c]; //fill the inputfile into MyGrid
            }
        }
        myReadFile.close();
    }
}
/***********************************************************
printGrid() meathod: 	this method takes no argument. It 
			will fill MyGrid with 9 rows and 
			9 columns.
***********************************************************/
void Verifier::printGrid()
{
        for (int c=0; c < 9; c++)
        {
            if (c==0||c==3||c==6)//--- at these column postions
                cout << "-------------------------" << endl;
            for (int r = 0; r < 9; r++)
            {
                if (r==0||r==3||r==6)
                    cout << "| ";   //print | at this row postions 
                cout << MyGrid[r][c] << " "; 
                if (r==8)
                   cout << "|"; //print | at this row postions
            }
                if (c==8)
                    cout << endl << "-------------------------"; //print -- at this column postion
          	    cout << endl; 
        }
}
/***********************************************************
verifyGrid() meathod:	This method takes no arguments and
			it returns a boolen value of true or
			false. It checks for multiple
			values in a  row, column and block 
			of the grid.
***********************************************************/
bool Verifier::verifySolution()
{
    int columnV=0;  //cloumn Verify
    int rowV=0;    //row verify
    bool status;  //return status as true or false

/*********************************************************
For the sake of being monotone, columns and rows will
run a similar for loop sequence. They will check r or c's
value up to 9, if they are nont equal to 45 then 
a value is either missing or was doubled such that 
the total of columns and rows did not equal to 45. 45 
is the total of values in  a single row, column or block.
*********************************************************/
//Verify columns

    for (int b=0; b < 9; b=b+3)
    {
        for (int r = 0; r < 9; r++)
        {

            for (int c=0; c < 9; c++)
            {
               columnV=columnV+MyGrid[r][c];
               if (c==8&&columnV==45)
                   status=true;  //return true for a total of 45 in the column
               else if (c==8&&columnV != 45)
                   return false;  //return false for a total less than 45
           }
            if (columnV==45) //set the columns back to zero to reloop
               columnV=0;
        }

    }

//Verify rows

    for (int b=0; b < 9; b=b+3)  
    {
        for (int c=0; c < 9; c++) 
        {

            for (int r = 0; r < 9; r++)
            {
               rowV=rowV+MyGrid[r][c];

               if (r==8 && rowV==45)
                   status=true; 
               else if (r==8 && rowV != 45) 
                   return false;  
               if(MyGrid[r][c]== MyGrid[r+1][c])
                   return false;
            }

            if (rowV==45)  //set the row back to zero to reloop
               rowV=0;
        }
    } 

    return status; //return status  as true or false
 
}

