/* This program requires the student to write 3 functions described in
 * Program project 4 (Page 535) and Program Project 6 (Page 536).
 * The student also need to add a print function to print out an array.
 * The student may watch video notes on MyProgrammingLab to get the idea
 * on how to write the main function and three of these four functions
 *
 * Author: Jocelyn Ji
 * Version: 8/30/20
 */

#include <iostream>
#include <string>
#include <cstdlib>
#include <stdio.h>
#include <string.h>
using namespace std;

void reverse(char* front, char* rear);
// Precondition: The front and rear are pointing to the front
//               and rear of a C-string, respectively
// Postcondition: The C-string is reversed

string* addEntry(string* dynamiccArray, int& size, string newEntry);
// Precondition: dynamicArray point to a array of strings with give size,
//               newEntry is a string
// Postcondition: A new dynamic array is created, which is one larger than
//                dynamicArray All elements from dynamicArray are copied to
//                new array, the new entry is added to new array, the size
//                is increased, the dynamicArray is deleted, new dynamic
//                array is returned.

string* deleteEntry(string* dynamicArray, int& size, string entryToDelete);
// Precondition: dynamicArray point to a array of strings with give size,
//               newEntry is a string
// Postcondition: The function should search dynamicArray for entryToDelete.
//                If not found, the request should be ignored and the
//                unmodified dynamicArray returned. If found, create a new
//                dynamic array one element smaller than dynamicArray. Copy
//                all element except entryToDelete into the new array, delete
//                dynamicArray, decrement size, and return the new dynamic
//                array

void print(const string* dynamicArray, int size);
// Precondition: dynamicArray point to a array of strings with give size,
// Postcondition: The elements in dynamic array will be print out. One
//                element per line forllowed by its index

int main()
{
	string *Darray;
	int Size=5;
	Darray= new string[Size];
	Darray[0]="Mouse";
	Darray[1]="Bee";
	Darray[2]="Wolf";
	Darray[3]="Cat";
	Darray[4]="Bridge";
	
	cout<<"The original array is: "<<endl;  
	print(Darray,Size);
	Darray = addEntry(Darray,Size,"Meep");
	Darray = addEntry(Darray,Size,"Mew");
	Darray = deleteEntry(Darray,Size,"Cat");
	
	cout<<"The new array is: "<<endl;
	print(Darray,Size);
	
	
	char *x,*y, *a,*b;			//testing reverse
	char E[5] = "abcd";
	char O[4] = "odd";
	x = &E[0]; y = &E[4]; a= &O[0]; b = &O[3];
	
	reverse(x,y); 
	cout<<"The reversed string is "<<E<<endl;
	
	reverse(a,b);
	cout<<"The reversed string is "<<O<<endl;
	
	

	
	
    // write code to test reverse function.
    // make sure that you test it on at least two strings
    // one string has even length, another string has odd length
    
    // write code to test add entry and delete entry function
    // you may watch video notes to get idea for this part
    
	
	return 0;
}

void reverse(char* front, char* rear)   
{
	
	if (*rear == '\0')  //if rear is null char, move on to char before null
	{
		rear--;
	}
	
	for (char ch; front < rear; front++, rear--)  //increment front address and decrement rear address after each swap 
	{
		ch = *front;
		*front = *rear;
		*rear = ch;
	}
}




string* addEntry(string* dynamicArray, int& size, string newEntry)
{
	string *NewDarray;
	NewDarray= new string[size+1];
	
	for(int i=0;i<size;i++)
	{
		NewDarray[i]=dynamicArray[i];
	}
	
	NewDarray[size]= newEntry;
	size++;
	delete[] dynamicArray;
	
	return NewDarray;
	
}

string* deleteEntry(string* dynamicArray, int& size, string entryToDelete)
{
	
	int x=0;							
	for (int i=0;i<size;i++)
	{
		if (dynamicArray[i]== entryToDelete)
		{
			x=i;		
		}
	}
		
	if (x!=0)
	{
		string* NewDarray;
		NewDarray= new string[size-1];
		for (int i=0;i<x;i++)				//copy entries before entry to delete
		{
			NewDarray[i]=dynamicArray[i];
		}
		for (int i=x;i<size-1;i++)		//copy entries after entry to delete
		{
			NewDarray[i]=dynamicArray[i+1];
		}
		size--;
		delete[] dynamicArray;
		
	
		return NewDarray;
	}
	else
	{
		return dynamicArray;
	}
			
}

void print(const string* dynamicArray, int size)
{
    for (int i=0;i<size;i++)
    {
    	cout<<dynamicArray[i]<<"  ";
    	if ((i+1)%10==0)   //new line every 7 elements for readability
    	{
    		cout<<endl;
    	}
    
	}
	cout<<endl; cout<<endl; 
}
