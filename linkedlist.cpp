#include <iostream>

using namespace std;
struct node
{
    int data;
    node *next;

};
node *start = NULL;

void insertBeg (int newData)
{
    node *temp , *newNode = new node;
    newNode -> data = newData;

    temp = start;
    start= newNode;
    newNode ->next = temp;

}


void  display()
{
    node *ptr;
    ptr = start;

    while(ptr != NULL)
    {
        cout<<ptr -> data<<"\t";
        ptr = ptr-> next;

    }
}

void insert_after(int c, int data)
{
    node *new_node = new node;
    new_node ->data = data;
    new_node ->next = NULL;

    node *q;
    q = start;

    for(int i=1;i<c; i++)
    {
        q = q -> next;

    }

    new_node->next =q ->next;
    q ->next = new_node;
}


void insertEnd(int data)
{
    node *new_node = new node;
    new_node ->data = data;
    new_node ->next = NULL;

    node *temp = start;
    if(start == NULL)
    {
        start = new_node;
    }
    else
    {
        while(temp -> next != NULL)
        {
            temp = temp -> next;

        }

        temp ->next = new_node;   
    }
}

void deleteEnd()
{

    node *temp = start;
    if(start == NULL)
    {
        return;
    }
    else
    {
        while(temp -> next ->next != NULL)
        {
            temp = temp -> next;

        }

        node *toBeRemoved = temp ->next;

        temp->next= NULL;

        delete toBeRemoved;  
    }
}


int main()
{
    insertBeg(34);
    insertBeg(67);
    insertBeg(74);


    insertEnd(60);
    insert_after(2,77);
    display();

    deleteEnd();

    display();

    return 0;

}
