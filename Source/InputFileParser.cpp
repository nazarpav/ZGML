#include"InputFileParser.h"
const bool InputFileParser::ParseFromFileGetQueries(const std::string& filePath, std::vector<std::string>& queries, std::string& error)
{
	bool isCorrect;
	std::string res = GetAllDataFromFile(filePath, isCorrect);
	if (isCorrect) {
		ParseFromStringGetQueries(res, queries, error);
		return true;
	}
	else {
		error = res;
		return false;
	}
}
const std::string InputFileParser::GetAllDataFromFile(const std::string filePath, bool& isCorrect)
{
	std::ifstream inputFile(filePath);
	if (inputFile.is_open()) {
		std::string input;
		std::string line;
		while (std::getline(inputFile, line))input += line + "\n";
		inputFile.close();
		isCorrect = true;
		return input;
	}
	else {
		isCorrect = false;
		return "File not found!";
	}
}
const std::string InputFileParser::ParseFromFileGetInputData(const std::string filePath, bool& isCorrect)
{
	std::string res = GetAllDataFromFile(filePath, isCorrect);
	if (isCorrect) {
		res = ParseFromStringGetInputData(res, isCorrect);
		return res;
	}
	else {
		return res;
	}
}
const std::string InputFileParser::ParseFromStringGetInputData(const std::string input, bool& isCorrect)
{
	std::istringstream iss(input);
	std::string line;
	std::getline(iss, line);
	if (line == "") {
		isCorrect = false;
		return "Input is empty";
	}
	size_t indexBegin;
	size_t indexEnd;
	indexBegin = line.find_first_not_of(' ');
	if (indexBegin == std::string::npos) {
		isCorrect = false;
		return "Q or N not valid";
	}
	indexEnd = line.find(' ', indexBegin);
	if (indexBegin == std::string::npos) {
		isCorrect = false;
		return "Q or N not valid";
	}
	size_t inputDataStringCount;
	try {
		inputDataStringCount = std::stoul(line.substr(indexBegin, indexEnd));
	}
	catch (std::exception ex)
	{
		isCorrect = false;
		return "Q or N not valid";
	}
	std::string result;
	for (size_t i = 0; i < inputDataStringCount; i++) {
		getline(iss, line);
		result += line + "\n";
	}
	isCorrect = true;
	return result;
}
const bool InputFileParser::ParseFromStringGetQueries(const std::string& input, std::vector<std::string>& queries, std::string& error)const
{
	std::istringstream iss(input);
	std::string line;
	std::getline(iss, line);
	if (line == "") {
		error = "Input is empty";
		return false;
	}
	size_t indexBegin;
	size_t indexEnd;
	indexBegin = line.find_first_not_of(' ');
	if (indexBegin == std::string::npos) {
		error = "Q or N not valid";
		return false;
	}
	indexEnd = line.find(' ', indexBegin);
	if (indexBegin == std::string::npos) {
		error = "Q or N not valid";
		return false;
	}
	size_t inputDataStringCount;
	try {
		inputDataStringCount = std::stoul(line.substr(indexBegin, indexEnd));
	}
	catch (std::exception ex)
	{
		error = "Q or N not valid";
		return false;
	}
	indexBegin = line.find_first_not_of(' ', indexEnd);
	if (indexBegin == std::string::npos) {
		error = "Q or N not valid";
		return false;
	}
	indexEnd = line.find(' ', indexBegin);
	if (indexBegin == std::string::npos) {
		error = "Q or N not valid";
		return false;
	}
	size_t queriesStringCount;
	try {
		queriesStringCount = std::stoul(line.substr(indexBegin, indexEnd));
	}
	catch (std::exception ex)
	{
		error = "Q or N not valid";
		return false;
	}
	for (size_t i = 0; i < inputDataStringCount; i++) {
		getline(iss, line);
	}
	for (size_t i = 0; i < queriesStringCount; i++) {
		getline(iss, line);
		queries.push_back(line);
	}
	return true;
}