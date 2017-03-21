#ifndef VECTOR3_H
#define VECTOR3_H

#include <iostream>
using namespace std;

class Vector3
{		//overloaded ostream << operator
		friend ostream &operator << (ostream &, const Vector3 &);
		//overload multiplication operator declartion for multiplying the left operand
		friend Vector3 operator*(float ,const Vector3 &);

	private:  		//floating point values
		float x;
		float y;
		float z;

	public:

		
		Vector3(float newX=0,float newY=0, float newZ=0);	//default constructor - takes no arguments
		Vector3 operator+(const Vector3 &) const;  //addition operator overloading
		Vector3 operator-(const Vector3 &) const;  //subtraction "  "
		float operator * (const Vector3 &) const;  //scalar multiplication operator overload
		Vector3 operator*(float rightOp) const;   //multiply the vector by the right operand method
		float operator [](int index) const;      //subscrit operator for reading
		float &operator[](int index);		 //subcript operator for writing 
		bool  operator ==(const Vector3 &)const; //Equality operator to check fi two vectors are equal	

};

#endif
