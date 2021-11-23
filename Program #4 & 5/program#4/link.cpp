//Juhwan Lee
//CS-162
//Program #4
//This program will help us to manage all the different links or
//appointments that we need to keep track of in order to be successful
//with a course

#include "link.h"

/*
The data members are:
	char * name;
	char * link_itself;
	char * reason;
	int time;
	char * info;
	char * important_info;
*/

//This is the link constructor and it should initialize all of the
//data members in the link class
link::link()
{
	name = NULL;
	link_itself = NULL;
	reason = NULL;
	time = 0;
	info = NULL;
	important_info = NULL;
}

//Write the code to deallocate the dynamic memory in a destructor
link::~link()
{
	if(NULL != name)
		delete [] name;
	if(NULL != link_itself)
		delete [] link_itself;
	if(NULL != reason)
		delete [] reason;
	if(NULL != info)
		delete [] info;
	if(NULL != important_info)
		delete [] important_info;
	name = NULL;
	link_itself = NULL;
	reason = NULL;
	info = NULL;
	important_info = NULL;
}

//This function will read in a link after prompting the user
void link::read_link()
{
	char temp1[100];
	char temp2[100];
	char temp3[100];
	char temp4[100];
	char temp5[100];

	cout << "Please enter a name of the link: ";
	cin.get(temp1, 100, '\n');
	cin.ignore(100, '\n');

	//size the name just right
	name = new char [strlen(temp1) + 1];
	strcpy(name, temp1);

	cout << "Please enter a link itself: ";
	cin.get(temp2, 100, '\n');
	cin.ignore(100, '\n');

	//size the link itself just right
	link_itself = new char [strlen(temp2) + 1];
	strcpy(link_itself, temp2);

	cout << "Please enter a reason for the link: ";
	cin.get(temp3, 100, '\n');
	cin.ignore(100, '\n');

	//size the reason just right
	reason = new char [strlen(temp3) + 1];
	strcpy(reason, temp3);

	cout << "Please enter the amount of time you need to "
	<< endl << "allocate for this activity (in mins): ";
	cin >> time;
	cin.ignore(100, '\n');

	cout << "Please enter if it involves other information: ";
	cin.get(temp4, 100, '\n');
	cin.ignore(100, '\n');

	//size the info just right
	info = new char [strlen(temp4) + 1];
	strcpy(info, temp4);

	cout << "Please enter other important information: ";
	cin.get(temp5, 100, '\n');
	cin.ignore(100, '\n');

	//size the important info just right
	important_info = new char [strlen(temp5) +1];
	strcpy(important_info, temp5);
}

//This function will display the contents of the link object
void link::display_link()
{
	if(NULL == name)	return;
	if(NULL == link_itself) 	return;
	if(NULL == reason) 	return;
	if(NULL == info) 	return;
	if(NULL == important_info) 	return;
	cout << name << endl << link_itself << endl << reason << endl
	<< time << " mins" << endl << info << endl << important_info
	<< endl << "_______________________" << endl;
}

//Compare the name
bool link::is_match(char matching_name[])
{
	if(NULL == name) 	return false;
	if(strcmp(matching_name, name) == 0)
		return true;
	return false;
}
