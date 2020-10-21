#pragma once
#include <string>
#include "ZGMLOperatorReturnValue.h"
class BaseZGMLOperator
{
protected:
	std::string Symbol;
public:
	BaseZGMLOperator(std::string symbol);
	const std::string getSymbol()const;
	virtual ZGMLOperatorReturnValue Action(const std::string& input, size_t& beginInput, size_t& endInput, std::string& subQuery, std::string& out) = 0;
	virtual ~BaseZGMLOperator();
};

