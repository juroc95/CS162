//Juhwan Lee
//CS-162 Program #3
//This program will help keep track of the best ideas for stay and home
//vacations

#include <iostream>
#include <cctype>
#include <cstring>
#include <fstream>
using namespace std;

//constants
const int NAME = 31;
const int INFO = 131;
const int ACTIVITIES = 10;

//structure
struct activity
{
	char name[NAME];
	char description[INFO];
	char materials[INFO];
	char requirements[INFO];
};

//prototypes
void read_activities(activity library[], int & num_of_activities);
void read_an_activity(activity & an_activity);
void display_an_activity(activity & one_activity);
int load(activity library[]);
void save(activity library[], int number_to_save);
void search(activity library[], int num_of_activities);
void display_activities(activity library[], int num_of_activities);

//main function
int main()
{
	activity library[ACTIVITIES];
	int num_of_activities = 0;
	char response = 'y';
	num_of_activities = load(library);

	while('Y' == toupper(response))
	{
		read_activities(library, num_of_activities);
		search(library, num_of_activities);
		display_activities(library, num_of_activities);
		save(library, num_of_activities);

		cout << "Do you want to do it again?: ";
		cin >> response;
		cin.ignore(100, '\n');
	}
	return 0;
}

//read information from the file
int load(activity library[])
{
	ifstream file_in;
	int i = 0;

	file_in.open("staycation.txt");
	if(file_in) //we connected by not being false
	{
		file_in.get(library[i].name, NAME, '|');
		file_in.ignore(100, '|');

		while(!file_in.eof() && i < ACTIVITIES)
		{
			file_in.get(library[i].description, INFO, '|');
			file_in.ignore(100, '|');
			file_in.get(library[i].materials, INFO, '|');
			file_in.ignore(100, '|');
			file_in.get(library[i].requirements, INFO, '|');
			file_in.ignore(100, '|');
			++i;
			file_in.get(library[i].name, NAME, '|');
			file_in.ignore(100, '|');
		}
		file_in.close();
	}
	return i;
}

//read all of the activities in that the user wants
void read_activities(activity library[], int & num_of_activities)
{
	int i = num_of_activities;
	char response = 'n';
	cout << "Do you want to read in a new activity?: ";
	cin >> response;
	cin.ignore(100, '\n');

	while('Y' == toupper(response) && i < ACTIVITIES)
	{
		read_an_activity(library[i]);
		cout << "Another?: ";
		cin >> response;
		cin.ignore(100, '\n');
		++i;
	}

	//update the number of activities
	num_of_activities = i;
}

//read in an activity and store it in the argument that is passed by reference
void read_an_activity(activity & an_activity)
{
	cout << "Please enter the activity name: ";
	cin.get(an_activity.name, NAME, '\n');
	cin.ignore(100, '\n');

	cout << "Enter description about the activity: ";
	cin.get(an_activity.description, INFO, '\n');
	cin.ignore(100, '\n');

	cout << "Enter a list of materials needed: ";
	cin.get(an_activity.materials, INFO, '\n');
	cin.ignore(100, '\n');

	cout << "Enter hands on requirements: ";
	cin.get(an_activity.requirements, INFO, '\n');
	cin.ignore(100, '\n');
}

//search for a matching activity by its name to display all of the information
//about that activity
void search(activity library[], int num_of_activities)
{
	char activity_name[NAME];
	char response = 'n';
	bool found = false;
	int i = 0;
	int j = 0;

	cout << "Do you want to search certain acitivity?: ";
	cin >> response;
	cin.ignore(100, '\n');
	while('Y' == toupper(response))
	{
		cout << "What is the name of the activity?: ";
		cin.get(activity_name, NAME, '\n');
		cin.ignore(100, '\n');
		for(int j = 0; j < num_of_activities; ++j)
		{
			for(int i = 0; i < strlen(activity_name); ++i)
			{
				if(activity_name[i] == library[j].name[i])
					found = true;
				else
					found = false;
			}
			//if there is matching result, save the library index
			//and exit the loop
			if(found)
			{
				i = j;
				j = num_of_activities;
			}
		}
		//if there is matching result, display the result
		if(found)
		{
			display_an_activity(library[i]);
			cout << "Do you want to search again?: ";
			cin >> response;
			cin.ignore(100, '\n');
		}
		else
		{
			cout << "There was no matching result."
			<< "Do you want to search again?: ";
			cin >> response;
			cin.ignore(100, '\n');
		}
	}
}

//display the contents of an activity
void display_an_activity(activity & one_activity)
{
	cout << one_activity.name << endl
	<< one_activity.description << endl
	<< one_activity.materials << endl
	<< one_activity.requirements << endl;
}

//display all of the activities
void display_activities(activity library[], int num_of_activities)
{
	for(int i = 0; i < num_of_activities; ++i)
		display_an_activity(library[i]);
}

//save the activities to an external data file
void save(activity library[], int num_to_save)
{
	ofstream file_out;
	file_out.open("staycation.txt");
	if(file_out)
	{
		for(int i = 0; i < num_to_save; ++i)
		{
			file_out << library[i].name << '|'
			<< library[i].description << '|'
			<< library[i].materials << '|'
			<< library[i].requirements << '|' << endl;
		}
		file_out.close();
	}
}
