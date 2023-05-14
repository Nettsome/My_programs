//#include "stek.h"
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//struct s_elem
//{
//	char c;
//	s_elem* next = nullptr;
//};
//
//void push(s_elem*& stack, char skob)
//{
//	s_elem* newel = new s_elem;
//
//	newel->c = skob;
//	newel->next = stack;
//	stack = newel;
//}
//
//bool pop(s_elem*& stack, char& skob)
//{
//	if (!stack) return false;
//
//	skob = stack->c;
//	auto old = stack;
//	stack = stack->next;
//	delete old;
//	return true;
//}
//
////char top(s_elem* stack)
//
//
//string infixToPostfix(string infix)
//{
//	s_elem* s = nullptr;
//
//	string postfix;
//
//	for (char c : infix)
//	{
//		// ������ 1. ���� ������� ����� �������� ����������� ������� '(',
//		// �������� ��� � stack
//		if (c == '(')
//			push(s, c);
//
//		// ������ 2. ���� ������� ����� �������� ����������� ������� ')'
//		else if (c == ')')
//		{
//			// ��������� ������ �� stack �� ��� ���, ���� �� �������� ��������������� ����������� ������ '('
//			// ��������� ������ �������� � ����� ������������ ���������
//			char pushIN;
//			while (pop(s, pushIN) && pushIN != '(')
//			{
//				postfix.push_back(pushIN);
//			}
//			pop(s, pushIN);
//		}
//
//		// ������ 3. ���� ������� ����� �������� ���������, ��������� ��� � �����
//		// ����������� ���������
//		else if (isOperand(c))
//			postfix.push_back(c);
//
//		// ������ 4. ���� ������� ����� �������� ����������
//		else
//		{
//
//			char pushIN;
//			
//			while (pop(s, pushIN) && prec(c) >= prec(pushIN))
//			{
//				postfix.push_back(pushIN);
//			}
//
//			push(s, c);
//		}	
//	}
//
//	// ��������� ��� ���������� ��������� � stack � ����� ������������ ���������
//	char pushIN;
//	while (pop(s, pushIN))
//	{
//		postfix.push_back(pushIN);
//	}
//
//	return postfix;
//}
