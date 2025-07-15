#include <iostream>
#include <list>
using namespace std;


// create a linkedlist-based implementation of stacks and queues
// you are not allowed to create any helper functions
// if you do create some helper functions (for debugging), please comment them out before submitting

// Implementation of Stack

class Stack
{
    public:

    // a stack can be thought of as a list, where insertion and deletion are restricted from one end only
    // the convention has been specified in the manual
    list<string> stack;
    int capacity;
    

    // TO-DO Function
    // parameterized constructor
    Stack(int cap)
    {
        // set capacity to cap
        capacity = cap;
    }

    // TO-DO Function
    int length()
    {
        // return the number of items stored in the stack
        return stack.size();
    }

    // TO-DO Function
    string push(string s)	
    {
        // push string s to the top of the stack
        // if this function is called on a full stack, do not push anything and simply return "NULL"
        if(stack.size() >= capacity)
        {
            return "NULL";
        }
        stack.push_front(s);
    }

    // TO-DO Function
    string pop()
    {
        // remove the topmost string from the stack and return it
        // if this function is called on an empty stack, do not remove anything and simply return "NULL"
        if(stack.empty())
            return "NULL";
        else
        {
            string remove = stack.front();
            stack.pop_front();
            return remove;
        }
    }

    // TO-DO Function
    string top()
    {
        // return the topmost string from the stack without removing it
        // if this function is called on an empty stack, simply return "NULL"
        if(stack.empty())
            return "NULL";
        else
            return stack.front();
    }

    // TO-DO Function
    void reverse()
    {
        // reverses the stack
        // you are not allowed to create another stack or queue
        // hint: a single array should be sufficient
        if(!stack.empty())
        {
            string* arr = new string[capacity];
            for(int i=0; i < capacity; i++)
            {
                arr[i] = stack.front();
                stack.pop_front();
            }
            for(int i = 0; i < capacity; i++)
            {
                stack.push_front(arr[i]);
            }
        }
    }
};

// Implementation of Queue

class Queue
{
    public:

    // a queue can be thought of as a list, where insertion and deletion are restricted from opposite ends
    // the convention has been specified in the manual
    list<string> queue;
    int capacity;


    // TO-DO Function
    // parameterized constructor
    Queue(int cap)
    {
        // set capacity to cap
        capacity = cap;
    }

    // TO-DO Function
    int length()
    {
        // return the number of items stored in the queue
        return queue.size();
    }

    // TO-DO Function
    string enqueue(string s)	
    {
        // push string s to the back of the queue
        // if this function is called on a full queue, do not push anything and simply return "NULL"
        if(queue.size() >= capacity)
        {
            return "NULL";
        }
        else
            queue.push_front(s);
    }

    // TO-DO Function
    string dequeue()
    {
        // remove the frontmost string from the queue and return it
        // if this function is called on an empty queue, do not remove anything and simply return "NULL"
        if(queue.empty())
        {
            return "NULL";
        }
        else
        {
            string remove = queue.back();
            queue.pop_back();
            return remove;
        }
    }

    // TO-DO Function
    string front()
    {
        // return the frontmost string from the queue without removing it
        // if this function is called on an empty queue, simply return "NULL"
        if(queue.empty())
        {
            return "NULL";
        }
        else
        {
            return queue.back();
        }
    }

    // TO-DO Function
    void reverse()
    {
        // reverses the queue
        // you are not allowed to create another stack or queue
        // hint: a single array should be sufficient
        if(!queue.empty())
        {
            string* arr = new string[capacity];
            for(int i = 0; i < capacity; i++)
            {
                arr[i] = queue.back();
                queue.pop_back();
            }
            for(int i = 0; i < capacity; i++)
            {
                queue.push_back(arr[i]);
            }
        }
    }
};


// You can use the main function below to test your implementation
// Remember to comment out the main section before running test_1.cpp

// int main()
// {

// }