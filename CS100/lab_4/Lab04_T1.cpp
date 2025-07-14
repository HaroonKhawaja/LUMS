#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    //Marks in Physics, English, Math Respectively
    double haroon_p = 85.58 ; 
    double haroon_e = 93.39 ;
    double haroon_m = 98.89 ;

    double yousuf_p = 82.28 ;
    double yousuf_e = 91.29 ;
    double yousuf_m = 96.69 ;

    double ahmed_p = 80.08 ;
    double ahmed_e = 85.58 ;
    double ahmed_m = 91.10 ;
    //Combined Percentage of Haroon, Yousuf, Ahmed Respectively
    double comb_percentage_h = ((haroon_p + haroon_e + haroon_m)/300) * 100 ;
    double comb_percentage_y = ((yousuf_p + yousuf_e + yousuf_m)/300) * 100 ;
    double comb_percentage_a = ((ahmed_p + ahmed_e + ahmed_m)/300) * 100 ;
    //Average Marks in Physics, English, Math Respectively
    double avg_physics = (haroon_p + yousuf_p + ahmed_p) / 3 ;
    double avg_english = (haroon_e + yousuf_e + ahmed_e) / 3 ;
    double avg_math = (haroon_m + yousuf_m + ahmed_m) / 3 ;

    cout << left ;
    cout << setw(20) << "Student Name" << setw(20) << "Marks in English" ;
    cout << setw(20) << "Marks in Physics" << setw(20) << "Marks in Math" << setw(20) << "Percentage" << endl ;
    cout << fixed << setprecision(2) ;
    cout << setw(20) << "Haroon" << setw(20) << haroon_e << setw(20) << haroon_p << setw(20) << haroon_m << setw(20) << comb_percentage_h << endl ;
    cout << setw(20) << "Yousuf" << setw(20) << yousuf_e << setw(20) << yousuf_p << setw(20) << yousuf_m << setw(20) << comb_percentage_y << endl ;
    cout << setw(20) << "Ahmed" << setw(20) << ahmed_e << setw(20) << ahmed_p << setw(20) << ahmed_m << setw(20) << comb_percentage_a << endl ;
    cout << setw(20) << "Average Marks" << setw(20) << avg_english << setw(20) << avg_physics << setw(20) << avg_math << endl ;
    return 0 ;

}