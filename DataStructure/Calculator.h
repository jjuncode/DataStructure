#pragma once
#include <deque>
#include <string>

class Calculator {
private:
	std::deque<char> m_operand;
	std::deque<char> m_operator;

public:
	void SetNotation(const std::string& other);
	void ShowNotation();
	void Calculate();

private:
	int GetPrecede(char ch);
};