#include <iostream>
#include <fstream>
#include <cstdlib>
#include "JiJMoney.h"
#include "JiJMoney.cpp"
using namespace std;

int main()
{
	Money amount = (40.4);
	cout<<"Amount 1 is "<<amount<<".\n";
	Money amount2;
	cout<<"Input either - or an empty string, then input the amount in this structure:  $24.00\n";
	cin>>amount2; 
	cout<<"The amount inputted is "<<amount2<<".\n";
	
	Money amount3;
	if (amount<amount2)
	{
		cout<<"$40 is less than Amount 2.\n";
	}
	if (amount>amount3)
	{
		cout<<"$40 is more than $0.\n";
	}
	
	cout<<amount.percent(10)<<" is 10 percent of "<<amount<<".\n";
	
	return 0;
}

