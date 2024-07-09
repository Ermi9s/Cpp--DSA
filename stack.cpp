#include <iostream>

using namespace std;
struct node
{
    int data;
    node *next;

};
node *top = NULL;

void push(int data)
{
    node *new_node = new node;
    node *ptr = new_node;
    new_node ->data = data;

    new_node ->next = top;
    top = ptr;

}

void pop()
{
    if(top != NULL)
    {
        node *temp = top;
        top = top->next;

        temp ->next = NULL;

        delete(temp);
    }
}

void  display()
{
    node *ptr;
    ptr = top;

    while(ptr != NULL)
    {
        cout<<ptr -> data<<"\t";
        ptr = ptr-> next;

    }
}


int main()
{
    push(24);
    push(25);
    push(26);
    push(27);

    display();

    pop();
    cout<<endl;
    display();
}