// g++ -std=c++11 -w -lm roman-con-v1.cpp -o roman-con
#include <iostream>
#include <chrono>

#define ROMANARRLEN 13

using namespace std;

int decs_i[] = 		{1000, 900, 500,  400, 100,   90,  50,   40,  10,    9,   5,    4,   1};
string romans_s[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

string dec2Roman(int n) {
	string ret = "";

	for (int i = 0; i < ROMANARRLEN; i++)
		while (n - decs_i[i] >= 0) {
			n -= decs_i[i];
			ret += romans_s[i];
		}

	return ret;
}

int roman2Dec(string &s) {
	int ret = 0;
	string sub_s;

	for (int i = 0; i < s.length(); i++) {
		for (int j = 0; j < ROMANARRLEN; j++) {
			if (romans_s[j].length() == 2) {
				//~ toupper(s[i]);
				//~ toupper(s[i + 1]);
				sub_s = s.substr(i, 2);
				if (!sub_s.compare(romans_s[j])) {
					ret += decs_i[j];
					i++;
					break;
				}
			} else {
				//~ toupper(s[i]);
				if (romans_s[j][0] == s[i]) {
					ret += decs_i[j];
					break;
				}
			}
		}
	}

	return ret;
}

/* checkSyntax
 * check if input string is a number format or roman number format
 * Params:
 *   s: input string
 *
 * Return:
 *   0: number
 *   1: roman number
 *   -1: syntax error
 */
char checkSyntax(string &s) {
	if (s[0] >= 30 && s[0] <= 57) {
		for (const char & c : s)
			if (c < 30 || c > 57)
				return -1;
		return 0;
	}
	else if ((s[0] >= 65 && s[0] <= 90) || (s[0] >= 97 && s[0] <= 122)) {
		for (char & c : s) {
			toupper(c);
			int j;
			for (j = 0; j < ROMANARRLEN; j++)
				if (romans_s[j][0] == c) {
					break;
				}
			if (j == ROMANARRLEN)
				return -1;
		}
		return 1;
	}

	return -1;
}

int main(int argc, char *argv[])
{
	string n_s;

	cout << "Please input a unsigned integer number or roman number to convert: ";
	cin >> n_s;

	//~ auto start_time = std::chrono::high_resolution_clock::now();

	try {
		char check_c = checkSyntax(n_s);
		if ( check_c < 0) {
			cout << "Input is not in correct Syntax" << endl;
		} else if (check_c == 0) {
			int n = stoi(n_s);
			if (n <= 0)
					cout << "Input number must be > 0" << endl;
			else
				cout << "Roman number of " << n << " is " << dec2Roman(n) << endl;
		} else {
			cout << "Value of Roman number " << n_s << " is " << roman2Dec(n_s) << endl;
		}
	}
	catch (const exception& e) {
		cout << "Exception: " << e.what() << endl;
	}

	//~ auto finish_time = chrono::high_resolution_clock::now();
	//~ auto dur = chrono::duration_cast<chrono::microseconds>(finish_time - start_time).count();
	//~ cout << "Execution ticks: " << dur << endl;

	return 0;
}