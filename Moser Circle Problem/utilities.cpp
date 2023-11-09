#include "header.h"

// increments a vector by one
vector<int> increment(vector<int> vect) {
	vector<int> incrementer{ 1 };
	return addBigInts(incrementer, vect);
}

// remove extras from the front of the vector
vector<int> removeExtraZeros(vector<int> vect) {
	if (vect.size() > 1) {
		int x = vect.size() - 1;
		while (vect.size() > 0 && vect[x] == 0) {
			vect.pop_back();
			x--;
		}
	}
	return vect;
}

// prints the vector representation of a number as a normal-looking number
void printVectorNum(vector<int> vect) {
	vect = removeExtraZeros(vect);

	for (int i = vect.size() - 1; i >= 0; i--) {
		cout << vect[i];
	}
	cout << endl;
}

// prints the vector representation of a number as a normal-looking number INLINE
void printInlineVectorNum(vector<int> vect) {
	vect = removeExtraZeros(vect);

	for (int i = vect.size() - 1; i >= 0; i--) {
		cout << vect[i];
	}
}

// converts vector to integer
int vectorToInt(vector<int> vect) {
	string intStr;
	vect = removeExtraZeros(vect);
	for (int i = vect.size() - 1; i >= 0; i--) {
		intStr += to_string(vect[i]);
	}
	return atoi(intStr.c_str());
}

// converts integer to vector
vector<int> intToVector(int remainder) {
	vector<int> vect;
	string intStr = to_string(remainder);

	for (int i = intStr.length() - 1; i >= 0; i--) {
		vect.push_back(intStr[i] - '0');
	}

	vect = removeExtraZeros(vect);
	return vect;
}

// performs the Moser Formula
vector<int> getNumRegions(vector<int> n) {
	return addBigInts(addBigInts(choose(n, { 4 }), choose(n, { 2 })), { 1 });
}

// prints the console screen
void printScreen(int iterations, int n, vector<int> numRegions, vector<int> powerOfTwoSeeds, vector<vector<int>> powersOfTwo, int start, int subStart, int stop) {
	string estimateUnit, totalUnit;
	long long lastExecutionDuration = (stop - subStart) / double(CLOCKS_PER_SEC) * 1000;
	long long totalRunningTime = (stop - start) / double(CLOCKS_PER_SEC) * 1000;
	long long averageExecutionDuration = totalRunningTime / (n - 4);
	long long estimatedTimeRemaining = (iterations - n) * averageExecutionDuration;
	getFriendlyFormat(estimatedTimeRemaining, estimateUnit);
	getFriendlyFormat(totalRunningTime, totalUnit);

	system("CLS");
	cout << "---- CURRENT ----" << endl;
	cout << "n = " << n << endl;
	cout << "numRegions = ";
	printVectorNum(numRegions);

	cout << endl << "---- EXECUTION INFO ---- " << endl;

	cout << "Last Execution Duration (ms): " << lastExecutionDuration << endl;
	cout << "Average Execution Duration (ms): " << averageExecutionDuration << endl;
	cout << "Total Running Time (" << totalUnit << "): " << totalRunningTime << endl;
	cout << "Estimated Time Remaining (" << estimateUnit << "): " << estimatedTimeRemaining << endl;

	cout << endl << "---- POWERS OF TWO ---- " << endl;
	
	for (int i = 0; i < powerOfTwoSeeds.size(); i++) {
		cout << powerOfTwoSeeds[i] << ": ";
		printVectorNum(powersOfTwo[i]);
	}
}

// format time
void getFriendlyFormat(long long& time, string& unit) {
	if (time >= 360000) {
		time /= 360000;
		unit = "hr";
	} else if (time >= 60000) {
		time /= 60000;
		unit = "min";
	} else if (time >= 1000) {
		time /= 1000;
		unit = "s";
	} else {
		unit = "ms";
	}
}

