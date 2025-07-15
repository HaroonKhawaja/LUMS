#include <iostream>
#include <cmath>
using namespace std;

class StudentRecord;    // Forward Declaration (Relevant to Task 2)

// defines a keyValue object
// DO NOT CHANGE THE MEMBER VARIABLE SET OR CONSTRUCTOR
// You can, however, do operator overloading
class keyValue
{
public:
    int key;
    StudentRecord *value;

    keyValue()
    {
        value = NULL;
    }

    keyValue(int _key, StudentRecord *_value)
    {
        key = _key;
        value = _value;
    }
};

// defines a node in the B-tree
// DO NOT CHANGE THE MEMBER VARIABLE SET OR CONSTRUCTOR
class Node
{
public:
    keyValue *keys;
    int order;
    Node **children;
    int num_keys;
    int num_children;
    bool isLeaf;

    Node(int _order, bool _isLeaf)
    {
        order = _order;
        keys = new keyValue[order - 1];
        num_keys = 0;
        num_children = 0;
        children = new Node *[order];
        isLeaf = _isLeaf;
    }

    ~Node()
    {
        delete[] keys;
        delete[] children;
    }

    // RELEVANT TO TEST CASES
    // DO NOT MODIFY
    void traverse(string &output)
    {
        int i;
        for (i = 0; i < num_keys; i++)
        {
            if (isLeaf == false)
                children[i]->traverse(output);
            output = output + " " + to_string(keys[i].key);
        }

        if (isLeaf == false)
            children[i]->traverse(output);
    }
};

/* -----------------------------------------------------------------------------

You can create as many helper functions as you need in all three classes.

The general steps to insertion and deletion have been highlighted (aside from edge cases),
so you are encouraged to create several helper functions and utilize abstraction in your implementation.

----------------------------------------------------------------------------- */
// FORWARD DECLARATION //
Node* addKey(Node* node, int index, int key, StudentRecord* value);
Node* addChild(Node* parent, Node* child);
Node* splitNode(Node* &node, int med_index, int index);
Node* mergeNode(Node* &previous, Node* merge, int prev_child_index, StudentRecord* value);
void printKeys(Node* node);
Node* ShiftChildrenRight(Node* previous, int count);
// HELPER FUNCTIONS //
void BTreeDiagram(Node* node)
{   
    cout << "\t\t\t  ";
    printKeys(node);
    cout << endl;
    for (int i = 0; i < node->num_children; i++)
    {
        cout << "\t     ";
        printKeys(node->children[i]);
    }
    cout << endl;
    for (int j = 0; j < node->num_children; j++)
    {
        for (int i = 0; i < node->children[j]->num_children; i++)
        {
            printKeys(node->children[j]->children[i]);
            cout << "\t" ;
        }
    }
    cout << "\n" << endl;
    for (int j = 0; j < node->num_children; j++)
    {
        for (int i = 0; i < node->children[j]->num_children; i++)
        {
            for (int k = 0; i < node->children[j]->children[i]->num_children; k++)
            {
                printKeys(node->children[j]->children[i]->children[k]);
                cout << "\t" ;
            }
        }
    }
}
void printKeys(Node* node)
{
    for (int i = 0; i < node->num_keys; i++)
    {   
        cout << "[" << node->keys[i].key << "]";
    }

    
}
Node* sortNode(Node* node, int num_keys)
{
    for (int i = num_keys - 1; i > 0; i--)
    {
        
        if (node->keys[i].key < node->keys[i - 1].key)
        {
            int temp = node->keys[i].key;
            node->keys[i].key = node->keys[i - 1].key;
            node->keys[i - 1].key = temp;
        }
        
    }
}
Node* find_Insert(Node* &traverse, Node* &previous, int _key, int &index, StudentRecord* value)
{
    int j = 0;
    while (traverse->isLeaf == false )
    {
        int last_key_index = traverse->num_keys - 1 ;
        if (_key < traverse->keys[j].key)
        {
            previous = traverse;
            index = j;
            traverse = traverse->children[j];
        }
        else if (_key > traverse->keys[last_key_index].key)
        {
            previous = traverse;
            index = traverse->num_keys;
            traverse = traverse->children[traverse->num_keys];
        }
        else
        {
            index++;
            j++;
        }
    }
        
    int i = 0;
    while (i < traverse->num_keys) // getting an empty space to place key in
    {
        i++;
    }
    traverse = addKey(traverse, i, _key, value); // adding the key to the node
    return traverse;
}
Node* addKey(Node* node, int index, int key,  StudentRecord* value)
{
    node->keys[index].key = key;
    node->keys[index].value = value;
    node->num_keys++;
    sortNode(node, node->num_keys);
    return node;
}
Node* addChild(Node* parent, Node* child)
{
    int i = 0;
    while (i < parent->num_children)
    {
        i++;
    }
    parent->children[i] = child;
    parent->num_children++;

    return parent;   
}
Node* splitNode(Node* &node, int med_index, int index)
{
    int order = node->order;
    int merge_index = 0;

    Node* left = new Node(5, true); // temp left child node
    for (int i = 0; i < med_index; i++) // copying all keys before median key into temp left child
    {
        int key = node->keys[i].key;
        StudentRecord* value = node->keys[i].value;
        left = addKey(left, i, key, value);
    }

    Node* right = new Node(5, true); // temp right child node
    for (int i = med_index + 1; i < 5; i++) // copying all keys after median key into temp right child
    {
        int key = node->keys[i].key;
        StudentRecord* value = node->keys[i].value;
        right = addKey(right, merge_index, key, value);
        merge_index++;
    }

    StudentRecord* value = node->keys[med_index].value;
    Node* parent = new Node(5, false); // temp root node
    parent = addKey(parent, 0, node->keys[med_index].key, value); // adding median key into temp root node

    int half_children = node->num_children / 2;
    if (node->num_children != 0) // copying all children of original root into left and right children if original root has pre existing children
    {
        for (int i = 0; i < half_children; i++)
        {
            left = addChild(left, node->children[i]);
        }
        for (int i = half_children; i < node->num_children; i++)
        {
            right = addChild(right, node->children[i]);

        }
        left->isLeaf = false;
        right->isLeaf = false;

    }
    parent = addChild(parent, left); // assigning left child to temp root
    parent = addChild(parent, right); // assigning right child to temp root
    parent = ShiftChildrenRight(parent, index);
    
    node = parent;
}
Node* mergeNode(Node* &node, Node* merge, int index, StudentRecord* value)
{   
    int merge_root_data  = merge->keys[0].key;
    int node_lastch_index = node->num_keys;
    
    int i = 0;
    while (i < node->num_keys) // getting an empty space to place key in
    {
        i++;
    }
    node = addKey(node, i, merge_root_data, merge->keys[0].value);
    node->num_children++;  
    node = ShiftChildrenRight(node, index);
   
    if (index == 0)
    {
        int merge_child_index = 0;
        for (int i = 0; i < index + merge->num_children; i++)
        {
            node->children[i] = merge->children[merge_child_index];
            merge_child_index++;
        }
    }  
    else
    {
        int merge_child_index = 0;
        for (int i = index ; i < index + merge->num_children; i++)
        {   
            node->children[i] = merge->children[merge_child_index];
            merge_child_index++;
        }
    }
}
Node* ShiftChildrenRight(Node* previous, int count)
{
    for (int i = previous->num_children  - 1; i > count + 1; i--)
    {
        previous->children[i] = previous->children[i-1];
    }
    return previous;
}
Node* checkPredecessor(Node* traverse, int j)
{
    Node* predecessor = traverse->children[j+1];
    if (predecessor->num_keys > traverse->order/2)// checks if predecessor has more than minimum amount of keys present in its node
    {
        return predecessor;
    }
    else
    {
        return NULL;
    }
}
Node* checkSuccessor(Node* traverse, int j)
{
    Node* successor = traverse->children[j];
    if (successor->num_keys > traverse->order/2) // checks if successor has more than minimum amount of keys present in its node
    {
        return successor;
    }
    else
    {
        return NULL;
    }
    
}
Node* removeKey(Node* node, int del_key)
{
    int i = 0;
    while (node->keys[i].key != del_key) // searches for key to delete
    {
        i++;
    }
    for (i; i < node->num_keys-1; i++) // copies every key on index with its next one
    {
        node->keys[i].key = node->keys[i + 1].key;
        node->keys[i].value = node->keys[i + 1].value;
    }
    node->num_keys--; // adjusts number of keys after deletion

    return node;
}
Node* removeChild(Node* node, int index)
{
    int i = 0;
    while (i != index)
    {
        i++;
    }
    for (i; i < node->num_children - 1; i++) // replaces every child on index with the next one
    {
        node->children[i] = node->children[i + 1];
    }
    node->num_children--; // adjusts number of children after deletion

    return node;
}
Node* mergeChildren(Node* &node, int index)
{
    Node* right = node->children[index + 1]; // create a temp right child
    Node* left = node->children[index]; // create a temp left child
    Node* merge = new Node(node->order, true); // temp to merge both left and right

    merge->num_keys = left->num_keys + right->num_keys; // accumulating both left and right number of keys
    int merge_index = 0;
    for (int i = 0; i < 5; i++)
    {
        merge->keys[i].key = left->keys[i].key; // copying all left childs keys into temp
        merge->keys[i].value = left->keys[i].value; // copying all left childs values into temp
    }
    for (int i = left->num_keys; i < 5; i++)
    {
        merge->keys[i].key = right->keys[merge_index].key; // copying all right childs keys into temp
        merge->keys[i].value = right->keys[merge_index].value; // copying all right childs values into temp
        merge_index++;
    }
            BTreeDiagram(left);


    node = removeChild(node, index); // adjusting number of children after merging 2 children into 1
    node->children[index] = merge; // setting merged child as new child

    delete left, right, merge; // deleting temp variables
    left = right = merge = NULL;
}

class B_Tree
{
    public:
    Node *root; // Pointer to root node
    int order;

    // TO DO Function
    B_Tree(int _order)
    {
        // this is the contructor
        // set the root node to NULL here and order to _order
        root = NULL;
        order = _order;
    }

    // TO-DO Function
    // insert the integer key and its associated StudentRecord *value (a keyValue object as a whole) 
    // at the correct position in the tree. The value is relevant for Task 2.
    // make sure the properties of a B-tree are not violated
    void insertKey(int _key, StudentRecord *value = NULL)
    {
        // if B-Tree empty, initialize a new node and insert into it
        // if B-Tree not empty:
        //      Find the leaf node where insertion should be done
        //      Insert if the leaf node has space in it
        //             else if leaf node overflows, then split the node into two nodes
        //                  and promote the middle key to parent (cascading effect)
        //
        // Note: assume left-biased convention if the number of keys is even, that is, if
        //       a leaf node is [1 2 3] and 4 is being inserted, then the node would be split
        //       into [1] and [3, 4], where 2 will be promoted
    
        if(root == NULL)
        {
            root = new Node(order, 1);
            root->keys[0].key = _key;
            root->keys[0].value = value;
            root->num_keys++;
        }
        else
        {
            Node* traverse = root;
            Node* previous = root;
            Node* temp = root;
            int last_child_index = traverse->num_keys;
            int last_key_index = traverse->num_keys - 1 ;
            int index = 0;

            find_Insert(traverse, previous, _key, index, value);
            if (traverse != root && traverse->num_keys == traverse->order)
            {
                cout << "ONE" << endl;
                int median = traverse->num_keys / 2;
                splitNode(traverse, median, index);
                BTreeDiagram(traverse);
                mergeNode(previous, traverse, index, value);
                BTreeDiagram(previous);

            }
            else if (traverse->num_keys == traverse->order)
            {
                cout << "TWO" << endl;
                int median = traverse->num_keys / 2;
                splitNode(traverse, median, index);
                BTreeDiagram(traverse);

            }
            if (root->num_keys == root->order)
            {
                cout << "THREE" << endl;
                int median = root->num_keys / 2;
                Node* temp = root;
                splitNode(temp, median, index);
                root = temp;
            }
            BTreeDiagram(root);
        }
    }

    // TO-DO Function
    // delete the int key from the tree
    // make sure the properties of a B-tree are not violated
    void deleteKey(int key)
    {
        // if key to be deleted exists on a leaf node
        //      if the leaf node contains more than the mininum number of keys, then delete key
        //      if the leaf node contains the mininum number of keys
        //          - then try borrowing from immediate left node (sibling), transfering through shared root
        //          - otherwise try borrowing from immediate right node (sibling), transfering through shared root
        //          - otherwise merge with either sibling along with parent shared with said sibling and delete key
        // if key to be deleted exists on an internal node
        //      then try to delete key and replace with its
        //          - inorder predecessor (max key in left subtree of key to be deleted), assuming that node that
        //            contains it has more than minimum number of elements
        //          - inorder successor (min key in right subtree of key to be deleted), assuming that node that
        //            contains it has more than minimum number of elements
        //          - otherwise delete key and merge the left and right subtree to become children of a single root
        //
        // Note: It is very possible for some B-tree properties to be violated even after deletion, e.g if you
        //       were deleted 20 from an internal node [10, 20] in a B-tree of order 5, the internal node will
        //       now have [10], i.e only one key even though it should have a minimum of two keys. This must be
        //       resolved by borrowing from either sibling or merging, as described above
        Node* traverse = root;
        Node* previous = root;
        int j = 0;
        while (traverse->isLeaf == false )
        {
            int last_key_index = traverse->num_keys - 1 ;
            if (key < traverse->keys[j].key)
            {
                previous = traverse;
                traverse = traverse->children[j];
            }
            else if (key > traverse->keys[last_key_index].key)
            {
                previous = traverse;
                traverse = traverse->children[traverse->num_keys];
            }
            else if (key == traverse->keys[j].key)
            {
                int min_keys = traverse->order/2;
                Node* P = checkPredecessor(traverse, j);
                Node* S = checkSuccessor(traverse, j);
                if (P == NULL && S == NULL)
                {
                    mergeChildren(traverse, j);
                    traverse = removeKey(traverse, traverse->keys[j].key);
                    return;
                }
                else if (P == NULL )
                {
                    int max_left = S->keys[S->num_keys-1].key;
                    traverse->keys[j].key = max_left; // replacing key node with successor key
                    traverse->children[j+1]  = removeKey(traverse->children[j+1], max_left); 
                    // deleting the successor key and adjusting number of keys
                    return;
                }
                else if (S == NULL)
                {
                    int min_right = P->keys[0].key;
                    traverse->keys[j].key = min_right; // replacing key node with predecessor key
                    traverse->children[j+1]  = removeKey(traverse->children[j+1], min_right); 
                    // deleting the predecessor key and adjusting number of keys
                    return;
                }
            }          
            else
            {
                j++;
            }
        }
        // Deleting from leaf node
        for (int i = 0; i <= traverse->order; i++) // searching if key exists in node - break from loop if it does - return from function if not
        {
            if (i == traverse->order)
            {
                return;
            }
            if (key == traverse->keys[i].key)
            {
                break;
            }
        }
        if (traverse->num_keys > traverse->order / 2) // if more than minimum number of keys are present, simply delete the key
        {
            // traverse  = removeKey(traverse, key); 
        }
        else
        {
            if (j > 0 && j < previous->num_children) // Has immediate left sibling
            {
                Node* right_sibling = previous->children[j + 1];
                Node* left_sibling = previous->children[j - 1];
                // Check immediate left
                if (left_sibling->num_keys > left_sibling->order/2)
                {
                    // cout << "Borrow from left" << endl;
                }
                // Check immediate right
                else if (right_sibling->num_keys > right_sibling->order/2)
                {
                    int min_right = right_sibling->keys[0].key; // immediate right sibling key
                    int i = 0;
                    while (i < previous->num_keys)
                    {
                        i++;
                    }
                    previous = addKey(previous, i, min_right, right_sibling->keys[0].value); // shifting immediate right key into root
                    right_sibling  = removeKey(right_sibling, min_right);  // removing immediate right key

                    int k = 0;
                    while (k < traverse->num_keys)
                    {
                        k++;
                    }
                    traverse = addKey(traverse, k, previous->keys[j].key, previous->keys[j].value); // shifting key from root into down traverse node
                    traverse = removeKey(traverse, key); // deleting the target key from traverse node
                    previous  = removeKey(previous, previous->keys[j].key); // deleting key from root which was shifted down into traverse node
                }
                else
                {
                    // cout << "Merge"  << endl;
                }
            }
            else if (j == 0) // Left most node - No immediate left sibling
            {
                Node* right_sibling = previous->children[j + 1];
                if (right_sibling->num_keys > right_sibling->order/2)
                {
                    // shift left-most key of right_sibling into root
                    // shift left-most key of root down into target node
                    // delete target key from node
                }
                else
                {
                    mergeChildren(previous, j);
                    traverse = previous->children[j];
                    int k = 0;
                    while (k < traverse->num_keys)
                    {
                        k++;
                    }
                    traverse = addKey(traverse, k, previous->keys[j].key, previous->keys[j].value); // shifting key from root into down traverse node
                    traverse = removeKey(traverse, key); // deleting the target key from traverse node
                    previous  = removeKey(previous, previous->keys[j].key); // deleting key from root which was shifted down into traverse node

                    return;
                }
            }
            else if (j == previous->num_children) // Right most node - No immediate right sibling
            {
                Node* left_sibling = previous->children[j - 1];
                if (left_sibling->num_keys > left_sibling->order/2)
                {
                    // shift right-most key of left_sibling into root
                    // shift right-most key of root down into target node
                    // delete target key from node
                }
                else
                {
                    mergeChildren(previous, j);
                    traverse = previous->children[j];
                    int k = 0;
                    while (k < traverse->num_keys)
                    {
                        k++;
                    }
                    traverse = addKey(traverse, k, previous->keys[j].key, previous->keys[j].value); // shifting key from root into down traverse node
                    traverse = removeKey(traverse, key); // deleting the target key from traverse node
                    previous  = removeKey(previous, previous->keys[j].key); // deleting key from root which was shifted down into traverse node

                    return;
                }
            }
            
        }
    }

    // TO-DO Function
    // search the int key from the tree; return NULL if not found
    Node *searchKey(int key)
    {
        // since we are working with multiple children now, there will be subtrees other than
        // just the left and right subtrees you are used to from assignment 3
        //
        // Note: remember that since the keys in a node are sorted in ascending order by convention,
        //       you do not need to iterate over the entire keys array everytime
        Node* traverse = root;
        int j = 0;
        while (traverse->isLeaf == false )
        {
            int last_key_index = traverse->num_keys - 1 ;
            if (key < traverse->keys[j].key)
            {
                traverse = traverse->children[j];
            }
            else if (key > traverse->keys[last_key_index].key)
            {
                traverse = traverse->children[traverse->num_keys];
            }
            else if (key == traverse->keys[j].key)
            {
                return traverse;
            }          
            else
            {
                j++;
            }
        }
        return NULL;
    }

    // TO DO Function
    ~B_Tree()
    {
        // this is the decontructor
        // set the root node to NULL here and delete pointers to all nodes in the tree
        // This will be particularly checked manually
    }

    // RELEVANT TO TEST CASES
    // DO NOT MODIFY
    string traverse()
    {
        if (root != NULL)
        {
            string out = "";
            root->traverse(out);
            return out;
        }
    }
};

// You can use the main function below to test your implementation
// Remember to comment out the main section before running test_1.cpp and test_2.cpp

// int main() {
//     B_Tree BTree(5);

    // INSERTING
    // BTree.insertKey(1); // TEST 1
    // BTreeDiagram(BTree.root);
    // cout << "TRAVERSE: " << BTree.traverse() << endl;

    // BTree.insertKey(3);
    // BTreeDiagram(BTree.root);
    // BTree.insertKey(7);
    // BTreeDiagram(BTree.root);
    // BTree.insertKey(16);
    // BTreeDiagram(BTree.root);
    // BTree.insertKey(19);
    // BTreeDiagram(BTree.root);
    // BTree.insertKey(24);
    // BTreeDiagram(BTree.root);

    // BTree.insertKey(25);
    // BTreeDiagram(BTree.root);
    // BTree.insertKey(26);
    // BTreeDiagram(BTree.root);
    // BTree.insertKey(10);
    // BTreeDiagram(BTree.root);
    // BTree.insertKey(11);
    // BTreeDiagram(BTree.root);
    // BTree.insertKey(13);
    // BTreeDiagram(BTree.root);

    // BTree.insertKey(8);
    // BTreeDiagram(BTree.root);
    // BTree.insertKey(15);
    // BTreeDiagram(BTree.root);
    // BTree.insertKey(18);
    // BTreeDiagram(BTree.root);
    // BTree.insertKey(21);
    // BTreeDiagram(BTree.root);
    // BTree.insertKey(4);
    // BTreeDiagram(BTree.root);

    // BTree.insertKey(5);
    // BTreeDiagram(BTree.root);
    // BTree.insertKey(20);
    // BTreeDiagram(BTree.root);
    // BTree.insertKey(22);
    // BTreeDiagram(BTree.root);
    // BTree.insertKey(2);
    // BTreeDiagram(BTree.root);
    // BTree.insertKey(17);
    // BTreeDiagram(BTree.root);

    // DELETE
    // BTree.insertKey(1);
    // BTree.insertKey(3);
    // BTree.insertKey(7);
    // BTree.insertKey(16);
    // BTree.insertKey(19);
    // BTree.insertKey(24);
    // BTree.insertKey(25);
    // BTree.insertKey(26);
    // BTree.insertKey(10);
    // BTree.insertKey(11);
    // BTree.insertKey(13);
    // BTree.insertKey(14);
    // BTree.insertKey(15);
    // BTree.insertKey(18);
    // BTree.insertKey(21);
    // BTree.insertKey(4);
    // BTree.insertKey(5);
    // BTree.insertKey(20);
    // BTree.insertKey(22);
    // BTree.insertKey(2);
    // BTree.insertKey(17);
    // BTreeDiagram(BTree.root);
    // cout << "DELETE 13" << endl;
    // BTree.deleteKey(13);
    // BTreeDiagram(BTree.root);
    // cout << "TRAVERSE: " << BTree.traverse() << endl;
    // cout << "DELETE 7" << endl;
    // BTree.deleteKey(7);
    // BTreeDiagram(BTree.root);
    // cout << "TRAVERSE: " << BTree.traverse() << endl;
    // cout << "DELETE 4" << endl;
    // BTree.deleteKey(4);
    // BTreeDiagram(BTree.root);
    // cout << "TRAVERSE: " << BTree.traverse() << endl;
    // cout << "DELETE 2" << endl;
    // BTree.deleteKey(2);
    // BTreeDiagram(BTree.root);
    // cout << "TRAVERSE: " << BTree.traverse() << endl;
    // cout << "DELETE 6" << endl;
    // BTree.deleteKey(6);
    // BTreeDiagram(BTree.root);
    // cout << "TRAVERSE: " << BTree.traverse() << endl;

    // SEARCH
    // BTree.insertKey(1);
    // BTree.insertKey(3);
    // BTree.insertKey(7);
    // BTree.insertKey(16);
    // BTree.insertKey(19);
    // BTree.insertKey(24);
    // BTree.insertKey(25);
    // BTree.insertKey(26);
    // BTree.insertKey(10);
    // BTree.insertKey(11);
    // BTree.insertKey(13);
    // BTree.insertKey(14);
    // BTree.insertKey(15);
    // BTree.insertKey(18);
    // BTree.insertKey(21);
    // BTree.insertKey(4);
    // BTreeDiagram(BTree.root);
// }