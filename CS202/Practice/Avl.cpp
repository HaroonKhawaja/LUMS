#include<iostream>
using namespace std;


struct AVLNode
{
    AVLNode* left;
    AVLNode* right;
    int data;
    int balance_factor;

};

AVLNode* newNode(int data)
{
    AVLNode* temp = new AVLNode;
    temp->data = data;
    temp->left = temp->right = NULL;
    temp->balance_factor = 0;
    return temp;
}

class AVLTree
{
    private:
        AVLNode* root;
    
    public:
    AVLTree();
    AVLTree(int data);
    AVLNode* Insert(AVLNode* node, int data);
    AVLNode* Delete(AVLNode* node, int data);
    AVLNode* findMin(AVLNode* node);
    AVLNode* findMax(AVLNode* node);
    string Inorder(AVLNode* node);
    string PreOrder(AVLNode* node);
    string PostOrder(AVLNode* node);
    
};

// DEFINITIONS
AVLTree::AVLTree()
{
    root = NULL;
}
AVLTree::AVLTree(int data)
{
    root = newNode(data);
}
AVLNode* AVLTree::Insert(AVLNode* node, int data)
{
    if(node == NULL)
    {
        root = newNode(data);
    }
    else/
}
AVLNode* AVLTree::Delete(AVLNode* node, int data)
{

}
AVLNode* AVLTree::findMin(AVLNode* node)
{

}
AVLNode* AVLTree::findMax(AVLNode* node)
{

}
string AVLTree::Inorder(AVLNode* node)
{

}
string AVLTree::PreOrder(AVLNode* node)
{

}
string AVLTree::PostOrder(AVLNode* node)
{

}
    
int main()
{

    return 0;
}