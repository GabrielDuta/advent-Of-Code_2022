#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	string tmp;
	int count = 0;
	int max1 = 0, max2 = 0, max3 = 0;

	ifstream in("input.txt");

	// Solution 1: consider only the first if
	while(getline(in, tmp)) {
		// Check if the line is empty
		if(!tmp.size()) {
			if(count > max1) {
				max3 = max2;
				max2 = max1;
				max1 = count;
			}
			else if(count > max2) {
				max3 = max2;
				max2 = count;
			}
			else if(count > max3)
				max3 = count;
			count = 0;
		}
		else
			count += stoi(tmp);
	}

	cout << max1 + max2 + max3 << endl;
  	return 0;
}