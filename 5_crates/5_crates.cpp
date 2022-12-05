#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

vector<stack<char>> crates;

void move(int, int, int);

int main() {
  	int crates_number, moves;
	int quantity = 0;
	int start = 0, end = 0;

	ifstream in("input.txt");
	ofstream out("output.txt");

	in >> crates_number >> moves;
	crates.resize(crates_number);

	for (int i = 0; i < crates_number; i++){
		in >> quantity;
		for (int f = 0; f < quantity; f++) {
			char tmp;
			in >> tmp;
			crates[i].push(tmp);
		}
	}
	for(int i = 0; i < moves; i++) {
		in >> quantity >> start >> end;
		move(quantity, start - 1, end - 1);
	}

	for(int i = 0; i < crates_number; i++)
		out << crates[i].top();

  return 0;
}

void move(int quantity, int start, int end) {
	stack<char> s;

	for(int i = 0; i < quantity; i++) {
		s.push(crates[start].top());
		crates[start].pop();
	}
	for(int i = 0; i < quantity; i++) { 
		crates[end].push(s.top());
		s.pop();
	}
}