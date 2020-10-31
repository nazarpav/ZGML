#pragma once
#include<fstream>
#include<string>
#include"StandartParser.h"
#include"ZGMLOperatorReturnValue.h"
class InputFileParser
{
private:
	StandartParser parser;
public:
	const bool ParseFromFileGetQueries(const std::string filePath, std::vector<std::string>& queries, std::string& error);
	const std::string ParseFromFileGetInputData(const std::string filePath);
};