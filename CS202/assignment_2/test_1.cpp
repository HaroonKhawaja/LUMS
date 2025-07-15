#include <iostream>
#include <iomanip>
#include <iterator>
#include "Task_01.cpp"

using namespace std;

// ------------------------------------- Task 01 Tests -------------------------------------

// -------------- Stack Tests --------------
class StackTest : public Stack
{
public:
    StackTest(int cap) : Stack(cap) {}

    string operator[](int i)
    {
        list<string>::iterator it = (stack).begin();
        advance(it, i);
        return *it;
    }
};

void testStackInitialization(int &score_task_1)
{
    cout << "-------------- Stack Tests --------------" << endl;
    cout << "Initializing Test 1 - Initialization" << endl;
    StackTest test(3);

    try
    {
        int cap = test.capacity;
        if (cap == 3)
        {
            score_task_1 += 1;
            cout << "Test 1 passed! " << score_task_1 << "/30" << endl;
        }
        else
        {
            cout << "Test 1 failed! Incorrect capacity. " << score_task_1 << "/30" << endl;
            return;
        }
    }
    catch (exception ex1)
    {
        cout << "Test 1 failed! " << score_task_1 << "/30" << endl;
    }
}

void testStackLength(int &score_task_1)
{
    cout << "Initializing Test 2 - Length" << endl;
    StackTest test(5);

    try
    {
        string arr[4] = {"1", "2", "3", "4"};
        (test.stack).assign(arr, arr + 4);
        if (test.length() == 4)
        {
            score_task_1 += 2;
            cout << "Test 2 passed! " << score_task_1 << "/30" << endl;
        }
        else
        {
            cout << "Test 2 failed! " << score_task_1 << "/30" << endl;
            return;
        }
    }
    catch (exception ex2)
    {
        cout << "Test 2 failed! " << score_task_1 << "/30" << endl;
    }
}

void testStackPush(int &score_task_1)
{
    cout << "Initializing Test 3 - Push" << endl;
    StackTest test(3);

    try
    {
        test.push("1");
        if (test[0] == "1")
        {
        }
        else
        {
            cout << "Test 3 failed! " << score_task_1 << "/30" << endl;
            return;
        }

        test.push("2");
        test.push("3");
        if (test[0] == "3" && test[1] == "2" && test[2] == "1" && test.push("4") == "NULL")
        {
            score_task_1 += 3;
            cout << "Test 3 passed! " << score_task_1 << "/30" << endl;
        }
        else
        {
            cout << "Test 3 failed! " << score_task_1 << "/30" << endl;
            return;
        }
    }
    catch (exception ex3)
    {
        cout << "Test 3 failed! " << score_task_1 << "/30" << endl;
    }
}

void testStackPop(int &score_task_1)
{
    cout << "Initializing Test 4 - Pop" << endl;
    StackTest test(3);

    try
    {
        string arr[3] = {"1", "2", "3"};
        (test.stack).assign(arr, arr + 3);
        string removed = test.pop();
        if (removed == "1" && (test.stack).size() == 2)
        {
        }
        else
        {
            cout << "Test 4 failed! " << score_task_1 << "/30" << endl;
            return;
        }

        removed = test.pop();
        if (removed == "2" && (test.stack).size() == 1)
        {
        }
        else
        {
            cout << "Test 4 failed! " << score_task_1 << "/30" << endl;
            return;
        }

        removed = test.pop();
        if (removed == "3" && (test.stack).size() == 0)
        {
        }
        else
        {
            cout << "Test 4 failed! " << score_task_1 << "/30" << endl;
            return;
        }

        if (test.pop() == "NULL" && (test.stack).size() == 0)
        {
            score_task_1 += 3;
            cout << "Test 4 passed! " << score_task_1 << "/30" << endl;
        }
        else
        {
            cout << "Test 4 failed! " << score_task_1 << "/30" << endl;
            return;
        }
    }
    catch (exception ex4)
    {
        cout << "Test 4 failed! " << score_task_1 << "/30" << endl;
    }
}

void testStackTop(int &score_task_1)
{
    cout << "Initializing Test 5 - Top" << endl;
    StackTest test1(3);
    StackTest test2(3);
    StackTest test3(3);

    try
    {
        string arr1[3] = {"1", "2", "3"};
        (test1.stack).assign(arr1, arr1 + 3);
        string top = test1.top();
        if (top == "1" && (test1.stack).size() == 3)
        {
        }
        else
        {
            cout << "Test 5 failed! " << score_task_1 << "/30" << endl;
            return;
        }

        string arr2[2] = {"2", "1"};
        (test2.stack).assign(arr2, arr2 + 2);
        top = test2.top();
        if (top == "2" && (test2.stack).size() == 2)
        {
        }
        else
        {
            cout << "Test 5 failed! " << score_task_1 << "/30" << endl;
            return;
        }

        top = test3.top();
        if (top == "NULL" && (test3.stack).size() == 0)
        {
            score_task_1 += 2;
            cout << "Test 5 passed! " << score_task_1 << "/30" << endl;
        }
        else
        {
            cout << "Test 5 failed! " << score_task_1 << "/30" << endl;
            return;
        }
    }
    catch (exception ex5)
    {
        cout << "Test 5 failed! " << score_task_1 << "/30" << endl;
    }
}

void testStackReverse(int &score_task_1)
{
    cout << "Initializing Test 6 - Reverse" << endl;
    StackTest test(5);
    StackTest test2(3);

    try
    {
        string array[5] = {"1", "2", "3", "4", "5"};
        (test.stack).assign(array, array + 5);
        test.reverse();
        if (test[0] == "5" && test[1] == "4" && test[2] == "3" && test[3] == "2" && test[4] == "1")
        {
        }
        else
        {
            cout << "Test 6 failed! " << score_task_1 << "/30" << endl;
            return;
        }

        test2.reverse();
        if ((test2.stack).size() == 0)
        {
            score_task_1 += 4;
            cout << "Test 6 passed! " << score_task_1 << "/30" << endl;
        }
        else
        {
            cout << "Test 6 failed! " << score_task_1 << "/30" << endl;
            return;
        }
    }
    catch (exception ex6)
    {
        cout << "Test 6 failed! " << score_task_1 << "/30" << endl;
    }
}

// -------------- Queue Tests --------------
class QueueTest : public Queue
{
public:
    QueueTest(int cap) : Queue(cap) {}

    string operator[](int i)
    {
        list<string>::iterator it = (queue).begin();
        advance(it, i);
        return *it;
    }
};

void testQueueInitialization(int &score_task_1)
{
    cout << "\n-------------- Queue Tests --------------" << endl;
    cout << "Initializing Test 1 - Initialization" << endl;
    QueueTest test(3);

    try
    {
        int cap = test.capacity;
        if (cap == 3)
        {
            score_task_1 += 1;
            cout << "Test 1 passed! " << score_task_1 << "/30" << endl;
        }
        else
        {
            cout << "Test 1 failed! Incorrect capacity. " << score_task_1 << "/30" << endl;
            return;
        }
    }
    catch (exception ex7)
    {
        cout << "Test 1 failed! " << score_task_1 << "/30" << endl;
    }
}

void testQueueLength(int &score_task_1)
{
    cout << "Initializing Test 2 - Length" << endl;
    QueueTest test(5);

    try
    {
        string arr[4] = {"1", "2", "3", "4"};
        (test.queue).assign(arr, arr + 4);
        if (test.length() == 4)
        {
            score_task_1 += 2;
            cout << "Test 2 passed! " << score_task_1 << "/30" << endl;
        }
        else
        {
            cout << "Test 2 failed! " << score_task_1 << "/30" << endl;
            return;
        }
    }
    catch (exception ex8)
    {
        cout << "Test 2 failed! " << score_task_1 << "/30" << endl;
    }
}

void testQueueEnqueue(int &score_task_1)
{
    cout << "Initializing Test 3 - Enqueue" << endl;
    QueueTest test(3);

    try
    {
        test.enqueue("1");
        if (test[0] == "1")
        {
        }
        else
        {
            cout << "Test 3 failed! " << score_task_1 << "/30" << endl;
            return;
        }

        test.enqueue("2");
        test.enqueue("3");
        if (test[0] == "3" && test[1] == "2" && test[2] == "1" && test.enqueue("4") == "NULL")
        {
            score_task_1 += 3;
            cout << "Test 3 passed! " << score_task_1 << "/30" << endl;
        }
        else
        {
            cout << "Test 3 failed! " << score_task_1 << "/30" << endl;
            return;
        }
    }
    catch (exception ex9)
    {
        cout << "Test 3 failed! " << score_task_1 << "/30" << endl;
    }
}

void testQueueDequeue(int &score_task_1)
{
    cout << "Initializing Test 4 - Dequeue" << endl;
    QueueTest test(3);

    try
    {
        string arr[3] = {"1", "2", "3"};
        (test.queue).assign(arr, arr + 3);
        string removed = test.dequeue();
        if (removed == "3" && (test.queue).size() == 2)
        {
        }
        else
        {
            cout << "Test 4 failed! " << score_task_1 << "/30" << endl;
            return;
        }

        removed = test.dequeue();
        if (removed == "2" && (test.queue).size() == 1)
        {
        }
        else
        {
            cout << "Test 4 failed! " << score_task_1 << "/30" << endl;
            return;
        }

        removed = test.dequeue();
        if (removed == "1" && (test.queue).size() == 0)
        {
        }
        else
        {
            cout << "Test 4 failed! " << score_task_1 << "/30" << endl;
            return;
        }

        if (test.dequeue() == "NULL" && (test.queue).size() == 0)
        {
            score_task_1 += 3;
            cout << "Test 4 passed! " << score_task_1 << "/30" << endl;
        }
        else
        {
            cout << "Test 4 failed! " << score_task_1 << "/30" << endl;
            return;
        }
    }
    catch (exception ex10)
    {
        cout << "Test 4 failed! " << score_task_1 << "/30" << endl;
    }
}

void testQueueFront(int &score_task_1)
{
    cout << "Initializing Test 5 - Front" << endl;
    QueueTest test1(3);
    QueueTest test2(3);
    QueueTest test3(3);

    try
    {
        string arr1[3] = {"1", "2", "3"};
        (test1.queue).assign(arr1, arr1 + 3);
        string front = test1.front();
        if (front == "3" && (test1.queue).size() == 3)
        {
        }
        else
        {
            cout << "Test 5 failed! " << score_task_1 << "/30" << endl;
            return;
        }

        string arr2[2] = {"2", "1"};
        (test2.queue).assign(arr2, arr2 + 2);
        front = test2.front();
        if (front == "1" && (test2.queue).size() == 2)
        {
        }
        else
        {
            cout << "Test 5 failed! " << score_task_1 << "/30" << endl;
            return;
        }

        front = test3.front();
        if (front == "NULL" && (test3.queue).size() == 0)
        {
            score_task_1 += 2;
            cout << "Test 5 passed! " << score_task_1 << "/30" << endl;
        }
        else
        {
            cout << "Test 5 failed! " << score_task_1 << "/30" << endl;
            return;
        }
    }
    catch (exception ex11)
    {
        cout << "Test 5 failed! " << score_task_1 << "/30" << endl;
    }
}

void testQueueReverse(int &score_task_1)
{
    cout << "Initializing Test 6 - Reverse" << endl;
    QueueTest test(5);
    QueueTest test2(3);

    try
    {
        string arr[5] = {"1", "2", "3", "4", "5"};
        (test.queue).assign(arr, arr + 5);
        test.reverse();
        if (test[0] == "5" && test[1] == "4" && test[2] == "3" && test[3] == "2" && test[4] == "1")
        {
        }
        else
        {
            cout << "Test 6 failed! " << score_task_1 << "/30" << endl;
            return;
        }

        test2.reverse();
        if ((test2.queue).size() == 0)
        {
            score_task_1 += 4;
            cout << "Test 6 passed! " << score_task_1 << "/30" << endl;
        }
        else
        {
            cout << "Test 6 failed! " << score_task_1 << "/30" << endl;
            return;
        }
    }
    catch (exception ex12)
    {
        cout << "Test 6 failed! " << score_task_1 << "/30" << endl;
    }
}
// ------------------------------------- Running the Tests -------------------------------------

int main()
{
    int score_task_1 = 0;
    cout << "-----------------------------------------------" << endl;
    cout << "Testing Implementation of Task 1" << endl
         << endl;

    testStackInitialization(score_task_1);
    testStackLength(score_task_1);
    testStackPush(score_task_1);
    testStackPop(score_task_1);
    testStackTop(score_task_1);
    testStackReverse(score_task_1);

    testQueueInitialization(score_task_1);
    testQueueLength(score_task_1);
    testQueueEnqueue(score_task_1);
    testQueueDequeue(score_task_1);
    testQueueFront(score_task_1);
    testQueueReverse(score_task_1);

    cout << endl
         << endl;

    cout << "-----------------------------------------------" << endl
         << endl;
    cout << "Total Score for Task 1: " << score_task_1 << "/30" << endl
         << endl;
}