#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

enum color { red, black, white, noColor, inValid };
enum values { success, fail_to_open, read_write_error, wrong_number_of_command_line_argument, cannot_read_file, cannot_extract, cannot_getline, no_well_formed_piece, out_of_size};
string aColor(enum color s);
enum color aString(string s);