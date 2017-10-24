/*
 ============================================================================
 Name        : Mathematical_expression.cpp
 Author      : Priyadarshini Singh Solanki
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C++, Ansi-style
 Enter first integer: 99
 Enter second integer: 4
 The sum is: 103
 The difference is: 95
 The product is: 396
 The quotient is: 24
 ============================================================================
 */

#include <iostream>
using namespace std;

int main() {
	int num1, num2;
	double quotient;
	float a = 78.99;
	a=a+8;
	/*cout << "Enter first integer: ";
	 cin >> num1;
	 cout << "Enter second integer: ";
	 cin >> num2;*/
	cout << "Enter 2 integer value: ";
	cin >> num1 >> num2;
	cout << "The sum is: " << num1 + num2 << endl;
	cout << "The difference is: " << num1 - num2 << endl;
	cout << "The product is: " << num1 * num2 << endl;
	cout << "The quotient is: " << num1 / num2 << endl;

	++num1;    // Increment the value stored in variable number1 by 1
			   // same as "number1 = number1 + 1"
	--num2;    // Decrement the value stored in variable number2 by 1
			   // same as "number2 = number2 - 1"
	cout << "number1 after increment is " << num1 << endl;
	cout << "number2 after decrement is " << num2 << endl;

	quotient = num1 / num2;
	cout << "The new quotient of " << num1 << " and " << num2 << " is "
			<< quotient << endl;

	return 0;
}
