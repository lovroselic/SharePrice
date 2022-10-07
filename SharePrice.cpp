// https://www.codeabbey.com/index/task_view/share-price-volatility
//

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include "Console.h"
#include "CodeAbbey.h"
#define VERSION 0.02

using namespace std;

//vector<string> loadData(string name);

int main() {
	cout << "SharePrice v" << VERSION << "!\n\n";
	string path = "Input_demo.txt";
	vector<string> data = loadData(path);
	printVector(data);
}
