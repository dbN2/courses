#include <iostream>
#include <fstream>
#include <cctype>
#include <cstdlib>
#include "JiJMoney.h"

using namespace std;

int digit_to_int(char c);

Money::Money(long dollars, int cents) //constructor
{
	if (dollars*cents < 0)
	{
		cout << "Invalid input for dollars and cents.\n";
		exit(1);
	}
	all_cents = dollars * 100 + cents;
	
}

Money::Money(long dollars)  //constructor
{
	all_cents = dollars * 100;
}

Money::Money()   //default constructor
{
	all_cents = 0;
}

Money Money::percent(int percent_figure) const   //returns Money object times the percentage given
{
	return static_cast<double>(all_cents) * static_cast<double>(percent_figure) / 10000;
}


istream& operator >> (istream& ins, Money& amount)  //overloaded input operator
{
	char one_char, decimal_point, digit1, digit2;
	long dollars;
	int cents;
	bool negative;
	
	ins >> one_char;
	if (one_char == '-') //if negative
	{
		negative = true;
		ins >> one_char;
	}
	else
	{
		negative = false;
	}
	ins >> dollars >> decimal_point >> digit1 >> digit2;
	if(one_char != '$' || decimal_point  != '.' || !isdigit(digit1) || !isdigit(digit2))
	{
		cout<< "Invalid form for money input.\n";  
		exit(1);
	}
	cents = digit_to_int(digit1)*10 + digit_to_int(digit2);
	amount.all_cents = dollars * 100 +cents;
	if(negative)
	{
		amount.all_cents = -amount.all_cents;
	}
	
	return ins;
}

int digit_to_int(char c)   //changes digit  to int type
{
	return (static_cast<int>(c) - static_cast<int>('0'));
}

ostream& operator <<(ostream& outs, const Money& amount)  //overloaded output operator
{
	long positive_cents, dollars, cents;
	positive_cents = abs(amount.all_cents);
	dollars = positive_cents / 100;
	cents = positive_cents % 100;
	
	if (amount.all_cents < 0)
	{
		outs << "-$" << dollars << '.';
	}
	else{
		
		outs << "$" << dollars << '.';
	}	
	
	if (cents <10)
	{
		outs << 0;
	}
	else{
		
		outs << cents;
	}
	return outs;
}

bool operator <(const Money& left_side, const Money& right_side) //overloaded < operator
{
	return left_side.all_cents < right_side.all_cents;
}
bool operator <=(const Money& left_side, const Money& right_side) //overloaded <= operator
{
	return left_side.all_cents <= right_side.all_cents;
}
bool operator >(const Money& left_side, const Money& right_side) //overloaded > operator
{
	return left_side.all_cents > right_side.all_cents;
}
bool operator >=(const Money& left_side, const Money& right_side) //overloaded >= operator
{
	return left_side.all_cents >= right_side.all_cents;
}

