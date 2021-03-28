// Brian Shipman
// Skill Practice Assignment 3
// Date: March 5, 2021

// Headers
 #include <iostream>
 #include <string>
 #include <cmath>
 #include <iomanip>
 using namespace std;

 // Function Prototypes
 void prompts(double[]);
 void kineticEnergy(double[]);
 void answer(double[]);

 int main()
 {
     cout << "This program calculates the kinetic energy of a moving object from user inputs" << endl << endl;

     double values[3];

     prompts(values);

     kineticEnergy(values);
    
     answer(values);

     return 0;
 }
 // Functions
 void prompts(double values[])
 {
     cout << "Object's mass in kilograms (kg) then press [ENTER]: ";
     cin >> values[0];
     cin.ignore();
     cout << endl;

     cout << "Object's velocity in meters per second (m/s) then press [Enter]: ";
     cin >> values[1];
     cin.ignore();
     cout << endl << endl;
 }

 void kineticEnergy(double values[])
 {
     values[2] = 0.5 * (values[0] * (pow(values[1], 2)));
 }

 void answer(double values[])
 {
     cout << setw(19) << "Values:" << endl;
     cout << setw(20) << "Mass: " << values[0] << " kg" << endl;
     cout << setw(20) << "Velocity: " << values[1] << " m/s" << endl;
     cout << fixed << showpoint << setprecision(3);
     cout << setw(20) << "Kinetic Energy: " << values[2] << " J" << endl;
 }