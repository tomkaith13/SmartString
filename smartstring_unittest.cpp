#include "SmartString.hpp"

int 
main() {
	//using namespace smartstring;
	using namespace std;
	SmartString s(" Hello   world !! !   ");	

	
	cout<<"split unit tests"<<endl;
	for(auto wrd : s.split()) {
		cout<<"word: "<<wrd<<endl;
	}
	

	cout<<"<<operator unit test"<<endl;
	cout<<"smart string s:"<<s<<endl;	

	cout<<"left trim unit test"<<endl;
	cout<<"left trimmed string:"<<"|"<<s.ltrim()<<endl;

	cout<<"right trim unit test"<<endl;
	cout<<"right trimmed string:"<<s.rtrim()<<"|"<<endl;

	cout<<"full trim unit test"<<endl;
	cout<<"fully trimmed string:"<<"|"<<s.trim()<<"|"<<endl;

	s.mutate_trim();
	cout<<"mutated smart string:"<<"|"<<s<<"|"<<endl;


	return(0);
}