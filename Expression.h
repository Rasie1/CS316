#pragma once
#include <memory>
#include <string>

class Expression //: public std::enable_shared_from_this<Expression>
{
public:
	Expression() {}
	~Expression() {}

	//virtual std::shared_ptr<Expression> eval() = 0;
	virtual std::string toString() const = 0;
};

