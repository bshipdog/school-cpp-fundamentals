/******************************
   Name
   Date
   PA3_Starter.cpp
   Write a description of the program
********************************/

// Headers
#include <iostream>		// cout, cin
#include <cstdlib>		// exit()
#include <string>		// strings
#include <fstream>		// file processing
#include <iomanip>		// stream manipulation
using namespace std;

// Global variables
const int MAX_STUDENTS = 25;	// We will not process more than 25 students even if the file contains more
const int MAX_GRADES = 5;		// Each student has exactly 5 grades
const string FILENAME = "NamesGrades.txt";	// The name of the file that you will read

// Function declarations
int loadStudentNamesGrades(string students[], int grades[][MAX_GRADES], string fileName, int maxStudents);
void displayAverages(string students[], int grades[][MAX_GRADES], int studentCount);
void displayMax(string students[], int grades[][MAX_GRADES], int studentCount);
void displayMin(string students[], int grades[][MAX_GRADES], int studentCount);
char getLetterGrade(double grade, string letter_grades[]);
int getLongestNameLength(string students[], int studentCount);

int main()
{
	// You will need some variables here
	// You need one to keep up with the actual number of students
	// You need an array of strings for the student names
	// You need a two dimensional array of ints for the grades of the students
	// You need a variable to hold the choice of the user for the menu
	string students[MAX_STUDENTS];
    int grades[MAX_STUDENTS][MAX_GRADES];
    int studentCount = 0;
    string fileName = "NamesGrades.txt";
    double grade;
    
    // Get students and grades
    studentCount = loadStudentNamesGrades(students, grades, fileName, MAX_STUDENTS);
    int choice;
    
    // Loop until user says to quit
   	do 
    {
        // present menu and get user's choice
		cout << endl << setw(8) << "1. Display Average Grade" << endl;
		cout << setw(8) << "2. Display Maximum Grade" << endl;
		cout << setw(8) << "3. Display Minimum Grade" << endl;
		cout << setw(8) << "4. Quit Program" << endl;
		cout << "\nEnter your choice (1-4): ";

        cin >> choice;

        // Process the choice
        switch(choice)
        {
            case 1: displayAverages(students, grades, studentCount, grade);
                break;
            case 2: displayMax(students, grades, studentCount, grade);
                break;
            case 3: displayMin(students, grades, studentCount, grade);
                break;
            case 4:
                break;
            default:
                cout << "Please check your input and try again." << endl;
        }
    }while(choice != 4);
		
	// End of program    
	//	Make sure we place the end message on a new line
    cout << endl;

    return 0;
}

/***********************************************************
loadStudentNameGrades opens and read fileName. It will read in two strings, concatenate them, and then save
to the students array. It then reads five integers and save each to the grades array. The function will return
the actual number of student/grade combinations read
PARAM:	students is an array of strings that can hold up ot maxStudents values
		grades is a two dimensional array for holding the grades of each student
		fileName is the name of the file that will be opened and read
		maxStudents is the maximum number of students that we will read from the file
PRE:	students[] is large enough to contain up to maxStudents elements
		grades[] is large enough ot contain up to maxStudents elements
POST:	students[] contains the names of up to maxStudents
		grades[][] contains the grades for up to maxStudents
		The number of student/grade combinations actually read from the file is returned. This value can range
		between 0 <= numStudents <= maxStudents
NOTE:	students[] and grades[] are meant to be parralel arrays. students[0] and grades[0] are the same student		
************************************************************/
int loadStudentNamesGrades(string students[], int grades[][MAX_GRADES], string fileName, int maxStudents)
{
    // file stream object
    ifstream inputFile;
    inputFile.open(fileName);

    string first_name, last_name; // first 2
    int grade_1, grade_2, grade_3, grade_4, grade_5; // last three
    int index = 0; // vertical movement

    while (!inputFile.eof() && index < maxStudents) // process going horiz. and then vertical
    {
        // take horizontally
        inputFile >> first_name >> last_name >> grade_1 >> grade_2 >> grade_3 >> grade_4 >> grade_5;
        students[index] = first_name + last_name;
        grades[index][0] = grade_1;
        grades[index][1] = grade_2;
        grades[index][2] = grade_3;
        grades[index][3] = grade_4;
        grades[index][4] = grade_5;

        index++;
    }
	return index;	// for stub out purposes, change this in your code
}

/***********************************************************
displayAverages calculates the average of each student and displays the
students name, average, and letter grade of the average in a table
PARAM:	students[] is an array of strings that contains the names of studentCount students
		grades[] is an array of integers that contains the grades of studentCount students
		studentCount contains the value of the number of elements in the students[] and grades[] arrays
PRE:	students[] and grades[] contain values for studentCount elements
POST:	table of student names, averages, and letter grades is displayed
************************************************************/
void displayAverages(string students[], int grades[][MAX_GRADES], int studentCount, double grade)
{
	cout << endl << endl << setw(20) << "Student Name" << setw(20) << "Average" << setw(20) << "Letter Grade" << endl << endl;

    for(int i = 0; i < studentCount; i++) // start at index 0 (vertical)
    {
        double sum = 0;
        for(int c = 0; c < MAX_GRADES; c++) // add across
        {
            sum += grades[i][c];
        }
        double avg = sum / MAX_GRADES;
    cout << setw(20) << students[i] << setw(20) << avg << setw(20) << getLetterGrade(avg) << endl;
    }
}

/***********************************************************
displayMax calculates the maximum grade of each student and displays the
students name, maximum grade, and letter grade of the maximum grade in a table
PARAM:	students[] is an array of strings that contains the names of studentCount students
		grades[] is an array of integers that contains the grades of studentCount students
		studentCount contains the value of the number of elements in the students[] and grades[] arrays
PRE:	students[] and grades[] contain values for studentCount elements
POST:	table of student names, maximum grades, and letter grades is displayed
************************************************************/
void displayMax(string students[], int grades[][MAX_GRADES], int studentCount, double grade)
{
	cout << endl << endl << setw(20) << "Student Name" << setw(20) << "Maximum Grade" << setw(20) << "Letter Grade" << endl << endl;
    for (int i = 0; i < studentCount; i++)
    {
        int max = 0;
        for (int c = 0; c < MAX_GRADES; c++)
        {
            if (grades[i][c] > max)
            max = grades[i][c];
        }
    cout << setw(20) << students[i] << setw(20) << max << setw(20) << getLetterGrade(max) << endl;
    }
}

/***********************************************************
displayMin calculates the minimum grade of each student and displays the
students name, minimum grade, and letter grade of the minimum grade in a table
PARAM:	students[] is an array of strings that contains the names of studentCount students
		grades[] is an array of integers that contains the grades of studentCount students
		studentCount contains the value of the number of elements in the students[] and grades[] arrays
PRE:	students[] and grades[] contain values for studentCount elements
POST:	table of student names, minimum grades, and letter grades is displayed
************************************************************/
void displayMin(string students[], int grades[][MAX_GRADES], int studentCount, double grade)
{
	cout << endl << endl << setw(20) << "Student Name" << setw(20) << "Minimum grade" << setw(20) << "Letter Grade" << endl << endl;
    for (int i = 0; i < studentCount; i++) // start vertical
    {
        int min = 100;
        for (int c = 0; c < MAX_GRADES; c++) // move across (could do a bubble sort)
        {
            if (grades[i][c] < min)
            min = grades[i][c];
        }
    cout << setw(20) << students[i] << setw(20) << min << setw(20) << getLetterGrade(min) << endl;
    }
}

/***********************************************************
getLetterGrade converts a numerical grade to a letter grade
PARAM:	grade is the numerical grade to convert. Expected range is 0 <= grade <= 100
PRE:	grade contains a value in the correct range
POST:	The corresponding letter grade of the numerical grade is returned
************************************************************/
char getLetterGrade(double grade)
{
    if (grade >= 90)
        return 'A';

    if (grade < 90 && grade >= 80)
        return 'B';

    if (grade < 80 && grade >= 70)
        return 'C';

    if (grade < 70 && grade >= 60)
        return 'D';

    if (grade < 60 && grade >= 0)
        return 'F';
}

/***********************************************************
getLongestNameLength returns the length of the longest string from a list of strings
PARAM:	students[] is an array of strings that contains the name of students
		studentCount is the size of the students[] array
PRE:	students[] contains studentCount names
POST:	The length of the longest string in students[] is returned
************************************************************/
int getLongestNameLength(string students[], int studentCount)
{
	
}