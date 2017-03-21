#ifndef SORTS_H
#define SORTS_H
/**************************************************
Program:	Assignment 8 sorts.h template
Programmer:	Andrew Krutke
ZID:		z1756942
Due:		4/21/2015
Function:	sorts.h header file 
****************************************************/

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

//Function Prototypes for sorts list
template <class T> void buildList(vector<T>&, const char*); //buildlist prototype
template <class T> void printList(const vector<T>&, int, int); //printlist prototype
template <class T> bool lessThan(const T&, const T&);      //less than prototype
template <class T> bool greaterThan(const T&, const T&);   //great than prototype


/**************************************************
Build List Function
Function: Extract the contents of the text file
***************************************************/

template <class T>
void buildList(vector<T>& set, const char* fileName)
{
T item;				//file declaration
ifstream inFile;
inFile.open(fileName);		//open the file
	
	if(!inFile)		//check for it to be open
	{			//exit if it cannot
	cout << "Fille could not be opened" <<endl;
	exit(1);
	}

inFile >> item;
	while(inFile)
	{
	set.push_back(item);		//while in the file extract the info
	
	inFile >> item;			//and feed it into variable item
	}
inFile.close();				//close the input file
}	

/******************************************
Print List Function
Function: Print the contents of the list
*******************************************/

template <class T>
void printList (const vector<T>& set, int itemWidth, int numPerLine)
{
	//use an  unsigned int to go through the vector
	for(unsigned i=0; i < (int) set.size(); i++)
	{
	  if (i % numPerLine ==0)  //print a new line
                {
                 cout<<endl;
                }

	cout << setw(itemWidth+1) << set[i];  //cout the width of the vector+1 to account for negatives	

	}
}

/************************************************
Less than Function
Function: check to see  item1 is less than
	  item2 using standard relation operators
*************************************************/

template <class T>
bool lessThan (const T& item1, const T& item2)
{
	if(item1 < item2)
	{return true;}
	else 
	return false;

} 

/**************************************************
Greater Than Function
Function: test to see if item1 is greater than 
	   item2 using standar relation operators
***************************************************/

template <class T>
bool greaterThan (const T& item1, const T& item2)
{
	if(item1 > item2)
	{return true;}
	else 
	return false;
}

#endif
