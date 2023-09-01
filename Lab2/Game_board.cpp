
#include "Header.h"
#include "GameHeader.h"
#include "Game_board_Header.h"
using namespace std;


int readFile(ifstream& f, unsigned int& col, unsigned int& row) {//read gameboard dimensions
	string local;

	if (getline(f, local)) {
		istringstream in(local);
		if (in >> col) {
		}//do nothing
		else return cannot_extract;//return error message

		if (in >> row) {
		}//do nothing
		else return cannot_extract;//return error message
	}
	else {
		return cannot_getline;
	}

	//f.close();
	return success;//should i write successs or 0
}

int readGamePieces(ifstream & f,vector<game_piece> & g, unsigned int col, unsigned int row) {
	string read;
	string color;// color of game piece
	string name;//the name of the game piece
	string gameboard;//with which to display with when the gameboard is printed out
	unsigned int x;
	unsigned int y;
	enum color cr;

	int numOfSuccess = 0;

	while (getline(f, read)) {
		istringstream in(read);
		if (in >> color) {
			lowercase(color);
			cr = aString(color);
			if (cr != inValid) {
				if (in >> name) {
					if (in >> gameboard) {
						if (in >> x && x < col) {
							if (in >> y && y < row) {
								int index = col * y + x;
								g[index].c = cr;
								g[index].name = name;
								g[index].where = gameboard;
								numOfSuccess++;
							}
						}
					}
				}
			}
		}
	}
	if (numOfSuccess != 0)
		return success;
	else
		return no_well_formed_piece;
}

int printBoard(const vector<game_piece>& g, unsigned int col, unsigned int row) {//col=width; row=height
	if (col * row > unsigned(g.size())) {
		return out_of_size;//
	}
	else {
		for(int i = row - 1; i >= 0; i--) {
			string print;
			for (int j = 0; j < col; j++) {
				int index = col * i + j;
				print += g[index].where;
		
			}
			cout << print << endl;
		}
	}
	return success;
}