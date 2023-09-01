// Lab1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Header.h"
using namespace std;

enum values parse(vector<string>& v, char* c);
enum values usage_message(char* s);


enum values parse(vector<string>& v, char* c) {
	ifstream ifs;
	
	ifs.open(c);
	if (ifs.fail()) {
		return fail_to_open;
	}
	if (ifs.bad()) {
		return read_write_error;
	}

	if (ifs.is_open()) {
		string read;
		while (ifs >> read) {
			v.push_back(read);
		}
	}
	ifs.close();
	return success;
}

enum values usage_message(char*s) {
	cout <<"usage message:" << s << "input" << endl;
	return wrong_number_of_command_line_argument;
}


int main(int argc, char* argv[])
{
	if (argc != 2) {
		return usage_message(argv[0]);
	}
	vector<string> v;
	enum values r=parse(v, argv[1]);
	if (r != 0) {
		return r;
	}
	vector<int> integer;
	for (size_t i = 0; i < v.size(); i++) {
		int j = 0;
		char c = v[i].at(j);
		int n = 0;
		while(j<sizeof(v[i])&&isdigit(c)){
			n++;
			j++;
			}

		if (n == sizeof(v[i])) {
			istringstream in(v[i]);
			int count;
			in >> count;
			integer.push_back(count);
		}

		else
		{
			cout << v[i] << endl;
		}

		}

	for (size_t i = 0; i < integer.size(); i++) {
		cout << integer[i] << endl;
	}

	return success;
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
