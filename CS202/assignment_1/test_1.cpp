#include <iostream>
#include <iomanip>
#include "Task_01.cpp"

using namespace std;




// ------------------------------------- Task 01 Tests -------------------------------------


class VectorTest: public CreateVector {
    public:

    void testIncrement(int var_x) {
        array_size ++;
        array[array_size - 1] = var_x;
    }
};


void testInitialization(int &score_task_1)
{
    cout << "Initializing Test 1 - Object Initialization" << endl;
    VectorTest test;

    try {
        int size = test.array_size;
        if (size==0)
        {
            score_task_1 += 2;
            cout << "Test 1 passed! " << score_task_1 << "/30" << endl;
        }
        else
        {
            cout << "Test 1 failed! Incorrect array size." << score_task_1 << "/30" << endl;
            return;
        }
    }
    catch(exception ex1) {
        cout << "Test 1 failed! " << score_task_1 << "/30" << endl;
    }
}


void testOverloader(int &score_task_1)
{
    cout << "Initializing Test 2 - Operator Overloading" << endl;
    VectorTest test;
    try {
        test.testIncrement(1);
        test.testIncrement(2);
        test.testIncrement(3);
        if (test[0]==1 && test[1]==2 && test[2]==3) {
            score_task_1 += 4;
            cout << "Test 2 passed! " << score_task_1 << "/30" << endl;
        }
        else {
            cout << "Test 2 failed! " << score_task_1 << "/30" << endl;
            return;
        }
    }
    catch(exception ex2) {
        cout << "Test 2 failed! " << score_task_1 << "/30" << endl;
    }
}


void testPush(int &score_task_1)
{
    cout << "Initializing Test 3 - Push" << endl;
    VectorTest test;

    try {
        test.push(1);
        if (test.array[0]==1 && test.array_size==1) {}
        else {
            cout << "Test 3 failed! " << score_task_1 << "/30" << endl;
            return;
        }

        test.push(2);
        test.push(3);
        if (test.array[0]==1 && test.array[1]==2 && test.array[2]==3 && test.array_size==3) {
            score_task_1 += 5;
            cout << "Test 3 passed! " << score_task_1 << "/30" << endl;
        }
        else {
            cout << "Test 3 failed! " << score_task_1 << "/30" << endl;
            return;
        }
    }
    catch(exception ex3) {
        cout << "Test 3 failed! " << score_task_1 << "/30" << endl;
    }
}


void testPop(int &score_task_1)
{
    cout << "Initializing Test 4 - Pop" << endl;
    VectorTest test;

    try {
        test.testIncrement(1);
        test.testIncrement(2);
        test.testIncrement(3);
        int removed = test.pop();
        if (test.array[0]==1 && test.array[1]==2 && test.array_size==2 && removed==3) {}
        else {
            cout << "Test 4 failed! " << score_task_1 << "/30" << endl;
            return;
        }

        if (test.pop()==2 && test.pop()==1 && test.array_size==0) {}
        else {
            cout << "Test 4 failed! " << score_task_1 << "/30" << endl;
            return;
        }

        if (test.pop()==-1 && test.array_size==0) {
            score_task_1 += 5;
            cout << "Test 4 passed! " << score_task_1 << "/30" << endl;
        }
        else {
            cout << "Test 4 failed! " << score_task_1 << "/30" << endl;
            return;
        }
    }
    catch(exception ex4) {
        cout << "Test 4 failed! " << score_task_1 << "/30" << endl;
    }
}


void testVectorLength(int &score_task_1)
{
    cout << "Initializing Test 5 - Vector Length" << endl;
    VectorTest test;

    try {
        int size = test.array_size;
        if (size==0)
        {}
        else {
            cout << "Test 5 failed! " << score_task_1 << "/30" << endl;
            return;
        }

        test.testIncrement(1);
        test.testIncrement(2);
        test.testIncrement(3);
        test.testIncrement(4);
        test.testIncrement(5);
        if (test.vectorLength()==5) {
            score_task_1 += 2;
            cout << "Test 5 passed! " << score_task_1 << "/30" << endl;
        }
        else {
            cout << "Test 5 failed! " << score_task_1 << "/30" << endl;
            return;
        }
    }
    catch(exception ex5) {
        cout << "Test 5 failed! " << score_task_1 << "/30" << endl;
    }
}


void testRemoveFromIndex(int &score_task_1)
{
    cout << "Initializing Test 6 - Remove from Index" << endl;
    VectorTest test;

    try {
        test.testIncrement(1);
        test.testIncrement(2);
        test.testIncrement(3);
        test.testIncrement(4);
        
        test.removeFromIndex(1);
        if (test.array[0]==1 && test.array[1]==3 && test.array[2]==4 && test.array_size==3) {}
        else {
            cout << "Test 6 failed! " << score_task_1 << "/30" << endl;
            return;
        }

        test.removeFromIndex(2);
        if (test.array[0]==1 && test.array[1]==3 && test.array_size==2) {}
        else {
            cout << "Test 6 failed! " << score_task_1 << "/30" << endl;
            return;
        }

        test.removeFromIndex(0);
        if (test.array[0]==3 && test.array_size==1) {}
        else {
            cout << "Test 6 failed! " << score_task_1 << "/30" << endl;
            return;
        }

        test.removeFromIndex(0);
        if (test.array_size==0) {
            score_task_1 += 6;
            cout << "Test 6 passed! " << score_task_1 << "/30" << endl;
        }
        else {
            cout << "Test 6 failed! " << score_task_1 << "/30" << endl;
            return;
        }
    }
    catch(exception ex6) {
        cout << "Test 6 failed! " << score_task_1 << "/30" << endl;
    }
}


void testRemoveValue(int &score_task_1)
{
    cout << "Initializing Test 7 - Remove Value" << endl;
    VectorTest test;

    try {
        test.testIncrement(1);
        test.testIncrement(2);
        test.testIncrement(3);
        test.testIncrement(4);
        
        test.removeValue(2);
        if (test.array[0]==1 && test.array[1]==3 && test.array[2]==4 && test.array_size==3) {}
        else {
            cout << "Test 7 failed! " << score_task_1 << "/30" << endl;
            return;
        }

        test.removeValue(4);
        if (test.array[0]==1 && test.array[1]==3 && test.array_size==2) {}
        else {
            cout << "Test 7 failed! " << score_task_1 << "/30" << endl;
            return;
        }

        test.removeValue(1);
        if (test.array[0]==3 && test.array_size==1) {}
        else {
            cout << "Test 7 failed! " << score_task_1 << "/30" << endl;
            return;
        }

        test.removeValue(3);
        if (test.array_size==0) {
            score_task_1 += 6;
            cout << "Test 7 passed! " << score_task_1 << "/30" << endl;
        }
        else {
            cout << "Test 7 failed! " << score_task_1 << "/30" << endl;
            return;
        }
    }
    catch(exception ex7) {
        cout << "Test 7 failed! " << score_task_1 << "/30" << endl;
    }
}






// ------------------------------------- Running the Tests -------------------------------------


int main() {
    int score_task_1 = 0;
    cout << "-----------------------------------------------" << endl;
    cout << "Testing Implementation of Task 1" << endl << endl;

    testInitialization(score_task_1);
    testOverloader(score_task_1);
    testPush(score_task_1);
    testPop(score_task_1);
    testVectorLength(score_task_1);
    testRemoveFromIndex(score_task_1);
    testRemoveValue(score_task_1);

    cout << "\nTotal Score for Task 1: " << score_task_1 << "/30" << endl;

    cout << endl << endl << endl;


    cout << "-----------------------------------------------" << endl << endl;
    cout << "Total Score for Task 1: " << score_task_1 << "/30" << endl << endl;
}