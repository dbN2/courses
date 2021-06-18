
#include <iostream>
#include <iomanip>
using namespace std;

class CDAccount
{
public:
    CDAccount();
    CDAccount(double new_balance, double new_interest_rate, int new_term);
    double get_initial_balance() const;
    double get_balance_at_maturity() const;
    double get_interest_rate() const;
    int get_term() const;
    void input(istream& in);
    void output(ostream& out);
    
private:
    int dollar=0;
    int cent=0;
    double balance;
    double interest_rate=0; 
    int term=0; // months until maturity
    
};

int main()
{
	CDAccount acc(800,5,12);
	acc.output(cout);
    cout<<"Input a balance, interest rate in percent, and term \n";
    acc.input(cin);
    acc.output(cout);

}

	CDAccount::CDAccount(){    //constructor allows default declaration
		balance = 0;
		interest_rate = 0;
		term = 0;
	}
	
	CDAccount::CDAccount(double new_balance, double new_interest_rate, int new_term){  //function specifies declaration of variables of type CDAccount 
    	balance = new_balance;
    	interest_rate = new_interest_rate;
    	term = new_term;
    }
    	
    double CDAccount::get_initial_balance() const{  //returns balance
    	return balance;
    }
    
    double CDAccount::get_balance_at_maturity() const{    //returns balance after maturity
    	double interest = balance*(interest_rate/100) * (term/12.0);
    	return balance + interest;
    }
    
    double CDAccount::get_interest_rate() const{  //returns interest rate
    	return interest_rate;
    }
    
    int CDAccount::get_term() const{   //returns term
    	return term;
    }

	void CDAccount::input(istream& in){
   		in >> balance; // get initial balance from user
    
    	// convert balance to dollars and cents since this is how balance stored
    	dollar = (int) balance; // dollar is the interger part of balace
    	cent = (int) ((balance - dollar)*100); // cent is the fraction part * 100
    
    	in >> interest_rate; // get interest rate from user
    	in >> term; // get term from user
	}
	
    void CDAccount::output(ostream& out){   //outputs the interest rate, initial and final balance, and term to cout
        out << fixed << showpoint;  
    	out.precision(2);
    	out << "Interest Rate: " << get_interest_rate()<<endl;
    	out << "Account Maturity Time: "<<get_term()<<" Months"<<endl;
    	out << "Initial Balance: "<<get_initial_balance()<<endl;
    	out << "Balance at Maturity: "<<get_balance_at_maturity()<<endl;
    }
