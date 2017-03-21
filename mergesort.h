#ifndef MERGESORT_H
#define MERGESORT_H

/**************************************************
Program:        Assignment 8 sorts.h template
Programmer:     Andrew Krutke
ZID:            z1756942
Due:            4/21/2015
Function:       mergesort.h header file
****************************************************/

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

//Function Protottypes

template <class T> void mergeSort(vector<T>&, bool (*)(const T&, const T&)); //merge sort prototype
template <class T> void mergeSort(vector<T>&, int, int, bool (*)(const T&, const T&)); //recursive mergeSort prototype
template <class T> void merge(vector<T>&, int, int, int, bool (*)(const T&, const T&)); //merge prototype


//Function Definitions

/************************************
MergeSort Function 1
Function: call the recursive mergeSort
	  function and pass it
	  elements
*************************************/

template <class T>
void mergeSort(vector<T>& set, bool (*compare)(const T&, const T&))
{
mergeSort(set, 0, (set.size()-1), compare);  //make the recursive call
}

/*************************************
MergeSort Function 2
Function: divides a vector into two
	  sub vectors, sorts and then
          merges the vectors
**************************************/

template <class T>
void mergeSort(vector<T>& set, int low, int high, bool (*compare)(const T&, const T&))
{
	int mid;
	
	if (low < high)
	{
	mid = (low + high) / 2;   //calculate mid

	//divide the vector
	
	mergeSort(set, low, mid, compare);
	mergeSort(set, mid + 1, high, compare);

	//combine the vectors
	merge(set, low, mid, high, compare);
	}
}

/*************************************
Merge Function
Function: merge the two sorted 
	  subvectors
**************************************/

template <class T>
void merge(vector<T>& set, int low, int mid, int high, bool (*compare)(const T&, const T&))
{
// Create temporary vector to hold merged subvectors
   vector<T> temp(high - low + 1);

   int i = low;      // Subscript for start of left sorted subvector
   int j = mid + 1;    // Subscript for start of right sorted subvector
   int k = 0;        // Subscript for start of merged vector

   // While not at the end of either subvector
   while (i <= mid && j <= high)
      {
     	if(compare(set[j], set[i]))
         {
	//copy element j of set into element k of temp
         temp[k]=set[j];
         ++j;
         ++k;
         }
      else
         {
        // Copy element i of set into element k of temp
        temp[k]=set[i];
	 ++i;
         ++k;
         }
      }

   // Copy over any remaining elements of left subvector
   while (i <= mid)
      {
     // Copy element i of set into element k of temp
      temp[k]=set[i];
      ++i;
      ++k; 
      }

   // Copy over any remaining elements of right subvector
   while (j <= high)
      {
      //Copy element j of set into element k of temp
      temp[k]=set[j];
      ++j; 
      ++k;
      }

   // Copy merged elements back into original vector
   for (i = 0, j = low; j <= high; i++, j++)
   {   //Copy element i of temp into element j of set
	set[j]=temp[i];;
   }
}

#endif
