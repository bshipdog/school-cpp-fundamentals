/*The problem is as below:
The Greatest and Least of These
Write a program with a loop that lets the user enter a series of integers. 
The user should enter -99 to signal the end of the series. After all the numbers have been entered, 
the program should display the largest and smallest numbers entered.*/

#include <iostream>
#include <iomanip>

using namespace std;

// function prototypes
void numInput(int &num, int &smallest, int &largest);
void displayResults(int &smallest, int &largest);

int main()
{
     // code goes here
     // variables
     int num, smallest, largest;

     // prompts
     cout << "\nThis program gets a series of inputs and determines the largest and smallest numbers." << endl;
     cout << "Enter the integer and then press [ENTER].  To end the series use -99." << endl;
    
     // while loop with numInput func
     numInput(num, smallest, largest); 

     // display results
     displayResults(smallest, largest);

     return 0;
}

void numInput(int &num, int &smallest, int &largest)
{
     while (num != -99)
     {
         cout << "Integer: ";
         cin >> num;
         cout << endl;

         // comparison
         if (num == -99)
         {
             break;
         }

         if (num < smallest)
         {
             smallest = num;
         } 

         if (num > largest)
         {
             largest = num;
         }
     }
}

void displayResults(int &smallest, int &largest)
{
     cout << "\n Largest number:" << setw(5) << largest << endl;
     cout << "Smallest number:" << setw(5) << smallest << endl;
}