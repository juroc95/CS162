//REMEMBER, .h files have the following components:
//  1. #includes
//  2. constants
//  3. structures
//  4. class interfaces
//  5. prototypes
//
#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

//My name and the purpose of the code in this file
//This code is going manage how we work with an individual movie

const int TITLE = 31;
const int INFO = 131;

class movie
{
    public:
       movie();   //constructor - initialize the data members 
       ~movie();  //deallocate the dynamic memory 
       void read();
       void display();
       bool is_match(char matching_title[]); 
    private:
        char * title;
        char info[INFO];
        int stars;

};


