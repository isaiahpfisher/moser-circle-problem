#include "header.h"

// adds two vectors together
vector<int> addBigInts(vector<int> one, vector<int> two) {

	vector<int> greaterNum = (one.size() > two.size() ? one : two); // the bigger of the two adddends
	vector<int> smallerNum = (one.size() > two.size() ? two : one); // the smaller of the two addends
	vector<int> resultNum; // final answer to be returned
	bool hasExtraOne = false;

	// equalizes length of addends with 0s
	while (smallerNum.size() < greaterNum.size()) {
		smallerNum.push_back(0);
	}

	// adds the two numbers together one element at a time
	for (int i = 0; i < smallerNum.size(); i++) {
		int sum = smallerNum[i] + greaterNum[i];
		if (sum > 9) {
			sum -= 10;

			if (i < smallerNum.size() - 1) {
				greaterNum[i + 1] += 1;
			}
			else {
				hasExtraOne = true;
			}
		}
		resultNum.push_back(sum);
		if (hasExtraOne) resultNum.push_back(1);
	}

	return resultNum;
}

// subtracts vector r from vector n
vector<int> subtractBigInts(vector<int> n, vector<int> r) {
	vector<int> resultNum; // final answer to be returned

	// equalizes the size of the vectors with 0s
	while (r.size() < n.size()) {
		r.push_back(0);
	}

	// subtracts the numbers one element at time
	for (int i = 0; i < r.size(); i++) {
		int sum = n[i] - r[i];
		if (sum < 0) {
			sum += 10;
			n[i + 1] -= 1;

		}
		resultNum.push_back(sum);
	}

	resultNum = removeExtraZeros(resultNum);
	return resultNum;
}

// multiplies two vectors together
vector<int> multiplyBigInts(vector<int> one, vector<int> two) {
	vector<int> greaterNum = (one.size() > two.size() ? one : two); // greater of the two factors
	vector<int> smallerNum = (one.size() > two.size() ? two : one); // smaller of the two factors
	vector<int> resultSum = { 0 }; // final answer to be returned

	// multiplies the two numbers in the old-fashioned "long multiplication" way
	for (int i = 0; i < smallerNum.size(); i++) {
		vector<int> tempSum(greaterNum.size() * 2, 0); // product of current place value in multiplication process

		// multiplies a single digit from the smaller factor by the larger factor
		for (int j = 0; j < greaterNum.size(); j++) {
			int product = smallerNum[i] * greaterNum[j];

			if (tempSum[j + i] + product > 9) {
				if (tempSum[j + i] + (product % 10) > 9) {
					tempSum[j + i] = ((tempSum[j + i] + (product % 10)) % 10);
					tempSum[j + i + 1] += (product / 10) + 1;
				}
				else {
					tempSum[j + i] += (product % 10);
					tempSum[j + i + 1] += (product / 10);
				}
			} else {
				tempSum[j + i] += product;
			}
		}

		// adds the sum of the current place value in the process to the total sum
		resultSum = addBigInts(resultSum, tempSum);
	}

	resultSum = removeExtraZeros(resultSum);
	return resultSum;
}

// divides the numerator vector by the denominator vector (subtractive method)
vector<int> divideBigInts(vector<int> numerator, vector<int> denominator) {
	vector<int> resultNum = { 0 }; // final answer to be returned
	vector<int> currentNum = { 0 }; // current number that will build up to the numerator (always a multiple of denominator)
	
	// adds numerator to currentNum as much as possible without going over numerator
	while (lessThanOrEqual(addBigInts(currentNum, denominator), numerator)) {
		currentNum = addBigInts(denominator, currentNum);
		resultNum = increment(resultNum);
	}

	return resultNum;
}

// divides the numerator vector by the denominator vector (long division method)
vector<int> longDivideBigInts(vector<int> numerator, vector<int> denominator) {
	vector<int> quotient; // final answer to be returned
	vector<int> dividend; // the current thing being divided

	// finds the first dividend (the smallest part of the numerator than can be divided into by the denominator)
	while (!lessThanOrEqual(denominator, dividend)) {
		dividend.insert(dividend.begin(), numerator[numerator.size() - 1]);
		numerator.pop_back();
	}

	// calculates the quotient
	while (dividend.size() > 0) {
		
		// divide dividend by denominator to get part of answer
		int answer = divideBigInts(dividend, denominator)[0];
		quotient.insert(quotient.begin(), answer);

		// gets the remainder (dividend - (answer * denominator))
		vector<int> remainder = subtractBigInts(dividend, multiplyBigInts(intToVector(answer), denominator));

		// bring down next digit from numerator to end of remainder
		if (numerator.size() > 0) {
			int nextDigit = numerator[numerator.size() - 1];
			numerator.pop_back();
			remainder.insert(remainder.begin(), nextDigit);
			dividend = remainder;
		} else { // if numerator is empty, we're done. set dividend to empty vector to fail while loop.
			dividend = {};
		}
	}

	return quotient;
}

// returns the factorial of vector representation of integer n
vector<int> factorial(vector<int> n) {
	vector<int> factorial = { 1 }; // the final answer to be returned
	
	// multiplies all numbers from 1 to n to determine the factorial
	for (vector<int> i = { 1 }; lessThanOrEqual(i, n); i = increment(i)) {
		factorial = multiplyBigInts(factorial, i);
	}

	factorial = removeExtraZeros(factorial);
	return factorial;
}

// returns the answer to n choose r
 vector<int> choose(vector<int> n, vector<int> r) {

	 if (equal(r, n)) return { 1 };
	 if (lessThanOrEqual(n, r)) return { 0 };

	 vector<int> numerator = { 1 }; // numerator of choose formula
	 vector<int> denominator = factorial(r); // denominator of choose formula
	 vector<int> one = { 1 }; // vector represenation of ONE

	 // calculates the part of the numerator that isn't canceled out by part of the denominator
	for (vector<int> i = addBigInts(subtractBigInts(n, r), one); lessThanOrEqual(i, n); i = increment(i)) {
		numerator = multiplyBigInts(numerator, i);
	}

	 return longDivideBigInts(numerator, denominator); // calculates final answer
 }