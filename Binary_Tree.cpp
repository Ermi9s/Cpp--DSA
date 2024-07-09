#include<bits/stdc++.h>

using namespace std;

class Node
{
    public:
    int val;
    Node *left;
    Node *right;
    Node(int data)
    {
        val = data;
        left = nullptr;
        right = nullptr;
    }
};

class Binary_Tree
{
    private:
    Node *root;
    int len;

    Node* insert(Node *ptr , int data)
    {
        Node* newNode = new Node(data);

        if(ptr == nullptr)
        {
            ptr = newNode;
        }

        else if(ptr->val < data)
        {
            ptr->right = insert(ptr->right,  data);
        }
        else if(ptr->val > data)
        {
            ptr->left = insert(ptr->left , data);
        }

        return ptr;
    }


    void destroy(Node *rt)
    {
        Node*ptr = rt;

        if(ptr)
        {
            destroy(ptr->left);
            destroy(ptr->right);
            delete(ptr);
        }
    }

    public:

    Binary_Tree(int data)
    {
        root = new Node(data);
        len = 1;
    }
    ~Binary_Tree()
    {
        destroy(root);
    }


    //the methods

    Node* getroot()
    {
        return root;
    }

    void insert_node(int data)
    {
        root = insert(root , data);
    }

    void postorder(Node* ptr)
    {
        if(ptr->left)
        {
            postorder(ptr->left);
        }
        if(ptr->right)
        {
            postorder(ptr->right);
        }
        cout<<ptr->val<<" ";  
    }

    void preorder(Node* ptr)
    {
        cout<<ptr->val<<" ";  
        if(ptr->left)
        {
            preorder(ptr->left);
        }
        if(ptr->right)
        {
            preorder(ptr->right);
        }
        
    }
    void inorder(Node* ptr)
    {
         
        if(ptr->left)
        {
            inorder(ptr->left);
        }
        cout<<ptr->val<<" "; 
        if(ptr->right)
        {
            inorder(ptr->right);
        }   
    }

    bool find(Node*ptr , int data)
    {
        if(data == ptr->val)
        {
            return true;
        }
        else if (data > ptr->val)
        {
            return find(ptr->right , data);
        }
        else if(data < ptr->val)
        {
            return find(ptr->left , data);
        }
        else if (ptr == nullptr)
        {
            return false;
        }
    }

    int findmin(Node*ptr)
    {
        if(ptr->left)return findmin(ptr->left);
        else return ptr->val;
    }

    Node* cdelete(int data , Node*ptr)
    {
        if(ptr == nullptr) return ptr;
        else if(data > ptr->val) ptr->right = cdelete(data , ptr->right);
        else if (data < ptr->val) ptr->left = cdelete(data , ptr->left);
        else // if it is equal
        {
            if( ptr->left == nullptr && ptr->right == nullptr)
            {
                delete ptr;
                ptr = nullptr;
            }
            else if(ptr->left == nullptr && ptr->right != nullptr)
            {
                Node *temp = ptr;
                ptr = ptr->right;
                delete temp;
            }
            else if(ptr->left != nullptr && ptr->right == nullptr)
            {
                Node *temp = ptr;
                ptr = ptr->left;
                delete temp;
            }
            else // it has 2 childrens
            {
                int min = findmin(ptr->right);
                ptr->val = min;
                ptr->right = cdelete(min , ptr->right);
            }

            return ptr;
        }

    }

};

int main()
{
    Binary_Tree T(5);
    T.insert_node(6);
    T.insert_node(7);
    T.insert_node(9);
    T.insert_node(2);
    T.insert_node(22);
    T.insert_node(1);
    T.insert_node(0);
    T.insert_node(3);
    T.insert_node(10);

    T.inorder(T.getroot());
    cout<<"\n";
    T.cdelete(5 , T.getroot());
    T.inorder(T.getroot());
    return 0;
}