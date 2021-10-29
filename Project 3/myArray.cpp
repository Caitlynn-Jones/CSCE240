/*
*   Name: Caitlynn Jones
*   Email: caj16@email.sc.edu
*   Date: 10/04/2020 11:32 AM
*   Function: Various functions intended to mimic the ArrayList in Java
*   Functions include: 
*   Insert method that inserts a value into an array and resizes the array.
*   Remove method that removes selected value from array and resizes the array.
*   Get method that returns the value and indicated index
*   Clear method that clears all the values in the array to 0 and makes the size of array 0
*   Find method returns the index of element chosen and returns -1 if not found
*   Equals method returns true if the comparison of obj2 and object this are equal, returns false if not
*   Init method fills array with values inputted by user
*   Print method prints the values in the array
*
*   Inputs: Inputs all passed through the main except in init(), these float values are inputted from the user. Size is an int type and arrays are of type float.
*   Outputs: Get returns a float of the element at selected index. Find returns a float of element that was searched.
*   Equals returns a boolean, print cout's the array.
*   
*   Copyright 2020 by Caitlynn Jones
*/   
#include "myArray.h"



myArray::myArray() //default constructor
{
    size = 0;
    arr = new float[size]; 
}

myArray::myArray(int _size, float num) //alternate constructor, inputs passed in from main. Size defines how large array is and num are the values to populate the array
{
    size = _size;
    arr = new float[size];
    for(int i = 0; i < _size; i++) //setting all the elements in arr to num
    {
        arr[i] = num;
    }
}
myArray::myArray(float *_arr, int _size) //alternate constructor, inputs passed in from the main. 
{
    size = _size;
    arr = new float[size];
    for(int i = 0; i <_size; i++)
    {
        arr[i] = _arr[i];
    }
    
}
myArray::~myArray() //destructor
{
   delete [] arr; 
}
void myArray::insert (int index, float num)
{

    if(index <= size)
    {
        float *tempArr = new float[size+1]; //creating a temp array
        for(int i = 0; i < index; i++)
        {
            tempArr[i] = arr[i]; //moving values from temp array back to original array
        }
        tempArr[index] = num; //inserts the num in index passed in from the main
        for(int i = index+1; i < size+1; i++)
        {
            tempArr[i] = arr[i-1]; //i-1 is to counteract the size of the array since a new value was added
        }
        size++; //increases the size of the array
        delete [] arr;
        arr = tempArr; //setting array to the temp array
    }
    else if (index > size)
    {
        cout << "Error, index out of bounds" << endl;
    }
    
}
void myArray::remove(int index) //input from the main. Index is the location in the array of the value to be removed.
{
    if(index < size)
    {   
        for(int i = index; i < size-1; i++) //starting at target value 
        {
            arr[i] = arr[i+1]; //pushes the target value to end of array to be erased
        }
        arr[size-1] = 0; //erases the last element
        size--; //decreasing the size of the array since a value was removed
        
    }
    else if(index >= size) //if the index is larger than the size of the array print error message
    {
        cout << "Error, index out of bounds" << endl;
    }
}
float myArray::get(int index)
{
    if(index < size)
    {
        return arr[index]; //returns the element at the index inputted from the main
    }
    else if(index >= size) //if the index is larger than the size of the array prints error message
    {
        cout << "Error, index out of bounds" << endl;
    
    }
    return 0;

}
void myArray::clear()
{
    for(int i=0; i<size; i++)
    {
        arr[i] = 0; //sets the elements in array in order to clear
    }
    size = 0; //size of array is now zero
}
int myArray::find(float num)
{
    for(int i = 0; i < size; i++)
    {
        if(arr[i] == num) //if the value at index i is equal to num input from the main, return
        {
            return i;
        }
        else
        {
            return -1;
        }
        
    }
    return 0;
}
bool myArray::equals(myArray & obj2)
{
    if(&obj2 == this)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void myArray::init() 
{
    int input = 0;
    cout << "Please enter your values" << endl;
    for(int i = 0; i < size; i++)
    {
        cin >> input; //taking the input from the user to fill the array
        arr[i] = input; //filling the array with the inputs from the user

    }
    
}
void myArray::print() 
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << endl; //prints out the array
    }
}
