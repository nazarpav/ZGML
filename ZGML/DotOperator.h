#pragma once
#include"BaseZGMLOperator.h"
class DotOperator :public BaseZGMLOperator
{
public:
	DotOperator();
	bool Action(const std::string& input, size_t& beginInput, size_t& endInput, std::string& subQuery)override;
};

