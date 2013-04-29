// jacob minshall
// pal.cpp
#include <iostream>
using namespace std;


int is_pal(string str);

int main() 
{
	string input;
	while(1) {
		cout << "please input string: ";
		cin >> input;

		if(input == "-1")
			break;
		if(is_pal(input))
			cout << "yes it is a palindrome";
		else
			cout << "that is not a palindrome";
		cout  << endl <<"-1 to stop, or palindrome to continue"<< endl;
	}
	cout << "Thank you for doing" << endl;
}


int is_pal(string str)
{
	if(str.size() == 1)
		return 1;
	if(str.size() == 2 && str[0] == str[1])
		return 1;
	if(str[0] == str[str.size() - 1])
		return is_pal(str.substr(1, str.size() - 2));
	else
		return 0;
}
