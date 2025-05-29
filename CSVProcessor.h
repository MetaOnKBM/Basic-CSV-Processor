// By MetaOnKBM.
// Https://GitHub.com/MetaOnKBM/MetaOnKBM
// Basic CSV control.

#include <map>
#include <fstream>
#include <string>
#include <sstream>

#pragma once

// Writing full sentences in keys or values will not work, it will simply truncate everything after the first space.

template<typename keyType, typename valueType>

std::map<keyType, valueType> loadCSVToMap(const std::string& filePath)
{
	std::map<keyType, valueType> data;
	std::ifstream inFile(filePath);
	std::string currentLine;

	if (!inFile.is_open()) return {};

	while (std::getline(inFile, currentLine))
	{
		std::stringstream stringStream(currentLine);
		std::string keyString, valueString;

		std::getline(stringStream, keyString, ',');
		std::getline(stringStream, valueString);

		keyType key;
		valueType value;

		std::stringstream keyStream(keyString);
		std::stringstream valueStream(valueString);

		keyStream >> key;
		valueStream >> value;

		data[key] = value;
	}
	return data;
}

template<typename keyType, typename valueType>

bool saveMapToCSV(const std::map<keyType, valueType>& data, const std::string& filePath)
{
	std::ofstream outFile(filePath);
	if (!outFile.is_open()) return false;

	for (const auto& [key, value] : data)
	{
		outFile << key << ',' << value << '\n';
	}

	return true;
}