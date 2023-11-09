#include "header.h"

// main function
int main() {
	int iterations;
	int interval;
	vector<int> powerOfTwoSeeds;
	vector<vector<int>> powersOfTwo;

	cout << "How many iterations?" << endl;
	cin >> iterations;

	cout << endl << "Refresh every __ iterations:" << endl;
	cin >> interval;

	system("CLS");

	int start = clock();

	for (int n = 2; n <= iterations; n++) {
		int subStart = clock();
		vector<int> numRegions = getNumRegions(intToVector(n));
		int subStop = clock();
		double prevExecutionTime = (subStop - subStart) / double(CLOCKS_PER_SEC) * 1000;
		double totalTime = (subStop - start) / double(CLOCKS_PER_SEC) * 1000;

		if (isPowerOfTwo(numRegions)) {
			powerOfTwoSeeds.push_back(n);
			powersOfTwo.push_back(numRegions);
		}

		if (n % interval == 0) { printScreen(iterations, n, numRegions, powerOfTwoSeeds, powersOfTwo, start, subStart, subStop); };

	}

	return 0;
}