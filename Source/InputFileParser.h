#pragma once
#include<fstream>
#include<string>
#include<sstream>
#include"StandartParser.h"
#include"ZGMLOperatorReturnValue.h"
class InputFileParser
{
private:
	StandartParser parser;
public:
	const bool ParseFromFileGetQueries(const std::string& filePath, std::vector<std::string>& queries, std::string& error);
	const std::string GetAllDataFromFile(const std::string filePath, bool& isCorrect);
	const std::string ParseFromFileGetInputData(const std::string filePath);
	const std::string ParseFromStringGetInputData(const std::string input);
	const bool ParseFromStringGetQueries(const std::string& input, std::vector<std::string>& queries, std::string& error) const;
};