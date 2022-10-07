// https://www.codeabbey.com/index/task_view/share-price-volatility
//

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include "Console.h";

using namespace std;

vector<string> loadData(string name);

int main() {
	cout << "SharePrice V0.01!\n\n";
	//data read
	string path = "Input_demo.txt";
	vector<string> data = loadData(path);
	//end data

	printVector(data);
}

vector<string> loadData(string name) {
	try {
		ifstream file;
		string line;
		vector<string> data;
		file.open(name);
		if (!file) {
			throw runtime_error("Could not open file.");
		}
		while (getline(file, line)) {
			data.push_back(line);
		}

		file.close();
		return data;
	}

	catch (exception& e) {
		cerr << e.what() << endl;
	}
}