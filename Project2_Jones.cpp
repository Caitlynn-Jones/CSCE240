/* Caitlynn Jones 9/16/2020 4:24PM
Description: Program asks user to input 10 integers. The program will then sort through the array from least to greatest.
Lastly, it will search the array for 1 or 99 and locate where it is in the sorted array.
Inputs: 10 integers seperated by the enter key.
Outputs: Program outputs an array of inputted integers and then prints the sorted array.
It will also print where, if found, the values 1 or 99
*/
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//Function Prototypes
void mySort(int arr[], int size);
int search(int arr[], int size, int element);
void readData(int arr[], int size);
void printData(int arr[], int size);


int main(int argc, char **argv)
{
    int data[10] = {0};
    //function calls
    readData(data, 10);
    printData(data, 10);
    mySort(data, 10);
    printData(data, 10);
    int indexFound = -999;
    indexFound = search(data, 10, 1); //searching for 1
    if(indexFound != -1)
    {
        cout << "The number 1 was found at index: " << indexFound << endl;
    }
    else
    {
        cout << "The number 1 was not found" << endl;
    }

    indexFound = search(data, 10, 99); //searching for 99
    if(indexFound != -1)
    {
        cout << "The number 99 was found at index: " << indexFound << endl;
    }
    else
    {
        cout << "The number 99 was not found" << endl;
    }

    return 0;
    
}

//Function definitions
void mySort(int arr[], int size) //bubble sort
{
    for(int i = 0; i < size-1; i++)
    {
        for(int j = 0; j < size-i-1; j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

}

int search(int arr[], int size, int element)
{
    for(int i = 0; i < size; i++)
    {
        if(arr[i] == element)
        {
            return i;
        }
    }
    return -1;
}

void readData(int arr[], int size)
{
    int userInput = 0;
    cout << "Please enter 10 integers:" << endl;
    for(int i = 0; i < 10; i++)
    {
        cin >> userInput;
        arr[i] = userInput;
    }
    
}

void printData(int arr[], int size)
{
    for(int i = 0; i <= size-1; i++)
    {
        cout << "Element at [" << i << "] is " << arr[i] << endl; 
    }
}
