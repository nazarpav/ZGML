#pragma once
#include"BaseZGMLOperator.h"
#include "ZGMLOperatorReturnValue.h"
class DotOperator :public BaseZGMLOperator
{
public:
	DotOperator();
	ZGMLOperatorReturnValue Action(const std::string& input, size_t& beginInput, size_t& endInput, std::string& subQuery, std::string& out)override;
};

