#ifndef CIRCLE_H	//header gaurds
#define CIRCLE_H
/*************************************
Program:        Assignment 9
Programmer:     Andrew Krutke
LOGON ID:       z1756942
DUE:            4/28/2015
Function:       header file for the 
		circle class
**************************************/
#include <string>
#include "shape.h"


class Circle: public Shape
{

private:
	int radius;  //radius for the circle class

public:
	Circle(const string&, int);	//constructor
	virtual void print() const;	//overridden print method
	virtual	double get_area() const;  //overridden get_area method
};
#endif
