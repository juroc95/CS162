//Juhwan Lee
//CS-162
//Program #4
//This program will help us to manage all the different links or
//appointments that we need to keep track of in order to be successful
//with a course

#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

class link
{
	public:
		link(); 	//constructor - initialize the data members
		~link(); 	//deallocate the dynamic memory
		void read_link();
		void display_link();
		bool is_match(char matching_name[]);
	private:
		char * name;
		char * link_itself;
		char * reason;
		int time;
		char * info;
		char * important_info;
};
