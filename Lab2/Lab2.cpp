// Lab1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Header.h"
#include "Game_board_Header.h"
#include "GameHeader.h"
using namespace std;


enum values usage_message(char*s, char* parameter) {
	cout <<"usage message:" << s <<" "<< parameter<< endl;
	return wrong_number_of_command_line_argument;
}


void lowercase(string & s) {
	for (int i = 0; i < s.length(); i++) {
		if (s.at(i) >= 65 && s.at(i) <= 90)
			s[i] += 32;
	}

	return;
}

int main(int argc, char* argv[])
{
	if (argc != 2) {
		return usage_message(argv[0],"filename");//if the user input is wrong
	}

	ifstream ifs;
	ifs.open(argv[1]);
	if (ifs.fail()) {
		cout << "fail_to_open" << endl;
		return 1;
	}
	if (ifs.bad()) {
		cout<<"read_write_error"<<endl;
		return 2;
	}

	if (ifs.is_open()) {
		unsigned int height;
		unsigned int width;

		//while (readFile(ifs,width,height) == cannot_extract) {
		//}

		int result = readFile(ifs, width, height);
		while (result == cannot_extract) {
			result = readFile(ifs, width, height);
		}
		if (result != 0) {
			cout << "cannot_getline" << endl;
			return result;
		}

		vector<game_piece> g;
		for (unsigned int i = 0; i < height * width; i++) {
			game_piece p = {noColor,""," "};
			g.push_back(p);
		}

		int outcome = readGamePieces(ifs, g, width, height);
		if (outcome != 0) {
			cout << "no_well_formed_pieces" << endl;
			return outcome;
		}
		else
			return printBoard(g, width, height);
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
