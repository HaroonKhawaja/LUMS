#include <iostream>
#include <iomanip>
#include "Task_01.cpp"

using namespace std;

int TOTAL = 30;

Node* increment_(Node* x, int y)
{
    if (x == NULL)
    {
        Node* z = new Node(y);
        return z;
    }
    else if (x->data < y)
    {
        x->right = increment_(x->right, y);
    }
    else if (x->data > y)
    {
        x->left = increment_(x->left, y);
    }
    return x;
}


string display_(Node* x)
{
    string y = "";
    if (x != NULL)
    {
        y += display_(x->left);
        y += to_string(x->data) + " ";
        y += display_(x->right);
    }
    return y;
}

string remove_trail(string x)
{
    int y = x.length();
    if (y)
    {
        x = x.substr(0,y-1);
    }
    return x;
}


class Test: public BST
{
    public:

    void increment(int x)
    {
        root = increment_(root, x);
    }

    string display()
    {
        return remove_trail(display_(root));
    }
};



void testInitialization(int &score_task_1)
{
    cout << "Initializing Test 1 - Tree Initialization" << endl;
    Test test;

    try {
        if (test.root == NULL)
        {
            score_task_1 += 1;
            cout << "Test 1 passed! " << score_task_1 << "/" << TOTAL << endl;
        }
        else
        {
            cout << "Test 1 failed! Incorrect tree initialization. " << score_task_1 << "/" << TOTAL << endl;
            return;
        }
    }
    catch(exception ex1) {
        cout << "Test 1 failed! Exception occurred. " << score_task_1 << "/" << TOTAL << endl;
    }
}



void testInsert(int &score_task_1)
{
    cout << "Initializing Test 2 - Insertion" << endl;
    Test test;

    try {
        test.insert(40);
        if(test.root->data == 40)
        {
            score_task_1 += 2;
        }
        else
        {
            cout << "Test 2 failed! Incorrect insertion into empty tree. " << score_task_1 << "/" << TOTAL << endl;
        }

        test.insert(30);
        test.insert(65);
        test.insert(60);
        test.insert(36);
        bool condition = test.root->data==40 && test.root->left->data==30 && test.root->left->right->data==36 
        && test.root->right->data==65 && test.root->right->left->data==60 && test.display()=="30 36 40 60 65"; 
        if (condition)
        {
            score_task_1 += 3;
            cout << "Test 2 passed! " << score_task_1 << "/" << TOTAL << endl;
        }
        else
        {
            cout << "Test 2 failed! Incorrect insertion. " << score_task_1 << "/" << TOTAL << endl;
            return;
        }
    }
    catch(exception ex1) {
        cout << "Test 2 failed! Exception occurred. " << score_task_1 << "/" << TOTAL << endl;
    }
}



void testInorder(int &score_task_1)
{
    cout << "Initializing Test 3 - Inorder Traversal" << endl;
    Test test;

    try {
        test.increment(40);
        test.increment(20);
        test.increment(52);
        test.increment(6);
        test.increment(31);
        test.increment(55);
        test.increment(60);
        test.increment(25);
        test.increment(57);
        if (test.inorder()=="6 20 25 31 40 52 55 57 60")
        {
            score_task_1 += 1;
            cout << "Test 3 passed! " << score_task_1 << "/" << TOTAL << endl;
        }
        else
        {
            cout << "Test 3 failed! Incorrect traversal. " << score_task_1 << "/" << TOTAL << endl;
            return;
        }
    }
    catch(exception ex1) {
        cout << "Test 3 failed! Exception occurred. " << score_task_1 << "/" << TOTAL << endl;
    }
}


void testPreorder(int &score_task_1)
{
    cout << "Initializing Test 4 - Preorder Traversal" << endl;
    Test test;

    try {
        test.increment(40);
        test.increment(20);
        test.increment(52);
        test.increment(6);
        test.increment(31);
        test.increment(55);
        test.increment(60);
        test.increment(25);
        test.increment(57);
        if (test.preorder()=="40 20 6 31 25 52 55 60 57")
        {
            score_task_1 += 1;
            cout << "Test 4 passed! " << score_task_1 << "/" << TOTAL << endl;
        }
        else
        {
            cout << "Test 4 failed! Incorrect traversal. " << score_task_1 << "/" << TOTAL << endl;
            return;
        }
    }
    catch(exception ex1) {
        cout << "Test 4 failed! Exception occurred. " << score_task_1 << "/" << TOTAL << endl;
    }
}



void testPostorder(int &score_task_1)
{
    cout << "Initializing Test 5 - Postorder Traversal" << endl;
    Test test;

    try {
        test.increment(40);
        test.increment(20);
        test.increment(52);
        test.increment(6);
        test.increment(31);
        test.increment(55);
        test.increment(60);
        test.increment(25);
        test.increment(57);
        if (test.postorder()=="6 25 31 20 57 60 55 52 40")
        {
            score_task_1 += 1;
            cout << "Test 5 passed! " << score_task_1 << "/" << TOTAL << endl;
        }
        else
        {
            cout << "Test 5 failed! Incorrect traversal. " << score_task_1 << "/" << TOTAL << endl;
            return;
        }
    }
    catch(exception ex1) {
        cout << "Test 5 failed! Exception occurred. " << score_task_1 << "/" << TOTAL << endl;
    }
}



void testGetNode(int &score_task_1)
{
    cout << "Initializing Test 6 - Get Node" << endl;
    Test test;

    try {
        if (test.getNode(1) == NULL)
        {
            score_task_1 += 1;
        }
        else
        {
            cout << "Task 6 failed! Does not return NULL from empty tree. " << score_task_1 << "/" << TOTAL << endl;
        }

        test.increment(40);
        test.increment(20);
        test.increment(52);
        test.increment(6);
        test.increment(31);
        test.increment(55);
        test.increment(60);
        test.increment(25);
        test.increment(57);

        Node* temp = test.getNode(40);
        if (temp!=NULL && test.root==temp)
        {
            score_task_1 += 1;
        }
        else
        {
            cout << "Test 6 failed! Incorrect root node. " << score_task_1 << "/" << TOTAL << endl;
        }

        temp = test.getNode(4);
        if (temp==NULL)
        {
            score_task_1 += 1;
        }
        else
        {
            cout << "Test 6 failed! Does not return NULL for node not present in tree. " << score_task_1 << "/" << TOTAL << endl;
        }

        temp = test.getNode(25);
        if (temp == test.root->left->right->left)
        {
            score_task_1 += 1;
            cout << "Test 6 passed! " << score_task_1 << "/" << TOTAL << endl;
        }
        else
        {
            cout << "Test 6 failed! " << score_task_1 << "/" << TOTAL << endl;
            return;
        }
    }
    catch(exception ex1) {
        cout << "Test 6 failed! Exception occurred. " << score_task_1 << "/" << TOTAL << endl;
    }
}



void testGetHeight(int &score_task_1)
{
    cout << "Initializing Test 7 - Get Height" << endl;
    Test test;

    try {
        if (test.height() == 0)
        {
            score_task_1 += 1;
        }
        else
        {
            cout << "Task 7 failed! Incorrect height for empty tree " << score_task_1 << "/" << TOTAL << endl;
        }

        test.increment(40);

        if (test.height() == 1)
        {
            score_task_1 += 1;
        }
        else
        {
            cout << "Task 7 failed! Incorrect height for single node tree " << score_task_1 << "/" << TOTAL << endl;
        }

        test.increment(20);
        test.increment(52);
        test.increment(6);
        test.increment(31);
        test.increment(55);
        test.increment(60);
        test.increment(25);
        test.increment(57);

        if (test.height()==5)
        {
            score_task_1 += 1;
            cout << "Test 7 passed! " << score_task_1 << "/" << TOTAL << endl;
        }
        else
        {
            cout << "Test 7 failed! " << score_task_1 << "/" << TOTAL << endl;
            return;
        }
    }
    catch(exception ex1) {
        cout << "Test 7 failed! Exception occurred. " << score_task_1 << "/" << TOTAL << endl;
    }
}



void testGetSize(int &score_task_1)
{
    cout << "Initializing Test 8 - Get Size" << endl;
    Test test;

    try {
        if (test.size() == 0)
        {
            score_task_1 += 1;
        }
        else
        {
            cout << "Task 8 failed! Incorrect size for empty tree " << score_task_1 << "/" << TOTAL << endl;
        }

        test.increment(40);

        if (test.size() == 1)
        {
            score_task_1 += 1;
        }
        else
        {
            cout << "Task 8 failed! Incorrect size for single node tree " << score_task_1 << "/" << TOTAL << endl;
        }

        test.increment(20);
        test.increment(52);
        test.increment(6);
        test.increment(31);
        test.increment(55);
        test.increment(60);
        test.increment(25);
        test.increment(57);

        if (test.size()==9)
        {
            score_task_1 += 1;
            cout << "Test 8 passed! " << score_task_1 << "/" << TOTAL << endl;
        }
        else
        {
            cout << "Test 8 failed! " << score_task_1 << "/" << TOTAL << endl;
            return;
        }
    }
    catch(exception ex1) {
        cout << "Test 8 failed! Exception occurred. " << score_task_1 << "/" << TOTAL << endl;
    }
}



void testGetPath(int &score_task_1)
{
    cout << "Initializing Test 9 - Get Path" << endl;
    Test test;

    try {
        if (test.path(-1) == "")
        {
            score_task_1 += 2;
        }
        else
        {
            cout << "Task 9 failed! Incorrect path for empty tree " << score_task_1 << "/" << TOTAL << endl;
        }

        test.increment(40);
        test.increment(20);
        test.increment(52);
        test.increment(6);
        test.increment(31);
        test.increment(55);
        test.increment(60);
        test.increment(25);
        test.increment(57);

        if (test.path(31)=="40 20 31" && test.path(40)=="40" && test.path(57)=="40 52 55 60 57")
        {
            score_task_1 += 2;
            cout << "Test 9 passed! " << score_task_1 << "/" << TOTAL << endl;
        }
        else
        {
            cout << "Test 9 failed! " << score_task_1 << "/" << TOTAL << endl;
            return;
        }
    }
    catch(exception ex1) {
        cout << "Test 9 failed! Exception occurred. " << score_task_1 << "/" << TOTAL << endl;
    }
}



void testDeleteNode(int &score_task_1)
{
    cout << "Initializing Test 10 - Delete Node" << endl;
    Test test;

    try {
        test.increment(40);
        test.increment(20);
        test.increment(52);
        test.increment(6);
        test.increment(31);
        test.increment(55);
        test.increment(60);
        test.increment(25);
        test.increment(57);
        test.deleteNode(40);
        if(test.display()=="6 20 25 31 52 55 57 60")
        {
            score_task_1 += 1;
        }
        else
        {
            cout << "Test 10 failed! Incorrect deletion at root node " << score_task_1 << "/" << TOTAL << endl;
        }

        test.deleteNode(31);
        if(test.display()=="6 20 25 52 55 57 60")
        {
            score_task_1 += 2;
        }
        else
        {
            cout << "Test 10 failed! " << score_task_1 << "/" << TOTAL << endl;
        }
        
        test.deleteNode(20);
        if(test.display()=="6 25 52 55 57 60")
        {
            score_task_1 += 2;
        }
        else
        {
            cout << "Test 10 failed! " << score_task_1 << "/" << TOTAL << endl;
        }

        test.deleteNode(57);
        if(test.display()=="6 25 52 55 60")
        {
            score_task_1 += 1;
        }
        else
        {
            cout << "Test 10 failed! " << score_task_1 << "/" << TOTAL << endl;
        }

        test.deleteNode(55);
        test.deleteNode(25);
        test.deleteNode(60);
        test.deleteNode(6);
        test.deleteNode(52);
        if(test.display()=="")
        {
            score_task_1 += 1;
            cout << "Test 10 passed! " << score_task_1 << "/" << TOTAL << endl;
        }
        else
        {
            cout << "Test 10 failed! " << score_task_1 << "/" << TOTAL << endl;
            return;
        }

    }
    catch(exception ex1) {
        cout << "Test 10 failed! Exception occurred. " << score_task_1 << "/" << TOTAL << endl;
    }
}








// ------------------------------------- Running the Tests -------------------------------------


int main() {
    int score_task_1 = 0;
    cout << "-----------------------------------------------" << endl;
    cout << "Testing Implementation of Task 1" << endl << endl;

    testInitialization(score_task_1);
    testInsert(score_task_1);
    testInorder(score_task_1);
    testPreorder(score_task_1);
    testPostorder(score_task_1);
    testGetNode(score_task_1);
    testGetHeight(score_task_1);
    testGetSize(score_task_1);
    testGetPath(score_task_1);
    testDeleteNode(score_task_1);

    cout << endl << endl << endl;


    cout << "-----------------------------------------------" << endl << endl;
    cout << "Total Score for Task 1: " << score_task_1 << "/" << TOTAL << endl << endl;
}