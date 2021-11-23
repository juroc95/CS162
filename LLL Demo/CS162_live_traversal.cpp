#include "list.h"

//Let's count the number of nodes with the value 2
//and return that value
int count_2(node * head)
{
    node * current = head;
    int counter = 0;

    while (current != NULL) //touch EVERY SINGLE NODE THE SAME
    {
        if (2 == current->data)
            ++counter;
        current = current->next;
    }
    return counter;
}

//Let's find out IF the last node IS a 2
//return true if it is, false otherwise
bool is_it_2(node * head)
{
    node * current = head;
    if (NULL == head) return false; //we have no list!!!

    while (current->next != NULL)
    {
        current= current->next; //traverse
    }
    //I'm at the last node right now
    if (current->data == 2)
        return true;
    return false;
}
