// g++ -std=c++11 -w -lm roman-con-v1.cpp -o roman-con
#include <iostream>
#include <chrono>
#include <map>
#include <unordered_map>

using namespace std;

unsigned int factorial(unsigned int n) {
	if (n < 2)
        return 1;
    else if (n == 2)
        return n;
    else
        return n * factorial(n-1);
}

unordered_map<unsigned int, unsigned int> cache;
unsigned int factorialWithCache(unsigned int n) {
	if (n < 2)
        return 1;
    else if (n == 2)
        return n;
    else if (cache[n])
        return cache[n];
	cache[n] = n * factorialWithCache(n - 1);
	return cache[n];
}

/* checkSyntax
 * check if input string is a number format
 * Params:
 *   s: input string
 *
 * Return:
 *   0: number
 *   -1: syntax error
 */
char checkSyntax(string &s) {
	if (s[0] >= 30 && s[0] <= 57) {
		for (const char & c : s)
			if (c < 30 || c > 57)
				return -1;
		return 0;
	}
	return -1;
}

int main(int argc, string *argv)
{
	string n_s;

	cout << "Please input a unsigned integer number: ";
	cin >> n_s;

	auto start_time = std::chrono::high_resolution_clock::now();

	try {
		char check_c = checkSyntax(n_s);
		if ( check_c < 0) {
			cout << "Input is not in correct Syntax" << endl;
		} else if (check_c == 0) {
			int n = stoi(n_s);
			if (n <= 0)
					cout << "Input number must be > 0" << endl;
			else {
				cout << "The factorial of " << n << " is " << factorial(n) << endl;
				cout << "The factorialWithCache of " << n << " is " << factorialWithCache(n) << endl;
			}
		}
	}
	catch (const exception& e) {
		cout << "Exception: " << e.what() << endl;
	}

	auto finish_time = chrono::high_resolution_clock::now();
	auto dur = chrono::duration_cast<chrono::microseconds>(finish_time - start_time).count();
	cout << "Execution ticks: " << dur << endl;

	return 0;
}