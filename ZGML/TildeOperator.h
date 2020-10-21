#pragma once
#include"BaseZGMLOperator.h"
class TildeOperator:public BaseZGMLOperator 
{
public:
	TildeOperator();
	bool Action(const std::string& input, size_t& beginInput, size_t& endInput, std::string& subQuery)override;
};

