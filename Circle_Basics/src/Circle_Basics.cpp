/*============================================================================
 // Name        : Circle_Basics.cpp
 // Author      : Priyadarshini Singh Solanki
 // Version     :
 // Copyright   : Your copyright notice
 // Description : Hello World in C++, Ansi-style

 Prompt user for the radius of a circle and compute its area and circumference
 (CircleComputation.cpp)

 Enter the radius: 1.2
 The radius is: 1.2
 The area is: 4.52389
 The circumference is: 7.53982
 ============================================================================*/

#include <iostream>
using namespace std;
#define PI 3.14159265
int main() {
	double radius, area, circumference;
	cout << "Enter the radius: ";
	cin >> radius;
	area = PI * radius * radius;
	circumference = 2 * PI * radius;
	cout << "The radius is: " << radius << endl;
	cout << " The area is: " << area << endl;
	cout << "The circumference is: " << circumference << endl;

	return 0;
}
