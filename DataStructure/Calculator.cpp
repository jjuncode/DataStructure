#include "Calculator.h"
#include <iostream>
#include <stack>

void Calculator::SetNotation(const std::string& other)
{
	for (const char& ch : other) {
		int num = ch - '0';
		if ( 0<= num && num<= 9 ){
			// ����
			m_operand.emplace_back(ch);
		}
		else {
			// ������
			// ������ �� �� push
			// �ƹ��͵� ������ �׳� push
			if (m_operator.empty())
				m_operator.emplace_back(ch);
			else if (ch == '(')
				m_operator.emplace_back(ch);

			else if (ch != ')') {
				int op1 = GetPrecede(m_operator.back());
				int op2 = GetPrecede(ch);

				if (op1 > op2 && op1 >0 && op2 >0) {
					// ������ ���� 
					// top�� �־��ش�.
					char top = m_operator.back();
					m_operator.pop_back();

					m_operand.emplace_back(top);
				}

				// �־��ٰ� �־��ش�.
				m_operator.emplace_back(ch);
			}
			else {
				// �ݴ� ��ȣ���
				// '('�� ���� ������ �ǿ����ڿ� �ٿ��ش�.

				while (1) {
					char top = m_operator.back();
					m_operator.pop_back();

					if (top == '(') 
						break;

					// �̾Ƽ� �ǿ����ڿ� �ٿ��ش�.
					m_operand.emplace_back(top);
				}
			}
			
		}
	}

	// �Ⱥ��� ������ �� �ٿ��ش�.
	// �ڿ�������
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
			// ���ڸ� �ǿ����� ���ÿ� �ִ´�.
			value.push(temp);
		else {
			// �����ڸ� 
			char oper = m_operand.front();

			int result{};
			// �ǿ����� �ΰ� �̱�
			// �ڿ� �ִ°� �����̴�.
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

			// �ǿ����� ���ÿ� �ֱ�
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
