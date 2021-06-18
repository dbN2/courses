#ifndef JIJMONEY_H
#define JIJMONEY_H
#include <iostream>
using namespace std;

class Money {
	public:
		friend istream& operator >>(istream& ins, Money& amount);  //overloaded input operator
		friend ostream& operator <<(ostream& outs, const Money& amount);  //overloaded output operator
		friend bool operator <(const Money& left_side, const Money& right_side);  //overloaded less than operator
		friend bool operator <=(const Money& left_side, const Money& right_side); //overloaded lessthan or equal to operator
		friend bool operator >(const Money& left_side, const Money& right_side); //overloaded greater than operator
		friend bool operator >=(const Money& left_side, const Money& right_side); //overloaded greater than or equal to operator
		Money(long dollars, int cents);  //constructor
		Money(long dollars); //constructor
		Money(); //default constructor
		Money percent(int percent_figure) const;  //returns value of Money class object, multiplied by the percentage inputted.
	private:
		long all_cents;
	};
	
	#endif
