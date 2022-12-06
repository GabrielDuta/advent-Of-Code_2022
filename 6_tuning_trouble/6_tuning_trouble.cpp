#include <iostream>
#include <fstream>
#include <unordered_map>
using namespace std;

// Complexity O(n), n = characters in the considered string
int main() {
	unordered_map<char, int> map; // used to save the position of the last time a character has been encountered
	int count = 0; // counts the different characters considered
	int i = 0, j = 0; // pointers to the start and end of the considered substring
	string val; // the whole string
	ifstream in("input.txt");

	in >> val;

	// Part 1: put 'count < 4'
	while(j < val.size() && count < 14) {
		/* Check if the element is already present in the considered substring */
		if(map.count(val[j]) > 0) {
			if(map[val[j]] >= i) {
				count -= (map[val[j]] - i + 1); // remove from the count the elements elimineted from the substring
				i = map[val[j]] + 1;
			}
		}
		map[val[j]] = j;
		j++;
		count++;
	}
	cout << j << endl;

  	return 0;
}