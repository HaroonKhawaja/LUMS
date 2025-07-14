#include <iostream>
#include <iomanip>
#include <fstream>
#include "Task_02.cpp"

using namespace std;

// ------------------------------------- Task 02 Tests -------------------------------------

class B_TreeTest : public B_Tree
{
public:
    B_TreeTest(int _order) : B_Tree(_order) {}
};

class Database_Test : public Database
{
public:
    Database_Test(string filename) : Database(filename) {}
};

void testInitialization(int &score_task_2)
{
    cout << "Initializing Test 1 - Initialization" << endl;
    Database_Test test("table.txt");

    try
    {
        fstream newfile;
        int index = 0;
        newfile.open("table.txt", ios::in);
        if (newfile.is_open())
        {
            string line;
            while (getline(newfile, line))
            {
                if (test.table[index].printRecord() != line)
                {
                    cout << "Test 1 failed! Database Initialization problem. " << score_task_2 << "/40" << endl;
                    return;
                }
                index++;
            }
            newfile.close();
        }
        score_task_2 += 10;

        if (test.indexer->traverse() == " 101 102 103 104 105 106 107 108 109 110 111 112 113 114 115 116 117 118 119 120 121 122 123 124 125 126 127 128 129 130 131 132 133 134 135 136 137 138 139 140 141 142 143 144 145 146 147 148 149 150")
        {
            score_task_2 += 10;
            cout << "Test 1 passed!." << score_task_2 << "/40" << endl;
        }
        else
        {
            cout << "Test 1 failed! B-Tree Initialization problem. " << score_task_2 << "/40" << endl;
            return;
        }
    }
    catch (exception ex1)
    {
        cout << "Test 1 failed! " << score_task_2 << "/40" << endl;
    }
}

void testQuery(int &score_task_2)
{
    cout << "Initializing Test 2 - Query" << endl;
    Database_Test test("table.txt");

    try
    {
        if (test.query(101)->printRecord() == "101 Reinhard Lohengramm Male 19")
        {
            score_task_2 += 1;
        }
        else
        {
            cout << "Test 2 failed!." << score_task_2 << "/40" << endl;
            return;
        }
        if (test.query(115)->printRecord() == "115 Marty Garrett Female 19")
        {
            score_task_2 += 1;
        }
        else
        {
            cout << "Test 2 failed!." << score_task_2 << "/40" << endl;
            return;
        }
        if (test.query(113)->printRecord() == "113 Gojou Satoru Male 21")
        {
            score_task_2 += 1;
        }
        else
        {
            cout << "Test 2 failed!." << score_task_2 << "/40" << endl;
            return;
        }
        if (test.query(150)->printRecord() == "150 Chester Ford Male 20")
        {
            score_task_2 += 1;
        }
        else
        {
            cout << "Test 2 failed!." << score_task_2 << "/40" << endl;
            return;
        }
        if (test.query(160) == NULL)
        {
            score_task_2 += 1;
            cout << "Test 2 passed!." << score_task_2 << "/40" << endl;
        }
        else
        {
            cout << "Test 2 failed!." << score_task_2 << "/40" << endl;
            return;
        }
    }
    catch (exception ex1)
    {
        cout << "Test 2 failed! " << score_task_2 << "/40" << endl;
    }
}

void testInsert(int &score_task_2)
{
    cout << "Initializing Test 3 - Insert" << endl;
    Database_Test test("table.txt");

    try
    {
        test.insert(151, "Frankie", "Rodriguez", "Male", 19);
        test.insert(152, "Barbara", "Greer", "Female", 20);
        test.insert(153, "Vicky", "Gonzalez", "Female", 21);
        test.insert(154, "David", "Martinez", "Male", 22);
        test.insert(155, "Loid", "Forger", "Male", 20);

        fstream newfile;
        int index = 50;
        newfile.open("testInsert.txt", ios::in);
        if (newfile.is_open())
        {
            string line;
            while (getline(newfile, line))
            {
                if (test.table[index].printRecord() != line)
                {
                    cout << "Test 3 failed! Table insertion problem. " << score_task_2 << "/40" << endl;
                    return;
                }
                index++;
            }
            newfile.close();
        }
        score_task_2 += 2;

        Node *node = test.indexer->searchKey(153);
        if (node->keys[0].key == 152 && node->keys[1].key == 153 && node->keys[1].value->printRecord() == "153 Vicky Gonzalez Female 21" && node->keys[2].key == 154 && node->keys[3].key == 155)
        {
            score_task_2 += 1;
        }
        else
        {
            cout << "Test 3 failed! B-Tree insertion problem. " << score_task_2 << "/40" << endl;
            return;
        }
        node = test.indexer->searchKey(151);
        if (node->keys[0].key == 148 && node->keys[1].key == 151 && node->keys[1].value->printRecord() == "151 Frankie Rodriguez Male 19")
        {
            score_task_2 += 1;
        }
        else
        {
            cout << "Test 3 failed! B-Tree insertion problem. " << score_task_2 << "/40" << endl;
            return;
        }
        node = test.indexer->searchKey(156);
        if (node == NULL)
        {
            score_task_2 += 1;
            cout << "Test 3 passed!. " << score_task_2 << "/40" << endl;
        }
        else
        {
            cout << "Test 3 failed! B-Tree insertion problem. " << score_task_2 << "/40" << endl;
            return;
        }
    }
    catch (exception ex1)
    {
        cout << "Test 3 failed! " << score_task_2 << "/40" << endl;
    }
}

void testDelete(int &score_task_2)
{
    cout << "Initializing Test 4 - Delete" << endl;
    Database_Test test("table.txt");

    try
    {
        test.remove(150);
        test.remove(105);

        for (int i = 0; i <= 48; i++)
        {
            if (test.table[i].printRecord() == "150 Chester Ford Male 20" || test.table[i].printRecord() == "105 Lora Reynolds Female 20")
            {
                cout << "Test 4 failed! " << score_task_2 << "/40" << endl;
                return;
            }
        }
        score_task_2 += 2;

        Node *node = test.indexer->searchKey(101);
        if (node->keys[0].key == 101 && node->keys[1].key == 102 && node->keys[2].key == 103 && node->keys[3].key == 104)
        {
            score_task_2 += 1;
        }
        else
        {
            cout << "Test 4 failed!. " << score_task_2 << "/40" << endl;
            return;
        }
        node = test.indexer->searchKey(147);
        if (node->keys[0].key == 146 && node->keys[1].key == 147 && node->keys[2].key == 148 && node->keys[3].key == 149)
        {
            score_task_2 += 1;
        }
        else
        {
            cout << "Test 4 failed!. " << score_task_2 << "/40" << endl;
            return;
        }
        if (test.remove(160) == false)
        {
            score_task_2 += 1;
            cout << "Test 4 passed!. " << score_task_2 << "/40" << endl;
        }
        else
        {
            cout << "Test 4 failed!. " << score_task_2 << "/40" << endl;
            return;
        }
    }
    catch (exception ex1)
    {
        cout << "Test 4 failed! " << score_task_2 << "/40" << endl;
    }
}

void testUpdate(int &score_task_2)
{
    cout << "Initializing Test 5 - Update" << endl;
    Database_Test test("table.txt");

    try
    {
        test.update(145, "Kurosaki", "Ichigo", "Male", 20);
        test.update(120, "Siegfried", "Kircheis", "Male", 21);
        test.update(131, "Edward", "Newgate", "Male", 19);
        test.update(101, "Hildegard", "Mariendorf", "Female", 22);

        if (test.table[44].printRecord() == "145 Kurosaki Ichigo Male 20")
        {
            score_task_2 += 1;
        }
        else
        {
            cout << "Test 5 failed!. " << score_task_2 << "/40" << endl;
            return;
        }
        if (test.table[19].printRecord() == "120 Siegfried Kircheis Male 21")
        {
            score_task_2 += 1;
        }
        else
        {
            cout << "Test 5 failed!. " << score_task_2 << "/40" << endl;
            return;
        }
        if (test.table[30].printRecord() == "131 Edward Newgate Male 19")
        {
            score_task_2 += 1;
        }
        else
        {
            cout << "Test 5 failed!. " << score_task_2 << "/40" << endl;
            return;
        }
        if (test.table[0].printRecord() == "101 Hildegard Mariendorf Female 22")
        {
            score_task_2 += 1;
        }
        else
        {
            cout << "Test 5 failed!. " << score_task_2 << "/40" << endl;
            return;
        }
        if (test.update(160, "Noel", "Deyzel", "Male", 22) == false)
        {
            score_task_2 += 1;
            cout << "Test 5 passed!. " << score_task_2 << "/40" << endl;
        }
        else
        {
            cout << "Test 5 failed!. " << score_task_2 << "/40" << endl;
            return;
        }        
    }
    catch (exception ex1)
    {
        cout << "Test 5 failed! " << score_task_2 << "/40" << endl;
    }
}

// ------------------------------------- Running the Tests -------------------------------------

int main()
{
    int score_task_2 = 0;
    cout << "-----------------------------------------------" << endl;
    cout << "Testing Implementation of Task 2" << endl
         << endl;

    testInitialization(score_task_2);
    testQuery(score_task_2);
    testInsert(score_task_2);
    testDelete(score_task_2);
    testUpdate(score_task_2);

    cout << endl
         << endl;

    cout << "-----------------------------------------------" << endl
         << endl;
    cout << "Total Score for Task 2: " << score_task_2 << "/40" << endl
         << endl;
}