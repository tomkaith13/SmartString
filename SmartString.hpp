#ifndef __SMARTSTRING_HPP__
#define __SMARTSTRING_HPP__
#include <iostream>
#include <cstring>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class SmartString {	
	string smartString;
	
public:
	SmartString(char*, size_t);
	SmartString(string);
	string ltrim();
	string rtrim();
	string trim();
	void mutate_trim();	
	vector<string> split(char delim = ' ');	
	friend ostream& operator<<(ostream&, const SmartString&);
};


#endif
