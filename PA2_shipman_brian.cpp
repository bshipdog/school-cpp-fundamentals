// Brian Shipman
// Programming Assignment 2
// Date: March 12, 2021

// Headers
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

// Function Prototypes:
void name(string student_name[]);
void grade_name(string assign_names[]);
void grade(string assign_names[], int assign_grade[]);
void assign_average(int assign_grade[], double average[]);
void assign_display(string student_name[], string assign_names[], int assign_grade[], double average[]);


int main()
{   
     string student_name[1];
     string assign_names[3];
     int assign_grade[3];
     double average[1];
     cout << endl << endl;
     cout << "This program gets the average for your 3 assignments." << endl << endl;

     name(student_name);
     grade_name(assign_names);
     grade(assign_names, assign_grade);
     assign_average(assign_grade, average);
     assign_display(student_name, assign_names, assign_grade, average);

     return 0;
}

void name(string student_name[])
{
     cout << "Please enter student's first and last name separated by a space, then press [Enter]: ";
     getline(cin, student_name[0]);
     cout << endl << endl;
}

void grade_name(string assign_names[])
{
     cout << "Enter the name of assignment 1: ";
     getline(cin, assign_names[0]);
     cout << "Enter the name of assignment 2: ";
     getline(cin, assign_names[1]);
     cout << "Enter the name of assignment 3: ";
     getline(cin, assign_names[2]);
     cout << endl << endl;
}

void grade(string assign_names[], int assign_grade[])
{
     cout << "Enter the grade for " << assign_names[0] << ": ";
     cin >> assign_grade[0];
     cout << "Enter the grade for " << assign_names[1] << ": ";
     cin >> assign_grade[1];
     cout << "Enter the grade for " << assign_names[2] << ": ";
     cin >> assign_grade[2];
     cout << endl << endl;
}

void assign_average(int assign_grade[], double average[])
{
     average[0] = (assign_grade[0] + assign_grade[1] + assign_grade[2]) / 3;
}

void assign_display(string student_name[], string assign_names[], int assign_grade[], double average[])
{
     cout << setprecision(2) << fixed;
     cout << "The average grade for " << student_name[0] << " is " << average[0] << endl << endl;
     cout << "Here are your grades:" << endl;
     cout << setprecision(2) << fixed;
     cout << setw(15) << assign_names[0] << ":" << setw(10) << assign_grade[0] << endl;
     cout << setw(15) << assign_names[1] << ":" << setw(10) << assign_grade[1] << endl;
     cout << setw(15) << assign_names[2] << ":" << setw(10) << assign_grade[2] << endl << endl;
}