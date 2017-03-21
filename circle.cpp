
/*************************************
Program:        Assignment 9
Programmer:     Andrew Krutke
LOGON ID:       z1756942
DUE:            4/28/2015
Function:       source file for the 
		circle class
**************************************/
#include <iostream>
#include <string>
#include "circle.h"
#include <iomanip>


/************************************
Circle Constructor
Function: intialize the color and the
	  and radius of the circle
*************************************/
Circle::Circle(const string &color, int  radius): Shape(color)
{
this -> radius= radius;  //grab radius and set it to be accessed
}

/************************************
Print Method
Function: Print the contents of the
	  circle.
*************************************/
void Circle::print() const
{
Shape::print();   //call the overridden print method
cout << " circle, " << "radius " << radius <<", " << "area " << get_area() <<endl;		//print format for circle derived class
}

/************************************
get_area Method
Function:  Get the area of the circle
	   by overriding the virtual 
           method in the shape class
*************************************/

double Circle::get_area() const
{
return ((radius * radius) * 3.14159);  //calculate the area of a circle (r^2 * pi)
}

