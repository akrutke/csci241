/**************************************************
Program: Assignment 4 csci241
Programmer:	Andrew Krutke
Logon ID: 	z1756942
Due:		3/20/2015

Fuction: Source code to test overload operations
***************************************************/

#include <iostream>
#include "Vector3.h"

using namespace std;

/**********************************
Vector3 Default Contructor
Function: set x, y, z to a temp 
value
***********************************/

Vector3::Vector3(float newX, float newY, float newZ)
{
	x=newX;		//store newX,Y,Z into new values
	y=newY;
	z=newZ;
}

/**********************************
Addition Overload Method
Function: Add two vectors together
***********************************/

Vector3 Vector3::operator+(const Vector3 &rightOp) const
{
	Vector3 temp;		//create a temp Vector3 variable

	temp.x = x+rightOp.x;	 //call x, y, z from temp and perform additon
	temp.y = y+rightOp.y;
	temp.z = z+rightOp.z;
	return temp;		//return the temp value as to not change the orginal vectors
}

/**********************************
Subtraction Overload Method
Function: Subtract two vectors 
***********************************/

Vector3 Vector3::operator-(const Vector3 &rightOp) const
{
	Vector3 temp;		//create a temp Vector3 variable
	
	temp.x = x-rightOp.x;	//call z, y, z from temp and perform subtraction
	temp.y = y-rightOp.y;
	temp.z = z-rightOp.z;
	return temp;		//return a temp value as to not change the orginal vectors
}

/*********************************
Scalar Product Overload Method
Function: Multiply two vectors 
together, add them and produce
a single floating point value
**********************************/

float Vector3::operator * (const Vector3 &rightOp) const
{
	Vector3 temp;		//create a temp Vector3 variable
	float total;		//add the temp compenets to total to get the scalar product
	temp.x = x*rightOp.x;   //call x, y, z and multiply by rightOp.variable
 	temp.y = y*rightOp.y;
	temp.z = z*rightOp.z;
	
	total = temp.x + temp.y + temp.z;  //add all the temp variables to get the total of the scalar product

	return total; 		//return the total of the scalar products
}

/********************************************
Multiplication Overload Operator of rightOp 
Method
Function: Multiple a vector by the constant
vector
*********************************************/

Vector3 Vector3::operator * (const float rightOp)const
{
	Vector3 temp;        //temp variable of Vector3 to hold multplication values
	temp.x =x* rightOp;	//multiply x,y,z by right operand 
	temp.y =y* rightOp;
	temp.z =z* rightOp;

	return temp;		//stored value is returned as to not change the const
}

/***************************************
Left Operand Multiplication Method
Function: Multiple constant by the 
vector
****************************************/

Vector3 operator * (float leftOp, const Vector3 & rightOp)  
{
	Vector3 temp;  //create a temp varabile to store the multiplied vlaues

	temp.x = leftOp * rightOp.x;  //multiple the left operand by the right operand (right.Op.x,y,z)
	temp.y = leftOp * rightOp.y;
	temp.z = leftOp * rightOp.z;

	return temp;  //return the value as to not change the orginal vector
}

/**************************************
Index Operator Method
Function: Provide accessor methods to
get x, y, z and store them into an array
**************************************/
float Vector3::operator[](int index) const
{
	if(index==0)		//read in array values
		return x;	//0=x
	else if(index==1)
		return y;	//1=y
	else if(index==2)
		return z;	//2=z
}

/**************************************
Index Set Operator Method 
Function: Writes to index to set
the value of x, y, z
***************************************/

float & Vector3::operator[](int index)
{
	if(index==0)  //set the array values
		return x;  //refer to above
	if(index==1)
		return y;
	if(index==2)
		return z;
}

/**************************************
Equality Overload
Function: test to see if two of the 
vectors are equal to each other
***************************************/

bool Vector3::operator==(const Vector3 &rightOp)const
{	//return true if float value is equal to rightOp.x,y,z
	return (x == rightOp.x && y == rightOp.y && z == rightOp.z);
}

/***************************************
Print
Function: Over the << operand to print 
the vector as and 3 piece order pair
****************************************/

ostream& operator<<(ostream &print, const Vector3 &rightOp)
{
		//print out the vector by setting the postions of x,y,z with rightOp	
	print << "(" <<rightOp.x << ", " <<rightOp.y << ", " << rightOp.z << ")";

	return print;   
}
