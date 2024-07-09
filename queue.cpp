#include<iostream>
using namespace std;
struct node
{
    int data;
    node *next;

};
node *front = NULL;
node *back = NULL;

void enqueue(int data)
{
    node *new_node = new node;
    
    new_node ->data = data;
    new_node ->next = NULL;

    if(front == NULL)
    {
        front = new_node;
        back = new_node;
    }
    else
    {
        back ->next = new_node;
        back = new_node;
    }

}


void dequeue()
{
    if(front == back)
    {
        delete(front);
        back = NULL;
        front = back;
        
    }
    else if(front != NULL)
    {
        node *temp = front;
        front = front ->next;
        temp ->next = NULL;
        delete(temp);
    }
}


void  display()
{
    node *ptr;
    ptr = front;

    while(ptr != NULL)
    {
        cout<<ptr -> data<<"\t";
        ptr = ptr-> next;

    }
}


int main()
{
    enqueue(23);
    enqueue(24);
    enqueue(25);
    enqueue(26);
    enqueue(27);

    display();

    dequeue();
    cout<<endl;
    display();
    return 0;
}