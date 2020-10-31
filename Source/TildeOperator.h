#pragma once
#include"BaseZGMLOperator.h"
#include "ZGMLOperatorReturnValue.h"
class TildeOperator :public BaseZGMLOperator
{
public:
	TildeOperator();
	ZGMLOperatorReturnValue Action(const std::string& input, size_t& beginInput, size_t& endInput, std::string& subQuery, std::string& out)override;
	const bool trimTagToEnd(std::string& input, std::string& error) const;
	const std::pair<std::string, bool> getAttributeValue(const std::string& input, const size_t& beginAttributeIndex, const std::string beginSymbol, const std::string endSymbol) const;
	const size_t findBeginAttributeIndex(const std::string& input, const std::string attribute)const;
};

