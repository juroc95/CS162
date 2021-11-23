//Juhwan Lee
//CS-162 Program #2

//This program will let the user enter in some text
//three different categories and it will ask the user
//for a word they would like to search for and it will
//let them know which category it is located in and
//then it will display three categories and it will ask
//the user if they would like to do it again.

#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

//Prototypes
void get_name(char name[], char response);
void get_school(char school[], char response);
void get_major(char major[], char response);
void compare_info(char name[], char school[], char major[], char response);
void capitalize(char name[], char school[], char major[]);
void search(char word[], char name[], char school[], char major[], char response);

//MAIN
int main()
{
	const int SIZE = 300;
	char name[SIZE];
	char school[SIZE];
	char major[SIZE];
	char word[SIZE];
	char response = '\0';

	cout << "There are three different categories you can type in" << endl;
	cout << "1. Name" << endl << "2. School" << endl << "3. Major" << endl;

	do
	{
		get_name(name, response);
		get_school(school, response);
		get_major(major, response);
		compare_info(name, school, major, response);
		capitalize(name, school, major);
		search(word, name, school, major, response);

		cout << "Your Name : " << name << endl;
		cout << "Your School : " << school << endl;
		cout << "Your Major : " << major << endl;

		cout << "Would you like to do it again? (Y/N)" << endl;
		cin >> response;
		cin.ignore(100, '\n');
		response = toupper(response);
	} while(response == 'Y');

	return 0;
}

//Functions
void get_name(char name[], char response) {
	do {
		cout << "Please type your name" << endl;
		cin.get(name, 300, '\n');
		cin.ignore(100, '\n');
		cout << "You entered " << name << ". Is it correct? (Y/N)" << endl;
		cin >> response;
		cin.ignore(100, '\n');
		response = toupper(response);
	} while(response != 'Y');
}

void get_school(char school[], char response) {
	do {
		cout << "Please type your school" << endl;
		cin.get(school, 300, '\n');
		cin.ignore(100, '\n');
		cout << "You entered " << school << ". Is it correct? (Y/N)" << endl;
		cin >> response;
		cin.ignore(100, '\n');
		response = toupper(response);
	} while(response != 'Y');
}

void get_major(char major[], char response) {
	do {
		cout << "Please type your major" << endl;
		cin.get(major, 300, '\n');
		cin.ignore(100, '\n');
		cout << "You entered " << major << ". Is it correct? (Y/N)" << endl;
		cin >> response;
		cin.ignore(100, '\n');
		response = toupper(response);
	} while(response != 'Y');
}

void compare_info(char name[], char school[], char major[], char response) {
	int cmp_value1 = strcmp(name, school);
	if(cmp_value1 == 0) {
		do {
			cout << "Name and School contain exact same information" << endl;
			get_name(name, response);
			get_school(school, response);
			cmp_value1 = strcmp(name, school);
		} while(cmp_value1 == 0);
	}
	int cmp_value2 = strcmp(name, major);
	if(cmp_value2 == 0) {
		do {
			cout << "Name and Major contain exact same information" << endl;
			get_name(name, response);
			get_major(major, response);
			cmp_value2 = strcmp(name, major);
		} while(cmp_value2 == 0);
	}
	int cmp_value3 = strcmp(school, major);
	if(cmp_value3 == 0) {
		do {
			cout << "School and Major contain exact same information" << endl;
			get_school(school, response);
			get_major(major, response);
			cmp_value3 = strcmp(school, major);
		} while(cmp_value3 == 0);
	}
}

void capitalize(char name[], char school[], char major[]) {
	name[0] = toupper(name[0]);
	school[0] = toupper(school[0]);
	major[0] = toupper(major[0]);
	for(int i = 0; i < strlen(name); ++i) {
		if(name[i] == '.')
			name[i+2] = toupper(name[i+2]);
	}
	for(int i = 0; i < strlen(school); ++i) {
		if(school[i] == '.')
			school[i+2] = toupper(school[i+2]);
	}
	for(int i = 0; i < strlen(major); ++i) {
		if(major[i] == '.')
			major[i+2] = toupper(major[i+2]);
	}
}

void search(char word[], char name[], char school[], char major[], char response)
{
	do
	{
		do
		{
			cout << "Please type a word that you would like to search for" << endl;
			cin.get(word, 300, '\n');
			cin.ignore(100, '\n');
			word[0] = toupper(word[0]);
			cout << "You entered " << word << ". Is it correct? (Y/N)" << endl;
			cin >> response;
			cin.ignore(100, '\n');
			response = toupper(response);
		} while(response != 'Y');
		int j = 0;
		response = '\0';
		for(int i = 0; i < strlen(name); ++i)
		{
			if(word[j] == name[i])
				++j;
		}
		if(j == strlen(word))
			cout << "The word is found in NAME" << endl;
		else
		{
			j = 0;
			for(int i = 0; i < strlen(school); ++i)
			{
				if(word[j] == school[i])
					++j;
			}
			if(j == strlen(word))
				cout << "The word is found in SCHOOL" << endl;
			else
			{
				j = 0;
				for(int i = 0; i < strlen(major); ++i)
				{
					if(word[j] == major[i])
						++j;
				}
				if(j == strlen(word))
					cout << "The word is found in MAJOR" << endl;
				else
				{
					cout << "There was no matching result" << endl;
					cout << "Would you like to search different word? (Y/N)" << endl;
					cin >> response;
					cin.ignore(100, '\n');
					response = toupper(response);
				}
			}
		}
	} while(response == 'Y');
}
