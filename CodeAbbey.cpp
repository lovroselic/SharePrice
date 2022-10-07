/*
selection of helper functions
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include "CodeAbbey.h"

std::vector<std::string> loadData(std::string name) {
	try {
		std::ifstream file;
		std::string line;
		std::vector<std::string> data;
		file.open(name);
		if (!file) {
			throw std::runtime_error("Could not open file: " + name);
		}
		while (std::getline(file, line)) {
			data.push_back(line);
		}

		file.close();
		return data;
	}

	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}