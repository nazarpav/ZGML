#pragma once
#include <string>
class BaseZGMLOperator
{
protected:
	std::string Symbol;
public:
	BaseZGMLOperator(std::string symbol);
	const std::string getSymbol()const;
	virtual bool Action(const std::string& input, size_t& beginInput, size_t& endInput, std::string& subQuery) = 0;
	virtual ~BaseZGMLOperator();
};

