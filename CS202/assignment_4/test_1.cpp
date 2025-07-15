#include <iostream>
#include <iomanip>
#include <iterator>
#include "Task_01.cpp"

using namespace std;

// ------------------------------------- Task 01 Tests -------------------------------------

class B_TreeTest : public B_Tree
{
public:
    B_TreeTest(int _order) : B_Tree(_order) {}
};

void testBTreeInitialization(int &score_task_1)
{
    cout << "-------------- BTree Tests --------------" << endl;
    cout << "Initializing Test 1 - Initialization" << endl;
    B_TreeTest test(3);

    try
    {
        int order = test.order;
        Node* root = test.root;
        if (order == 3)
        {
            score_task_1 += 1;
        }
        else
        {
            cout << "Test 1 failed! Incorrect order. " << score_task_1 << "/35" << endl;
            return;
        }
        if (root == NULL)
        {
            score_task_1 += 1;
            cout << "Test 1 passed! " << score_task_1 << "/35" << endl;
        }
        else
        {
            cout << "Test 1 failed! root not pointing to NULL. " << score_task_1 << "/35" << endl;
            return;
        }
    }
    catch (exception ex1)
    {
        cout << "Test 1 failed! " << score_task_1 << "/35" << endl;
    }
}

void testBTreeInsertion(int &score_task_1)
{
    cout << "Initializing Test 2 - Insertion" << endl;
    B_TreeTest test(5);

    try
    {
        test.insertKey(1);
        if (test.traverse() == " 1")
        {
            score_task_1 += 2;
        }
        else
        {
            cout << "Test 2 failed!. " << score_task_1 << "/35" << endl;
            return;
        }
        test.insertKey(3);
        test.insertKey(7);
        test.insertKey(16);
        test.insertKey(19);
        test.insertKey(24);
        if (test.traverse() == " 1 3 7 16 19 24")
        {
            score_task_1 += 2;
        }
        else
        {
            cout << "Test 2 failed!. " << score_task_1 << "/35" << endl;
            return;
        }
        test.insertKey(25);
        test.insertKey(26);
        test.insertKey(10);
        test.insertKey(11);
        test.insertKey(13);
        if (test.traverse() == " 1 3 7 10 11 13 16 19 24 25 26")
        {
            score_task_1 += 2;
        }
        else
        {
            cout << "Test 2 failed!. " << score_task_1 << "/35" << endl;
            return;
        }
        test.insertKey(14);
        test.insertKey(15);
        test.insertKey(18);
        test.insertKey(21);
        test.insertKey(4);
        if (test.traverse() == " 1 3 4 7 10 11 13 14 15 16 18 19 21 24 25 26")
        {
            score_task_1 += 2;
        }
        else
        {
            cout << "Test 2 failed!. " << score_task_1 << "/35" << endl;
            return;
        }
        test.insertKey(5);
        test.insertKey(20);
        test.insertKey(22);
        test.insertKey(2);
        test.insertKey(17);
        if (test.traverse() == " 1 2 3 4 5 7 10 11 13 14 15 16 17 18 19 20 21 22 24 25 26")
        {
            score_task_1 += 2;
            cout << "Test 2 passed! " << score_task_1 << "/35" << endl;
        }
        else
        {
            cout << "Test 2 failed!. " << score_task_1 << "/35" << endl;
            return;
        }
    }
    catch (exception ex1)
    {
        cout << "Test 2 failed! " << score_task_1 << "/35" << endl;
    }
}

void testBTreeDeletion(int &score_task_1)
{
    cout << "Initializing Test 3 - Deletion" << endl;
    B_TreeTest test(5);

    try
    {
        test.insertKey(1);
        test.insertKey(3);
        test.insertKey(7);
        test.insertKey(16);
        test.insertKey(19);
        test.insertKey(24);
        test.insertKey(25);
        test.insertKey(26);
        test.insertKey(10);
        test.insertKey(11);
        test.insertKey(13);
        test.insertKey(14);
        test.insertKey(15);
        test.insertKey(18);
        test.insertKey(21);
        test.insertKey(4);
        test.insertKey(5);
        test.insertKey(20);
        test.insertKey(22);
        test.insertKey(2);
        test.insertKey(17);

        test.deleteKey(13);
        if (test.traverse() == " 1 2 3 4 5 7 10 11 14 15 16 17 18 19 20 21 22 24 25 26")
        {
            score_task_1 += 3;
        }
        else
        {
            cout << "Test 3 failed!. " << score_task_1 << "/35" << endl;
            return;
        }

        test.deleteKey(7);
        if (test.traverse() == " 1 2 3 4 5 10 11 14 15 16 17 18 19 20 21 22 24 25 26")
        {
            score_task_1 += 3;
        }
        else
        {
            cout << "Test 3 failed!. " << score_task_1 << "/35" << endl;
            return;
        }

        test.deleteKey(4);
        if (test.traverse() == " 1 2 3 5 10 11 14 15 16 17 18 19 20 21 22 24 25 26")
        {
            score_task_1 += 3;
        }
        else
        {
            cout << "Test 3 failed!. " << score_task_1 << "/35" << endl;
            return;
        }

        test.deleteKey(2);
        if (test.traverse() == " 1 3 5 10 11 14 15 16 17 18 19 20 21 22 24 25 26")
        {
            score_task_1 += 3;
        }
        else
        {
            cout << "Test 3 failed!. " << score_task_1 << "/35" << endl;
            return;
        }

        test.deleteKey(6);
        if (test.traverse() == " 1 3 5 10 11 14 15 16 17 18 19 20 21 22 24 25 26")
        {
            score_task_1 += 3;
            cout << "Test 3 Passed!. " << score_task_1 << "/35" << endl;
        }
        else
        {
            cout << "Test 3 failed!. " << score_task_1 << "/35" << endl;
            return;
        }
    }
    catch (exception ex1)
    {
        cout << "Test 3 failed! " << score_task_1 << "/35" << endl;
    }
}

void testBTreeSearch(int &score_task_1)
{
    cout << "Initializing Test 4 - Search" << endl;
    B_TreeTest test(5);

    try
    {
        test.insertKey(1);
        test.insertKey(3);
        test.insertKey(7);
        test.insertKey(16);
        test.insertKey(19);
        test.insertKey(24);
        test.insertKey(25);
        test.insertKey(26);
        test.insertKey(10);
        test.insertKey(11);
        test.insertKey(13);
        test.insertKey(14);
        test.insertKey(15);
        test.insertKey(18);
        test.insertKey(21);
        test.insertKey(4);

        Node* node = test.searchKey(16);
        if (node->keys[0].key == 7 && node->keys[1].key == 13 && node->keys[2].key == 16 && node->keys[3].key == 24)
        {
            score_task_1 += 3;
        }
        else
        {
            cout << "Test 4 failed!. " << score_task_1 << "/35" << endl;
            return;
        }
        node = test.searchKey(30);        
        if (node == NULL)
        {
            score_task_1 += 2;
            cout << "Test 4 passed!. " << score_task_1 << "/35" << endl;
        }
        else
        {
            cout << "Test 4 failed!. " << score_task_1 << "/35" << endl;
            return;
        }
    }
    catch (exception ex1)
    {
        cout << "Test 4 failed! " << score_task_1 << "/35" << endl;
    }
}

void testBTreeDeinitialization(int &score_task_1)
{
    cout << "Initializing Test 5 - Deinitialization" << endl;
    cout << "[Will be checked manually]" << endl;
}


// ------------------------------------- Running the Tests -------------------------------------

int main()
{
    int score_task_1 = 0;
    cout << "-----------------------------------------------" << endl;
    cout << "Testing Implementation of Task 1" << endl
         << endl;

    testBTreeInitialization(score_task_1);
    testBTreeInsertion(score_task_1);
    testBTreeDeletion(score_task_1);
    testBTreeSearch(score_task_1);
    testBTreeDeinitialization(score_task_1);

    cout << endl
         << endl;

    cout << "-----------------------------------------------" << endl
         << endl;
    cout << "Total Score for Task 1: " << score_task_1 << "/35" << endl
         << endl;
}