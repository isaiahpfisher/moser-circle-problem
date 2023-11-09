#ifndef HEADER_H
#define HEADER_H
#pragma once

// Included Files
#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <ctime>
using namespace std;

// FUNCTION PROTOTYPES

// UTILITY
vector<int> increment(vector<int>);
vector<int> removeExtraZeros(vector<int>);
void printVectorNum(vector<int>);
void printInlineVectorNum(vector<int> vect);
vector<int> getNumRegions(vector<int> n);
int vectorToInt(vector<int> vect);
vector<int> intToVector(int remainder);
void printScreen(int iterations, int n, vector<int> numRegions, vector<int> powerOfTwoSeeds, vector<vector<int>> powersOfTwo, int start, int subStart, int end);
void getFriendlyFormat(long long& time, string& unit);

// MATH
vector<int> divideBigInts(vector<int>, vector<int>);
vector<int> longDivideBigInts(vector<int>, vector<int>);
vector<int> multiplyBigInts(vector<int>, vector<int>);
vector<int> addBigInts(vector<int>, vector<int>);
vector<int> subtractBigInts(vector<int>, vector<int>);
vector<int> factorial(vector<int> n);
vector<int> choose(vector<int> n, vector<int> r);

// COMPARISON
bool equal(vector<int>, vector<int>);
bool greaterThan(vector<int> one, vector<int> two);
bool lessThanOrEqual(vector<int> one, vector<int> two);
bool isPowerOfTwo(vector<int>);


#endif
