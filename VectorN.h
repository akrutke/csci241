/********************************************************
Program:	Assignment 5 header file
Programmer: Andrew Krutke
Due Date: 3/27/2015

Function: The header file for class NectorN
*********************************************************/
#ifndef VECTORN_H 		//header gaurds for class VectorN
#define VECTORN_H

#include <iostream>
using namespace std;

class VectorN
{               //overloaded ostream << operator
                friend ostream &operator << (ostream &, const VectorN &);
                //overload multiplication operator declartion for multiplying the left operand
                friend VectorN operator*(double ,const VectorN &);

        private:
		//array of floating point value 
	double *vectorArray;
		//size of the vector fo manipulation
		int   vectorSize;
        public:
		//constructors
		VectorN();       //default constructor - takes no arguments
		VectorN(double vector[], int newVsize); //constructor to set the array
		VectorN(const VectorN &other); //copy constructor

		~VectorN();			//destructor
                int size() const;  //method to find the size
		void clear();      //method to clear the array

		VectorN& operator=(const VectorN& rightOp); //assigntment operator overload
		VectorN operator+(const VectorN &) const;  //addition operator overloading
                VectorN operator-(const VectorN &) const;  //subtraction "  "
                double operator*(const VectorN &) const;  //scalar multiplication operator overload
                VectorN operator*(double right) const;   //multiply the vector by the right operand method
                double operator [](int index) const;      //subscrit operator for reading
                double &operator[](int index);            //subcript operator for writing
		double at(int index) const throw(out_of_range);
		double & at(int index) throw(out_of_range);

                bool  operator ==(const VectorN &)const; //Equality operator to check fi two vectors are equal

};

#endif

