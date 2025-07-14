#include <iostream>
#include <string>
#include "Task_01.cpp"
using namespace std;

// application of priority queues
// hospital patient scheduler
// you are allowed to make as many helper functions as you need to

// defines a Doctor object
// DO NOT CHANGE THE MEMBER VARIABLE SET OR CONSTRUCTOR
// You can, however, do operator overloading
class Doctor
{
public:
    int Doctor_ID;
    string First_Name;
    string Last_Name;
    int Assigned_Patient_ID;

    Doctor()
    {
        Doctor_ID = 0;
        First_Name = "";
        Last_Name = "";
        Assigned_Patient_ID = -1;
    }

    Doctor(int _Doctor_ID, string _First_Name, string _Last_Name)
    {
        Doctor_ID = _Doctor_ID;
        First_Name = _First_Name;
        Last_Name = _Last_Name;
        Assigned_Patient_ID = -1;
    }
};

// defines a Patient object
// DO NOT CHANGE THE MEMBER VARIABLE SET OR CONSTRUCTOR
// You can, however, do operator overloading
class Patient
{
public:
    int Patient_ID;
    string First_Name;
    string Last_Name;
    int Assigned_Doctor_ID;
    int Age;

    Patient()
    {
        Patient_ID = 0;
        First_Name = "";
        Last_Name = "";
        Age = 0;
        Assigned_Doctor_ID = -1;
    }

    Patient(int _Patient_ID, string _First_Name, string _Last_Name, int _Age, int _Assigned_Doctor_ID)
    {
        Patient_ID = _Patient_ID;
        First_Name = _First_Name;
        Last_Name = _Last_Name;
        Age = _Age;
        Assigned_Doctor_ID = _Assigned_Doctor_ID;
    }
};


// defines a Hosptial object
// DO NOT CHANGE THE MEMBER VARIABLE SET OR CONSTRUCTOR
class Hospital
{
public:
    int num_patients;
    int num_doctors;
    Doctor staff[10];
    Patient paitents[50];
    MaxHeap* scheduler;
    
    // HELPER ATTRIBUTE
    int maxSeen_PatientID;

    // TO DO Function
    Hospital()
    {
        staff[0].Doctor_ID = 1; staff[0].First_Name = "Aizen"; staff[0].Last_Name = "Sosuke"; staff[0].Assigned_Patient_ID = -1;
        staff[1].Doctor_ID = 2; staff[1].First_Name = "Muhammad"; staff[1].Last_Name = "Ahmed"; staff[1].Assigned_Patient_ID = -1;
        staff[2].Doctor_ID = 3; staff[2].First_Name = "Lorenzo"; staff[2].Last_Name = "Pratt"; staff[2].Assigned_Patient_ID = -1;
        staff[3].Doctor_ID = 4; staff[3].First_Name = "Darnell"; staff[3].Last_Name = "Curtis"; staff[3].Assigned_Patient_ID = -1;
        staff[4].Doctor_ID = 5; staff[4].First_Name = "Ellis"; staff[4].Last_Name = "Dunn"; staff[4].Assigned_Patient_ID = -1;
        num_patients = 0;
        num_doctors = 5;
        // dynamically allocate a MaxHeap of capacity 50
        scheduler = new MaxHeap(50);
        maxSeen_PatientID = 0;
    }

    // TO DO Function
    bool registerDoctor(string _fname, string _lname) 
    {
        // add a Doctor to the staff array if its capacity has not already been reached: return True
        // if the staff array's capacity has been reached: return False
        // DoctorIDs start from 1 and increase incrementally with each new Doctor
        if (num_doctors == 10)
        {
            return false;
        }
        staff[num_doctors].Doctor_ID = num_doctors + 1;
        staff[num_doctors].First_Name = _fname;
        staff[num_doctors].Last_Name = _lname;
        staff[num_doctors].Assigned_Patient_ID = -1;
        num_doctors++;
        return true;
    }

    // TO DO Function
    bool registerPatient(string _fname, string _lname, int _age) 
    {
        // add a Patient to the patients array if its capacity has not already been reached & insert Full name and age into priority queue: return True
        // if the patients array's capacity has been reached: return False
        // PatientIDs start from 1 and increase incrementally with each new Patient
        if (num_patients == 50)
        {
            return false;
        }
        int i = 0;
        while (paitents[i].First_Name != "")
        {
            i++;
        }
        maxSeen_PatientID++;
        paitents[i].Patient_ID = maxSeen_PatientID;
        paitents[i].First_Name = _fname;
        paitents[i].Last_Name = _lname;
        paitents[i].Assigned_Doctor_ID = -1;;
        paitents[i].Age = _age;
        num_patients++;
        string full_name = _fname + " " + _lname;
        scheduler->insertElement(full_name, _age);
        
        return true;
    }

    // TO DO Function
    bool scheduleCheckup(int _Patient_ID) 
    {
        // attempt to schedule a checkup for a Patient with ID _Patient_ID if such a patient truly exists and is in line, waiting for a checkup
        //      check if the specified _Patient_ID is truly the ID of the patient with the highest priority right now
        //      if so, the patient will be assigned the first available doctor (and vice versa) from the staff and cease to wait any longer inside the priority queue
        //          if the patient is successfully assigned a doctor, the function will return True. Otherwise, it will return False.
        //
        // while there is only one scenario where the function will return True, there are multiple scenarios where the function will return False 
        // you must figure them out on your own.
        if (_Patient_ID > maxSeen_PatientID) // invalid ID
        {
            return false;
        }
        int paitent_index = _Patient_ID - 1;
        Patient check_paitent = paitents[paitent_index];
        string cp_fullname = check_paitent.First_Name + " " + check_paitent.Last_Name;
        if (cp_fullname != scheduler->getMax().name) // paitent not top priority
        {
            return false;
        }
        else if (cp_fullname == scheduler->getMax().name)
        {
            if (check_paitent.Assigned_Doctor_ID != -1) // paitent has no doctor
            {
                return false;
            }
            int i = 0;
            while (staff[i].Assigned_Patient_ID != -1) // finding open doctor
            {
                i++;
            }
            if (i == num_doctors)
            {
                return false;
            }
            else
            {
                paitents[paitent_index].Assigned_Doctor_ID = staff[i].Doctor_ID;
                staff[i].Assigned_Patient_ID = check_paitent.Patient_ID;
                scheduler->extractMax();
                return true;
            }
        }
    }

    // TO DO Function
    bool finishCheckup(int _Patient_ID) 
    {
        // will attempt to finish a checkup for a Patient with ID _Patient_ID if such a patient truly exists and they are currently having a checkup
        // their checkup will be finished and they will sent home, consequently getting removed from the patients array 
        // on the other hand, everyone currently waiting in the priority queue will have their priority increased by 10
        // the doctor conducting the checkup will also be unassigned (setting back to -1)
        // return True if all proceeds successfully – otherwise, return False
        int paitent_index = _Patient_ID - 1;
        Patient find_patient = paitents[paitent_index];
        if (_Patient_ID > maxSeen_PatientID) // invalid patient ID
        {
            return false;
        }
        else if (find_patient.Assigned_Doctor_ID == -1) // Patient not having a checkup
        {
            return false;
        }
        else
        {
            int doc_id = paitents[paitent_index].Assigned_Doctor_ID; // finding paitents doctors ID
            int doc_index = doc_id - 1;
            staff[doc_index].Assigned_Patient_ID = -1; // freeing paitent from doctor
            int i = 0;
            while (paitents[i].Patient_ID != _Patient_ID) // finding paitent ID in paitent array
            {
                i++;
            }
            for (int j = i; j < num_patients - 1; j++) // shifting every paitent right after the paitent is removed
            {
                paitents[j].Patient_ID =  paitents[j + 1].Patient_ID;
                paitents[j].First_Name = paitents[j + 1].First_Name;
                paitents[j].Last_Name = paitents[j + 1].Last_Name;
                paitents[j].Assigned_Doctor_ID = paitents[j + 1].Assigned_Doctor_ID;
                paitents[j].Age = paitents[j + 1].Age;
            }
            num_patients--;
            for (int i = 0; i < num_patients; i++)
            {
                scheduler->increasePriority(i,10);
            }
            return true;
        }
    }
};

// You can use the main function below to test your implementation
// Remember to comment out the main section before running test_2.cpp

// int main()
// {
    
// }