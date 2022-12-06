#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int main() {
	string s,s2, s3;
	int prio_sum = 0;

	ifstream in("input.txt");

	/* Solution 1
	while(in >> s) {
		// Divide the string in two substrings
		s2 = s.substr(0, s.length() / 2);
		s3 = s.substr(s.length() / 2);

		// Check if the character is present in the other string; if find() returns -1 the character is not present
		for(int i = 0; i < s2.length(); i++)
			if(s3.find(s2[i]) != -1) {
				// calculate the value
				if(s[i] >= 'a' && s[i] <= 'z')
					prio_sum += s[i] - 'a' + 1;
				else
					prio_sum += s[i] - 'A' + 27;
				break;
			}
	}
	*/
	// Solution 2
	while(in >> s) {
		in >> s2 >> s3;
		for(int i = 0; i < s.size(); i++)	
			// Check if the character is present in the other strings; if find() returns -1 the character is not present
			if(s2.find(s[i]) != -1 && s3.find(s[i]) != -1) {
				// calculate the value
				if(s[i] >= 'a' && s[i] <= 'z')
					prio_sum += s[i] - 'a' + 1;
				else
					prio_sum += s[i] - 'A' + 27;
				break;
			}
	}

	cout << prio_sum << endl;
  	return 0;
}
