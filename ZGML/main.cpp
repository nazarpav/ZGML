#include<iostream>
#include<chrono>
#include<ctime>
#include<memory>
#include<string>
#include<vector>
#include"BaseZGMLOperator.h"
#include"DotOperator.h"
#include"Parser.h"

int main()
{
	const std::string inputData("<tag><tag1 value=\"super\"></tag1><tag2 name=\"good\"></tag2></tag>");
	const std::string query(".tag.tag2.tag3");
	std::vector<std::shared_ptr<BaseZGMLOperator>> useSymbols;
	useSymbols.push_back(std::make_shared<DotOperator>());
	std::shared_ptr<BaseZGMLOperator> baseSymbol = std::make_shared<DotOperator>();
	Parser p;
	p.parse(inputData, query, useSymbols, baseSymbol);
	return 0;
}