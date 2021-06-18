#include <iostream>
#include <string>
#include <cstdlib>
#include "Book.cpp"
#include <algorithm>
#include <vector>
using namespace std;
using namespace BookDatabase;

void AddNewBook(vector<Book> &bookdata); //add a new book to the list
void PrintBooks(vector<Book> &bookdata); //print all books sorted by author
void SortBooks(vector<Book> &bookdata); //sort books by author
void PrintMenu(); //print menu of choices


int main()
{
	vector<Book> bookdata;
	int choice;
	
	do
	{
		PrintMenu();
		cin >> choice;
		cin.ignore();
		switch (choice)
		{
			case 1:
				AddNewBook(bookdata);
				break;
			case 2:
				PrintBooks(bookdata);
				break;
		}
		
	} while (choice != 3);   //exit program if choice is 3
	 
	return 0;
}


void AddNewBook(vector<Book> &bookdata)
{
	string newAuthor, newTitle, newDate;
	cout<< "Enter author name:" << endl;
	getline(cin, newAuthor);
	cout<< "Enter book title:" << endl;
	getline(cin, newTitle);
	cout<< "Enter book date:" << endl;
	getline(cin, newDate);
	
	Book book1(newAuthor, newTitle, newDate);
	bookdata.push_back(book1);
}

void PrintBooks(vector<Book> &bookdata)
{
	SortBooks(bookdata);
	for (unsigned int i = 0; i < bookdata.size(); i++)
	{
		cout << " " << bookdata[i].getAuthor() << ", " << bookdata[i].getTitle()
		<< ", " << bookdata[i].getDate() << endl;
	}
}

void SortBooks(vector<Book> &bookdata)
{
	sort(bookdata.begin(),bookdata.end());
}

void PrintMenu()
{
	cout<< "1. Add new book" << endl;
	cout<< "2. Print titles sorted by author" << endl;
	cout<< "3. Quit"<<endl;
}

