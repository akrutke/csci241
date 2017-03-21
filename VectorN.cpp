
/**************************************************
Program: Assignment 5 csci241
Programmer:     Andrew Krutke
Logon ID:       z1756942
Due:            3/27/2015

Fuction: Source code to test overload operations
***************************************************/

#include <iostream>
#include <stdexcept>
#include "VectorN.h"

using std::out_of_range;
/**********************************
VectorN Default Contructor
Function: sets VectorN to 0
***********************************/

VectorN::VectorN()
{	//set the vector size to zero
	vectorSize=0;
	//dynamic memory allocation for vectorArray
	vectorArray= NULL;
}

/*****************************************
VectorN Constructor with arguments
Function: provide an aray to be copied 
and count how many elements are in 
vectorArray
*****************************************/

VectorN::VectorN ( double vector[], int newVsize)
{
	vectorSize=newVsize;
	if ( vectorSize < 0) //anytime the size is less then 0, make it 0
	vectorSize=0;

	vectorArray= new double[vectorSize];   //dynamically allocate the double and restore it
	for(int i=0; i < vectorSize; i++)
	{
		vectorArray[i]=vector[i]; //store vectorArray into Vector for mannipulation
	}
}

/*****************************************
Copy Constructor
Function: Copys an existing vector
object
******************************************/

VectorN::VectorN(const VectorN &other)
{
	vectorSize= other.vectorSize;	//copy vectorSize

	vectorArray= new double[vectorSize];	//copy vectorArray for DMA

	for(int i=0; i < vectorSize; i++)	//loop through

	vectorArray[i]=other.vectorArray[i];
}

/*****************************************
Destructor
Function: remove DMA
******************************************/
VectorN::~VectorN()
{	
	delete[] vectorArray;
}

/*****************************************
Size Method
Function: finds the size of the array
******************************************/

int VectorN::size() const
{
	return vectorSize;
}

/*****************************************
Clear Method
Function: Clears the vector size
******************************************/

void VectorN::clear()
{
	vectorSize=0;
}

/******************************************
Assignment Method Overloaded
Function: assign  Vectors to values
*******************************************/

VectorN& VectorN::operator=(const VectorN & rightOp)
{
	if ( this != &rightOp)  // if rightOp can't be reused
		{
		 delete[] vectorArray; //then delete the vectorArray

		 vectorArray= new double[rightOp.vectorSize];  //create a new vectorArray 

		 for (int i= 0; i < rightOp.vectorSize; i++)  //loop through
				{
					vectorArray[i] = rightOp.vectorArray[i];  //and call vectorArray with righOp
				}
			vectorSize=rightOp.vectorSize; //set vectorSize by calling it with rightOp
		}
return *this;


}

/**********************************
Addition Overload Method
Function: Add two vectors together
***********************************/

VectorN VectorN::operator+(const VectorN &rightOp) const
{
        VectorN temp;           //create a temp Vector3 variable

        if (vectorSize < rightOp.vectorSize)	//check the size of the vector
                temp.vectorSize = vectorSize;
        else
                temp.vectorSize = rightOp.vectorSize;

        temp.vectorArray = new double[temp.vectorSize];  //send vector to DAM
	
	for(int i=0; i < temp.vectorSize; i++)  //loop through the vectorSize
	{
	temp.vectorArray[i] = vectorArray[i] + rightOp.vectorArray[i];
        }

        return temp;            //return the temp value as to not change the orginal vectors
}

/**********************************
Subtraction Overload Method
Function: Subtract two vectors
***********************************/

VectorN VectorN::operator-(const VectorN &rightOp) const
{
	VectorN temp;  //temp variable to hold values

	if (vectorSize < rightOp.vectorSize)		//check the size of the vectors
		temp.vectorSize = vectorSize;
	else 
		temp.vectorSize = rightOp.vectorSize;

        temp.vectorArray = new double [temp.vectorSize];	//send new vector to DAM

	for(int i=0; i < temp.vectorSize; i++)  //loop throught the elements of the array
	{
	temp.vectorArray[i]= vectorArray[i]- rightOp.vectorArray[i];
	}

        return temp;            //return a temp value as to not change the orginal vectors
}

/***************************************
Multiplication Overload to Find a Scalar
Function: Multiply the contents of an 
an array and add them to find a total
****************************************/

double VectorN::operator*(const VectorN &rightOp) const
{
        VectorN temp;           //create a temp Vector3 variable
	double total;                    //double value to hold  the total 	
	int i;	

	if (vectorSize < rightOp.vectorSize)    //check the size of the vectors

		temp.vectorSize = vectorSize;
	else
		temp.vectorSize = rightOp.vectorSize; //and return the smallest

	temp.vectorArray = new double [temp.vectorSize];

	for(i=0; i < temp.vectorSize; i++)  //for loop for the vector elements
	{
		temp.vectorArray[i] = vectorArray[i] * rightOp.vectorArray[i]; //multiply the contents of the vector by the  rightOp array

		total+= temp.vectorArray[i];   //add the vector contents to find the total
	}
        return total;           //return the total of the scalar products
}

/******************************************
Scalar Multiplication Overload Method
Function: to multiply a constant by a 
vector.
******************************************/

VectorN operator*(double leftOp, const VectorN &rightOp)
{
	
	VectorN temp=rightOp;  //set temp to rightOp
	int  i;

	for(i=0; i < temp.vectorSize; i++) //loop through for the vector
	{
	
		temp.vectorArray[i]= leftOp * rightOp.vectorArray[i]; //multiply the constant by the vectorArray
	}

	return temp;
}

/******************************************
Scalar Multiplication Overload Method
Function: to multiply a vector by a 
constant
******************************************/

VectorN VectorN::operator*(const double rightOp) const
{
	VectorN temp= *this;  //store VectorN into a *this
	int i;

	for (i=0; i < temp.vectorSize; i++)
	{
		temp.vectorArray[i] = vectorArray[i] * rightOp;  //multiply the vector by the rightOp(constant)
	}

	return temp;  //return the *this
}

/*****************************************
Subscripting Method for getting a Value
Function: gets a value from the array
and stores it for  access from DMA
******************************************/
double& VectorN::operator[](int index)
{
	
	return vectorArray[index];
}

/*****************************************
Subscripting Method for setting a Value
Function: sets the values from the array
so that it can be accessed via DMA
******************************************/
double VectorN::operator[](int index) const
{

	return vectorArray[index];
}
/*****************************************
Equality Overload Method
Function: test to see if two vectors are 
equal
******************************************/
bool VectorN::operator==(const VectorN &rightOp) const
{
        if (vectorSize != rightOp.vectorSize)  //check the vector size
                return false;  //false if it is not equal to the rightOp vector

	for (int i=0; i<vectorSize; i++)
	{
	 if (vectorArray[i]!=rightOp.vectorArray[i])
		return false;  //check the contents of the orginal array vs. the rightOp array
	}
return true;  //otherwise return true
}
/**************************************
Subscript Overload For error checking
Function: checks to see if a subscript
is in the allowed range
***************************************/

double& VectorN::at(int index) throw(out_of_range)
{
        if (index <0 || index >=vectorSize)  //error checking to make sure the  index isn't below zero or past the vector size

	throw out_of_range("subscript out of range");

return vectorArray[index];
}

/***************************************
Subscrupt Overload For error checking
Checks to see if the write subscrupt
overload is in allowed range
****************************************/

double VectorN::at(int index) const throw(out_of_range)  //same as above
{
        if(index <0 || index >=vectorSize)

        throw out_of_range("subscript out of range");

        return vectorArray[index];
}


/*****************************************
Print Method
Function: Overload << and print to output
******************************************/

ostream& operator<<(ostream &print, const VectorN &rightOp)
{
		int i=0;
        //print out the vector by setting the postions of x,y,z with rightOp
        print << "(" ; 
		if(rightOp.vectorSize > 0)  //when  the rightOp vector is greater than zero
		{
		for (i=0; i < rightOp.vectorSize - 1; i++)  //incriment i
			{
				print << rightOp.vectorArray[i] <<", ";

			}

				print << rightOp.vectorArray[i];  //and print its content

		}
		print << ") ";

        return print;
}


