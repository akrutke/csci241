
/*************************************
Program:        Assignment 9
Programmer:     Andrew Krutke
LOGON ID:       z1756942
DUE:            4/28/2015
Function:       Source file for the 
		shape class
**************************************/
#include <string>
#include <iostream>
#include "shape.h"

using namespace std;
/****************************
Shape Method
Function:  set the default 
	   color
*****************************/
Shape::Shape(const string& color)
{
this->color=color;  //set color to the this point 
}
/******************************
Print Method
Function:  will be passed to 
	   the derived classes
           and print the colors
*******************************/
void Shape::print() const
{	//print the color
cout << color;
}
//Desctructor
Shape::~Shape()
{
//empty body
}
