/********************************
Name: Brian Shipman
Date: 4-21-21
Description: 
Speakers' Bureau:
Write a program that keeps track of a speakers' bureau.
The program should use a structure to store the following data about a speaker:
------------------------------------------------------------------------------
Name
Telephone Number
Speaking Topic
Fee Required
------------------------------------------------------------------------------
The program should use an array of at least 5 structures. It should let the user enter data into the array, 
and display all the data stored in the array. The program should have a menu-driven user interface. 
It should go to the menu first and give the user the option to enter the array of 5 structures, 
list all the data stored in the structure, and exit the program.

Input Validation: When the data for a new speaker is entered, be sure the user enters data for all the fields. 
No negative amounts should be entered for a speaker's fee.
*********************************/

#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>

using namespace std;

// Global variables
struct SpeakerData
{
    string name;    // name of speaker
    string phone;   // Telephone number of speaker
    string topic;   // Speaking Topic
    double fee;        // fee required
    int time;       // speaker time
};

// Function prototypes
void getSpeakerInfo(SpeakerData info[]);
void displaySpeakerInfo(SpeakerData info[]);

int main()
{
    // your code goes here
    // create an array of SpeakerData stucture
    SpeakerData info[5];
    int choice;

    // ask user if they want to enter speaker's data
    do
    {
        cout << "\nDo you want to enter the speaker's data?" << "\n1. YES" << "\n2. NO" << "\nPlease select 1. for YES or 2. for NO: ";
        cin >> choice;

        switch(choice)
        {
            case 1: getSpeakerInfo(info);
                displaySpeakerInfo(info);
                break;

            case 2: cout << "\nThank you for using this program.";
                break;

            default: cout << "\nYou did not enter a valid choice.  Please check and try again" << endl;
                break;
        }
    } while (choice != 2);

    // Make sure we place the end message on a new line
    cout << endl;

    // OS X not Windows
    // A non-system dependent method is below
    cin.get();

    return 0;
}

void getSpeakerInfo(SpeakerData info[])
{
    // get the speakers data
    cout << "\nEnter the following information" << endl;

    // get speakers name
    cout << "\tSpeaker's Name: ";
    getline(cin, info[0].name);
    cin.get();

    // get the speakers phone number
    cout << endl << "\tSpeaker's Phone Number: ";
    getline(cin, info[0].phone);
    cin.get();

    // get the speakers speaking topic
    cout << endl << "\tSpeaker's Topic: ";
    getline(cin, info[0].topic);
    cin.get();

    // get the speakers fee required
    cout << endl << "\tSpeaker's Fee: ";
    cin >> info[0].fee;

    // validate the input
    while (info[0].fee != 0 || info[0].fee < 0)
    {
        cout << "\nERROR: Fee must be above $0\n";
        cout << "\tSpeaker's Fee: ";
        cin >> info[0].fee;
    }

    // get the speakers time required
    cout << endl << "\tSpeaker's Time: ";
    cin >> info[0].time;
    cin.get();

    // validate the input
    while (info[0].time < 0)
    {
        cout << "\nERROR: Time must be above 0 minutes.\n";
        cout << "\tSpeaker's Time: ";
        cin >> info[0].time;
        cin.get();
    }
}

void displaySpeakerInfo(SpeakerData info[])
{
    cout << endl << setw(30) << "Speaker's Name:     " << info[0].name;
    cout << endl << setw(30) << "Speaker's Phone Number:     " << info[0].phone;
    cout << endl << setw(30) << "Speaker's Topic:     " << info[0].topic;
    cout << endl << setw(30) << "Speaker's Fee:     " << "$" << fixed << showpoint << setprecision(2) << info[0].fee;
    cout << endl << setw(30) << "Speaker's Time:     " << info[0].time << " minutes";
}