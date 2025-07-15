#include <iostream>
#include <iomanip>
#include "Task_01.cpp"

using namespace std;


// node for linked list
// contains student ID, an object of CreateVector to store quiz scores, and a next pointer
class Node
{
    public:

    int ID;
    CreateVector scores;
    Node *next;
};



// define functionality for the linked list
// you are allowed to make as many helper function as you need to
class LinkedList
{
    public:
    
    // head and tail pointers
    Node *head, *tail;
    void print();
    void printScoresTest(int id);
    // TO-DO Function
    // constructor function
    LinkedList()
    {
        // set head and tail pointers to NULL
        head = NULL;
        tail = NULL;
    }


    // TO-DO Function
    int getSize()
    {
        // return the size of the list (number of student records)

        int size = 0 ;
        if(head == NULL)
            return size;
        else
        {
            Node* traverse = new Node;
            traverse = head;
            while(traverse != NULL)
            {
                size += 1;
                traverse = traverse->next;
            }
            return size;
        }
    }


    // TO-DO Function
    void addStudent(int id)
    {
        // add a new student record to the end of the list with the given ID
        // the quizzes array should be left empty
        Node* new_student = new Node;
        new_student->ID = id;
        new_student->next = NULL;

        if(head == NULL)
        {
            head = new Node;
            head = new_student;
            tail = head;
        }
        else
        {
            tail->next = new_student;
            tail = new_student;
        }
    }


    // TO-DO Function
    void addMarks(int id, int marks)
    {
        // add the marks for a quiz to the end of the quizzes array for a student with the given ID
        Node* traverse = new Node;
        traverse = head;

        while(traverse->ID != id)
        {
            traverse = traverse->next;
        }
        if (traverse->ID != id)
        {
            //cout << "No student with this ID found" << endl ;
        }
        else
        {
            traverse->scores.push(marks);
            //cout << "Marks have been updated" << endl ;
        }
        
    }


    // TO-DO Function
    void deleteStudent(int id)
    {
        // delete the record for a student with the given ID
        Node* traverse = new Node;
        traverse = head;
        if (head == NULL)
        {
            //cout << "List is empty" << endl ;
        }
        else
        {
            if(traverse->ID == id)
            {
                head = head->next;
                delete traverse;
            }
            else
            {
                while(traverse->next != NULL)
                {
                    if(traverse->next->ID == id)
                    {
                        Node* remove = new Node;
                        remove = traverse->next;
                        traverse->next = remove->next;
                        delete remove;
                        return;
                    }
                    traverse = traverse->next;
                }
                //cout << "No student found" << endl;
            }
        }
    }


    // TO-DO Function
    void Sort()
    {
        
        Node* prev_node = new Node;
        Node* next_node = new Node;

        for(int i = 0; i < 6; i++)
        {
            prev_node = head;
            next_node = head->next;

            while(next_node != NULL)
            {
                if(prev_node->ID > next_node->ID)
                {
                    int temp = prev_node->ID;
                    prev_node->ID = next_node->ID;
                    next_node->ID = temp;
                }

                next_node = next_node->next;
                prev_node = prev_node->next;
            }
        }
    


        
    }


    // TO-DO Function
    int numberOfQuizzes(int id)
    {
        // return the number of quizzes entered in the record of a student with the given ID
        Node* traverse = new Node;
        traverse = head;

        if (head == NULL)
        {
            //cout << "List is empty" << endl ;
            return 0;
        }
        else
        {
            while (traverse->ID != id && traverse != NULL)
            {
                traverse = traverse->next;
            }
            if(traverse == NULL)
            {
                //cout << "No student found" << endl ;
            }
            else
            {
                return traverse->scores.vectorLength();
            }
        }
    }


    // TO-DO Function
    double studentAverage(int id)
    {
        // return the average of all the quizzes in the record of a student with the given ID
        // the return value must be a double and not an int
        double avg = 0 ;
        double total = 0 ;

        Node* traverse = new Node;
        traverse = head;
        if (head == NULL)
        {
            //cout << "List is empty" << endl ;
            return 0;
        }
        else
        {
            while (traverse->ID != id)
            {
                traverse = traverse->next;
            }
            if(traverse == NULL)
            {
                //cout << "No student found" << endl ;
            }
            else
            {
                if(traverse->scores.array_size != 0)
                {   
                    for(int i = 0; i < traverse->scores.array_size; i++)
                    {
                        total += traverse->scores[i];
                    }
                    avg = total / double(traverse->scores.array_size);

                    return avg;
                }
                else
                    return 0;
            }
        }
    }


    // TO-DO Function
    void removeQuiz(int id, int quiz_no)
    {
        // remove the quiz with the given quiz number from the record of a student with the given ID
        // if quiz_no = 2, remove the quiz at index 1 from the respective quizzes array
        Node* traverse = new Node;
        traverse = head;

        if (head == NULL)
        {
            //cout << "List is empty" << endl ;
            return;
        }
        else
        {
            while (traverse->ID != id)
            {
                traverse = traverse->next;
            }
            if(traverse == NULL)
            {
                //cout << "No student found" << endl ;
            }
            else
            {
                traverse->scores.removeFromIndex(quiz_no - 1);
            }
        }
        
    }


    // TO-DO Function
    void removeLowest(int id)
    {
        // remove the quiz with the lowest score from the record of a student with the given ID
        // if the student has only one or no quizzes, do not remove anything
        Node* traverse = new Node;
        traverse = head;

        if (head == NULL)
        {
            //cout << "List is empty" << endl ;
            return;
        }
        else
        {
            while (traverse->ID != id)
            {
                traverse = traverse->next;
            }
            if(traverse == NULL)
            {
                //cout << "No student found" << endl ;
            }
            else
            {
                int lowest = traverse->scores[0];
                if (traverse->scores.array_size <= 1)
                {
                    return;
                }
                else
                {
                    for(int i = 1; i < traverse->scores.array_size; i++)
                    {
                        if(lowest < traverse->scores[i])
                        {
                            //nothing
                        }
                        else
                        {
                            lowest = traverse->scores[i];
                        }
                    }
                    traverse->scores.removeValue(lowest);
                }
            }
        }

    }


    // destructor
    // DO NOT change this
    ~LinkedList()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            delete[] temp->scores.array;
            temp = temp->next;
        }
    }
};

void LinkedList::print()
{
    Node* traverse = new Node;
    traverse = head;
    if (head == NULL)
    {
        cout << "List is empty" << endl;
    }
    else
    {
        cout << "Students: ";
        while(traverse != NULL)
        {
            cout << traverse->ID << " ";
            traverse = traverse->next;
        }
        cout << endl ;
    }
}

void LinkedList::printScoresTest(int id)
{
    Node *temp = head;

    while (temp->ID != id)
    {
        temp = temp->next;
    }

    for (int i = 0; i < temp->scores.array_size; i++)
    {
        cout << temp->scores[i] << " " ;
    }
    cout << endl;

}

// You can use the main function below to test your implementation
// Remember to comment out the main section before running test_2.cpp

// int main()
// {
//     LinkedList list;
//     int input;
//     int id;
//     int marks;
//     int quiz_num;
//     do
//     {
//         cout << "\n1. List size\n2. Add a Student\n3. Add Marks\n4. Delete a Student\n5. Sort Students\n6. Quizzes Taken by Student\
//         \n7. Average Marks of Student\n8. Remove a Students Quiz\n9. Remove Lowest Quiz Score\n10. Print Students\n11. Print Student Scores\n0. Exit" << endl;
//         cout << "Input: ";
//         cin >> input;
//         cout << endl ;

//         if (input == 1)
//         {
//             cout << "List size is: " << list.getSize() << endl ;
//         }
//         else if (input == 2)
//         {
//             cout << "Enter student ID: ";
//             cin >> id ;
//             list.addStudent(id);
//         }
//         else if (input == 3)
//         {
//             if (list.getSize() == 0)
//             {
//                 cout << "List is empty" << endl ;
//             }
//             else
//             {
//                 cout << "Student ID: ";
//                 cin >> id;
//                 cout << "Student Marks: ";
//                 cin >> marks;
//                 list.addMarks(id, marks);
//             }
//         }
//         else if (input == 4)
//         {
//             cout << "Delete Student ID Number: ";
//             cin >> id;
//             list.deleteStudent(id);
//         }
//         else if (input == 5)
//         {
//             cout << "Sorted List: ";
//             list.Sort();
//             list.print();
//         }
//         else if (input == 6)
//         {
//             cout << "Student ID: ";
//             cin >> id;
//             cout << "Number of quizzes taken: " << list.numberOfQuizzes(id) << endl;
//         }
//         else if (input == 7)
//         {
//             cout << "Student ID: ";
//             cin >> id;
//             cout << "Average of Student: " << list.studentAverage(id) << endl;
//         }
//         else if (input == 8)
//         {
//             cout << "Student ID: ";
//             cin >> id;
//             cout << "Quiz number: ";
//             cin >> quiz_num;
//             list.removeQuiz(id, quiz_num);
//             list.printScoresTest(id);
//         }
//         else if (input == 9)
//         {
//             cout << "Student ID: ";
//             cin >> id;
//             list.removeLowest(id);
//         }
//         else if(input == 10)
//         {
//             list.print();
//         }
//         else if(input == 11)
//         {
//             cout << "Student ID: ";
//             cin >> id;
//             list.printScoresTest(id);
//         }
//     }
//     while(input != 0);
// }