#include<iostream>

using namespace std;

int main()
{
    string s1_first_name = "Haroon" ;
    string s2_favorite_movie_or_show = "The Witcher" ; 
    string s3_favorite_course = "Computer Science" ;
    
    int s1_length = s1_first_name.length() ; 
    int s2_length = s2_favorite_movie_or_show.length() ;
    int s3_length = s3_favorite_course.length() ;

    cout << s1_first_name << " has length: " << s1_length << endl ;
    cout << s2_favorite_movie_or_show << " has length: " << s2_length << endl ; 
    cout << s3_favorite_course << " has length: " << s3_length << endl ;

    int shortest_string = s1_length;
    int longest_string = s3_length;
    // Shortest String
    if ( s1_length <= shortest_string )
        cout << "\nShortest string is " << "\"" << s1_first_name << "\"" << " with length: " << s1_length << endl ;
    if ( s2_length <= shortest_string )
        cout << "Shortest string is " << "\"" << s2_favorite_movie_or_show << "\"" << " with length: " << s2_length << endl ;
    if ( s3_length <= shortest_string )
        cout << "Shortest string is " << "\"" << s3_favorite_course << "\"" << " with length: " << s3_length << endl ;
    // Longest String
    if ( s1_length >= longest_string )
        cout << "Longes string is " << "\"" << s1_first_name << "\"" << " with length: " << s1_length << endl ;
    if ( s2_length >= longest_string )
        cout << "Longes string is " << "\"" << s2_favorite_movie_or_show << "\"" << " with length: " << s2_length << endl ;
    if ( s3_length >= longest_string )
        cout << "Longest string is " << "\"" << s3_favorite_course << "\"" << " with length: " << s3_length << endl ;
        return 0 ;
}