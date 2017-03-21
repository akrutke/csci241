/**********************************
Program:	Assignment 9
Programmer:	Andrew Krutke
Due:		4/28/2015
LOGON ID	z1756942
**********************************/
#include <vector>
#include <iostream>
#include <string>
#include <iomanip>
#include <typeinfo>

#include "shape.h"
#include "circle.h"
#include "rectangle.h"
#include "triangle.h"

using namespace std;

int main()
{
//set output format
cout << fixed << setprecision(2);

//shape vector
vector <Shape *>shapes(6);

//passing value to the different classes
shapes[0]= new Circle("green", 10);
shapes[1]= new Rectangle("red" , 8, 6);
shapes[2]= new Triangle ("yellow", 8, 4);
shapes[3]= new Triangle ("black", 4, 10);
shapes[4]= new Circle ("orange", 5);
shapes[5]= new Rectangle ("blue", 3, 7);



//print the contents of the shapes
for (unsigned i =0; i < shapes.size(); ++i)
{
	shapes[i] -> print();
}

//loop through to print only triangles
cout << "Print only triangles..."<<endl;
for (unsigned i=0; i < shapes.size(); ++i)
{
//cout << "Print only triangles..."<<endl; 
Triangle* tptr = dynamic_cast < Triangle* >(shapes[i]);
if (tptr!= NULL )		//tptr = triangle point
{
	tptr-> print();		//call the print method with tptr
}
}

//deleted the storage in memory of shapes
for (unsigned int i=0; i < shapes.size(); ++i)
{
delete shapes[i];
}

return 0;
}
