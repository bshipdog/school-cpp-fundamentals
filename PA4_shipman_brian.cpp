/******************************
Name: Brian Shipman
Date: April 26, 2021
Assignment: Programming Assignment 4
*******************************/

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

// GLOBAL VARIABLES
struct File
{
    const string FILENAME = "PA4.txt";
    int MONTHS = 12;
    const int MAX_DATA = 2;
};

struct Rainfall
{
    string m_name;      // month name
    double r_amount;    // rainfall amount
    double s, l, avg;   // smallest, largest, average
    string s_m, l_m;    // smallest month, largest month
};

// FUNCTION PROTOYPES
int loadMonthsData(File &f, Rainfall array[12][2]);
void findMinMax(File &f, Rainfall array[12][2], Rainfall &c);
void findAverage(File &f, Rainfall array[12][2], Rainfall &c);
int sortArray(File &f, Rainfall array[12][2], Rainfall &c);
void displayData(File &f, Rainfall array[12][2], Rainfall &c);

int main()
{
    // code goes here
    // create array of structs
    File f;
    Rainfall array[12][2];
    Rainfall compare;

    // call functions
    loadMonthsData(f, array);
    findMinMax(f, array, compare);
    findAverage(f, array, compare);
    displayData(f, array, compare);
    sortArray(f, array, compare);

    // OS X not Windows
    // A non-system dependent method is below
    cin.get();

    return 0;
}

int loadMonthsData(File &f, Rainfall array[12][2]) // take data from file and store it correctly
{
    // file stream object
    ifstream inputFile;
    inputFile.open(f.FILENAME);

    int i = 0; // vertical movement

    while (!inputFile.eof() && i < f.MONTHS) // process going horiz. and then vertical
    {
        // take horizontally
        inputFile >> array[i][0].m_name >> array[i][1].r_amount;

        i++; // add for next row vertically
    }
    inputFile.close();
}

void findMinMax(File &f, Rainfall array[12][2], Rainfall &c)
{
    for (int i = 0; i < f.MONTHS; i++)
    {
        if (array[i][1].r_amount < c.s)
        {
            c.s = array[i][1].r_amount;
            c.s_m = array[i][0].m_name;
        } 

        if (array[i][1].r_amount > c.l)
        {
            c.l = array[i][1].r_amount;
            c.l_m = array[i][0].m_name;
        }
    }
}

void findAverage(File &f, Rainfall array[12][2], Rainfall &c)
{
    for(int i = 0; i < f.MONTHS; i++)
    {
        c.avg = c.avg + array[i][1].r_amount;
    }
    c.avg = c.avg/f.MONTHS;
}

void displayData(File &f, Rainfall array[12][2], Rainfall &c)
{
    
    cout << "\nMonthly Rainfall for Fort Worth, TX 2014" << endl;
    cout << "\nMinimum: " << c.s_m << " " << c.s;
    cout << "\nMaximum: " << c.l_m << " " << c.l << endl;
    cout << "Monthly Average for Year: " << fixed << showpoint << setprecision(2) << c.avg << endl << endl;
    cout << "Month" << setw(14) << "Rainfall" << endl;
}

int sortArray(File &f, Rainfall array[12][2], Rainfall &c)
{
    bool swap;
    int temp;

    do
    {
        swap = false;
        for (int i = 0; i < (f.MONTHS - 1); i++)
        {
            if (array[i][1].r_amount > array[i++][1].r_amount)
            {
                array[i][1].r_amount = array[i++][1].r_amount;
                array[i][0].m_name = array[i++][0].m_name;
                swap = true;
            }
        }
    }while(swap);
    for (int i = 0; i < f.MONTHS; i++)
    {
        cout << setw(9) << left << array[i][0].m_name << setw(10) << right << array[i][1].r_amount << endl;
    }
}