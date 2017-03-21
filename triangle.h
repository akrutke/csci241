#ifndef TRIANGLE_H	//header gaurds
#define TRIANGLE_H
/*************************************
Program:        Assignment 9
Programmer:     Andrew Krutke
LOGON ID:       z1756942
DUE:            4/28/2015
Function:       Header file for the
 		triangle class
**************************************/

#include <string>
#include "shape.h"

class Triangle: public Shape
{
private:
	int height;	//height and base of the triangle class
	int base;

public:
	Triangle(const string&, int , int);   //defualt constructor for triangle class
	virtual void print() const; 		//reused code
	virtual	double get_area() const;		//area calculator


};
#endif
