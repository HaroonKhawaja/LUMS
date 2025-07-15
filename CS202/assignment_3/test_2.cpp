#include <iostream>
#include <iomanip>
#include "Task_02.cpp"

using namespace std;

int TOTAL = 40;




void testAddOrder(int &score_task_2)
{
    cout << "Initializing Test 1 - Add Order" << endl;
    Expedite test;

    try {
        test.addOrder(4);
        if (test.order_record.check()==1 && test.order_record.disp()=="4")
        {
            score_task_2 += 2;
        }
        else
        {
            cout << "Test 1 failed! " << score_task_2 << "/" << TOTAL << endl;
        }
        
        test.addOrder(2);
        test.addOrder(5);
        test.addOrder(9);
        test.addOrder(3);
        test.addOrder(6);
        test.addOrder(1);
        test.addOrder(8);
        test.addOrder(7);
        test.addOrder(10);
        if (test.order_record.check()==10 && test.order_record.disp()=="1 2 3 4 5 6 7 8 9 10")
        {
            score_task_2 += 2;
        }
        else
        {
            cout << "Test 1 failed! " << score_task_2 << "/" << TOTAL << endl;
        }

        test.addOrder(11);
        test.addOrder(12);
        test.addOrder(13);
        if (test.order_record.check()==10 && test.order_record.disp()=="1 2 3 4 5 6 7 8 9 10")
        {
            score_task_2 += 1;
        }
        else
        {
            cout << "Test 1 failed! " << score_task_2 << "/" << TOTAL << endl;
            return;
        }

        if (test.hold_size==3 && test.on_hold[0]==11 && test.on_hold[1]==12 && test.on_hold[2]==13)
        {
            score_task_2 += 2;
            cout << "Test 1 passed! " << score_task_2 << "/" << TOTAL << endl;
        }
        else
        {
            cout << "Test 1 failed! " << score_task_2 << "/" << TOTAL << endl;
            return;
        }
    }
    catch(exception ex1) {
        cout << "Test 1 failed! Exception occurred. " << score_task_2 << "/" << TOTAL << endl;
    }
}



void testProcessOrders(int &score_task_2)
{
    cout << "Initializing Test 2 - Process n Orders" << endl;
    Expedite test;

    try {
        test.order_record.increment(4);
        test.order_record.increment(2);
        test.order_record.increment(5);
        test.order_record.increment(9);
        test.order_record.increment(3);
        test.order_record.increment(6);
        test.order_record.increment(1);
        test.order_record.increment(8);
        test.order_record.increment(7);
        test.order_record.increment(10);

        test.hold_size = 5;
        int el = 11;
        for (int i=0; i<5; i++)
        {
            test.on_hold[i] = el;
            el++;
        }

        string three = test.processNOrders(3);
        if (test.order_record.check()==10 && test.order_record.disp()=="1 2 3 7 8 9 10 13 14 15" && three == "4 5 6")
        {
            score_task_2 += 2;
        }
        else
        {
            cout << "Test 2 failed! " << score_task_2 << "/" << TOTAL << endl;
        }
        if (test.hold_size==2 && test.on_hold[0]==11 && test.on_hold[1]==12)
        {
            score_task_2 += 2;
        }
        else
        {
            cout << "Test 2 failed! " << score_task_2 << "/" << TOTAL << endl;
        }

        string seven = test.processNOrders(7);
        if (test.order_record.check()==5 && test.order_record.disp()=="1 2 3 11 12" && seven == "7 8 9 10 13 14 15")
        {
            score_task_2 += 2;
        }
        else
        {
            cout << "Test 2 failed! " << score_task_2 << "/" << TOTAL << endl;
        }

        if (test.hold_size==0)
        {
            score_task_2 += 1;
            cout << "Test 2 passed! " << score_task_2 << "/" << TOTAL << endl;
        }
        else
        {
            cout << "Test 2 failed! " << score_task_2 << "/" << TOTAL << endl;
        }
    }
    catch(exception ex1) {
        cout << "Test 2 failed! Exception occurred. " << score_task_2 << "/" << TOTAL << endl;
    }
}



void testParseOrders(int &score_task_2)
{
    cout << "Initializing Test 3 - Parse Orders" << endl;
    Expedite test;

    try {
        string parse_1 = "Current orders: 0\nCapacity for new orders: 10\nOrders in queue: none";
        if (test.parseOrders() == parse_1)
        {
            score_task_2 += 2;
        }
        else
        {
            cout << "Test 3 failed! " << score_task_2 << "/" << TOTAL << endl;
        }


        test.order_record.increment(4);
        test.order_record.increment(2);
        test.order_record.increment(5);
        test.order_record.increment(9);
        test.order_record.increment(3);
        test.order_record.increment(6);

        string parse_2 = "Current orders: 6\nCapacity for new orders: 4\nOrders in queue: 2 3 4 5 6 9";
        if (test.parseOrders() == parse_2)
        {
            score_task_2 += 3;
            cout << "Test 3 passed! " << score_task_2 << "/" << TOTAL << endl;
        }
        else
        {
            cout << "Test 3 failed! " << score_task_2 << "/" << TOTAL << endl;
        }

    }
    catch(exception ex1) {
        cout << "Test 3 failed! Exception occurred. " << score_task_2 << "/" << TOTAL << endl;
    }
}



void testCancelOrder(int &score_task_2)
{
    cout << "Initializing Test 4 - Cancel Order" << endl;
    Expedite test;

    try {
        test.order_record.increment(4);
        test.order_record.increment(2);
        test.order_record.increment(5);
        test.order_record.increment(9);
        test.order_record.increment(3);
        test.order_record.increment(6);
        test.order_record.increment(1);
        test.order_record.increment(8);
        test.order_record.increment(7);
        test.order_record.increment(10);

        test.hold_size = 2;
        test.on_hold[0] = 11;
        test.on_hold[1] = 12;

        string cancel = test.cancelOrder(15);
        if (test.order_record.check()==10 && test.order_record.disp()=="1 2 3 4 5 6 7 8 9 10" && cancel=="Order Processed!")
        {
            score_task_2 += 2;
        }
        else
        {
            cout << "Test 4 failed! " << score_task_2 << "/" << TOTAL << endl;
        }


        cancel = test.cancelOrder(2);
        if (test.order_record.check()==10 && test.order_record.disp()=="1 3 4 5 6 7 8 9 10 12" && cancel=="Order Canceled ;-;")
        {
            score_task_2 += 2;
        }
        else
        {
            cout << "Test 4 failed! " << score_task_2 << "/" << TOTAL << endl;
        }
        if (test.hold_size==1 && test.on_hold[0]==11)
        {
            score_task_2 += 2;
            cout << "Test 4 passed! " << score_task_2 << "/" << TOTAL << endl;
        }
        else
        {
            cout << "Test 4 failed! " << score_task_2 << "/" << TOTAL << endl;
        }

    }
    catch(exception ex1) {
        cout << "Test 4 failed! Exception occurred. " << score_task_2 << "/" << TOTAL << endl;
    }
}



void testShiftUp(int &score_task_2)
{
    cout << "Initializing Test 5 - Shift Up" << endl;
    Expedite test;

    try {
        test.order_record.increment(4);
        test.order_record.increment(2);
        test.order_record.increment(5);
        test.order_record.increment(9);
        test.order_record.increment(3);
        test.order_record.increment(6);

        string result = test.shiftUp(4);
        int new_root = test.order_record.root->data;
        if (test.order_record.check()==6 && test.order_record.disp()=="2 3 4 5 6 9" && new_root==4 && result=="Order already at top")
        {
            score_task_2 += 2;
        }
        else
        {
            cout << "Test 5 failed! " << score_task_2 << "/" << TOTAL << endl;
        }

        result = test.shiftUp(9);
        new_root = test.order_record.root->data;
        if (test.order_record.check()==6 && test.order_record.disp()=="2 3 4 5 6 9" && new_root==9 && result=="Order shifted up")
        {
            score_task_2 += 5;
            cout << "Test 5 passed! " << score_task_2 << "/" << TOTAL << endl;
        }
        else
        {
            cout << "Test 5 failed! " << score_task_2 << "/" << TOTAL << endl;
        }
    }
    catch(exception ex1) {
        cout << "Test 5 failed! Exception occurred. " << score_task_2 << "/" << TOTAL << endl;
    }
}



void testReturnedOrder(int &score_task_2)
{
    cout << "Initializing Test 4 - Returned Order" << endl;
    Expedite test;

    try {
        test.order_record.increment(4);
        test.order_record.increment(2);
        test.order_record.increment(5);
        test.order_record.increment(9);
        test.order_record.increment(3);
        test.order_record.increment(6);
        test.order_record.increment(1);
        test.order_record.increment(8);
        test.order_record.increment(7);
        
        test.returnedOrder(10);
        if(test.order_record.check()==10 && test.order_record.root->data==10 && test.order_record.disp()=="1 2 3 4 5 6 7 8 9 10")
        {
            score_task_2 += 2;
        }
        else
        {
            cout << "Test 4 failed! " << score_task_2 << "/" << TOTAL << endl;
        }
        if(test.hold_size==0)
        {
            score_task_2 += 1;
        }
        else
        {
            cout << "Test 4 failed! " << score_task_2 << "/" << TOTAL << endl;
        }


        test.hold_size = 2;
        test.on_hold[0] = 11;
        test.on_hold[1] = 12;

        test.returnedOrder(15);
        if (test.order_record.check()==10 && test.order_record.root->data==15 && test.order_record.checkBalanced())
        {
            score_task_2 += 3;
        }
        else
        {
            cout << "Test 4 failed! " << score_task_2 << "/" << TOTAL << endl;
        }
        if (test.hold_size==3 && test.on_hold[0]==11 && test.on_hold[1]==12)
        {
            score_task_2 += 2;
            cout << "Test 4 passed! " << score_task_2 << "/" << TOTAL << endl;
        }
        else
        {
            cout << "Test 4 failed! " << score_task_2 << "/" << TOTAL << endl;
        }

    }
    catch(exception ex1) {
        cout << "Test 4 failed! Exception occurred. " << score_task_2 << "/" << TOTAL << endl;
    }
}









// ------------------------------------- Running the Tests -------------------------------------


int main() {
    int score_task_2 = 0;
    cout << "-----------------------------------------------" << endl;
    cout << "Testing Implementation of Task 1" << endl << endl;

    testAddOrder(score_task_2);
    testProcessOrders(score_task_2);
    testParseOrders(score_task_2);
    testCancelOrder(score_task_2);
    testShiftUp(score_task_2);
    testReturnedOrder(score_task_2);

    cout << endl << endl << endl;


    cout << "-----------------------------------------------" << endl << endl;
    cout << "Total Score for Task 2: " << score_task_2 << "/" << TOTAL << endl << endl;
}