#include <iostream>
#include <iomanip>
#include "Task_02.cpp"

using namespace std;





// ------------------------------------- Task 02 Tests -------------------------------------


class Test: public LinkedList {
    public:

    void testAddAtHead(int id) {
        Node *temp = new Node;
        temp->ID = id;
        temp->next = head;
        head = temp;
    }


    Node* getHead() {
        return head;
    }


    Node* getTail() {
        return tail;
    }


    string printScoresTest(int id)
    {
        Node *temp = head;
        string quiz_scores = "[";

        while (temp->ID != id)
        {
            temp = temp->next;
        }

        for (int i = 0; i < temp->scores.array_size; i++)
        {
            quiz_scores += to_string(temp->scores[i]);
            if (i != temp->scores.array_size-1) {
                quiz_scores += ",";
            }
        }
        quiz_scores += "]";

        return quiz_scores;
    }


    string printIDsTest()
    {
        Node *temp = head;
        string ids = "[";

        while (temp != NULL) {
            ids += to_string(temp->ID);
            if (temp->next != NULL) {
                ids += ",";
            }
            temp = temp->next;
        }
        ids += "]";

        return ids;
    }


    void manualDestructor() {
        Node *current = head;
        while (current != NULL)
        {
            Node *temp = current->next;
            delete current;
            current = temp;
        }
        head = NULL;
    }


    void studentIncrement (int var_x) {
        Node *var_y = new Node;
        var_y->ID = var_x;
        var_y->next = NULL;

        if (head == NULL){
            head = var_y;
            tail = var_y;
        }
        else{
            tail->next = var_y;
            tail = var_y;
        }
    }


    void marksIncrement (int var_x, int var_y) {
        Node *var_z = head;
        while (var_z != NULL)
        {
            if (var_z->ID == var_x)
            {
                var_z->scores.array_size ++;
                var_z->scores.array[var_z->scores.array_size - 1] = var_y;
                return;
            }
            var_z = var_z->next;
        }
    }
};



void testListInitialization(int &score_task_2)
{
    cout << "Initializing Test 1 - Object Initialization" << endl;
    Test test;

    try {
        if (test.getHead()==NULL && test.getTail()==NULL)
        {
            score_task_2 += 1;
            cout << "Test 1 passed! " << score_task_2 << "/45" << endl;
            test.manualDestructor();
        }
        else
        {
            cout << "Test 1 failed! Incorrect initialization of head and tail pointers." << score_task_2 << "/45" << endl;
            test.manualDestructor();
            return;
        }
    }
    catch(exception ex1) {
        cout << "Test 1 failed! " << score_task_2 << "/45" << endl;
        test.manualDestructor();
    }
}


void testGetSize(int &score_task_2)
{
    cout << "Initializing Test 2 - Get Size" << endl;
    Test test;

    try {
        if (test.getSize()==0){}
        else
        {
            cout << "Test 2 failed!" << score_task_2 << "/45" << endl;
            test.manualDestructor();
            return;
        }

        test.testAddAtHead(1);
        test.testAddAtHead(2);
        if(test.getSize()==2) {
            score_task_2 += 2;
            cout << "Test 2 passed! " << score_task_2 << "/45" << endl;
            test.manualDestructor();
        }
        else {
            cout << "Test 2 failed!" << score_task_2 << "/45" << endl;
            test.manualDestructor();
            return;
        }
    }
    catch(exception ex2) {
        cout << "Test 2 failed! " << score_task_2 << "/45" << endl;
        test.manualDestructor();
    }
}


void testAddStudent(int &score_task_2)
{
    cout << "Initializing Test 3 - Add Student" << endl;
    Test test;

    try {
        test.addStudent(4);
        if (test.printIDsTest()=="[4]" && test.printScoresTest(4)=="[]"){}
        else
        {
            cout << "Test 3 failed!" << score_task_2 << "/45" << endl;
            test.manualDestructor();
            return;
        }

        test.addStudent(2);
        test.addStudent(6);
        if(test.printIDsTest()=="[4,2,6]" && test.printScoresTest(4)=="[]" && test.printScoresTest(2)=="[]" && test.printScoresTest(6)=="[]") {
            score_task_2 += 4;
            cout << "Test 3 passed! " << score_task_2 << "/45" << endl;
            test.manualDestructor();
        }
        else {
            cout << "Test 3 failed!" << score_task_2 << "/45" << endl;
            test.manualDestructor();
            return;
        }
    }
    catch(exception ex3) {
        cout << "Test 3 failed! " << score_task_2 << "/45" << endl;
        test.manualDestructor();
    }
}


void testAddMarks(int &score_task_2)
{
    cout << "Initializing Test 4 - Add Marks" << endl;
    Test test;

    try {
        test.studentIncrement(2);
        test.studentIncrement(3);
        test.studentIncrement(5);
        
        test.addMarks(2,7);
        test.addMarks(3,9);
        test.addMarks(2,10);
        
        if(test.printScoresTest(2)=="[7,10]" && test.printScoresTest(3)=="[9]" && test.printScoresTest(5)=="[]") {
            score_task_2 += 4;
            cout << "Test 4 passed! " << score_task_2 << "/45" << endl;
            test.manualDestructor();
        }
        else {
            cout << "Test 4 failed!" << score_task_2 << "/45" << endl;
            test.manualDestructor();
            return;
        }
    }
    catch(exception ex4) {
        cout << "Test 4 failed! " << score_task_2 << "/45" << endl;
        test.manualDestructor();
    }
}


void testDeleteStudent(int &score_task_2)
{
    cout << "Initializing Test 5 - Delete Student" << endl;
    Test test;

    try {
        test.studentIncrement(2);
        test.studentIncrement(3);
        test.studentIncrement(4);
        test.studentIncrement(5);

        test.deleteStudent(6);
        
        if(test.printIDsTest()=="[2,3,4,5]") {}
        else {
            cout << "Test 5 failed! " << score_task_2 << "/45" << endl;
            test.manualDestructor();
            return;
        }
        
        test.deleteStudent(4);
        
        if(test.printIDsTest()=="[2,3,5]") {}
        else {
            cout << "Test 5 failed! " << score_task_2 << "/45" << endl;
            test.manualDestructor();
            return;
        }

        test.deleteStudent(2);

        if(test.printIDsTest()=="[3,5]") {}
        else {
            cout << "Test 5 failed! " << score_task_2 << "/45" << endl;
            test.manualDestructor();
            return;
        }

        test.deleteStudent(5);

        if(test.printIDsTest()=="[3]") {}
        else {
            cout << "Test 5 failed! " << score_task_2 << "/45" << endl;
            test.manualDestructor();
            return;
        }

        test.deleteStudent(3);
        

        if(test.printIDsTest()=="[]") {
            score_task_2 += 6;
            cout << "Test 5 passed! " << score_task_2 << "/45" << endl;
            test.manualDestructor();
        }
        else {
            cout << "Test 5 failed! " << score_task_2 << "/45" << endl;
            test.manualDestructor();
            return;
        }
    }
    catch(exception ex5) {
        cout << "Test 5 failed! " << score_task_2 << "/45" << endl;
        test.manualDestructor();
    }
}


void testSort(int &score_task_2)
{
    cout << "Initializing Test 6 - Sort" << endl;
    Test test;

    try {
        test.studentIncrement(7);
        test.studentIncrement(3);
        test.studentIncrement(2);
        test.studentIncrement(8);
        test.studentIncrement(6);
        
        test.Sort();

        if(test.printIDsTest()=="[2,3,6,7,8]") {
            score_task_2 += 7;
            cout << "Test 6 passed! " << score_task_2 << "/45" << endl;
            test.manualDestructor();
        }
        else {
            cout << "Test 6 failed! " << score_task_2 << "/45" << endl;
            test.manualDestructor();
            return;
        }
    }
    catch(exception ex6) {
        cout << "Test 6 failed! " << score_task_2 << "/45" << endl;
        test.manualDestructor();
    }
}


void testNumberOfQuizzes(int &score_task_2)
{
    cout << "Initializing Test 7 - Number of Quizzes" << endl;
    Test test;

    try {
        test.studentIncrement(7);
        test.studentIncrement(3);
        test.studentIncrement(2);
        test.studentIncrement(8);

        test.marksIncrement(7,4);
        test.marksIncrement(7,9);
        test.marksIncrement(3,6);
        test.marksIncrement(8,5);
        test.marksIncrement(8,7);
        test.marksIncrement(8,2);
        test.marksIncrement(8,10);

        if(test.numberOfQuizzes(7)==2 && test.numberOfQuizzes(3)==1 && test.numberOfQuizzes(2)==0 && test.numberOfQuizzes(8)==4) {
            score_task_2 += 5;
            cout << "Test 7 passed! " << score_task_2 << "/45" << endl;
            test.manualDestructor();
        }
        else {
            cout << "Test 7 failed! " << score_task_2 << "/45" << endl;
            test.manualDestructor();
            return;
        }
    }
    catch(exception ex7) {
        cout << "Test 7 failed! " << score_task_2 << "/45" << endl;
        test.manualDestructor();
    }
}


void testStudentAverage(int &score_task_2)
{
    cout << "Initializing Test 8 - Student Average" << endl;
    Test test;

    try {
        test.studentIncrement(7);
        test.studentIncrement(3);
        test.studentIncrement(2);
        test.studentIncrement(8);

        test.marksIncrement(7,4);
        test.marksIncrement(7,9);
        test.marksIncrement(3,6);
        test.marksIncrement(8,5);
        test.marksIncrement(8,7);
        test.marksIncrement(8,2);
        test.marksIncrement(8,10);

        if(test.studentAverage(7)==6.5 && test.studentAverage(3)==6 && test.studentAverage(2)==0 && test.studentAverage(8)==6) {
            score_task_2 += 5;
            cout << "Test 8 passed! " << score_task_2 << "/45" << endl;
            test.manualDestructor();
        }
        else {
            cout << "Test 8 failed! " << score_task_2 << "/45" << endl;
            test.manualDestructor();
            return;
        }
    }
    catch(exception ex8) {
        cout << "Test 8 failed! " << score_task_2 << "/45" << endl;
        test.manualDestructor();
    }
}


void testRemoveQuiz(int &score_task_2)
{
    cout << "Initializing Test 9 - Remove Quiz" << endl;
    Test test;

    try {
        test.studentIncrement(7);
        
        test.marksIncrement(7,1);
        test.marksIncrement(7,6);
        test.marksIncrement(7,5);
        test.marksIncrement(7,3);

        test.removeQuiz(7,2);

        if(test.printScoresTest(7)=="[1,5,3]") {}
        else {
            cout << "Test 9 failed! " << score_task_2 << "/45" << endl;
            test.manualDestructor();
            return;
        }

        test.removeQuiz(7,1);

        if(test.printScoresTest(7)=="[5,3]") {}
        else {
            cout << "Test 9 failed! " << score_task_2 << "/45" << endl;
            test.manualDestructor();
            return;
        }

        test.removeQuiz(7,2);

        if(test.printScoresTest(7)=="[5]") {}
        else {
            cout << "Test 9 failed! " << score_task_2 << "/45" << endl;
            test.manualDestructor();
            return;
        }

        test.removeQuiz(7,1);

        if(test.printScoresTest(7)=="[]") {
            score_task_2 += 5;
            cout << "Test 9 passed! " << score_task_2 << "/45" << endl;
            test.manualDestructor();
        }
        else {
            cout << "Test 9 failed! " << score_task_2 << "/45" << endl;
            test.manualDestructor();
            return;
        }
    }
    catch(exception ex9) {
        cout << "Test 9 failed! " << score_task_2 << "/45" << endl;
        test.manualDestructor();
    }
}


void testRemoveLowest(int &score_task_2)
{
    cout << "Initializing Test 10 - Remove Lowest" << endl;
    Test test;

    try {
        test.studentIncrement(7);
        test.studentIncrement(3);
        test.studentIncrement(2);
        test.studentIncrement(8);

        test.marksIncrement(7,4);
        test.marksIncrement(7,9);
        test.marksIncrement(3,6);
        test.marksIncrement(8,5);
        test.marksIncrement(8,7);
        test.marksIncrement(8,2);
        test.marksIncrement(8,10);

        test.removeLowest(7);
        test.removeLowest(3);
        test.removeLowest(2);
        test.removeLowest(8);

        if(test.printScoresTest(7)=="[9]" && test.printScoresTest(3)=="[6]" && test.printScoresTest(2)=="[]" && test.printScoresTest(8)=="[5,7,10]") {
            score_task_2 += 6;
            cout << "Test 10 passed! " << score_task_2 << "/45" << endl;
            test.manualDestructor();
        }
        else {
            cout << "Test 10 failed! " << score_task_2 << "/45" << endl;
            test.manualDestructor();
            return;
        }
    }
    catch(exception ex10) {
        cout << "Test 10 failed! " << score_task_2 << "/45" << endl;
        test.manualDestructor();
    }
}





// ------------------------------------- Running the Tests -------------------------------------


int main() {
    int score_task_2 = 0;
    cout << "-----------------------------------------------" << endl;
    cout << "Testing Implementation of Task 2" << endl << endl << endl;

    testListInitialization(score_task_2);
    testGetSize(score_task_2);
    testAddStudent(score_task_2);
    testAddMarks(score_task_2);
    testDeleteStudent(score_task_2);
    testSort(score_task_2);
    testNumberOfQuizzes(score_task_2);
    testStudentAverage(score_task_2);
    testRemoveQuiz(score_task_2);
    testRemoveLowest(score_task_2);

    cout << endl << endl << endl;


    cout << "-----------------------------------------------" << endl << endl;
    cout << "Total Score for Task 2: " << score_task_2 << "/45" << endl << endl;
}