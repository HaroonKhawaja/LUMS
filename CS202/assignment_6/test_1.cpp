#include <iostream>
#include <iomanip>
#include <string>
#include "Task_01.cpp"

using namespace std;

// ------------------------------------- Task 01 Tests -------------------------------------

class MaxHeap_Test : public MaxHeap
{
public:
    MaxHeap_Test(int _capacity) : MaxHeap(_capacity) {}

    string printMaxHeap()
    {
        string output = "";
        for (int i = 0; i < length; i++)
        {
            output = output + to_string(heap_array[i].priority) + " ";
        }
        return output;
    }
};

void testHeapInitialization(int &score_task_1)
{
    cout << "-------------- Max Heap Tests --------------" << endl;
    cout << "Initializing Test 1 - Initialization" << endl;
    MaxHeap_Test test(50);

    try
    {
        if (test.heap_array != NULL)
        {
            score_task_1 += 1;
        }
        else
        {
            cout << "Test 1 failed! heap_array has not been dynamically allocated. " << score_task_1 << "/45" << endl;
            return;
        }
        if (test.capacity == 50 and test.length == 0)
        {
            score_task_1 += 2;
            cout << "Test 1 passed! " << score_task_1 << "/45" << endl;
        }
        else
        {
            cout << "Test 1 failed! Set capacity and length correctly. " << score_task_1 << "/45" << endl;
            return;
        }
    }
    catch (exception ex1)
    {
        cout << "Test 1 failed! " << score_task_1 << "/45" << endl;
    }
}

void testFamilyFunctions(int &score_task_1)
{
    cout << "Initializing Test 2 - Family Functions (getParent, getLeftChild and getRightChild)" << endl;
    MaxHeap_Test test(50);

    try
    {
        if (test.getParent(1) == 0 && test.getParent(3) == 1 && test.getParent(10) == 4)
        {
            score_task_1 += 1;
        }
        else
        {
            cout << "Test 2 failed! getParent() implemented incorrectly." << score_task_1 << "/45" << endl;
            return;
        }

        if (test.getLeftChild(1) == 3 && test.getLeftChild(3) == 7 && test.getLeftChild(10) == 21)
        {
            score_task_1 += 1;
        }
        else
        {
            cout << "Test 2 failed! getLeftChild() implemented incorrectly." << score_task_1 << "/45" << endl;
            return;
        }

        if (test.getRightChild(1) == 4 && test.getRightChild(3) == 8 && test.getRightChild(10) == 22)
        {
            score_task_1 += 1;
            cout << "Test 2 passed! " << score_task_1 << "/45" << endl;
        }
        else
        {
            cout << "Test 2 failed! " << score_task_1 << "/45" << endl;
            return;
        }
    }
    catch (exception ex2)
    {
        cout << "Test 2 failed! " << score_task_1 << "/45" << endl;
    }
}

void testHeapInsertion(int &score_task_1)
{
    cout << "Initializing Test 3 - Max Heap Insertion" << endl;
    MaxHeap_Test test(10);

    try
    {
        bool insert1 = test.insertElement("", 4) && test.insertElement("", 3) && test.insertElement("", 2) && test.insertElement("", 1);
        if ((insert1 == true) && (test.length == 4) && (test.printMaxHeap() == "4 3 2 1 "))
        {
            score_task_1 += 4;
        }
        else
        {
            cout << "Test 3 failed! " << score_task_1 << "/45" << endl;
            return;
        }
        bool insert2 = test.insertElement("", 10) && test.insertElement("", 9) && test.insertElement("", 20) && test.insertElement("", 13);
        if ((insert2 == true) && (test.length == 8) && (test.printMaxHeap() == "20 13 10 4 3 2 9 1 "))
        {
            score_task_1 += 4;
        }
        else
        {
            cout << "Test 3 failed! " << score_task_1 << "/45" << endl;
            return;
        }

        bool insert3 = test.insertElement("", 44) && test.insertElement("", 69) && test.insertElement("", 7);
        if ((insert3 == false) && (test.length == 10) && (test.printMaxHeap() == "69 44 10 13 20 2 9 1 4 3 "))
        {
            score_task_1 += 2;
            cout << "Test 3 Passed! " << score_task_1 << "/45" << endl;
        }
        else
        {
            cout << "Test 3 failed! " << score_task_1 << "/45" << endl;
            return;
        }
    }
    catch (exception ex3)
    {
        cout << "Test 3 failed! " << score_task_1 << "/45" << endl;
    }
}

void testMaximum(int &score_task_1)
{
    cout << "Initializing Test 4 - Maximum (getMax() and extractMax())" << endl;
    MaxHeap_Test test(10);

    try
    {
        test.insertElement("", 4);
        test.insertElement("", 7);
        test.insertElement("", 18);
        test.insertElement("", 15);

        if ((test.getMax().priority == test.heap_array[0].priority) && (test.getMax().priority == 18))
        {
            score_task_1 += 2;
        }
        else
        {
            cout << "Test 4 failed! " << score_task_1 << "/45" << endl;
            return;
        }
        
        test.insertElement("", 25);
        test.insertElement("", 17);
        if ((test.extractMax().priority == 25) && (test.length == 5) && (test.printMaxHeap() == "18 15 17 4 7 "))
        {
            score_task_1 += 10;
            cout << "Test 4 Passed! " << score_task_1 << "/45" << endl;
        }
        else
        {
            cout << "Test 4 failed! " << score_task_1 << "/45" << endl;
            return;
        }
    }
    catch (exception ex4)
    {
        cout << "Test 4 failed! " << score_task_1 << "/45" << endl;
    }
}

void testIncreasePriority(int &score_task_1)
{
    cout << "Initializing Test 5 - Increase Priority" << endl;
    MaxHeap_Test test(10);

    try
    {
        test.insertElement("Andrew", 5);
        test.insertElement("Drake", 4);
        test.insertElement("Gojo", 3);
        test.insertElement("Muhammad", 2);
        test.insertElement("Sugimoto", 1);

        if ((test.increasePriority(2, 10) == true) && (test.getMax().name == "Gojo") && (test.getMax().priority == 13) && (test.printMaxHeap() == "13 4 5 2 1 "))
        {
            cout << "Test 5 Passed! " << score_task_1 << "/45" << endl;
            score_task_1 += 5;
        }
        else
        {
            cout << "Test 5 failed! " << score_task_1 << "/45" << endl;
            return;
        }
    }
    catch (exception ex4)
    {
        cout << "Test 5 failed! " << score_task_1 << "/45" << endl;
    }
}

void testHeapDeletion(int &score_task_1)
{
    cout << "Initializing Test 6 - Max Heap Deletion" << endl;
    MaxHeap_Test test(10);

    try
    {
        test.insertElement("Andrew", 5);
        test.insertElement("Drake", 4);
        test.insertElement("Gojo", 3);
        test.insertElement("Muhammad", 2);
        test.insertElement("Sugimoto", 1);

        if ((test.deleteElement("Gojo") == true) && (test.printMaxHeap() == "5 4 1 2 "))
        {
            score_task_1 += 5;
        }
        else
        {
            cout << "Test 6 failed! " << score_task_1 << "/45" << endl;
            return;
        }

        test.deleteElement("Andrew");
        test.deleteElement("Drake");
        test.deleteElement("Muhammad");
        if ((test.deleteElement("Tristan") == false) && (test.deleteElement("Sugimoto") == true) && (test.deleteElement("Lelouch") == false) && (test.length == 0))
        {
            score_task_1 += 5;
            cout << "Test 6 Passed! " << score_task_1 << "/45" << endl;
        }
        else
        {
            cout << "2. Test 6 failed! " << score_task_1 << "/45" << endl;
            return;
        }
    }
    catch (exception ex4)
    {
        cout << "3. Test 6 failed! " << score_task_1 << "/45" << endl;
    }
}

void testHeapDeinitialization(int &score_task_1)
{
    cout << "Initializing Test 7 - Deinitialization" << endl;
    cout << "Will be checked manually!" << endl;
}

// ------------------------------------- Running the Tests -------------------------------------

int main()
{
    int score_task_1 = 0;
    cout << "-----------------------------------------------" << endl;
    cout << "Testing Implementation of Task 1" << endl
         << endl;

    testHeapInitialization(score_task_1);
    testFamilyFunctions(score_task_1);
    testHeapInsertion(score_task_1);
    testMaximum(score_task_1);
    testIncreasePriority(score_task_1);
    testHeapDeletion(score_task_1);
    testHeapDeinitialization(score_task_1);

    cout << endl
         << endl;

    cout << "-----------------------------------------------" << endl
         << endl;
    cout << "Total Score for Task 1: " << score_task_1 << "/45" << endl
         << endl;
}