#include "linklist.h"
#include <iostream>

using namespace std;



Link::Link()
{
    head = NULL;
}

Link::~Link()
{
    destory();
    // debug use
    //cout<< "end "<<endl;
    free(gethead());
}


void Link::insert(char *key, char *value)
{
    if(this->head == NULL)
    {
        Link::node_t *new_head =(Link::node_t *) malloc(sizeof(Link::node_t));
       
        new_head->key = key;
        new_head->value = value;
        new_head->next = NULL;
        new_head->prev = NULL;
        this->head = new_head;
    }
    else
    {
        Link::node_t *temp1;
        Link::node_t *temp2 =(Link::node_t *) malloc(sizeof(Link::node_t));
        temp1 = this->head;
        temp2 -> key = key;
        temp2 -> value = value;
        temp2 ->next = temp1;
        temp1 -> prev = temp2;
        temp2->prev = NULL;
        this->head = temp2; 
    }
}

Link::node_t *Link::search(char *value, int type)
{
    //TO DO!!! Return multiple results

    //-----------------------------------------
    Link::node_t *temp;
    temp = this->head;
    int i = 0;
    if (type == 0)
    {
        while(temp != NULL&& (strcmp(temp->key, value)!=0))
        {
           
            temp = temp->next;
        }
    }
    else if (type == 1)
    {
        while(temp != NULL && (strcmp(temp->value, value)!=0))
        {
            temp = temp->next;
        }
    }
    return temp;
}

void Link::print()
{
    Link::node_t *temp;
    temp = this->head;
    int i = 1;
    while(temp != NULL)
    {
        cout<<"node "<<i <<": "<<endl;
        cout<<"key: " <<temp->key << endl;
        cout<<"value: "<<temp->value <<endl;
        cout<<endl;
        temp=temp->next;
        i++;
    }
}

void Link::del(char *value, int type)
{
    Link::node_t *ptr;
    ptr = search(value, type);
    if(ptr == gethead())
    {
        head = ptr->next;
        free(ptr);
    }
    else if(ptr != NULL)
    {   
        ptr->prev->next = ptr->next;
        free(ptr);
    }
    
}
void Link::destory()
{
    Link::node_t *ptr1, *ptr2;
    ptr1 = gethead();
    while(ptr1!=NULL)
    {
        ptr2 = ptr1;
        ptr1 = ptr1->next;
        free(ptr2);
    }
    sethead(NULL);
}

Link *operator+(Link &ls1, Link &ls2)
{
    Link *newLink = new Link();
    Link::node_t *ptr;
    ptr = ls1.gethead();
    while(ptr != NULL)
    {
        newLink->insert(ptr->key, ptr->value);
        ptr = ptr->next;
    }
    ptr = ls2.gethead();
    while(ptr != NULL)
    {   
       
        newLink->insert(ptr->key,ptr->value);
        ptr = ptr->next;
        
    }
 
    return newLink;
}