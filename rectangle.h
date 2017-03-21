#ifndef RECTANGLE_H	//header gaurds
#define RECTANGLE_H
/*************************************
Program:        Assignment 9
Programmer:     Andrew Krutke
LOGON ID:       z1756942
DUE:            4/28/2015
Function:       Header file for the
                rectangle class
**************************************/
#include <string>
#include "shape.h"

class Rectangle: public Shape
{

private:
	int height;  //height and base for the triangle class
	int width;

public:
	Rectangle(const string&, int, int);  //rectangles constructor
	virtual void print() const;		//override print for rectangle class
	virtual double get_area() const;	//override get-area for rectangle class

};
#endif
