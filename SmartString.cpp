#include "SmartString.hpp"


SmartString::SmartString(char* charPtr, size_t n) {
	/* 
		The constructor will parse n characters from charPtr 
		and store it in smartString and smartCharPtr 
	*/	
	smartString = string(charPtr, n);
}


SmartString::SmartString(string s) {
	/*
		Constructor for storing any string as a parsed string.
	 */	
	smartString = s;	
}


string
SmartString::ltrim() {
	/*
		Returns a string with the left-hand side trimmed of all tabs and spaces
	*/

	size_t spaceNum=0;
	string newString;
	const char *ptr = smartString.c_str();	

	while(spaceNum != smartString.length() && (*ptr == ' ' || *ptr == '\t')) {
		ptr++;
		spaceNum++;
	}

	newString = string(ptr, smartString.length() - spaceNum);	
	return(newString);
}

string
SmartString::rtrim() {
	/*
		Returns a string with the right-hand side trimmed of all tabs and spaces
	*/
	string newString;
	size_t charCount = smartString.length() - 1;

	const char* ptr = smartString.c_str() + charCount;
	while((charCount != 0) && (*ptr == ' ' || *ptr == '\t')) {
		charCount--;
		ptr--;
	}

	newString = string(smartString.c_str(), charCount+1);
	return(newString);
}

string
SmartString::trim() {
	/*
		Returns a string both left and right hand side trimmed
	*/
	string ltrimmed = ltrim();
	string trimmed = SmartString(ltrimmed).rtrim();
	return(trimmed);
}

void
SmartString::mutate_trim() {
	/*
		Mutate the existing object to store a fully trimmed string
	*/
	string fully_trimmed = trim();
	smartString = fully_trimmed;
}

ostream& operator<<(ostream& os, const SmartString& s) {
	/*
		Friend function overloading the << operator to print 
		the string portion of the object
	*/
	os<<s.smartString;
	return os;
}

vector<string> 
SmartString::split(char delim) {
	/*
		Split the string based on the specified character 
		delimiter. The default delimiter is space.
		Finally, the split function returns a vector of strings
		containing the substring.
	*/
	vector<string> substrVector;
	stringstream ss (smartString);
	string substring;

	while(getline(ss, substring, delim)) {
		if (!substring.empty())
			substrVector.push_back(substring);
	}	
	return(substrVector);
}


