#include <iostream>
#include <fstream>
using namespace std;

int main() {
	char opp, me;
	int punteggio = 0;

	ifstream in("input.txt");
	ofstream out("output.txt");

	while(in >> opp >> me) {
		/*
		First part:
		switch (me) {
		case 'X': punteggio += 1;
			if(opp == 'A')
				punteggio += 3;
			else if(opp == 'C')
				punteggio += 6;
			break;
		case 'Y': punteggio += 2;
			if(opp == 'B')
				punteggio += 3;
			else if(opp == 'A')
				punteggio += 6;
			break;
		case 'Z': punteggio += 3;
			if(opp == 'C')
				punteggio += 3;
			else if(opp == 'B')
				punteggio += 6;
			break;
		}
		*/
		// Second part:
		switch (me) {
			case 'X':
				if(opp == 'A')
					punteggio += 3;
				else if(opp == 'B')
					punteggio += 1;
				else
					punteggio += 2;
				break;
			case 'Y': punteggio += 3;
				if(opp == 'A')
					punteggio += 1;
				else if(opp == 'B')
					punteggio += 2;
				else
					punteggio += 3;
				break;
			case 'Z': punteggio += 6;
				if(opp == 'A')
					punteggio += 2;
				else if(opp == 'B')
					punteggio += 3;
				else
					punteggio += 1;
				break;
		}
	}

	out << punteggio << endl;

  return 0;
}
