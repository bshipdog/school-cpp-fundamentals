#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
    string names[4] = {};
    string prompts[3][2] = {
        {"Enter the name of assignment 1: ", "Enter the name of assignment 2: "},
        {"Enter the name of assignment 3: ", "Enter the grade for "},
        {"The average grade for ", "Here are your grades:"}
    };
    float assign_x[3] = {};
    cout << endl << endl;
    cout << "This program gets the average for your 3 assignments." << endl << endl;

    cout << "Please enter student's first and last name separated by a space, then press [Enter]: ";
    getline(cin, names[0]);
    cout << endl << endl;

    cout << prompts[0][0];
    getline(cin, names[1]);
    cout << prompts[0][1];
    getline(cin, names[2]);
    cout << prompts[1][0];
    getline(cin, names[3]);
    cout << endl << endl;

    cout << prompts[1][1] << names[1] << ": ";
    cin >> assign_x[0];
    cout << prompts[1][1] << names[2] << ": ";
    cin >> assign_x[1];
    cout << prompts[1][1] << names[3] << ": ";
    cin >> assign_x[2];
    cout << endl << endl;

   double average = (assign_x[0] + assign_x[1] + assign_x[2]) / 3;

    cout << setprecision(2) << fixed;
    cout << prompts[2][0] << names[0] << " is " << average << endl << endl;
    cout << prompts[2][1] << endl;
    cout << setprecision(2) << fixed;
    cout << setw(15) << names[1] << ":" << setw(10) << assign_x[0] << endl;
    cout << setw(15) << names[2] << ":" << setw(10) << assign_x[1] << endl;
    cout << setw(15) << names[3] << ":" << setw(10) << assign_x[2] << endl << endl;

    return 0;
}