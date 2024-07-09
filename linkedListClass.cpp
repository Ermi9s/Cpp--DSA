#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;
};

class Linked_List
{
    private:

    int length;
    Node *head;

    public:

    Linked_List()
    {
        head = new Node;
        head->next = NULL;
        length = 0;
    }

    ~Linked_List()
    {
        Node *temp = head;

        while (temp != NULL)
        {
            Node *next = temp->next;
            delete temp;
            temp = next;
        }
         
    }

    void displayAll()
    {
        Node * temp;
        temp = head;
        if(length == 0)return;

        while(temp->next!= NULL)
        {
            cout<<temp->data<<",";
            temp = temp->next;
        }
        cout<<temp->data<<"\n";    

    }

    void append(int value)
    {
        if(length >= 1)
        {
            Node *new_node = new Node;
            new_node->data = value;
            new_node->next = NULL;

            Node *temp;
            temp = head;



            while(temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = new_node;
            length++;

        }
        else
        {
            head->data = value;
            length++;
        }
    }


    void appendFront(int value)
    {
        Node * new_node = new Node;
        new_node->data = value;

        if(length >= 1)
        {
            new_node->next = head;
            head = new_node;
        }
        else
        {
            head = new_node;
        }
        length++;
    }

    void insertAtPos(int pos , int value)
    {
        if(pos < 1 || pos > length)
        {
            cout<<"INVALID POSITION!\n";
            return;
        }

        Node *new_node = new Node;
        new_node->data = value;

        if(pos == 1)
        {
            appendFront(value);
            return;
        }
        if(length < 1)
        {
            head = new_node;
        }

        Node*temp;
        temp = head;
        for(int i= 1; i<pos-1; ++i)
        {
            temp = temp->next;

        }

        Node *ftemp;
        ftemp = temp->next;
        
        new_node->next = ftemp;
        temp->next = new_node;
        length ++;
    }


    int pop()
    {
        if(length == 0)return 0;
        if(length == 1)
        {
            int t = head->data;
            delete head;
            length=0;
            return t;
        }

        Node*temp;
        temp = head;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }

        Node*deltemp;
        deltemp = temp->next;

        temp->next = NULL;
        int t;
        t = deltemp->data;
        delete deltemp;
        length--;
        return t;
    }

    void pop(int pos)
    {
        if(pos < 1 || pos > length)
        {
            cout<<"INVALID POSITION!\n";
            return;
        }

        Node* temp;
        temp = head;
         for(int i = 1; i < pos; ++i)
         {
            temp = temp->next;
         }
        
    }

    
    

};

int main()
{
    Linked_List list;

    list.append(10);
    list.append(20);
    list.append(37);
    list.append(40);
    list.insertAtPos(3 , 33);
    list.displayAll();
    list.pop();

    list.displayAll();
    return 0;
}