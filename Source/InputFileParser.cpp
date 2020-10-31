#include"InputFileParser.h"
const bool InputFileParser::ParseFromFileGetQueries(const std::string filePath, std::vector<std::string>& queries, std::string& error)
{
	std::string line;
	std::ifstream inputFile(filePath);
	std::string spliter(" ");
	if (inputFile.is_open())
	{
		size_t N;
		size_t Q;
		getline(inputFile, line);
		auto spliterIndex = line.find(spliter);
		if (spliterIndex == std::string::npos || spliterIndex == 0)
		{
			error = "Q or N not valid";
			return false;
		}
		auto Nstr = line.substr(0, spliterIndex);
		N = std::stoi(Nstr);
		auto spliterIndexEnd = line.find(spliter, spliterIndex + spliter.size());
		if (spliterIndexEnd == std::string::npos)
			spliterIndexEnd = line.size();
		auto Qstr = line.substr(spliterIndex + spliter.size(), spliterIndexEnd);
		Q = std::stoi(Qstr);
		for (size_t i = 0; i < N; i++)
		{
			getline(inputFile, line);
		}
		for (size_t i = 0; i < Q; i++)
		{
			getline(inputFile, line);
			queries.push_back(line);
		}
		inputFile.close();
	}
	else {
		error = "File not found";
		return false;
	}
	return true;
}
const std::string InputFileParser::ParseFromFileGetInputData(const std::string filePath)
{
	std::string line;
	std::ifstream inputFile(filePath);
	std::string spliter(" ");
	std::string outInputData("");
	if (inputFile.is_open())
	{
		size_t N;
		getline(inputFile, line);
		auto spliterIndex = line.find(spliter);
		if (spliterIndex == 0)
		{
			return "N not valid";
		}
		else if (spliterIndex == std::string::npos)
		{
			spliterIndex = line.size();
		}
		auto Nstr = line.substr(0, spliterIndex);
		N = std::stoi(Nstr);
		for (size_t i = 0; i < N; i++)
		{
			getline(inputFile, line);
			outInputData += line + "\n";
		}
		inputFile.close();
	}
	else {
		return "File not found!";
	}
	return outInputData;
}

