// Lab3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Lab3Header.h"
#include <iostream>
using namespace std;

ostream& operator <<(ostream& out, const tic_tac_toe& p) {
	string print;
	for (int i = 4; i >= 0; i--) {
		out << i;
		for (int j = 0; j < p.cols; j++) {
			if (p.gameboard[i][j] == "") {
				out<< " ";
			}
			else {
				out<< p.gameboard[i][j];
			}
		}
		out << endl;
	}
	out << " 01234" << endl;
	return out;
}

enum values usage_message(char* s, char* parameter) {
	cout << "usage message:" << s << " " << parameter << endl;
	return wrong_number_of_command_line_argument;
}


int main(int argc, char **argv)
{
	if (argc != 2) {
		return usage_message(argv[0], "TicTacToe");
	}
	
	char tictactoe[] = "TicTacToe";
	if (strcmp(argv[1],tictactoe)!=0) {
		cout << "Wrong game name; Game name should be 'TicTacToe'." << endl;
		return wrong_game_name;//indicating wrong_game_name;
	}
	
	
	tic_tac_toe ttt;
	cout << "start" << endl;
	return ttt.play();
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
