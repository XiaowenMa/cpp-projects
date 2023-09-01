#include "GameHeader.h"
using namespace std;



 string aColor(enum color s) {
	string r="invalid";
	switch (s) {
	case red:r = "red";
		break;
	case black:
		r = "black";
		break;
	case white:
		r = "white";
		break;
	case noColor:
		r = "nocolor";
		break;
	}
	return r;
}

enum color aString(string s) {
	if (s.find("red") != std::string::npos) {
		return red;
	}
	else if (s.find("black") != std::string::npos) {
		return black;
	}
	else if (s.find("white") != std::string::npos) {
		return white;
	}
	unsigned int count = 0;
	for (unsigned int i = 0; i < s.length();i++) {
		if(s[i] == 32)
		count++;	
	}
	if (count == s.length())
			return noColor;
	return inValid;
}