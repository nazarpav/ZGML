#include<iostream>
#include<chrono>
#include<ctime>
#include<memory>
#include<string>
#include<vector>
#include"BaseZGMLOperator.h"
#include"DotOperator.h"
#include"TildeOperator.h"
#include"Parser.h"
#include <fstream>

int main()
{
	srand(time(0));
	std::string inputData;
	std::string line;
	std::ifstream inputFile("file.txt");
	if (inputFile.is_open())
	{
		while (getline(inputFile, line))
		{
			inputData += line;
		}
		inputFile.close();
	}

	const std::string query("tag.tag.tag2.tag2.tag2.tag2.tag2.tag2.tag2.tag2.tag2.tag2.tag2.tag2.tag2.tag2.tag2.tag2.tag2.tag2.tag2.tag2.tag2.tag2.tag2.tag2.tag2.tag2.tag2.tag2.tag2.tag2~attr");
#pragma region hide
	std::vector<std::shared_ptr<BaseZGMLOperator>> useSymbols;
	useSymbols.push_back(std::make_shared<DotOperator>());
	useSymbols.push_back(std::make_shared<TildeOperator>());
	std::shared_ptr<BaseZGMLOperator> baseSymbol = std::make_shared<DotOperator>();
#pragma endregion
	Parser p;
	std::chrono::steady_clock::time_point start = std::chrono::high_resolution_clock::now();
	/*p.parse(inputData, query, useSymbols, baseSymbol);
	p.parse(inputData, query, useSymbols, baseSymbol);
	p.parse(inputData, query, useSymbols, baseSymbol);
	p.parse(inputData, query, useSymbols, baseSymbol);
	p.parse(inputData, query, useSymbols, baseSymbol);
	p.parse(inputData, query, useSymbols, baseSymbol);
	p.parse(inputData, query, useSymbols, baseSymbol);
	p.parse(inputData, query, useSymbols, baseSymbol);
	p.parse(inputData, query, useSymbols, baseSymbol);
	p.parse(inputData, query, useSymbols, baseSymbol);
	p.parse(inputData, query, useSymbols, baseSymbol);
	p.parse(inputData, query, useSymbols, baseSymbol);
	p.parse(inputData, query, useSymbols, baseSymbol);
	p.parse(inputData, query, useSymbols, baseSymbol);
	p.parse(inputData, query, useSymbols, baseSymbol);
	p.parse(inputData, query, useSymbols, baseSymbol);
	p.parse(inputData, query, useSymbols, baseSymbol);
	p.parse(inputData, query, useSymbols, baseSymbol);
	p.parse(inputData, query, useSymbols, baseSymbol);
	p.parse(inputData, query, useSymbols, baseSymbol);
	p.parse(inputData, query, useSymbols, baseSymbol);
	p.parse(inputData, query, useSymbols, baseSymbol);
	p.parse(inputData, query, useSymbols, baseSymbol);
	p.parse(inputData, query, useSymbols, baseSymbol);
	p.parse(inputData, query, useSymbols, baseSymbol);
	p.parse(inputData, query, useSymbols, baseSymbol);
	p.parse(inputData, query, useSymbols, baseSymbol);
	p.parse(inputData, query, useSymbols, baseSymbol);
	p.parse(inputData, query, useSymbols, baseSymbol);
	p.parse(inputData, query, useSymbols, baseSymbol);
	p.parse(inputData, query, useSymbols, baseSymbol);
	p.parse(inputData, query, useSymbols, baseSymbol);
	p.parse(inputData, query, useSymbols, baseSymbol);
	p.parse(inputData, query, useSymbols, baseSymbol);
	p.parse(inputData, query, useSymbols, baseSymbol);
	p.parse(inputData, query, useSymbols, baseSymbol);
	p.parse(inputData, query, useSymbols, baseSymbol);
	p.parse(inputData, query, useSymbols, baseSymbol);
	p.parse(inputData, query, useSymbols, baseSymbol);
	p.parse(inputData, query, useSymbols, baseSymbol);
	p.parse(inputData, query, useSymbols, baseSymbol);
	p.parse(inputData, query, useSymbols, baseSymbol);
	p.parse(inputData, query, useSymbols, baseSymbol);
	p.parse(inputData, query, useSymbols, baseSymbol);
	p.parse(inputData, query, useSymbols, baseSymbol);
	p.parse(inputData, query, useSymbols, baseSymbol);
	p.parse(inputData, query, useSymbols, baseSymbol);
	p.parse(inputData, query, useSymbols, baseSymbol);
	p.parse(inputData, query, useSymbols, baseSymbol);
	p.parse(inputData, query, useSymbols, baseSymbol);
	p.parse(inputData, query, useSymbols, baseSymbol);
	p.parse(inputData, query, useSymbols, baseSymbol);
	p.parse(inputData, query, useSymbols, baseSymbol);
	p.parse(inputData, query, useSymbols, baseSymbol);
	p.parse(inputData, query, useSymbols, baseSymbol);
	p.parse(inputData, query, useSymbols, baseSymbol);
	p.parse(inputData, query, useSymbols, baseSymbol);
	p.parse(inputData, query, useSymbols, baseSymbol);
	p.parse(inputData, query, useSymbols, baseSymbol);
	p.parse(inputData, query, useSymbols, baseSymbol);
	p.parse(inputData, query, useSymbols, baseSymbol);
	p.parse(inputData, query, useSymbols, baseSymbol);
	p.parse(inputData, query, useSymbols, baseSymbol);
	p.parse(inputData, query, useSymbols, baseSymbol);
	p.parse(inputData, query, useSymbols, baseSymbol);
	p.parse(inputData, query, useSymbols, baseSymbol);
	p.parse(inputData, query, useSymbols, baseSymbol);
	p.parse(inputData, query, useSymbols, baseSymbol);
	p.parse(inputData, query, useSymbols, baseSymbol);
	p.parse(inputData, query, useSymbols, baseSymbol);
	p.parse(inputData, query, useSymbols, baseSymbol);
	p.parse(inputData, query, useSymbols, baseSymbol);
	p.parse(inputData, query, useSymbols, baseSymbol);
	p.parse(inputData, query, useSymbols, baseSymbol);
	p.parse(inputData, query, useSymbols, baseSymbol);
	p.parse(inputData, query, useSymbols, baseSymbol);
	p.parse(inputData, query, useSymbols, baseSymbol);
	p.parse(inputData, query, useSymbols, baseSymbol);
	p.parse(inputData, query, useSymbols, baseSymbol);
	p.parse(inputData, query, useSymbols, baseSymbol);
	p.parse(inputData, query, useSymbols, baseSymbol);
	p.parse(inputData, query, useSymbols, baseSymbol);
	p.parse(inputData, query, useSymbols, baseSymbol);
	p.parse(inputData, query, useSymbols, baseSymbol);
	p.parse(inputData, query, useSymbols, baseSymbol);
	p.parse(inputData, query, useSymbols, baseSymbol);
	p.parse(inputData, query, useSymbols, baseSymbol);
	p.parse(inputData, query, useSymbols, baseSymbol);
	p.parse(inputData, query, useSymbols, baseSymbol);
	p.parse(inputData, query, useSymbols, baseSymbol);
	p.parse(inputData, query, useSymbols, baseSymbol);
	p.parse(inputData, query, useSymbols, baseSymbol);
	p.parse(inputData, query, useSymbols, baseSymbol);
	p.parse(inputData, query, useSymbols, baseSymbol);
	p.parse(inputData, query, useSymbols, baseSymbol);
	p.parse(inputData, query, useSymbols, baseSymbol);
	p.parse(inputData, query, useSymbols, baseSymbol);
	p.parse(inputData, query, useSymbols, baseSymbol);
	p.parse(inputData, query, useSymbols, baseSymbol);
	p.parse(inputData, query, useSymbols, baseSymbol);
	p.parse(inputData, query, useSymbols, baseSymbol);*/
	p.parse(inputData, query, useSymbols, baseSymbol);
	std::chrono::steady_clock::time_point end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> duration = end - start;
	std::cout << "\nDuration => " << duration.count() << std::endl;
	std::cout<<p.parse(inputData, query, useSymbols, baseSymbol);
	return 0;
}