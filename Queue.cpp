/*********************************************
Program:	Assign 6, Queue Program
Programmer:	Andrew Krutke
Due Date:	4/7/2015

Function:	Source code for the Queue ADT
		that will test the fuctions of
		the Queue class
**********************************************/

#include <iostream>
#include <stdexcept>
#include "Queue.h"

using std::underflow_error;
using namespace std;

/*********************************************
Defualt constructor
Function: Create a constructor and set the
	  Queue values to 0 and the rear and 
	  front of the Queue to -1
**********************************************/

Queue::Queue()
{

qCap=1;   //capcaity, size and front of the Queue
qSize=0;
qFront=0;
qRear = qCap - 1;  //Rear will be equal to the cap minus one
qArray = new int [qCap];  //the new qArray of dynamically allocated  array of ints

}

/***********************************
Copy Constructor
Function: Copy the contents of an
	  exsisting Queue
************************************/

Queue::Queue(const Queue & other)
{
	qCap = other.qCap;	//set the values to be copied
	qSize = other.qSize;
	qArray= new int[qCap];   //put the array into Dynamic storage

	for( unsigned i = 0; i < qCap; i++)
	{	//loop through i while its less than the capacity

	qArray[i] = other.qArray[i];   //to copy the new Array

	}
	qFront = other.qFront;  //copy the front and rear
	qRear = other.qRear;
}

/***********************************
Destructor
Function: Delete the DAM
************************************/

Queue::~Queue()
{

delete[] qArray;  //delete dynamic storage on the qArray

}

/***********************************
Assignment Operator
Function: Assign Queues to each
	  other
************************************/

Queue& Queue::operator=(const Queue & rightOp)
{
	if(this != &rightOp)  //if the the object pointed to can't be used
	{
	qSize= rightOp.qSize;

		delete[] qArray;  //delete the dynamic storage

	qCap = rightOp.qCap;		//set the values of the queue to the rightOp
	qFront = rightOp.qFront;
	qRear = rightOp.qRear;	
		
	qArray = new int[rightOp.qSize];  //set the new array to qSize

	for ( int i= 0; i < rightOp.qSize; i ++)   //loop throught with the righOperand
		{

		 qArray[i]= rightOp.qArray[i];   //and make the Queue array set to the right operand

		}
	
	}
return *this;   //return the pointed to object
}

/***********************************
Size Method
Function: Find the size of Queue
************************************/

int Queue::size() const
{

unsigned queSize;  //set qSize to an unsigned variable
queSize=qSize;
return queSize;  //return that unsigned variable

}

/***********************************
Capacity Method
Function: return the capacity of the
	  Queue
************************************/

int Queue::capacity() const
{

unsigned queCap;  //set qCap to an unsigned variable
queCap=qCap;
return queCap;   //return the unsigned variable

}

/***********************************
Empty Method
Function: test to see if the 
	  Queue is empty
***********************************/

bool Queue::empty() const
{

if (qSize==0)   //test the Queue size for full ness
 return true;	//return true if it is empty
else 
 return false;  //false otherwise

}
/************************************
Push Method
Function: Insert an item into the 
	  Queue. Check to see if it is
 	  full. If it is wrap around 
	  to the front of it.
*************************************/

void Queue::push(int q)

{
	if (qCap==qSize)   //test the fullness of the Queue
	{
	reserve(qCap * 2);    //increase the Queue capacity
	}
	
	qRear = (qRear + 1) % qCap;   //wrap the rear of the Queue
	qArray[qRear] = q;   //set the array to the passed varabile
	qSize++;     //incriment the size of the Queue
}

/************************************
Pop Method
Function: check to see if the Queue 
	  is empty. Throw an exception
	  If no exception, incrment the 
	  the front, decremnent the 
	  Queue size.
*************************************/

void Queue::pop()
{
	if(qSize == 0)  //check if the Queue is empty
	    {
		throw underflow_error("Queue underflow on pop()");  //throw the exception
	    }
	
	qFront =(qFront +1) % qCap;  //wrap the front of the Queue
	qSize--;     //decrement the size of the Queue
}

/************************************
Front Method
Function: No arguments,throw an 
	  exception for empty
	  Queue. Return the front of 
	  Queue
*************************************/

int Queue::front() const
{
	if(qSize==0)  //if the Queue size is empty throw  an underflow exception
	{
		throw underflow_error(" Queue underflow on front()");
	}

return qArray[qFront];  //return the front item of the Queue

}

/************************************
Back Method
Function: No arguments, returns the
	  rear item of the Queue. 
	  Throw an exception if the 
	  Queue is empty
*************************************/

int Queue::back() const
{
	if (qSize==0)  //if the Queue is empty throw underflow exception
	{
	throw underflow_error("Queue underflow on back()");
	}
return qArray[qRear];   //return the rear item in the Queue
}

/************************************
Clear Method
Function: Clear the method and set it
	  back to the intial state
*************************************/

void Queue::clear() 
{
	delete[] qArray;  //delete Dynamic storage
	qSize = 0;		//intialize all variables to starting value
	qCap = 1;
	qFront = 0;
	qRear = qCap-1;
	qArray = new int [qCap];   //restore a new qArray
}

/************************************
Reserve Function
Function: use an unsigned integer, and
	  new array toextend the 
	  capacity of the Queue
*************************************/

void Queue::reserve(unsigned newCap)
   {
   int* copyArray = new int[newCap];  //create dynamic storage for a new array
   int current = qFront;     //value for manipulation

   for (unsigned i = 0; i < qSize; i++)
      {
      copyArray[i] = qArray[current]; 

      current = (current + 1) % qCap;  //wrap the Queue
      }
   qCap = newCap;  //make a new capacity to reserve storage

   delete[] qArray;  //delete dynamic storage

  qArray = copyArray;  //set the new array with new rear anf front values
  qFront = 0;
  qRear = qSize -1;

}

/************************************
Print Method
Function: Print the contentes of the 
	  Queue.
*************************************/

ostream & operator<<(ostream & leftOp, const Queue & rightOp)
{
int current, i;
      
for (current = rightOp.qFront, i = 0; i < (int) rightOp.qSize; ++i)
   {
   // Print queue element at subscript i
   leftOp << rightOp.qArray[current] << ' ';
   
   // Increment i, wrapping around to front of queue array if necessary     
   current = (current + 1) % rightOp.qCap;
   }

return leftOp;  
}
