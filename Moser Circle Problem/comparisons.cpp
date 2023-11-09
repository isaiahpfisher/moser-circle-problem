#include "header.h"

// returns true if one and two represent the same integer value
bool equal(vector<int> one, vector<int> two) {
	one = removeExtraZeros(one);
	two = removeExtraZeros(two);

	// checks the easy case where the sizes differ
	if (one.size() != two.size()) return false;

	// compares the vectors digit by digit
	for (int i = 0; i < one.size(); i++) {
		if (one[i] != two[i]) return false;
	}

	return true; // default to true
}

// returns true if one is greater than two
bool greaterThan(vector<int> one, vector<int> two) {
	one = removeExtraZeros(one);
	two = removeExtraZeros(two);

	// checks for easy cases where sizes differ
	if (one.size() > two.size()) return true;
	if (one.size() < two.size()) return false;

	// compares the numers digit for digit (starting from large end of number)
	for (int i = one.size() - 1; i >= 0; i--) {
		if (one[i] < two[i]) return false; // return true if at any point one's digit < two's digit
		if (one[i] > two[i]) return true; // return false if at any point one's digit > two's digit
	}

	return false; // this is the case where the numbers are the exact same
}

// returns true if one is less than or equal to two
bool lessThanOrEqual(vector<int> one, vector<int> two) {
	one = removeExtraZeros(one);
	two = removeExtraZeros(two);

	// checks for easy cases where sizes differ
	if (one.size() > two.size()) return false;
	if (one.size() < two.size()) return true;

	// compares the numers digit for digit (starting from large end of number)
	for (int i = one.size() - 1; i >= 0; i--) {
		if (one[i] < two[i]) return true; // return true if at any point one's digit < two's digit
		if (one[i] > two[i]) return false; // return false if at any point one's digit > two's digit
	}

	return true; // this is the case where the numbers are the exact same
}

bool isPowerOfTwo(vector<int> val) {
	vector<int> two = { 2 };

	if (equal(val, two)) return true;
	if (val[0] % 2 != 0) return false;

	while (greaterThan(val, two)) {
		val = longDivideBigInts(val, two);
		if (val[0] % 2 != 0) return false;
	}

	return equal(val, two);
}