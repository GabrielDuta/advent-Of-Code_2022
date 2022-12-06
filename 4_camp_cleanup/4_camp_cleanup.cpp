#include <iostream>
#include <fstream>
using namespace std;


int main() {
	int x1, x2, y1, y2;
	int count = 0;
	char tmp;
	ifstream in("input.txt");

	/* Part 1
	while(in >> x1 >> tmp >> x2 >> tmp >> y1 >> tmp >> y2) {
		// Check inclusions
		if((x1 >= y1 && x2 <= y2) || (y1 >= x1 && y2 <= x2))
			count++;
	}
	*/

	// Part 2
	while(in >> x1 >> tmp >> x2 >> tmp >> y1 >> tmp >> y2) {
		// Check overlappings
		if((y1 >= x1 && y1 <= x2) || (x1 >= y1 && x1 <= y2))
			count++;
	}

	cout << count << endl;
	return 0;
}
