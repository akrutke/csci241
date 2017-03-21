/***************************************************
Program:	Assignment 6: Queue Program
Programer:	Andrew Krutke
Due Date:	4/7/2015

Function: 	Header file for the ADT class Queue
****************************************************/
#ifndef QUEUE_H		//header gaurds
#define QUEUE_H

using namespace std;

class Queue
{
friend ostream & operator <<(ostream &, const Queue &);  //print function



public:

Queue(); //default constructor
~Queue();  //destructor
Queue(const Queue &other);  //copy constructor
Queue& operator=(const Queue& rightOp);   //assignment operator

bool empty() const; //empty method
void clear();		//clear method
int size() const;	//size of Queue method
int capacity() const;	//capacity of Queue method
void push(int);		//push method
void pop();		//pop method
void reserve(unsigned);// reserve capacity for the Queue
int front() const;   //front method
int back() const;


private:

int* qArray;  //values to hold Queue data, to manipulate the array
int  qCap;    //capacity of the queue
int  qSize;   //size of the queue
int  qFront;  //front of the queue
int  qRear;	//rear of the queue

};

#endif
