#include <iostream>
using namespace std;

struct EmployeeRecord {

	EmployeeRecord(){
		rate = 5.0;
		vacation = 5;
		status = 'h';
	}
	float rate;
	int vacation;
	char status;
};

int main(){
	
	
	
	return 0;
}

//	int Student::get_id(){
//		return id;
//	}

//5.
double OrderList::total_cost(double cost[],int num){
	double sum=0;
	for (int i=0;i<num;i++){
		sum+=cost[i];
	}
	return sum;
}
		
	
