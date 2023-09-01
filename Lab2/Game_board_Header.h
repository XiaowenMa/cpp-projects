#pragma once
#include "GameHeader.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

struct game_piece {
	color c;
	string name;
	string where;
};

int printBoard(const vector<game_piece>& g, unsigned int col, unsigned int row);
int readFile(ifstream& f, unsigned int& col, unsigned int& row);
int readGamePieces(ifstream& f, vector<game_piece>& g, unsigned int col, unsigned int row);
//int printBoard(const vector<game_piece>& g, unsigned int col, unsigned int row);