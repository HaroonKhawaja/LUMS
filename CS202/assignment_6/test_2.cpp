#include <iostream>
#include <iomanip>
#include <fstream>
#include "Task_02.cpp"

using namespace std;

// ------------------------------------- Task 02 Tests -------------------------------------

class Hospital_Test : public Hospital
{
public:
    Hospital_Test() : Hospital() {}
    
    string printMaxHeap()
    {
        string output = "";
        for (int i = 0; i < scheduler->length; i++)
        {
            output = output + to_string(scheduler->heap_array[i].priority) + " ";
        }
        return output;
    }

    bool inScheduler(string name) {
        for (int i = 0; i < scheduler->length; i++)
        {
            if (name == scheduler->heap_array[i].name)
            {
                return true;
            }
        }
        return false;
    }

    bool isPatient(int ID) {
        for (int i = 0; i < num_patients; i++)
        {
            if (ID == paitents[i].Patient_ID)
            {
                return true;
            }
        }
        return false;
    }
};

void testHospitalInitialization(int &score_task_2)
{
    cout << "-------------- Hospital Tests --------------" << endl;
    cout << "Initializing Test 1 - Initialization" << endl;
    Hospital_Test test;

    try
    {
        if (test.scheduler != NULL)
        {
            score_task_2 += 2;
            cout << "Test 1 passed! " << score_task_2 << "/30" << endl;
        }
        else
        {
            cout << "Test 1 failed! scheduler has not been dynamically allocated. " << score_task_2 << "/30" << endl;
            return;
        }
    }
    catch (exception ex1)
    {
        cout << "Test 1 failed! " << score_task_2 << "/30" << endl;
    }
}

void testRegistration(int &score_task_2)
{
    cout << "Initializing Test 2 - Registration (registerDoctor and registerPatient)" << endl;
    Hospital_Test test;

    try
    {
        if ((test.registerDoctor("Rudeus", "Greyrat") == true) && (test.staff[5].Doctor_ID == 6) && (test.staff[5].First_Name == "Rudeus") && (test.staff[5].Last_Name == "Greyrat") && (test.staff[5].Assigned_Patient_ID == -1))
        {
            score_task_2 += 2;
        }
        else
        {
            cout << "Test 2 failed! " << score_task_2 << "/30" << endl;
            return;
        }

        test.registerDoctor("Ira", "Lowe");
        test.registerDoctor("Richard ", "Evans");
        test.registerDoctor("Terri", "Ingram");
        test.registerDoctor("Yang", "Wen-Li");

        if (test.registerDoctor("Arturo", "Benson") == false)
        {
            score_task_2 += 1;
        }
        else
        {
            cout << "Test 2 failed! " << score_task_2 << "/30" << endl;
            return;
        }

        bool registration = test.registerPatient("Mabel", "Wright", 30);
        if ((registration == true) && (test.paitents[0].Patient_ID == 1) && (test.paitents[0].First_Name == "Mabel") && (test.paitents[0].Last_Name == "Wright") && (test.paitents[0].Assigned_Doctor_ID == -1) && (test.paitents[0].Age == 30))
        {
            score_task_2 += 2;
        }
        else
        {
            cout << "Test 2 failed! " << score_task_2 << "/30" << endl;
            return;
        }
        if ((test.scheduler->heap_array[0].name == "Mabel Wright") && (test.scheduler->heap_array[0].priority == 30))
        {
            score_task_2 += 2;
        }
        else
        {
            cout << "Test 2 failed! " << score_task_2 << "/30" << endl;
            return;
        }

        test.num_patients = 50;
        if (test.registerPatient("Arturo", "Benson", 50) == false)
        {
            score_task_2 += 1;
            cout << "Test 2 passed! " << score_task_2 << "/30" << endl;
        }
        else
        {
            cout << "Test 2 failed! " << score_task_2 << "/30" << endl;
            return;
        }
    }
    catch (exception ex2)
    {
        cout << "Test 2 failed! " << score_task_2 << "/30" << endl;
    }
}

void testCheckup(int &score_task_2)
{
    cout << "Initializing Test 3 - Checkup (scheduleCheckup() and finishCheckup())" << endl;
    Hospital_Test test;

    try
    {
        test.registerPatient("Ira", "Lowe", 12);
        test.registerPatient("Richard ", "Evans", 30);
        test.registerPatient("Terri", "Ingram", 45);
        test.registerPatient("Yang", "Wen-Li", 69);
        if (test.scheduleCheckup(7) == false && test.scheduleCheckup(2) == false && test.scheduleCheckup(4) == true)
        {
            score_task_2 += 3;
        }
        else
        {
            cout << "Test 3 failed! " << score_task_2 << "/30" << endl;
            return;
        }
        if (!test.inScheduler("Yang Wen-Li") && test.paitents[3].Assigned_Doctor_ID == 1 && test.staff[0].Assigned_Patient_ID == 4)
        {
            score_task_2 += 3;
        }
        else
        {
            cout << "Test 3 failed! " << score_task_2 << "/30" << endl;
            return;
        }
        if (test.scheduleCheckup(4) == false)
        {
            score_task_2 += 2;
        }
        else
        {
            cout << "Test 3 failed! " << score_task_2 << "/30" << endl;
            return;
        }
        if (test.finishCheckup(2) == false && test.finishCheckup(8) == false && test.finishCheckup(4) == true && !test.isPatient(4) && test.staff[0].Assigned_Patient_ID == -1 && test.num_patients == 3)
        {
            score_task_2 += 3;
        }
        else
        {
            cout << "Test 3 failed! " << score_task_2 << "/30" << endl;
            return;
        }
        if (test.scheduleCheckup(2) == false && test.scheduleCheckup(1) == false && test.scheduleCheckup(3) == true)
        {
            score_task_2 += 3;
        }
        else
        {
            cout << "Test 3 failed! " << score_task_2 << "/30" << endl;
            return;
        }

        test.finishCheckup(3);
        test.scheduleCheckup(2);
        test.finishCheckup(2);
        test.registerPatient("Mabel", "Wright", 26);
        if (test.scheduleCheckup(5) == false && test.scheduleCheckup(1) == true)
        {
            score_task_2 += 3;
        }
        else
        {
            cout << "Test 3 failed! " << score_task_2 << "/30" << endl;
            return;
        }
        test.registerPatient("Dianne", "Simmons", 16);
        test.registerPatient("Ted", "Armstrong", 46);
        test.registerPatient("Cary", "Pittman", 44);
        test.registerPatient("Courtney", "Castillo", 51);

        test.scheduleCheckup(9);
        test.scheduleCheckup(7);
        test.scheduleCheckup(8);
        test.scheduleCheckup(5);
        if (test.scheduleCheckup(6) == false && test.staff[0].Assigned_Patient_ID == 1  && test.staff[1].Assigned_Patient_ID == 9 && test.staff[2].Assigned_Patient_ID == 7 && test.staff[3].Assigned_Patient_ID == 8 && test.staff[4].Assigned_Patient_ID == 5)
        {
            cout << "Test 3 passed! " << score_task_2 << "/30" << endl;
            score_task_2 += 3;
        }
        else
        {
            cout << "Test 3 failed! " << score_task_2 << "/30" << endl;
            return;
        }
    }
    catch (exception ex2)
    {
        cout << "Test 3 failed! " << score_task_2 << "/30" << endl;
    }
}


// ------------------------------------- Running the Tests -------------------------------------

int main()
{
    int score_task_2 = 0;
    cout << "-----------------------------------------------" << endl;
    cout << "Testing Implementation of Task 2" << endl
         << endl;

    testHospitalInitialization(score_task_2);
    testRegistration(score_task_2);
    testCheckup(score_task_2);

    cout << endl
         << endl;

    cout << "-----------------------------------------------" << endl
         << endl;
    cout << "Total Score for Task 2: " << score_task_2 << "/30" << endl
         << endl;
}