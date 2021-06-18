#include <iostream>
#include <stdlib.h>
#include "CSCI361Proj5.h"

using namespace std;
using namespace FHSULINKEDLIST;

namespace FHSULINKEDLIST
{
    // FUNCTIONS for the linked list toolkit
    
    size_t list_length(const Node* head_ptr)  //gets length of linked list 
    {
    	int count = 0;
    	const Node* new_node;
		new_node = head_ptr;
    	while (new_node != NULL)
    	{
    		count ++;
    		new_node = new_node -> link;
    	}
    	return count;
    }
    
    void list_head_insert(Node*& head_ptr, const Node::Item& entry) //inserts node at head 
    {
    	Node *new_node = new Node;  
    	new_node->data = entry;   
    	new_node->link = head_ptr;  //makes new node the new head node
    	head_ptr = new_node;  
    }
    
    void list_insert(Node* previous_ptr, const Node::Item& entry) //inserts node after given previous node
    {
    	Node *new_node = new Node;
    	new_node->data = entry;
    	new_node->link = previous_ptr->link; //updates order of nodes
    	previous_ptr->link = new_node; 
    }
    
    Node* list_search(Node* head_ptr, const Node::Item& target) //searches linked list for data and returns its node
    {
    	Node *here = head_ptr; 
    	if (here == NULL)
    	{
    		return NULL;
    	}
    	else
    	{
    		while(here->data !=target && here->link !=NULL) 
    		{
    			here = here->link;
    		}
    		if (here->data == target)
    		{
    			return here;
    		}
    		else
    		{
    			return NULL;
    		}
    	}
	}
    
    Node* list_locate(Node* head_ptr, size_t position) //searches linked list for node at given position
    {
    	Node *current = head_ptr;
    
    	int count = 1;
    	while (current!=NULL)
    	{
    		if (count==position)
    		{
    			return current;
    		}
    		count++;
    		current = current->link;
    	}
    	return current;
    }
    
    void list_head_remove(Node*& head_ptr) //removes head of linked list and updates the order
	{
		Node* new_node = head_ptr;
		head_ptr = head_ptr->link; 
		delete new_node;
	}
	
    void list_remove(Node* previous_ptr) //removes node after given previous node
    {
    	Node* new_node = previous_ptr->link;
    	previous_ptr->link = new_node->link;
    	delete new_node;
    }
    
    void list_clear(Node*& head_ptr)  //removes all nodes in linked list
    {
		Node* current = head_ptr->link; //start at node after head
	    while(current!=NULL)
	    {
	    	head_ptr->link = current->link; 
	    	delete current;
	    	current = head_ptr->link;
	    }
	    head_ptr = NULL;
    }
    
    void list_copy(Node* source_ptr, Node*& head_ptr) //copies linked list 
    {
    	head_ptr = NULL;
   		Node *tail_ptr = NULL;
 
   		if (source_ptr == NULL)
      	return;
      	
   		list_head_insert(head_ptr, source_ptr->data);
   		tail_ptr = head_ptr;
   		
   		for (source_ptr = source_ptr->link; source_ptr != NULL; source_ptr = source_ptr->link)
   		{
      		list_insert(tail_ptr, source_ptr->data);
      		tail_ptr = tail_ptr->link;
   		}
    }
    
    size_t list_occurrences(Node* head_ptr, const Node::Item& target) //returns number of occurences of node with given data in the linked list
    {
    	Node* new_node = head_ptr;
    	int count = 0;
    	while (new_node!=NULL)
    	{
    		if (new_node->data == target) 
    		{
    			count++;
    		}
    		new_node= new_node->link;
    	}
    	return count;
    }
    
    void list_tail_attach(Node*& head_ptr, const Node::Item& entry) //inserts node at tail of linked list
    {
    	Node* new_node = new Node;
    	new_node->data = entry;
    	new_node->link = NULL;
    	if (head_ptr == NULL)
    	{
    		head_ptr = new_node;
    	}
    	else
    	{
    		Node *temp = new Node;
    		temp = head_ptr;
    		while(temp->link!=NULL)
    		{
    			temp = temp->link;
    		}
    		temp->link = new_node;
    	}
    }
    
    void list_tail_remove(Node*& head_ptr) //removes node at tail of linked list
	{
    	if(head_ptr == NULL)
        return;

    	if(head_ptr->link == NULL)
   		 {
     	    delete head_ptr;
    		head_ptr = NULL;
   	     	return;
  	 	 }

   	 	Node* current = head_ptr;
   		while (current->link && current->link->link != NULL)
    	{
   	    	current = current->link;
    	}
    	delete current->link;
    	current->link = NULL;
	}
	
    	Node* list_copy_front(Node* source_ptr, size_t n) //copies linked list and returns the node at the head
    {
    	if (source_ptr == NULL)
    	{
    		return NULL;
    	}
       
       	Node *temp = NULL;  
    	Node *new_node = source_ptr;  

    	int i = 0;   // Initializes temp variable

    	while(new_node!= NULL && i < n)   // Loop that continues while n is bigger than i and it is not NULL
    	{
        	list_tail_attach(temp, new_node->data); //allows head node to be returned 
        	new_node = new_node->link;  
        	i++;    
    	}
    	return temp;
    }
}



