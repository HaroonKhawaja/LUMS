#include <iostream>
#include <string>

using namespace std;



// defines a node in the binary search tree
// DO NOT CHANGE THIS
struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};



/* -----------------------------------------------------------------------------

You can create as many helper functions as you need here.
Please note that you are encouraged to create several helper functions and utilize abstraction in your implementation.
It is preferable not to have a single function more than ~50 lines long.

----------------------------------------------------------------------------- */
Node* minimumValue(Node* root)
{
    while(root->left != NULL)
    {
        root = root->left;
    }
    return root;
}
int getTreeSize(Node* root)
{
    int size = 1;
    if(root == NULL)
    {
        return 0; // returning zero when no node is present
    }
    else
    {
        size = size + getTreeSize(root->left) + getTreeSize(root->right); // recursively counting left and right subtrees
    }
    return size;
}
string inorderTraversal(Node* root)
{
    string s = "";
    if(root == NULL)
    {
        return s;
    }
    s = inorderTraversal(root->left) + to_string(root->data) + " " + inorderTraversal(root->right);
    
}
string preorderTraversal(Node* root)
{
    string s = "";
    if(root == NULL)
    {
        return s;
    }
    s = to_string(root->data) + " " + preorderTraversal(root->left) + preorderTraversal(root->right);
}
string postorderTraversal(Node* root)
{
    string s;
    if(root == NULL)
    {
        return s;
    }
    s = postorderTraversal(root->left) + postorderTraversal(root->right) + to_string(root->data) + " ";
}

void trimSpaces(string& s)
{
        int size = s.size();
        int last_index = s.size() - 1;
        int first_index = 0;

        if(s[first_index] == ' ')
        {
            s = s.substr(1, size-1);
        }
        if(s[s.size()-1] == ' ')
        {
            s.erase(size-1, 1);
        }
        for(int i = 0; i < s.size() - 1; i++)
        {
            if(s[i] == ' ' && s[i+1] == ' ')
            {
                s.erase(i,1);
            }
        }
}
int treeDepth(Node* root)
{
    if(root == NULL)
    {
        return 0;
    }
    // left sub-tree
    int lst_depth = treeDepth(root->left);
    // right sub-tree
    int rst_depth = treeDepth(root->right);

    if(lst_depth >= rst_depth) // compares max depth of left and right subtrees
    {
        return (lst_depth + 1);
    }
    else
    {
        return (rst_depth + 1);
    }
}
Node* recursiveDelete(Node* node, int key)
{   
    if(node == NULL)
    {
        return NULL;
    }
    else if(key < node->data)
    {
        node->left = recursiveDelete(node->left, key);
    }
    else if(key > node->data)
    {
        node->right = recursiveDelete(node->right, key);
    }
    else
    {
        if (node->left == NULL && node->right == NULL)
        {
            delete node;
            node = NULL;
            return NULL;
        }
        else if(node->left == NULL)
        {
            Node* temp = node->right;
            delete node;
            node = NULL;
            return temp;
        }
        else if(node->right == NULL)
        {
            Node* temp = node->left;
            delete node;
            node = NULL;
            return temp;
        }
        node->data = minimumValue(node->right)->data;
        node->right = recursiveDelete(node->right, node->data);
    }
    return node;
}

Node* findNode(Node* node, int key)
{
    if(node == NULL)
    {
        return node;
    }
    else if (key < node->data)
    {
        if(node->left != NULL)
        {
            node = findNode(node->left, key);
        }
        else
            return node;
    }
    else if(key > node->data)
    {
        if(node->right != NULL)
        {
            node = findNode(node->right, key);
        }
        else
            return node;
    }
}

void recursiveDestructor(Node* root)
{
    if(root == NULL)
    {
        return;
    }
    recursiveDestructor(root->left);
    recursiveDestructor(root->right);
    delete root;

}

// the BINARY SEARCH TREE
// Note: rememeber to write run-time complexity of each to-do function in Big-O notation
class BST
{
    public:

    Node* root;

    // TO DO Function
    BST()
    {
        // this is the contructor; set the root node to NULL here
        root = NULL;
    }


    // TO-DO Function
        // insert the int value at the correct position in the tree
        // make sure the properties of a binary search tree are not violated
    void insert(int value) // TIME COMPLEXITY: Average case is O log(n) with n being the number of nodes.
    {
        if(root == NULL)
        {
            root = new Node(value);
        }
        else
        {
            Node* temp = findNode(root, value);
            if(value < temp->data)
            {
                temp->left = new Node(value);
                temp = temp->left;
                temp->left = temp->right = NULL;
            }
            if(value > temp->data)
            {
                temp->right = new Node(value);
                temp = temp->right;
                temp->left = temp->right = NULL;
            }
        }
    }


    // TO DO Function
        // return a string depicting the inorder tree traversal
        // for example, if the inorder traversal is x->y->z, return "x y z"
    string inorder() // TIME COMPLEXITY: Worst case is O(n) with n being the number of nodes in the tree we have to visit.
    {

        string traversal = inorderTraversal(root);
        trimSpaces(traversal); // remove trailing spaces from string
        return traversal;
    }

    
    // TO DO Function
        // return a string depicting the preorder tree traversal
        // for example, if the preorder traversal is x->y->z, return "x y z"
    string preorder() // TIME COMPLEXITY: Worst case is O(n) with n being the number of nodes in the tree we have to visit.
    {
        string traversal = preorderTraversal(root);
        trimSpaces(traversal); // remove trailing spaces from string
        return traversal;
    }


    // TO DO Function
        // return a string depicting the postorder tree traversal
        // for example, if the postorder traversal is x->y->z, return "x y z"
    string postorder() // TIME COMPLEXITY: Worst case is O(n) with n being the number of nodes in the tree we have to visit.
    {
        string traversal = postorderTraversal(root);
        trimSpaces(traversal); // remove trailing spaces from string
        return traversal;
    }


    // TO DO Function
        // return a Node* pointer to the tree node with the given key stored in its data member
        // if the tree is empty or the key is not present in the tree, return NULL
    Node* getNode(int key) // TIME COMPLEXITY: Average case is O log(n) with n being the number of nodes.
    {
        if(root == NULL)
        {
            return NULL;
        }
        else
        {
            Node* traverse = root;
            while(traverse->data != key && (traverse->left != NULL || traverse->right != NULL))
            {
                if(key < traverse->data)
                {
                    traverse = traverse->left; // traversing left when key is less than data value
                }
                else if (key > traverse->data)
                {
                    traverse = traverse->right; // traversing right when key is greater than data value
                }
            }
            if(key != traverse->data)
            {
                return NULL;
            }
            else
            {
                return traverse;
            }
        }
    }


    // TO DO Function
        // return height of the search tree
        // if the tree is empty, height should be 0
        // start count of the height from 1, i.e. a one-node tree will have height 1
    int height() // TIME COMPLEXITY: Worst case is O(n) with n being the number of nodes we have to count and compare.
    {
        int tree_height;
        if(root == NULL)
        {
            return 0;
        }
        else
        {
            tree_height = treeDepth(root);
            return tree_height;
        }
    }


    // TO DO Function
        // return size of the search tree i.e. the number of nodes currently present in it
        // if the tree is empty, size should be 0
    int size() // TIME COMPLEXITY: Worst case is O(n) with each node "n" being counted once.
    {
        if(root == NULL)
        {
            return 0; // returning zero for empty tree
        }
        else
        {
            return getTreeSize(root);
        }
    }


    // TO DO Function
        // return a string with the path to a node with the given key
        // for example if the path to 5 is 2->4->5, return "2 4 5"
        // for an empty tree, return ""
    string path(int key) // TIME COMPLEXITY: Average case is O log(n) with n being the number of nodes.
    {
        if(root == NULL)
        {
            return ""; // returning empty string for an empty tree
        }
        else
        {
            string path = to_string(root->data); // root node
            Node* traverse = root;
            while(traverse->data != key)
            {
                if(key < traverse->data)
                {
                    traverse = traverse->left; // traversing left when key is less than data value
                }
                else if (key > traverse->data)
                {
                    traverse = traverse->right; // traversing right when key is greater than data value
                }
                path = path + " " + to_string(traverse->data); // adding paths from the root node
            }
            //cout << path << endl;
            return path;
        }
    }


    // TO DO Function
        // delete a node with the given key stored in its data member from the search tree
        // adjust the remaining nodes so that the properties of binary search trees are not violated
        // if the tree only has one node, delete that node and set the root node to NULL
    void deleteNode(int key) // TIME COMPLEXITY: Average case is O log(n) with n being the number of nodes.
    {
        Node* temp = root;
        root = recursiveDelete(temp, key);   
    }

    // TO DO Function
    ~BST() // TIME COMPLEXITY: Worst case is O(n) with n being the number of nodes in the tree we have to visit and delete.
    {
        // this is the destructor
        // delete pointers to all nodes present in the tree
        // reassign NULL to the root node
        recursiveDestructor(root);
    }
};





// You can use the main function to test your implementation
// Please remember to COMMENT OUT this section before running the test files

// int main()
// {

// }