#pragma once
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

enum gamepiece { X, O };
enum values { success, user_quits,no_more_spaces,wrong_number_of_command_line_argument,wrong_game_name};

class tic_tac_toe {
private:
	string gameboard[5][5];
	int rows = 5;
	int cols = 5;
	enum gamepiece {X,O};
	friend ostream& operator <<(ostream& out, const tic_tac_toe& p);

public:
	bool done() {
		enum gamepiece winner;
		//check if horizontal
		int countX;
		int countO;
		for (int i = 0; i <this->rows; i++) {
			countX = 0;
			countO = 0;
			for (int j = 0; j <this->cols; j++) {
				if (this->gameboard[i][j] == "X") {
					countX++;
				}
				else if (this->gameboard[i][j] == "O"){
					countO++;
				}
			}
			if (countX >= 3) {
				winner = X;
				cout << "winner is X" << endl;
				return true;
			}
			else if (countO >= 3) {
				winner = O;
				cout << "winner is O" << endl;
				return true;
			}
		}


		//check if vertical
		for (int j = 0; j < this->cols; j++) {
			countX = 0;
			countO = 0;
			for (int i = 0; i < this->rows; i++) {// why cannot this->gameboard->length
				if (this->gameboard[i][j] == "X") {
					countX++;
				}
				else if (this->gameboard[i][j] == "O") {
					countO++;
				}
			}
			if (countX >= 3) {
				winner = X;
				cout << "winner is X"<< endl;
				return true;
			}
			else if (countO >= 3) {
				winner = O;
				cout << "winner is O" << endl;
				return true;
			}
		}

		//check if diagonal part1
		 countX = 0;
		 countO = 0;
		for (int i = 1; i <= 3; i++) {
			if (this->gameboard[i][i] == "X") {
				countX++;
			}
			else if (this->gameboard[i][i] == "O") {
				countO++;
			}
		}
		if (countX >= 3) {
			winner = X;
			cout << "winner is X" << endl;
			return true;
		}
		else if (countO >= 3) {
			winner = O;
			cout << "winner is O" << endl;
			return true;
		}
			
		return false;
	}

	bool draw() {
		if (this->done()) {
			return true;
		}
		else {
			int emptyspace = 0;
			for (int i = 1; i <= 3; i++) {
				for (int j = 1; j <= 3; j++) {
					if (this->gameboard[i][j] == "")
						emptyspace++;
				}
			}
			if (emptyspace == 0) {//no winner but complete
				return true;
			}
		}
		return false;
	}

	int prompt(unsigned int& x, unsigned int& y) {
		cout << "Please enter the coordinate as 'x, y'(x and y should be from 1 to 3) or enter 'quit'" << endl;
		int a;
		int b;
		string input;
		cin >> input;

		if (input == "quit") {
			return 1;//representing quit
		}
		else if (input.find(",") != string::npos) {
			input.replace(input.find(","), 1, " ");//change the comman into a space

			istringstream in(input);
			if (in >> a && a >= 1 && a <=3) {
				x = (unsigned int)a;
			}
			else {
				cout << "Invalid Input" << endl;
				this->prompt(x, y);
			}
			if (in >> b && b >= 1 && b <=3&&this->gameboard[b][a]=="") {
				y = (unsigned int)b;
				return 0;//indicating success
			}
			else {
				cout << "Invalid Input" << endl;
				this->prompt(x, y);
			}
		}
		else {//reprompt the user to enter data
			cout << "Invalid Input" << endl;
			this->prompt(x, y);
		}
		return 0;
	}


	int turn() {
		unsigned int vertical;
		unsigned int horizontal;
		unsigned int& x = vertical;
		unsigned int& y = horizontal;
		enum gamepiece currentPlayer;
		int whoseTurn = 0;
		int numofturns = 0;
		string xmoves;
		string omoves;

		if (whoseTurn % 2 == 0) {
			currentPlayer = X;
			cout << "It's X's turn" << endl;
			cout << endl;
		}
		else {
			currentPlayer = O;
			cout << "It's O's turn" << endl;
			cout << endl;
		}

		int outcome = this->prompt(x, y);//repeatedly prompt the user until a valid one;first time

		while (outcome != 1 && this->gameboard[y][x] == "") {

			numofturns++;

			if (currentPlayer == X) {
				this->gameboard[y][x] = "X";
				xmoves = xmoves + to_string(x) + "," +to_string(y)+";";
				cout << *this << endl;
				cout <<"X: "<< xmoves << endl;

				cout << endl;
				currentPlayer=O;//change to the next player
			}
			else {
				this->gameboard[y][x] = "O";
				omoves = omoves + to_string(x) + "," + to_string(y)+";";
				cout << *this << endl;
				cout <<"O: "<< omoves << endl;
				cout << endl;
				currentPlayer = X;//change to the next player
			}
			if (this->done() == true) {
				return 0;
			}
			else if (this->draw() == true) {
				cout << "No more valid space to move into" << endl;
				cout << numofturns << " turns have been played" << endl;
				return 2;
			}

			if (currentPlayer == X) {
				cout << "It's X's turn" << endl;
			}
			else {
				cout << "It's O's turn" << endl;
			}
			outcome = this->prompt(x, y);//repeatedly prompt the user until a valid one
		}


		if (outcome == 1) {
			if (currentPlayer == X)
				cout << "Player X quits" << endl;
			else
				cout << "Player O quits" << endl;
			cout << numofturns << " turns have been played" << endl;
			return 1;
		}
		return outcome;
	}


	int play() {
		cout << *this << endl;
		if (this->done() == true) {
			cout << "some one wins" << endl;
			return 0;//someone wins
		}
		else if (this->draw() == true) {
			cout << "full" << endl;
			return 2;//indicating no more moves
		}

			int result = this->turn();
			return result;

	}
	
};

ostream& operator <<(ostream& , const tic_tac_toe& );