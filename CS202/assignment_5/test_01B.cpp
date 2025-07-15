#include "Task_01B.cpp"
#include <fstream>
#include <vector>
#include <random>
#include <chrono>

int TOTAL = 20;

// Modify this to allow the program to run for longer. Time is given in milliseconds.
int ALLOWED_TIME = 15;


void test(double& score, vector<string> queries)
{
    cout << "Testing Insert" << endl;
    Chaining my_table = Chaining(700);
    try
    {
        for (auto i = queries.cbegin(); i != queries.cend(); ++i)
        {
            my_table.insertWord(*i);
        }
        score += 8;
        cout << "Insertion passed! " << score << "/" << TOTAL << endl;
    }
    catch(const std::exception& e) {
        cout << "Insertion failed! " << score << "/" << TOTAL << endl;
        std::cerr << e.what() << '\n';
    }

    cout << "Testing Lookup" << endl;
    try
    {
        bool lookup = true;
        for (auto i = queries.cbegin(); i != queries.cend(); ++i)
        {
            if (my_table.lookupWord(*i)==false)
            {
                lookup = false;
                cout << "Lookup failed! " << score << "/" << TOTAL << endl;
                break;
            }
        }
        if (lookup)
        {
            score += 4;
            cout << "Lookup passed! " << score << "/" << TOTAL << endl;
        }
    }
    catch(const std::exception& e)
    {
        cout << "Lookup failed! " << score << "/" << TOTAL << endl;
        std::cerr << e.what() << '\n';
    }

    cout << "Testing Delete" << endl;
    try
    {
        for (auto i = queries.cbegin(); i != queries.cend(); ++i)
        {
            my_table.deleteWord(*i);
        }
        bool lookup = true;
        for (auto i = queries.cbegin(); i != queries.cend(); ++i)
        {
            if (my_table.lookupWord(*i)==true)
            {
                lookup = false;
                cout << "Deletion failed! " << score << "/" << TOTAL << endl;
                break;
            }
        }
        if (lookup)
        {
            score += 8;
            cout << "Deletion passed! " << score << "/" << TOTAL << endl;
        }
    }
    catch(const std::exception& e)
    {
        cout << "Deletion failed! " << score << "/" << TOTAL << endl;
        std::cerr << e.what() << '\n';
    }
}


int main()
{
    vector<string> test_lines;
    string line;

    ifstream file("test_lines.txt");
    while (getline(file, line))
    {
        test_lines.push_back(line);
    }
    
    cout << "\nTotal number of words being inserted: " << test_lines.size() << endl << endl;
    double score = 0;

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    test(score, test_lines);
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();


    // should be maximum 15 milliseconds
    auto elapsed_time = chrono::duration_cast<chrono::milliseconds>(end - begin).count();
    cout << "\nElapsed Time = " << elapsed_time << " ms" << endl;
    if (elapsed_time > ALLOWED_TIME)
    {
        cout << "Oops! Your code took too long to run." << endl;
    }
    if (elapsed_time > 30)
    {
        score *= 0.6;
    }
    else if (elapsed_time > 25)
    {
        score *= 0.8;
    }
    else if (elapsed_time > 20)
    {
        score *= 0.9;
    }
    else if (elapsed_time > 15)
    {
        score *= 0.95;
    }

    cout << "\nTotal score for task 01 B: " << score << "/" << TOTAL << endl << endl;

    file.close();
}