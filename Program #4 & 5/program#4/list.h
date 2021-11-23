//Juhwan Lee
//CS-162
//Program #4
//This program will help us to manage all the different links or
//appointments that we need to keep track of in order to be successful
//with a course

#include "link.h"

class list
{
	public:
		list(); 	//constructor
		~list(); 	//destructor
		void read_all();
		void display_all();
		void search(char matching_name[]);
	private:
		link * array; 	//can point to one link or the first of many
				//in an array
		int size_of_array;
		int num_of_links;
};
