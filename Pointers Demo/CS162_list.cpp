#include "CS162_list.h"

//My name and the purpose of the code in this file
//THis file will contain the implementation of the list class
//member functions
//
//The data members for the class:
/*
        movie array[MOVIES];
        int num_of_movies;
*/

//THis is the list class constructor. It should initialize
//the data members to the zero equivalent value
list::list()
{
    cout << "How many movies would you like: ";
    cin >> size_of_array;
    cin.ignore(100, '\n');

    array = new movie[size_of_array];
    num_of_movies = 0;
    /* alternative:
      array = NULL;
    size_of_array = 0;
    num_of_movies = 0; */
}

//Destructor will deallocate the dynamic memory
list::~list()
{
    if (NULL != array)
        delete [] array;
    array = 0;
    size_of_array = 0;
    num_of_movies = 0;
}

//Read in movies until the user wants to stop or we run out of space
void list::read_all()
{
    char response = 'y'; //does the user want to do this again
    while (tolower(response) == 'y' && num_of_movies < size_of_array)
    {
        array[num_of_movies].read();
        ++num_of_movies;
        cout << "Again? ";
        cin >> response;
        cin.ignore(100, '\n');
    }
}

//Display all movies
void list::display_all()
{
    for (int i = 0; i < num_of_movies; ++i)
        array[i].display();
}




