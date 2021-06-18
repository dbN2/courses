#include <iostream>
#include <string>
using namespace std;

int hexToInt(string x)
{
	for (int i=0; i<x.size()-1; i++)
	{
		try
		{
			if (!isxdigit(x[i]))     //if char of string != hex digit
			{
				throw x[i];             
			}
		}
		catch(char a)
		{
			cout << "Invalid Number Exception: Non-hexadecimal input not allowed." << endl;
		}
	}
	
	int temp;
	int base = 1;
    for (int i=x.size()-1; i>=0; i--)  
    {
      if (x[i]>='0' && x[i]<='9')           //hex digits 0 to 9
	  {
         temp += (x[i] - 48)*base;
         base = base * 16;
      }
      else if (x[i]>='A' && x[i]<='F')     //hex digits A to F
	  {
         temp += (x[i] - 55)*base;
         base = base*16;
      }
    }
    return temp;
}

int main()
{
	string valid = "CDA";
	cout<<"The string " << valid<< " is converted to " << hexToInt(valid) <<endl;    //valid input
	

	
}
