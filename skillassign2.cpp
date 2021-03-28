// Please write a program to allow a user to enter a temperature in Celsius and convert it to Fahrenheit.
// Then display the new temperature on the screen.  Consider using the fixed, showpoint, and setprecision
// stream manipulators with your output.  (hint, probably points to what sort of numeric variables you should use)
// I've provided the formula for the conversion here.  Note the use of () to enforce order of operations,
// as well as using floating point numbers for 9.0 and 5.0 in order to ensure floating point division
// happens. (celsius * 9.0) / 5.0 + 32.

// For extra credit, have your program then ask for the temperature in Fahrenheit and convert to Celsius and
// display in a similar manner.  I'll leave it up to you to figure out the formula for that and how to 
// convert it to c++

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
int main()
{
    cout << endl << endl;
    cout << "This program converts Fahrenheit to Celsius or Celsius to Fahrenheit." << endl << endl;
    
    string tempUnit[4] = {"Celsius", "celsius", "Fahrenheit", "fahrenheit"};
    string tempUnitInput;
    double tempInput, tempFahrenheit, tempCelsius;
    cout << "Do you want to convert Fahrenheit or Celsius?: ";
    cin >> tempUnitInput;
    cout << endl << endl;

    // If units are Fahrenheit or fahrenheit, ask for cout << "what is the temp in Fahrenheit?" << endl;
    // If units are Celsius or celsius, ask for cout << "what is the temp in Celsius?" << endl;
    if (tempUnitInput == tempUnit[0] || tempUnitInput == tempUnit[1])
    {
        cout << "What is the temp in Celsius? (Do not include unit): ";
        cin >> tempInput;
        cout << endl << endl;
        tempFahrenheit = (tempInput * 9.0) / 5.0 + 32;
        cout << setprecision(2) << fixed;
        cout << "The temperature is:" << setw(8) << tempFahrenheit << " degrees Fahrenheit" << endl << endl;
    }

    if (tempUnitInput == tempUnit[2] || tempUnitInput == tempUnit[3])
    {
        cout << "What is the temp in Fahrenheit? (Do not include unit): ";
        cin >> tempInput;
        cout << endl << endl;
        tempCelsius = (tempInput - 32) / 1.8;
        cout << setprecision(2) << fixed;
        cout << "The temperature is:" << setw(8) << tempCelsius << " degrees Celsius" << endl << endl;
    }
    if (tempUnitInput != tempUnit[0] && tempUnitInput != tempUnit[1] && tempUnitInput != tempUnit[2] && tempUnitInput != tempUnit[3])
    {   
        do
        {
        cout << "Please check spelling and try again." << endl << endl;
        cout << "Do you want to convert Fahrenheit or Celsius?: ";
        cin >> tempUnitInput;
        cout << endl << endl;

        if (tempUnitInput == tempUnit[0] || tempUnitInput == tempUnit[1])
        {
            cout << "What is the temp in Celsius? (Do not include unit): ";
            cin >> tempInput;
            cout << endl << endl;
            tempFahrenheit = (tempInput * 9.0) / 5.0 + 32;
            cout << setprecision(2) << fixed;
            cout << "The temperature is:" << setw(8) << tempFahrenheit << " degrees Fahrenheit" << endl << endl;
        }
        if (tempUnitInput == tempUnit[2] || tempUnitInput == tempUnit[3])
        {
            cout << "What is the temp in Fahrenheit? (Do not include unit): ";
            cin >> tempInput;
            cout << endl << endl;
            tempCelsius = (tempInput - 32) / 1.8;
            cout << setprecision(2) << fixed;
            cout << "The temperature is:" << setw(8) << tempCelsius << " degrees Celsius" << endl << endl;
        }
        }while (tempUnitInput != tempUnit[0] && tempUnitInput != tempUnit[1] && tempUnitInput != tempUnit[2] && tempUnitInput != tempUnit[3]);
    } 
        
    // If unit input is not listed in array "units", 
    // "Please check spelling and try again." << endl;
    
    return 0;
}