//Juhwan Lee
//CS-162
//Program #5
//This program will help us to manage all the different links or
//appointments that we need to keep track of in order to be successful
//with a course (this time with LLL)

#include "list.h"

//This function will read in links as much as the user wants
void read_all(node * & head, link & newdata)
{
	char response = 'y';
	head = new node;
	node * current = head;
	newdata.read_link();
	current -> data = newdata;
	current -> next = NULL;
	cout << "Again?: ";
	cin >> response;
	cin.ignore(100, '\n');
	while(tolower(response) == 'y')
	{
		current -> next = new node;
		current = current -> next;
		newdata.read_link();
		current -> data = newdata;
		current -> next = NULL;
		cout << "Again?: ";
		cin >> response;
		cin.ignore(100, '\n');
	}
}

//This function will display all the links
void display_all(node * head)
{
	if(NULL == head)
		return ;
	node * current = head;
	while(current != NULL)
	{
	 	current -> data.display_link();
		current = current -> next;
	}
}

//This function will search link
void search(node * head, char matching_name[])
{
	if(NULL == head)
		return;
	node * current = head;
	while(current != NULL)
	{
		if(current -> data.is_match(matching_name))
		{
			cout << "There is a match" << endl;
			current -> data.display_link();
			return;
		}
		else
			current = current -> next;
	}
	cout << "There is no match" << endl;
}

//This function will deallocate dynamic memory
void remove_all(node * & head)
{
	if(NULL == head)
		return;
	if(NULL == head -> next)
	{
		delete head;
		head = NULL;
	}
	else
	{
		node * current = head;
		current = current -> next;
		while(current != NULL)
		{
			delete head;
			head = current;
			current = current -> next;
		}
		delete head;
		head = NULL;
	}
}
		

