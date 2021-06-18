#include <iostream>
using namespace std;
int main()
{
}

struct node
{
	int data;
	node *link;
};

class list
{
	private:
		node *head, *tail;
	public:
		list()
		{
			head = NULL;
			tail = NULL;
		}
		void createnode(int value);
		node* search(int target);
};

 void list::createnode(int value)
    {
      node *temp=new node;
      temp->data=value;
      temp->link=NULL;
      if(head==NULL)
      {
        head=temp;
        tail=temp;
        temp=NULL;
      }
      else
      {	
        tail->link=temp;
        tail=temp;
      }
    }
    
node* search(int target)
{
	node * here = head;
	if (here == NULL)
	{
		return NULL;
	}
	else
	{
		whi
