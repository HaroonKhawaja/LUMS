#include<iostream>
#include<limits>

using namespace std;

int main()
{
    int ns , nl ; 

    do {  
        cout << "How many students are in the course: " ;
        cin >> ns ;
        if (cin.fail() || ns <= 0)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "How many students are in the course: " ;
            cin >> ns ;
        }
    } while (cin.fail() || ns <= 0) ;

    do 
    {
        cout << "How many labs are in the course: " ;
        cin >> nl ;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (cin.fail()) ;
    
    double overall_mean = 0 ;
    for(int j = 1; j <= nl; j++)
    {
        double score ;
        double total = 0 ;
        cout << "\n--- Lab " << j << " ---" << endl ;
        for(int i = 1; i <= ns; i++)
        {
            cout << "Enter Student No. " << i << " 's Lab " << j << " marks: " ;
            cin >> score ;
            total = total + score ;
        }
        double mean = total / ns ;
        cout << "\nLab 1 Mean = " << mean << " out of 100." << endl ;
        overall_mean = overall_mean + mean ;
    }
    double overall_marks = 100 * nl ;
    cout << "\nOverall Course Mean = " << overall_mean << " out of " << overall_marks << endl ;

    return 0;
}