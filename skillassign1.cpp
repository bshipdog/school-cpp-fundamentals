#include <iostream>
using namespace std;
int main()
{
    double fenceHeight, fenceLength, fenceCoats, paintGallons, fenceArea, finalGallons;
    fenceHeight = 6;
    fenceLength = 100;
    fenceCoats = 2;
    paintGallons = 340;
    fenceArea = fenceHeight * fenceLength;
    finalGallons = ((fenceCoats * fenceArea) / (paintGallons));

    cout << "To paint " << fenceCoats << " coats on " << fenceArea << " square feet of fence, you will need ";
    cout << finalGallons << " gallons of paint." << endl;

    return 0;
}