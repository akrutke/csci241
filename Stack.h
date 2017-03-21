/*********************************************
Program:	Assignment 7, Stack
Programmer:	Andrew Krutke
ID:		z1756942
Due:		4/14/2015
Function:	Create a Structure Node and 
		Class Stack
**********************************************/

#ifndef STACK_H		//head guards
#define STACK_H

#include <iostream>

using std::ostream;
using std::cout;
using std::cin;
using std::endl;
//Structure
template <class T>
struct Node
{

T data;		//data members of the structure
Node<T>* next;

Node(const T& = T(), Node<T>* next = NULL);   //Node Constructor

};

// Method definitions for the Node class
/***************************************
Constructor For struct Node
Function:  Set the values of  Node
****************************************/

template <class T>
Node<T>::Node(const T& newData, Node<T>* newNext)
	{
	data = newData;		//set the data members to null
	next = newNext;		//from the parameters provided
	}			//in calling function

// ************************************************************
// Forward declaration of the Stack template class
template <class T>
class Stack;
// Forward declaration of the operator<< template function
template <class T>
std::ostream& operator<<(std::ostream&, const Stack<T>&);

template <class T>
class Stack
{
   // friend declaration for the template function 
friend std::ostream& operator<< <>(std::ostream&, const Stack<T>&);

private:

	Node<T>* stkTop;      //top of the stack
	int stkSize;        //items currently stored in the stack
	void copyList(const Stack<T>&);   //copy list method
public:

	Stack();   		//constructor for Stack class
	~Stack();  		//destructor for Stack Class
	Stack(const Stack<T>&);	   //copy constructor	
	const Stack<T>& operator= (const Stack<T>&);  //assignment operator 
	T top() const;         //top of the stack
	void push(const T&);   //push method 
	void pop();		//pop method
	void clear();		//clear method
	int size() const;	//size method
	bool empty() const;	//empty method
};

// ***********************************************************
// Method definitions for the Stack class

/*********************************************
Default Constructor For Class Stack
Function: Set the values of class Stack
to 0 and Null.
**********************************************/

template <class T>
Stack<T>::Stack()
{
	stkTop=NULL;    //set the stack top to Null
	stkSize=0;	//and size to 0
}

/*********************************************
Copy Constructor
Function:  Copy the contents of Stack 
	   into a new Stack
**********************************************/

template <class T>
Stack<T>::Stack(const Stack<T>& stackToCopy)
{
   	stkTop = NULL;	//set the top of the stack to NULL

   	copyList(stackToCopy);   //call the copy list method

   	stkSize = stackToCopy.stkSize;  //set the size of the stack to the stackToCopy
}
/*********************************************
Destructor
Function: Deletes parts of the stack when 
	  called
**********************************************/

template <class T>
Stack<T>::~Stack()
{
	clear();  //call clear to delete dynamic storage
}

/********************************************
Assignment Operator
Function:  Assign the stack
*********************************************/

template <class T>

const Stack<T>& Stack<T>::operator=(const Stack<T>& rightOp)
{
  if (this != &rightOp)
	{
	clear();    //if this point is not to rightOp call clear
	
	copyList(rightOp);  //copy the linked list into rightOP
	stkSize = rightOp.stkSize;  //and set the stack size to rightOp

      	}

return *this;  //return the this pointer

}

/*********************************************
Top Method
Function:  return the data stored at the top
	   of the  stack, will not be called
           if the stack is empty
**********************************************/

template <class T>
T Stack<T>::top() const
{
	return stkTop->data;  //return the data in the top node of the stack

}

/*********************************************
Clear Method 
Function:  Clear the stack of current data
**********************************************/

template <class T>
void Stack<T>::clear()
{
	while( stkSize!=0)	//while the stack is not empty
	{

	pop();			//call pop to empty it

	}
}

/*********************************************
Size Method
Function:  Return the size of the class
	   Stack.
*********************************************/

template <class T>
int Stack<T>::size() const
{
return stkSize;  //return the stack size when called
}

/**********************************************
Empty Method
Function: Check to see if the Stack is empty
***********************************************/

template <class T>
bool Stack<T>::empty() const
{
	if(stkSize==0) //test if stkSize is empty
	{
		return true;
	}
	else
	{
		return false;   //return false when it is not empty
	}
}

/**********************************************
Push Method
Function: Move the item at the top of the Stack
***********************************************/

template <class T>
void Stack<T>::push(const T& item)
{
	Node<T>* newNode = new Node<T>(item, stkTop);  //set the top of the stack to dynamic storage

	stkTop = newNode;    //isert that item

	stkSize++;  //increment the stack size
}

/**********************************************
Pop Method
Function:  Remove the node at the top of the
	   stack. Will not call if the stack
	   is empty.
***********************************************/

template <class T>
void Stack<T>::pop()
{
	Node<T>* delNode = stkTop;    //set delNode to the top of the stack

	 stkTop = delNode->next;  //move to the next node at the top

	delete delNode;   //remove delNode to set the top node to NULL

	stkSize--;		//decrement the size of the Stack

}
/**********************************************
Copy List Method
Function:  Make a copy of the linked list for
	   the two classes
***********************************************/
template <class T>

void Stack<T>::copyList(const Stack<T>& stkToCopy)
{
	Node<T>* ptr, * newNode, * last = NULL;   //temp variables

   for (ptr = stkToCopy.stkTop; ptr != NULL; ptr = ptr->next)   
	{
		newNode = new Node<T>(ptr->data);  //dynamic storage

      		if (last == NULL)
	 	stkTop = newNode; //when last item in the stack is empty
				  //set the top to the dynamic storage node
		else
	 	last->next = newNode;  //otherwise the last item will
	 	last = newNode;		//be the new node
	}

}

/**********************************************
Print Function
Function:  Print the contents of the struct Node
           and the class Stack
***********************************************/

template <class T>
ostream& operator<< (ostream& leftOp, const Stack<T>& rightOp)
{
Node<T>* ptr;  //temp variable
for (ptr = rightOp.stkTop; ptr != NULL; ptr = ptr->next)

   leftOp << ptr->data << ' '; //print the structure data

return leftOp;  
}

#endif /* STACK_H */
