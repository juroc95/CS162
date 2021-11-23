//Juhwan Lee
//CS-162
//Program #4
//This program will help us to manage all the different links or
//appointments that we need to keep track of in order to be successful
//with a course

#include "list.h"

int main()
{
	char response = 'y'; 	//to check if the user wants to search

	list link_library;
	link_library.read_all();

	cout << "Do you want to search link?: ";
	cin >> response;
	cin.ignore(100, '\n');

	while(tolower(response) == 'y')
	{
		char matching_name[100];
		cout << "Please enter a name of the link: ";
		cin.get(matching_name, 100, '\n');
		cin.ignore(100, '\n');
		link_library.search(matching_name);
		cout << "Do you want to search again?: ";
		cin >> response;
		cin.ignore(100, '\n');
	}

	link_library.display_all();

	return 0;
}
