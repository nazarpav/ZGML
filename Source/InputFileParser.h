#pragma once
#include<fstream>
#include<string>
#include"StandartParser.h"
class InputFileParser
{
private:
	StandartParser parser;
public:
	const std::string ParseFromFileGetQueries(const std::string filePath);
	const std::string ParseFromFileGetInputData(const std::string filePath);
	const std::string ParseFromFileGetData(const std::string filePath);
};