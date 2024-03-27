#include "Calculator.h"
#include <iostream>
#include <stack>

void Calculator::SetNotation(const std::string& other)
{
	for (const char& ch : other) {
		int num = ch - '0';
		if ( 0<= num && num<= 9 ){
			// 숫자
			m_operand.emplace_back(ch);
		}
		else {
			// 연산자
			// 연산자 비교 후 push
			// 아무것도 없으면 그냥 push
			if (m_operator.empty())
				m_operator.emplace_back(ch);
			else if (ch == '(')
				m_operator.emplace_back(ch);

			else if (ch != ')') {
				int op1 = GetPrecede(m_operator.back());
				int op2 = GetPrecede(ch);

				if (op1 > op2 && op1 >0 && op2 >0) {
					// 기존이 높음 
					// top을 넣어준다.
					char top = m_operator.back();
					m_operator.pop_back();

					m_operand.emplace_back(top);
				}

				// 넣어줄건 넣어준다.
				m_operator.emplace_back(ch);
			}
			else {
				// 닫는 괄호라면
				// '('이 나올 때까지 피연산자에 붙여준다.

				while (1) {
					char top = m_operator.back();
					m_operator.pop_back();

					if (top == '(') 
						break;

					// 뽑아서 피연산자에 붙여준다.
					m_operand.emplace_back(top);
				}
			}
			
		}
	}

	// 안붙은 연산자 다 붙여준다.
	// 뒤에서부터
	std::reverse(m_operator.begin(), m_operator.end());
	for (char oper : m_operator)
		m_operand.emplace_back(oper);

	m_operator.clear();
}

void Calculator::ShowNotation()
{
	for (char c : m_operand)
		std::cout << c;
	std::cout << '\n';
}

void Calculator::Calculate()
{
	std::stack<int> value;
	while (!m_operand.empty()) {
		int temp = m_operand.front() - '0';

		if (0 <= temp && temp <= 9)
			// 숫자면 피연산자 스택에 넣는다.
			value.push(temp);
		else {
			// 연산자면 
			char oper = m_operand.front();

			int result{};
			// 피연산자 두개 뽑기
			// 뒤에 있는게 뒤쪽이다.
			int v2 = value.top();
			value.pop();

			int v1 = value.top();
			value.pop();

			switch (oper)
			{
			case '+':
				result += v1 + v2;
				break;

			case '-':
				result += v1 - v2;
				break;

			case '*':
				result += v1 * v2;
				break;

			case '/':
				result += v1 / v2;
				break;

			default:
				break;
			}

			// 피연산자 스택에 넣기
			value.push(result);
		}
		m_operand.pop_front();
	}
	std::cout << value.top();
}

int Calculator::GetPrecede(char ch)
{
	switch (ch)
	{
	case '+':
	case'-':
		return 1;

	case '*':
	case'/':
		return 2;

	default:
		return -1;
	}
}
