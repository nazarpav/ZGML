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

int main()
{
	const std::string inputData
	(
		"<tag><tag1 value = \"super\"></tag1><tag2 name = \"good\"><tag3> <tag3> <tag3 g = \"DDD\"></tag3></tag3></tag3> </tag1>  </tag1></tag2></tag>"
	);
	const std::string query("tag.tag2.tag3.tag3.tag3~g");
#pragma region hide
	std::vector<std::shared_ptr<BaseZGMLOperator>> useSymbols;
	useSymbols.push_back(std::make_shared<DotOperator>());
	useSymbols.push_back(std::make_shared<TildeOperator>());
	std::shared_ptr<BaseZGMLOperator> baseSymbol = std::make_shared<DotOperator>();
#pragma endregion
	Parser p;
	std::cout << p.parse(inputData, query, useSymbols, baseSymbol)<<std::endl;
	return 0;
}