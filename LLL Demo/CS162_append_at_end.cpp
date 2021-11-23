#include "list.h"

//Write the function to add a node to the end of 
//a LLL
void append_at_end(node * & head, int new_data)
{
    //Special case of empty list
    if (NULL == head) // if (!head)
    {
        head = new node;
        head->data = new_data;
        head->next = NULL;
    }
    else //not an empty list!
    {
        //traverse to the LAST node
        node * current = head;
        //while(current->next)
        while (current->next != NULL)
        {
            current = current->next;
        }

        //AT THE LAST NODE RIGHT NOW....
        //connect it up to a new node
        current->next = new node;
        current = current->next; //traverse to this node
        current->data = new_data;
        current->next = NULL;
    }
}




