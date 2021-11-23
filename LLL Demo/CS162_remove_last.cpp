#include "list.h"

//Remove the last item in a LLL
//Return success (failure means
//nothing could be removed)
bool remove_last_item(node * & head)
{
    //Special case - empty list
    if (NULL == head)  //if (!head)
        return false;

    //Next special case - 1 item list
    if (NULL == head->next)  //if (!head->next)
    {
        delete head; //release the node's memory
        head = NULL;
        return true;
    }
    //Traverse to the last node, dragging a prev ptr
    node * previous = head;
    node * current = head->next; 

    //STOP when current is POINTING TO the last node
    while (current->next != NULL)
    {
        previous = current; //drag previous
        current = current->next; //traverse current
    }

    //I KNOW FOR A FACT that current is pointing
    //to the LAST NODE IN THE LIST and that previous
    //is pointing to the node before that...
    previous->next = NULL; //new LAST NODE
    delete current;        //delete the last node
    return true;
}
