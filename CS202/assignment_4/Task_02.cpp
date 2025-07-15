#include <iostream>
#include <fstream>
#include <string>
#include "Task_01.cpp"
using namespace std;

// application of b-tree
// student database management
// you are allowed to make as many helper functions as you need to

// defines a StudentRecord object
// DO NOT CHANGE THE MEMBER VARIABLE SET OR CONSTRUCTOR
// You can, however, do operator overloading
class StudentRecord
{
public:
    int Student_ID;
    string First_Name;
    string Last_Name;
    string Gender;
    int Age;

    StudentRecord()
    {
        Student_ID = 0;
        First_Name = "";
        Last_Name = "";
        Gender = "";
        Age = 0;
    }

    StudentRecord(int _Student_ID, string _First_Name, string _Last_Name, string _Gender, int _Age)
    {
        Student_ID = _Student_ID;
        First_Name = _First_Name;
        Last_Name = _Last_Name;
        Gender = _Gender;
        Age = _Age;
    }

    // RELEVANT TO TEST CASES
    // DO NOT MODIFY
    string printRecord()
    {
        string output = to_string(Student_ID) + " " + First_Name + " " + Last_Name + " " + Gender + " " + to_string(Age);
        return output;
    }
};


// defines a Database object
// DO NOT CHANGE THE MEMBER VARIABLE SET OR CONSTRUCTOR
// You can, however, do operator overloading
class Database
{
public:
    int size;
    StudentRecord *table;
    B_Tree *indexer;

    // TO DO Function
    Database(string filename)
    {
        // TABLE CREATION
        //      read the filename containing all the rows of the database
        //      parse each row into Student_ID, First_Name, Last_Name, Gender and Age
        //      store each row in the StudentRecord array pointed to by the table member variable
        // B-TREE INITIALIZATION
        //      iterate over the StudentRecord array and initialize a corresponding B-Tree of order 5
        //      the B-Tree will contain keyValue objects between Student_ID integers and StudentRecord pointers
        //      it is important to insert the keyValue objects in the order of which they occur in the table

        int rows = 0;
        string s = "";
        string data_array[5];

        string line;
        fstream file (filename);

        if (file.is_open())
        {
            while ( getline (file,line) )
            {
                rows++;
            }
            file.close();
        }

        table = new StudentRecord[rows];

        fstream file2 (filename);
        if (file2.is_open())
        {
            int index = 0;
            while ( getline (file2,line) )
            {
                int d = 0;
                for (int i = 0; i <= line.length(); i++)
                {
                    if (line[i] == ' ' || i == line.length())
                    {
                        data_array[d] = s;
                        d++;
                        s = "";
                    }
                    else
                    {
                        s = s + line[i];
                    }
                }
                // Initializing values for each student
                table[index].Student_ID = stoi(data_array[0]);
                table[index].First_Name = data_array[1];
                table[index].Last_Name = data_array[2];
                table[index].Gender = data_array[3];
                table[index].Age = stoi(data_array[4]);
                
                index++;
                s = "";
            }
            file2.close();
        }
        indexer = new B_Tree(5);
        
        for (int i = 0; i < rows; i++)
        {
            int key = table[i].Student_ID;
            cout << "INSERTING: " << key << endl;
            indexer->insertKey(key, table);
        }
    }

    // TO-DO Function
	// This function will search the _ID inside B-Tree indexer and return 
    // the corresponding StudentRecord pointer if it is found. Otherwise it will return NULL.
    StudentRecord *query(int _ID)
    {
        return NULL;
    }

    // TO-DO Function
	// If not already in the table, the function will insert the new StudentRecord into the table 
    // as well as its keyValue object into the indexer, ultimately returning True. Otherwise, it will return False.
    bool insert(int _ID, string _fname, string _lname, string _gender, int _age)
    {
        return 0;
    }

    // TO-DO Function
    // If in the table, the function will delete the StudentRecord corresponding to _ID as well as 
    // the corresponding keyValue object from indexer, ultimately returning True. Otherwise, it will return False.
    bool remove(int _ID)
    {
        return 0;
    }

    // TO-DO Function
    // If in the table, the function will update the StudentRecord corresponding to _ID, ultimately returning True. 
    // Otherwise, it will return False.
    bool update(int _ID, string _fname, string _lname, string _gender, int _age)
    {
        return 0;
    }
};

// You can use the main function below to test your implementation
// Remember to comment out the main section before running test_2.cpp

// int main()
// {
//     Database test("table.txt");
// }