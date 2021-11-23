//Juhwan Lee
//CS-162
//Program #5
//This program will help us to manage all the different links or
//appointments that we need to keep track of in order to be successful
//with a course (this time with LLL)

#include "link.h"

//creating node (for LLL)
struct node
{
	link data; 	//data will have all the information of the link
	node * next;	//right next to data, there will be next pointer
};

//function prototypes
void read_all(node * & head, link & newdata);
void display_all(node * head);
void search(node * head, char matching_name[]);
void remove_all(node * & head); 	//deallocate the dynamic memory
