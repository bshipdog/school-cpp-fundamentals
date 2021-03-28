// Brian Shipman
// Skill Assignment 4
// Date: March 6, 2021

// Header files
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

// Function Prototypes
void menu_choice(int shape[]);
void circle(double value[]);
void rectangle(double value[]);
void triangle(double value[]);
void quit();

int main()
{
         int shape[1];
         double value[3];

         menu_choice(shape);
         switch (shape[0])
         {
                 case 1: circle(value);
                 break;

                 case 2: rectangle(value);
                 break;

                 case 3: triangle(value);
                 break;

                 case 4: cout << "Thanks for trying." << endl;
                 break;

                 default: cout << "You did not enter a valid option" << endl;
                 break;
         }
         return 0;
}
// Do not try to test it with letters.  I can't figure out what is going on but my friend
// said I might need to pass by reference.  I don't know anything about that and it wouldn't
// make sense to me sense it only occurs with string variables.
void menu_choice(int shape[])
{
         do 
         {
         cout << endl;
         cout << "Geometry Area Calculator" << endl << endl;
         cout << "1. Calculate the Area of a Circle." << endl << endl;
         cout << "2. Calculate the Area of a Rectangle." << endl << endl;
         cout << "3. Calculate the area of a Triangle." << endl << endl;
         cout << "4. Quit" << endl << endl;
         cout << "Enter your choice (1-4):" << endl << endl;
         cin >> shape[0];
         cin.ignore();
         } while (shape[0] != 1 && shape[0] != 2 && shape[0] != 3 && shape[0] != 4);
}

void circle(double value[])
{
    // the program should ask for the radius of the circle then display it's 
    // area using the following formula: area = PIr2 Use 3,14159 for PI and 
    //the radius of the circle for r
         cout << setw(5) << "Radius of the circle: ";
         cin >> value[0];
         cin.ignore();
         cout << endl << endl;

         value[2] = 3.14159 * (pow(value[0], 2));

         cout << setw(5) << "Radius:" << setw(3) << value[0] << endl;
         cout << fixed << showpoint << setprecision(3);
         cout << setw(5) << "Area:" << setw(3) << value[2] << endl;
}

void rectangle(double value[])
{
     /* the program should ask for the length and width of the rectangle, then 
     display the rectangle's area. Use the following formula: area = length * width */
         cout << setw(5) << "Length of Rectangle: ";
         cin >> value[0];
         cin.ignore();
         cout << endl;

         cout << setw(5) << "Width of Rectangle: ";
         cin >> value[1];
         cin.ignore();
         cout << endl << endl;
     
         value[2] = value[0] * value[1];

         cout << setw(5) << "Length:" << setw(3) << value[0] << endl;
         cout << setw(5) << "Width:" << setw(3) << value[1] << endl;
         cout << fixed << showpoint << setprecision(3);
         cout << setw(5) << "Area:" << setw(3) << value[2] << endl;
}

void triangle(double value[])
{
     /* the program should ask for the length of the triangle's base and it's height, 
     the display its area. Use the follow formula: area = base * height * .5 */
         cout << setw(5) << "Base of Triangle: ";
         cin >> value[0];
         cin.ignore();
         cout << endl;

         cout << setw(5) << "Height of Triangle: ";
         cin >> value[1];
         cin.ignore();
         cout << endl << endl;

         value[2] = (value[0] * value[1]) * 0.5;

         cout << setw(5) << "Base:" << setw(3) << value[0] << endl;
         cout << setw(5) << "Height:" << setw(3) << value[1] << endl;
         cout << fixed << showpoint << setprecision(3);
         cout << setw(5) << "Area:" << setw(3) << value[2] << endl;
}