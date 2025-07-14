#include <iostream>
#include <iomanip>
#include <iterator>
#include "Task_02.cpp"

using namespace std;

// ------------------------------------- Task 02 Tests -------------------------------------

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

StackTest studentstk(10);
QueueTest enrollq(3);
QueueTest waitq(10);

void testIncomingRequests(int &score_task_2)
{
    cout << "Initializing Test 1 - Incoming Requests" << endl;
    try
    {
        studentstk.push("22100222");
        studentstk.push("21110032");
        studentstk.push("22221320");
        incoming_request("24100027", enrollq, waitq, studentstk);
        incoming_request("23100169", enrollq, waitq, studentstk);
        incoming_request("22100222", enrollq, waitq, studentstk);
        incoming_request("25100011", enrollq, waitq, studentstk);
        if (enrollq[0] == "25100011" && enrollq[1] == "23100169" && enrollq[2] == "24100027" && waitq.length() == 0 && studentstk.length() == 3)
        {
        }
        else
        {
            cout << "Test 1 failed! " << score_task_2 << "/45" << endl;
            return;
        }

        incoming_request("26130011", enrollq, waitq, studentstk);
        incoming_request("22100242", enrollq, waitq, studentstk);
        incoming_request("24100055", enrollq, waitq, studentstk);
        incoming_request("21110032", enrollq, waitq, studentstk);
        incoming_request("21102200", enrollq, waitq, studentstk);
        incoming_request("22221320", enrollq, waitq, studentstk);
        incoming_request("23100026", enrollq, waitq, studentstk);
        if (enrollq[0] == "25100011" && enrollq[1] == "23100169" && enrollq[2] == "24100027" && waitq.length() == 4 && studentstk.length() == 3)
        {
            if (waitq[0] == "21102200" && waitq[1] == "24100055" && waitq[2] == "22100242" && waitq[3] == "26130011")
            {
                score_task_2 += 25;
                cout << "Test 1 passed! " << score_task_2 << "/45" << endl;
            }
            else
            {
                cout << "Test 1 failed! " << score_task_2 << "/45" << endl;
                return;
            }
        }
        else
        {
            cout << "Test 1 failed! " << score_task_2 << "/45" << endl;
            return;
        }
    }
    catch (exception ex1)
    {
        cout << "Test 1 failed! " << score_task_2 << "/45" << endl;
    }
}

void testProcessedRequests(int &score_task_2)
{
    cout << "Initializing Test 2 - Processed Requests" << endl;
    try
    {
        int earnings = 45;
        processed_request(earnings, enrollq, waitq, studentstk);
        if (enrollq[0] == "26130011" && enrollq[1] == "25100011" && enrollq[2] == "23100169" && waitq.length() == 3 && studentstk.length() == 4 && earnings == 60) 
        {
        }
        else
        {
            cout << "Test 2 failed! " << score_task_2 << "/45" << endl;
            return;
        }
        cout << "";
        processed_request(earnings, enrollq, waitq, studentstk);
        processed_request(earnings, enrollq, waitq, studentstk);
        if (enrollq[0] == "24100055" && enrollq[1] == "22100242" && enrollq[2] == "26130011" && waitq.length() == 1 && studentstk.length() == 6 && earnings == 90)
        {
        }
        else
        {
            cout << "Test 2 failed! " << score_task_2 << "/45" << endl;
            return;
        }
        cout << "";
        processed_request(earnings, enrollq, waitq, studentstk);
        processed_request(earnings, enrollq, waitq, studentstk);
        processed_request(earnings, enrollq, waitq, studentstk);
        processed_request(earnings, enrollq, waitq, studentstk);
        if (enrollq.length() == 0 && waitq.length() == 0 && studentstk.length() == 10 && earnings == 150)
        {
        }
        else
        {
            cout << "Test 2 failed! " << score_task_2 << "/45" << endl;
            return;
        }

        incoming_request("20100277", enrollq, waitq, studentstk);
        if (enrollq.length() == 0 && waitq.length() == 0 && studentstk.length() == 10 && earnings == 150)
        {
            score_task_2 += 20;
            cout << "Test 2 passed! " << score_task_2 << "/45" << endl;
        }
        else
        {
            cout << "Test 2 failed! " << score_task_2 << "/45" << endl;
            return;
        }
    }
    catch (exception ex2)
    {
        cout << "Test 2 failed! " << score_task_2 << "/45" << endl;
    }
}

// ------------------------------------- Running the Tests -------------------------------------

int main()
{
    int score_task_2 = 0;
    cout << "-----------------------------------------------" << endl;
    cout << "Testing Implementation of Task 2" << endl
         << endl;

    testIncomingRequests(score_task_2);
    testProcessedRequests(score_task_2);

    cout << endl
         << endl;

    cout << "-----------------------------------------------" << endl
         << endl;
    cout << "Total Score for Task 2: " << score_task_2 << "/45" << endl
         << endl;
}