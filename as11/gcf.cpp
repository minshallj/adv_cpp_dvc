// jacob minshall
// gcf.cpp
#include <iostream>
using namespace std;

int gcf(int, int);

int main()
{
	int num1, num2;

	cout << "Enter num 1\n? ";
	cin >> num1;
	cout << "Enter num 2\n? ";
	cin >> num2;
	
	cout << endl << "The gcf is " << gcf(num1, num2) << endl;
}

/*
 either 0 was passed in, or it got down to a modulus
 with the number 1 which returns 0, then 1 must be
 the lowest common factor
 otherwise modulo the last divisor with the current,
 then check if the remainder was 0 return the divisor
 otherwise call recursivley with the remainder as the
 current divisor, and the current divisor as the last
 divisor
*/
int gcf(int cur_divisor, int last_divisor)
{
	int remainder;

	if(last_divisor == 0 || cur_divisor == 0)
		return 1;
	remainder = last_divisor % cur_divisor;
	if(remainder == 0)
		return cur_divisor;
	else
		return gcf(remainder, cur_divisor);
}
