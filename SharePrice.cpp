// https://www.codeabbey.com/index/task_view/share-price-volatility
//

#include <iostream>
#include <vector>
#include <string>
#include "Console.h"
#include "CodeAbbey.h"
#include "LS_library.h";
#define VERSION 1.0

using namespace std;

int main() {
	cout << "SharePrice v" << VERSION << "!\n\n";
	string path = "Input_test.txt";
	vector<string> raw_data = loadData(path);
	int numberOfLines = stoi(raw_data.at(0));
	vector<string> data(raw_data.begin() + 1, raw_data.end());

	//unpack
	const int DAZA_SIZE = 14;
	vector<string> shares;
	vector<vector<int>> share_data(numberOfLines, vector<int>(DAZA_SIZE, 0));

	for (int i = 0; i < data.size(); i++) {
		string line = data[i];
		vector<string> split = splitString(line, " ");
		shares.push_back(split.at(0));
		for (int c = 1; c < split.size(); c++) {
			share_data[i][c - 1] = stoi(split.at(c));
		}
	}

	//unpack end
	printVector(shares);
	print2DVector(share_data);

	vector<string> solution;

	for (int i = 0; i < shares.size(); i++) {
		double provision = average(share_data[i]) * 0.01;
		double stdev = st_dev(share_data[i]);
		const double criteria = 4.0;
		double factor = stdev / provision;
		bool buy = factor >= criteria;
		cout << shares[i] << ": " << "provision: " << provision << " stdev: " << stdev;
		cout << " F: " << factor << " Buy: " << boolalpha << buy;
		cout << endl;
		if (buy) {
			solution.push_back(shares[i]);
		}
	}

	string final_solution = joinVector(solution, " ");
	cout << endl;
	cout << "Solution: " << final_solution << endl;
}
