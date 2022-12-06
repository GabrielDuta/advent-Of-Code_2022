#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
using namespace std;

vector<stack<char>> crates;

void move(int, int, int);

int main() {
  	int crates_number, moves;
	int quantity = 0;
	int start = 0, end = 0;
	char tmp;

	ifstream in("input.txt");
	ofstream out("output.txt");

	in >> crates_number >> moves;
	crates.resize(crates_number);

	// Populate the stacks: in the file the format of a stack is: <quantity> <crates, char>
	for (int i = 0; i < crates_number; i++){
		in >> quantity;
		for (int f = 0; f < quantity; f++) {
			in >> tmp;
			crates[i].push(tmp);
		}
	}

	// Execute the moves; the file is clean of useless text
	for(int i = 0; i < moves; i++) {
		in >> quantity >> start >> end;
		move(quantity, start - 1, end - 1);
	}

	// Print the crates at the top
	for(int i = 0; i < crates_number; i++)
		out << crates[i].top();

  return 0;
}

/* Solution 1: remove the stack */
void move(int quantity, int start, int end) {
	stack<char> s;

	// Save the crates in the stack to move them without changing the order
	for(int i = 0; i < quantity; i++) {
		s.push(crates[start].top());
		crates[start].pop();
	}
	for(int i = 0; i < quantity; i++) { 
		crates[end].push(s.top());
		s.pop();
	}
}