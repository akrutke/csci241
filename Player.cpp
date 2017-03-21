/***********************************************************
AUTHOR: 	Andrew Krutke
LOGON ID:	z1756942
DUE DATE: 	2/12/2015

PURPOSE: 	The Player class implementation
************************************************************/

#include <iostream>
#include <iomanip>
#include <string.h>
#include <stdio.h>
#include <cstdlib>
#include "Player.h"

//constructors
public:
	Player();	//Default Constructor
	Player(int, char*, char*, int, int);  //Alternate constructor to take arguments
	int 	getNumber();
	char* 	getName();
	//char*	getPostion();
	//int 	getHits();
	//int 	getAtBats(int);
	//void	setHits(int);
	//void 	setAtBats(int);
	//double	battingAverage();
	//void	print();

//***********************************************************
//Default Constructor Player();
//Set the name, player number, hits and bats to 0
//***********************************************************

Player::Player()
{
	strgpy(" ", playerObject);  //use strcpy to copy null string into playerObject
	int playerNum=0;		//set these values to 0
	int hitNum=0;
	int atBats=0;
}
//***********************************************************
//Alternate Player Constructor
//Takes 5 arguments, no return data type
//***********************************************************
Player::Player(int newNum, char* newName , char* newPostion , int newHits, int newBats )
{
getNumber=newNum;
strcpy(newName, getName);
strcpy(newPostion, getPostion);
newHits=getHits;
newBats=getAtBats;


}

//getNumber Method
int Player::getNumber(int n)
{
return n;
}

//getName Method

char Player::getName(char* name)
{
return name;
}




