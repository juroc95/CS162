//Juhwan Lee
//CS-162
//Program #5
//This program will help us to manage all the different links or
//appointments that we need to keep track of in order to be successful
//with a course (this time with LLL)

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
		bool is_match(char matcing_name[]);
	private:
		char * name;
		char * link_itself;
		char * reason;
		int time;
		char * info;
		char * important_info;
};
