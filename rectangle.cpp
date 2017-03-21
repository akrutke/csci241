
/*************************************
Program:        Assignment 9
Programmer:     Andrew Krutke
LOGON ID:       z1756942
DUE:            4/28/2015
Function:       source file for the
		rectangle class
**************************************/
#include <string>
#include "rectangle.h"

/*********************************
Rectangle Constructor
Function: intialize the color 
	  and the height and width
	  of the rectangle
**********************************/
Rectangle::Rectangle(const string &color, int height, int width): Shape(color)
{
this->height=height;   //set height and width to the this point
this->width=width;
}

/***********************************
Print Method
Function: Print the contents of the 
	  rectanlge
*************************************/
void Rectangle::print() const
{
Shape::print();   //access the overridden print method
cout << " rectangle, " << "height "<< height <<","<<' '<< "width " 
<<' '<< width<< "," <<' ' << "area " << get_area() <<endl;  //print format for rectangle class
}

/*************************************
get_area Method
Function: Get the area of the rectangle
	  by overriding the virtual
	  method in the shape class
**************************************/

double Rectangle::get_area() const
{
return (height * width);  //calculate the area of the rectangle
}
