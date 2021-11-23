//Juhwan Lee
//CS-162
//Program #4
//This program will help us to manage all the different links or
//appointments that we need to keep track of in order to be successful
//with a course

#include "list.h"

//The data members for the class:
/*
	link * array;
	int size_of_array;
	int num_of_links;
*/

//This is the list class constructor. It should initialize
//the data members to the zero equivalent value
list::list()
{
	cout << "How many links would you like: ";
	cin >> size_of_array;
	cin.ignore(100, '\n');

	array = new link[size_of_array];
	num_of_links = 0;
}

//Destructor will deallocate the dynamic memory
list::~list()
{
	if(NULL != array)
		delete [] array;
	array = NULL;
	size_of_array = 0;
	num_of_links = 0;
}

//Read in links until the user wants to stop
void list::read_all()
{
	char response = 'y'; 	//does the user want to do this again
	while(tolower(response) == 'y' && num_of_links < size_of_array)
	{
		array[num_of_links].read_link();
		++num_of_links;
		cout << "Again?: ";
		cin >> response;
		cin.ignore(100, '\n');
	}
}

//Display all links
void list::display_all()
{
	for(int i = 0; i < num_of_links; ++i)
		array[i].display_link();
}

//Search link
void list::search(char matching_name[])
{
	for(int i = 0; i < num_of_links; ++i)
	{
		if(array[i].is_match(matching_name))
		{
			array[i].display_link();
			return;
		}
	}
	cout << "There was no match" << endl;
}
