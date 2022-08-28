// g++ -std=c++11 -w -lm roman-con-v1.cpp -o roman-con
#include <iostream>
#include <chrono>
// import <vector>
// import <ranges>
#include <vector>
// #include <ranges>
#include <stdio.h>

#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"
#define BYTE_TO_BINARY(byte)  \
  (byte & 0x80 ? '1' : '0'), \
  (byte & 0x40 ? '1' : '0'), \
  (byte & 0x20 ? '1' : '0'), \
  (byte & 0x10 ? '1' : '0'), \
  (byte & 0x08 ? '1' : '0'), \
  (byte & 0x04 ? '1' : '0'), \
  (byte & 0x02 ? '1' : '0'), \
  (byte & 0x01 ? '1' : '0') 

using namespace std;

// Assumes little endian
void printBits(size_t const size, void const * const ptr)
{
    unsigned char *b = (unsigned char*) ptr;
    unsigned char byte;
    int i, j;
    
    for (i = size-1; i >= 0; i--) {
        for (j = 7; j >= 0; j--) {
            byte = (b[i] >> j) & 1;
            printf("%u", byte);
        }
    }
    puts("");
}

void print_binary(unsigned int number)
{
    if (number >> 1) {
        print_binary(number >> 1);
    }
    putc((number & 1) ? '1' : '0', stdout);
}

// 2 bytes
void EndianSwap (unsigned short& x)
{
	x = (x >> 8) | (x << 8);
}
// 4 bytes
void EndianSwap (unsigned int& x)
{
	x = (x >> 24) |
		((x << 8) & 0x00FF0000) |
		((x >> 8) & 0x0000FF00) |
		(x << 24);
}
// 8 bytes
void EndianSwap (unsigned long& x)
{
	x = (x >> 56) |
		((x << 40) & 0x00FF000000000000) |
		((x << 24) & 0x0000FF0000000000) |
		((x << 8)  & 0x000000FF00000000) |
		((x >> 8)  & 0x00000000FF000000) |
		((x >> 24) & 0x0000000000FF0000) |
		((x >> 40) & 0x000000000000FF00) |
		(x << 56);
}

/* check
 * check if a number is even
 * Params:
 *   n: number
 *
 * Return:
 *   0: odd
 *   1: even
 */
vector<int> checEvenInRange(vector<int> elements) {
	vector<int> ret;

	// for (int ele : elements | ranges::view::filter([](int ele) { ele % 2 == 0; })) {
	// 	ret.append(ele);
	// }
	return ret;
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
	vector<int> vec1{0, 1, 2, 5, 2, 6, 7, 18, 3, 9};
	
	for (auto &ele : checEvenInRange(vec1)) {
		cout << ele << endl;
	}

	return 0;
}