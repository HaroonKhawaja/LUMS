#include <iostream>
#include <iomanip>
#include "Task_01.cpp"

using namespace std;


Node* increment_(Node* x, int y)
{
    if (x == NULL){Node* z = new Node(y); return z;}
    else if (x->data < y){x->right = increment_(x->right, y);}
    else if (x->data > y){x->left = increment_(x->left, y);}
    return x;
}


string display_(Node* x)
{
    string y = "";if (x != NULL){y += display_(x->left);y += to_string(x->data) + " ";y += display_(x->right);}return y;
}


int count_(Node* root)
{
    if (root==NULL){return 0;cout << 0 << endl;}return (1 + count_(root->left) + count_(root->right));
}


string remove_trail(string x)
{
    int y = x.length();if (y){x = x.substr(0,y-1);}return x;
}


bool checkBal(Node* x)
{
    if(x==NULL)
    {
        return true;
    }
    if (!x->left && !x->right)
    {
        return true;
    }
    else if ((x->left && x->left->data>x->data) || (x->right && x->right->data<x->data))
    {
        return false;
    }
    if (checkBal(x->left)==false)
    {
        return false;
    }
    if (checkBal(x->right)==false)
    {
        return false;
    }
    return true;
}


class Test_BST: public BST
{
    public:

    void increment(int x)
    {
        root = increment_(root, x);
    }

    int check()
    {
        return count_(root);
    }

    string disp()
    {
        return remove_trail(display_(root));
    }

    bool checkBalanced()
    {
        return checkBal(root);
    }
};