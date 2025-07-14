#include "Task_01A.cpp"
#include <fstream>
#include <vector>
#include <random>

int TOTAL = 10;

void test(double& score, vector<string> queries)
{
    int hashes[] = {-2079800135,107864596,1696898533,8241265993,-685674878,-716069019,877251028,3916920,-1803570950,3627891,113282685,
    -1157461592,1368498081,118497238,-784360700,-1769391552,122254575,1920301485,-399601180,3814451,1618394959,127152086,127929379,
    -1669361538,140172969,-74758924};

    int compressions[] = {-35,96,33,93,-78,-19,28,20,-50,91,85,-92,81,38,0,-52,75,85,-80,51,59,86,79,-38,69,-24};

    cout << "Testing Get Hash Code" << endl;
    try
    {
        bool hash = true;
        int counter = 0;
        for (auto i = queries.cbegin(); i != queries.cend(); ++i)
        {
            if (getHashCode(*i) != hashes[counter])
            {
                hash = false;
                cout << "Get hash code failed! " << score << "/" << TOTAL << endl;
                break;
            }
            counter++;
        }
        if (hash)
        {
            score += 5;
            cout << "Get hash code passed! " << score << "/" << TOTAL << endl;
        }
    }
    catch(const std::exception& e) {
        cout << "Get hash code failed! " << score << "/" << TOTAL << endl;
        std::cerr << e.what() << '\n';
    }

    cout << "Testing Compression" << endl;
    try
    {
        bool compressed = true;
        for (auto i = 0; i < 26; ++i)
        {
            if (divCompression(hashes[i],100) != compressions[i])
            {
                compressed = false;
                cout << "Compression failed! " << score << "/" << TOTAL << endl;
                break;
            }
        }
        if (compressed)
        {
            score += 5;
            cout << "Compression passed! " << score << "/" << TOTAL << endl;
        }
    }
    catch(const std::exception& e) {
        cout << "Compression failed! " << score << "/" << TOTAL << endl;
        std::cerr << e.what() << '\n';
    }
}


int main()
{
    vector<string> test_lines;
    string line;

    ifstream file("hash_strings.txt");
    while (getline(file, line))
    {
        test_lines.push_back(line);
    }
    
    cout << "\nTotal number of words being checked: " << test_lines.size() << endl << endl;
    double score = 0;

    test(score, test_lines);

    cout << "\nTotal score for task 01 A: " << score << "/" << TOTAL << endl << endl;
}