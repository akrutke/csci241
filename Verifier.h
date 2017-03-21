/*****************************************************************
PROGRAMMER:	 Andrew Krutke
PROGRAM:   	 3
FILE:      	 Verifier.h
DUE DATE:        9/28/2012

PURPOSE:         Contains the declaration for the Verifier class.
*****************************************************************/
 
    #ifndef VERIFIER_H  //header gaurds
    #define VERIFIER_H

class Verifier
    {
      //Adding the access modifiers: private and public
        private:
                char MyGrid [9][9];  //method of 9 rows, 9 columns
        public:
                Verifier(); //default constructor
                void readGrid(const char* inputFile); //reads the grid from input file
                void printGrid();   //prints the sudoko grid
                bool verifySolution(); //boolean method to return t/f for the soduko solution
    };

    #endif

