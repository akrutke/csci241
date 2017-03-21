
/*************************************
Program:        Assignment 9
Programmer:     Andrew Krutke
LOGON ID:       z1756942
DUE:            4/28/2015
Function:       source file for the 
		triangle class
**************************************/
#include <iostream>
#include <string>
#include "triangle.h"

/*************************************
Triangle Constructor
Function:  intialize the color and the
	   area of the triangle class
**************************************/
Triangle::Triangle(const string& color, int height, int base): Shape(color)
{
this->height=height;  //set height and base to this point so they can
this->base=base;     //manipulated
}

/***********************************
Print Method
Function:  print the contents of 
	   triangle
************************************/
void Triangle::print() const
{                 //call the base print method
Shape::print();		//formatting for triangle class print function
cout << " triangle, " << "height " << height<<","
<<' ' << "base"<<' '<< base<<","<<' ' << "area " << get_area() <<endl;
}

/***************************************
get_area Method
Function: get the area of a triangle 
	  by multiplying 1/2 base times
	  height
****************************************/
double Triangle::get_area() const
{		//area of a triangle calculations
return (.5 * (base * height));
}
