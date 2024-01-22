/*
    RMIT University Vietnam
    Course: EEET2482/COSC2082
    Semester: 2023-3
    Lab Assessment: 2
    Author: Pham Ngoc Huy
    ID: S3926681    
    Compiler used: (Homebrew GCC 13.2.0) 13.2.0
    Created  date:  13/01/2024
    Acknowledgement:  W3School
*/


#include<iostream>
#include<fstream>

using namespace std;


int main ()
{
    string studentName;
    cout << "Input your student name" << endl;
    getline(cin >> ws, studentName);


    string studentId;
    cout << "Input your student Id" << endl;
    cin >> studentId;

    ofstream Myfile("Ngoc Huy.dat");

    Myfile << "Student Name : " << studentName << "\n";
    Myfile << "Student ID : " << studentId << "\n" << endl;

    cout << "Your data is saved !";

    
    Myfile.close();


    return 0;
}

