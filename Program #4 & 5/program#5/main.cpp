//Juhwan Lee
//CS-162
//Program #5
//This program will help us to manage all the different links or
//appointments that we need to keep track of in order to be successful
//with a course (this time with LLL)

#include "list.h"

int main()
{
	node * head;
	link newdata;
	char response = 'y';
	char matching_name[100];

	//read in links from the user
	read_all(head, newdata);

	//search link
	cout << "Do you want to search link?: ";
	cin >> response;
	cin.ignore(100, '\n');
	while(tolower(response) == 'y')
	{
		cout << "Please enter a name of the link: ";
		cin.get(matching_name, 100, '\n');
		cin.ignore(100, '\n');
		search(head, matching_name);
		cout << "Again?: ";
		cin >> response;
		cin.ignore(100, '\n');
	}

	//display all links
	display_all(head);

	//deallocate LLL
	remove_all(head);

	return 0;
}
