#pragma once
#include "Game_board_Header.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
using namespace std;

enum names { Lab2, Header, argc };
enum values usage_message(char* s, char* parameter);
void lowercase(string& s);
int readFile(ifstream& f, unsigned int& col, unsigned int& row);
int readGamePieces(ifstream& f, vector<game_piece>& g, unsigned int col, unsigned int row);


