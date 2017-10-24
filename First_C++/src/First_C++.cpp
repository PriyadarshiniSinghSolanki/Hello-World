//============================================================================
// Name        : First_C++.cpp
// Author      : Priyadarshini Singh Solanki
// Version     :
// Copyright   : Your copyright notice
// Description :
//Write programs called PrintPatternX.cpp (where X from A to D) to print EACH of the following patterns.
//Use one "cout <<" for each line of outputs. End each line by printing an "endl".
// * * * * *      * * * * *     * * * * *         *
//  * * * * *     *       *      *     *         * *
// * * * * *      *       *       *   *         *   *
//  * * * * *     *       *        * *           * *
// * * * * *      * * * * *         *             *
//   (a)            (b)           (c)           (d)
//Print the above patterns using ONE "cout <<" statement.
//============================================================================

#if 0
#include <iostream>
using namespace std;
int main() {
	int i,j;
	cout << "HEllo" <<endl;
	for (i = 0; i < 5; ++i) {
		for (j = 0; j < 5; ++j) {
			if (i % 2)
				cout << " *";
			else
				cout << "* ";
		}
		cout << "" << endl;

	}
	return 0;
}


#define N 5
#include <iostream>
using namespace std;
int main() {
	int i, j;
	for (i = 0; i < N; ++i) {
		for (j = 0; j < N; ++j) {
			if ((i == 0) || (i == (N - 1)))
				cout << "* ";
			else {
				if ((j == 0) || (j == (N - 1)))
					cout << "* ";
				else
					cout << "  ";
			}
		}
		cout << "" << endl;
	}
	return 0;
}
#endif

#include <iostream>
using namespace std;
int main() {
	static int cnt = 5;
	while (cnt) {
		cout << "* * * * * " << endl;
		cnt--;
		if (!(cnt % 2))
			cout << " ";
	}

	return 0;
}
