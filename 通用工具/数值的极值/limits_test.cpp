#include <iostream>
#include <limits>
#include <string>
using namespace std;


int main() {
	cout << boolalpha;
	cout << "max(short): " << numeric_limits<short>::max() << endl;
	cout << "max(int): " << numeric_limits<int>::max() << endl;
	cout << "max(long): " << numeric_limits<long>::max() << endl;
	cout << "max(long long): " << numeric_limits<long long>::max() << endl;
	cout << "max(float): " << numeric_limits<float>::max() << endl;
	cout << "max(double): " << numeric_limits<double>::max() << endl;
	cout << "max(long double): " << numeric_limits<long double>::max() << endl;


	cout << "min(short): " << numeric_limits<short>::min() << endl;
	cout << "min(int): " << numeric_limits<int>::min() << endl;
	cout << "min(long): " << numeric_limits<long>::min() << endl;
	cout << "min(long long): " << numeric_limits<long long>::min() << endl;
	cout << "min(float): " << numeric_limits<float>::min() << endl;
	cout << "min(double): " << numeric_limits<double>::min() << endl;
	cout << "min(long double): " << numeric_limits<long double>::min() << endl;

	cout << "is_signed(char): " << numeric_limits<char>::is_signed << endl;
	cout << "is_specialized(string): " << numeric_limits<string>::is_specialized << endl;

	return 0;
}