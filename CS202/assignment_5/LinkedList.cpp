#include <iostream>
#include <iomanip>

using namespace std;

// node for linked list
class Node
{
public:
    string data;
    Node *next;
};



class LinkedList
{
public:
    // head and tail pointers
    Node *head, *tail;

    // constructor
    LinkedList()
    {
        head = NULL;
        tail = NULL;
    }

    int getSize()
    {
        int size = 0;
        Node *temp = head;
        while (temp != NULL)
        {
            size++;
            temp = temp->next;
        }

        return size;
    }

    bool isEmpty()
    {
        return (head == NULL);
    }

    void addAtHead(string value)
    {
        Node *temp = new Node;
        temp->data = value;
        temp->next = NULL;

        if (head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            temp->next = head;
            head = temp;
        }
    }

    void addAtTail(string value)
    {
        Node *temp = new Node;
        temp->data = value;
        temp->next = NULL;

        if (head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }

    void addInBetween(string value, string after)
    {
        Node* temp = new Node;
        temp->data = value;
        temp->next = NULL;

        if (head == NULL)
        {
            head = temp;
        }
        else
        {
            Node *traverse = head;
            while (traverse->data != after)
            {
                traverse = traverse->next;
            }
            temp->next = traverse->next;
            traverse->next = temp;
        }
    }

    // remove the node at the given index
    void removeNode(int index)
    {
        if (index == -1) {
            return;
        }

        Node *temindex1 = head;
        Node *temindex2 = head;

        if (head==NULL) {
            return;
        }

        if (index == 0)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            return;
        }

        for (int i = 0; i < index - 1; i++)
        {
            temindex1 = temindex1->next;
            temindex2 = temindex2->next;
        }

        Node* temp = temindex1->next;
        temindex1->next = temindex2->next->next;
        delete temp;
    }

    int getIndexFromValue(string value)
    {
        int count = 0;
        Node *temp = head;

        while (temp != NULL && temp->data != value)
        {
            temp = temp->next;
            count++;
        }

        if (temp == NULL) {
            count = -1;
        }

        return count;
    }

    void deleteFromValue(string value)
    {
        int position = this->getIndexFromValue(value);
        this->removeNode(position);
    }

    void deleteHead()
    {
        Node* del = head;
        head = del->next;
        delete del;
    }

    void deleteTail()
    {
        if (head->next==NULL)
        {
            head = NULL;
            tail = NULL;
        }
        else
        {
            Node *temp = head;
            Node *prev = new Node;
            while (temp->next==NULL)
            {
                prev = temp;
                temp = temp->next;
            }
            prev->next = NULL;
        }
    }

    string printList()
    {
        int n = getSize();
        string list;
        Node* temp = head;
        int i = 0;
        while (temp != NULL)
        {
            list += temp->data + " ";
            i++;
            temp = temp->next;
        }
        return list;
    }

    bool isPresent(string value)
    {
        Node* temp = head;
        while (temp != NULL)
        {
            if (temp->data==value)
            {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
};