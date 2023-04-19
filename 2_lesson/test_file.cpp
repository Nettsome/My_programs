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
//		// Случай 1. Если текущий токен является открывающей скобкой '(',
//		// помещаем его в stack
//		if (c == '(')
//			push(s, c);
//
//		// Случай 2. Если текущий токен является закрывающей скобкой ')'
//		else if (c == ')')
//		{
//			// извлекаем токены из stack до тех пор, пока не появится соответствующая открывающая скобка '('
//			// Добавляем каждый оператор в конец постфиксного выражения
//			char pushIN;
//			while (pop(s, pushIN) && pushIN != '(')
//			{
//				postfix.push_back(pushIN);
//			}
//			pop(s, pushIN);
//		}
//
//		// Случай 3. Если текущий токен является операндом, добавляем его в конец
//		// постфиксное выражение
//		else if (isOperand(c))
//			postfix.push_back(c);
//
//		// Случай 4. Если текущий токен является оператором
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
//	// добавляем все оставшиеся операторы в stack в конце постфиксного выражения
//	char pushIN;
//	while (pop(s, pushIN))
//	{
//		postfix.push_back(pushIN);
//	}
//
//	return postfix;
//}
