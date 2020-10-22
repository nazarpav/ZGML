#include"InputFileParser.h"
const std::string InputFileParser::ParseFromFileGetQueries(const std::string filePath)
{
	std::string line;
	std::ifstream inputFile(filePath);
	std::string spliter(" ");
	std::string queries("");
	std::vector<std::string>queriesVector;
	if (inputFile.is_open())
	{
		size_t N;
		size_t Q;
		getline(inputFile, line);
		auto spliterIndex = line.find(spliter);
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
			queries += line + "\n";
		}
		inputFile.close();
	}
	else {
		return "File not found!";
	}
	return queries;
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
		auto Nstr = line.substr(0, spliterIndex);
		N = std::stoi(Nstr);
		for (size_t i = 0; i < N; i++)
		{
			getline(inputFile, line);
			outInputData += line+"\n";
		}
		inputFile.close();
	}
	else {
		return "File not found!";
	}
	return outInputData;
}

const std::string InputFileParser::ParseFromFileGetData(const std::string filePath)
{
	std::string line;
	std::ifstream inputFile(filePath);
	std::string spliter(" ");
	std::string inputData("");
	std::vector<std::string>queriesVector;
	if (inputFile.is_open())
	{
		size_t N;
		size_t Q;
		getline(inputFile, line);
		auto spliterIndex = line.find(spliter);
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
			inputData += line;
		}
		for (size_t i = 0; i < Q; i++)
		{
			getline(inputFile, line);
			queriesVector.push_back(std::string(line));
		}
		inputFile.close();
	}
	else {
		return "File not found!";
	}
	std::string outData;
	for (auto val : queriesVector)
	{
		outData += parser.parse(inputData, val) + "\n";
	}
	return outData;
}
