// driver.cpp
// jacob minshall
#include <iostream>
#include "Float_array.h"
using namespace std;

int main()
{
	int choice = 1, index;
	float value;
	Float_array obj(2);
	while(choice) {
		cout << "Choices:\n(1) store a number in any element of the array\n(2) retrieve a number from any element of the array\n(3) return the highest value stored in the array\n(4) return the lowest value stored in the array\n(5) return the average of the array\n(0) to exit, anything else will be ignored\n\n? ";

		cin >> choice;
		switch(choice) {
		case 1:
			cout << "value: ";
			cin >> value;
			cout << "index(" << obj.get_fill_len() << "): ";
			cin >> index;
			obj.add_member(value, index);
			break;
		case 2:
			cout << "index: ";
			cin >> index;
			cout << "The number is " << obj.return_member(index) << endl;
			break;
		case 3:
			cout << "max is " << obj.max() << endl;
			break;
		case 4:
			cout << "min is " << obj.min() << endl;
			break;
		case 5:
			cout << "mean is " << obj.mean() << endl;
			break;
		}
	}//if choice was 0, it will break

	return 0;
}
