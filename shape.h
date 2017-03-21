#ifndef SHAPES_H		//header gaurds
#define SHAPES_H
/*************************************
Program:	Assignment 9
Programmer:	Andrew Krutke
LOGON ID:	z1756942
DUE:		4/28/2015
Function:	Header file for the 
		shape class
**************************************/
#include <string>
#include <iostream>

using namespace std;

class Shape
{
private:
	string color;	//default color

public:
	Shape(const string& color);	//base constructor
	
	virtual ~Shape();	//virtual destructor
	virtual void print() const;   //print method 
	virtual double get_area() const =0;  //pure virtual area method
};
#endif
