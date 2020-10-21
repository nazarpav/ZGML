#include "BaseZGMLOperator.h"

BaseZGMLOperator::BaseZGMLOperator(std::string symbol) :Symbol(symbol)
{
}

const std::string BaseZGMLOperator::getSymbol() const
{
	return Symbol;
}

BaseZGMLOperator::~BaseZGMLOperator()
{
}
