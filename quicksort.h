#ifndef QUICKSORT_H
#define QUICKSORT_H
/**************************************************
Program:        Assignment 8 quicksort.h template
Programmer:     Andrew Krutke
ZID:            z1756942
Due:            4/21/2015
Function:       quicksort.h header file 
****************************************************/

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>


using namespace std;

template <class T> void quickSort(vector<T>&, int, int, bool (*)(const T&, const T&));  // quicksort prototype
template <class T> void quicksort(vector<T>&, int, int, bool (*)(const T&, const T&));  //recrusive quicksort prototype
template <class T> int partition(vector<T>&, int , int, bool (*)(const T&, const T&));  // partition prototype

/************************************************
QuickSort Method 1
Function: sort the elements in the vector set
	  using quicksort algorithm
*************************************************/

template <class T>
void quickSort(vector<T>& set, bool (*compare)(const T&, const T&))
{
quickSort(set, 0, (int) set.size() - 1, compare);  //call the recursive quicksort function
}

/************************************************
Quicksort Function 2
Function: performs the recursive calls 
	  of the quick sort function
*************************************************/

template <class T>
void quickSort (vector<T>& set, int start, int end, bool (*compare)( const T&, const T&))
{
int pivotPoint;

   if (start < end)
      {
      pivotPoint = partition(set, start, end, compare);     // Get the pivot point
      quickSort(set, start, pivotPoint - 1, compare);       // Sort first sublist
      quickSort(set, pivotPoint + 1, end, compare);         // Sort second sublist
      }
}

template <class T>
int partition (vector<T>& set, int start, int end, bool (*compare)(const T&, const T&))
{
	int pivotIndex, mid;
	T pivotValue;

		mid = (start + end) / 2;  //calculate mid

		swap(set[start],set[mid]);	//swap the elements in the vector
		

	pivotIndex = start;  //set the index to start
	pivotValue= set[start];  //and the value to an element start of set

	
	for (int scan = start+1; scan <= end; scan++)
	{
		if (compare(set[scan], pivotValue))
		//swap elements pivotIndex and scan of the vector	
			{
			pivotIndex++;  
			swap(set[pivotIndex], set[scan]);  //swap the elements in the vector
			}
	}
//swap elements start and pivotIndex of the vector
swap(set[start],set[pivotIndex]);

return pivotIndex;
}



#endif
