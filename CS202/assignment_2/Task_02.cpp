#include <iostream>
#include "Task_01.cpp"
using namespace std;

// application of stacks and queues
// online enrollment management system
// you are allowed to make as many helper functions as you need to (except in the queue and stack classes)

int queue_count(Stack studentstk, Queue enrollq, Queue waitq)
{
    return studentstk.length() + enrollq.length() + waitq.length();
}
void ID_check(string ID, Stack &studentstk, Queue &enrollq, Queue &waitq)
{
    string x = studentstk.top();
    if(x == "NULL")
    {
        //cout << "Couldnt find ID";
        if(studentstk.length() != 10)
        {
            // cout << " - Enrolling: " << ID;
            if(enrollq.length() != 3) // space in enrollment queue
            {
                //cout << " - Adding to enrollment" << endl;
                enrollq.enqueue(ID); 
            }
            else // if enroll queue is full, add to waitlist queue
            {
                // cout << " - Adding to waitlist" << endl;
                waitq.enqueue(ID);
            }
        }
    }
    else if(x != "NULL")
    {
        if(x == ID)
        {
            //cout << "Found ID: Do nothing" << endl;
        }
        else
        {
            studentstk.pop();
            ID_check(ID, studentstk, enrollq, waitq);
            studentstk.push(x);
        }
    }
}
void incoming_request(string ID, Queue &enrollq, Queue &waitq, Stack &studentstk)
{
    // receives an enrollment request from a student
    // should either enqueue into enrollq, waitq or ignore it depending on 
    // the conditions mentioned in the manual
    if(queue_count(studentstk, enrollq, waitq) != 10)
    {
        ID_check(ID, studentstk, enrollq, waitq);
    }
    else
    {
        //cout << "Queue is full." << endl;
    }
}

void processed_request(int &earnings, Queue &enrollq, Queue &waitq, Stack &studentstk)
{
    // is called when a student has been enrolled
    // updates studentstk
    // updates total earnings
    // adds the next student in line to the enrollq
    studentstk.push(enrollq.dequeue());
    if(waitq.front() != "NULL")
        enrollq.enqueue(waitq.dequeue());
    earnings = earnings + 15;
}


// You can use the main function below to test your implementation
// Remember to comment out the main section before running test_2.cpp

// int main()
// {
// }