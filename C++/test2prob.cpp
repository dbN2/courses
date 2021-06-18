#include <iostream>

using namespace std;

struct Node
{
	int item;
	Node* link;
};
typedef Node* NodePtr;

void list_head_insert(NodePtr& head,int entry)
{
	Node *new_node;
	new_node->item = entry;
	new_node->link = head;
	head = new_node;
}
void list_head_remove(NodePtr& head)
{
	Node* new_node = head;
	head = head->link; 
	delete new_node;
}
NodePtr list_search(NodePtr head_ptr, int target)
{
	Node *here = head_ptr; 
    	if (here == NULL)
    	{
    		return NULL;
    	}
    	else
    	{
    		while(here->item !=target && here->link !=NULL) 
    		{
    			here = here->link;
    		}
    		if (here->item == target)
    		{
    			return here;
    		}
    		else
    		{
    			return NULL;
    		}
    	}
}

bool Account::withdraw(double x)
{
	if(balance>=x;)
	{
		balance -=x;
		return true;
	}
	return false;
}

void Account::setBalance(double amount)
{
	balance = amount;
}
double Account::getBalance()
{
	return balance;
}
void Savings::addInterest()
{
	balance = balance* (1+interest_rate/100.0);
}
	
