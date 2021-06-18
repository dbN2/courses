#include <string>
#include "Book.h"

namespace BookDatabase
{
	Book::Book() //default constructor
	{
		author = "";
		title = "";
		date = "";
	}
	
	Book::Book(string new_author, string new_title, string new_date) //parameter constructor
	{
		author = new_author;
		title = new_title;
		date = new_date;
	}
		
	void Book::setData(string new_author, string new_title, string new_date) //sets book data members to those given
	{
		author = new_author;
		date = new_date;
		title = new_title;
	}
	
	string Book::getAuthor() const //returns author of book
	{
		return author;
	}
	string Book::getTitle() const //returns title of book
	{
		return title;
	}
	string Book::getDate() const //returns date of book
	{
		return date;
	}
	bool operator<(const Book &book1, const Book &book2) //friend operator function for sorting use
	{
		return (book1.author < book2.author);
	}
}
