//#include <iostream>
//#include <string>
//#include "stek.h"
//
//using namespace std;
//
//struct str_elem
//{
//	string str;
//	str_elem* next = nullptr;
//};
//
//struct double_elem
//{
//	double num;
//	double_elem* next = nullptr;
//};
//
//struct s_elem
//{
//	char c;
//	s_elem* next = nullptr;
//};
//
//
//void push(s_elem*& stack, char c)
//{
//	s_elem* newel = new s_elem;
//
//	newel->c = c;
//	newel->next = stack;
//	stack = newel;
//}
//
//void push(str_elem*& stack, string c)
//{
//	str_elem* newel = new str_elem;
//
//	newel->str = c;
//	newel->next = stack;
//	stack = newel;
//}
//
//void push(double_elem*& stack, double c)
//{
//	double_elem* newel = new double_elem;
//
//	newel->num = c;
//	newel->next = stack;
//	stack = newel;
//}
//
//void pop(s_elem*& stack)
//{
//	if (!stack) return;
//
//	auto old = stack;
//	stack = stack->next;
//	delete old;
//	return;
//}
//
//void pop(double_elem*& stack)
//{
//	if (!stack) return;
//
//	auto old = stack;
//	stack = stack->next;
//	delete old;
//	return;
//}
//
//char	top(s_elem* stack)
//{
//	return stack->c;
//}
//
//double	top(double_elem* stack)
//{
//	return stack->num;
//}
//
//bool isOperand(char c)
//{
//	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9' || c == '.');
//}
//
//int prec(char c)
//{
//	// Умножение и деление
//	if (c == '*' || c == '/')
//		return 3;
//
//
//	// Сложение и вычитание
//	if (c == '+' || c == '-')
//	{
//		return 4;
//	}
//
//	// Возведение в степень
//	if (c == '^')
//		return 2;
//
//	return INT_MAX;            // для открывающей скобки '('
//}
//
//void	push_num(double_elem*& result, string num)
//{
//	if (!num.empty())
//	{
//		double n = stod(num);
//		push(result, n);
//		num.clear();
//	}
//}
//
//double      calculate_expr(string expr)
//{
//	double a, b, c;
//	cout << "Enter the numbers a, b, c:" << endl;
//
//	cin >> a >> b >> c;
//
//	double_elem* result = nullptr;		// Для хранения результата
//
//	s_elem* s = nullptr;				// Для хранения операций и скобок
//
//	string num;
//
//	for (char c : expr)
//	{
//		if (c == '(')
//		{
//			push_num(result, num);
//			push(s, c);
//		}
//
//		else if (c == ')')
//		{
//			push_num(result, num);
//
//			while (top(s) != '(')
//			{
//				oper(result, top(s));
//				pop(s);
//			}
//			pop(s);
//		}
//
//		else if (isOperand(c))
//			num.push_back(c);
//
//		else
//		{
//			while (s && prec(c) >= prec(top(s)))
//			{
//				//sum()
//				pop(s);
//			}
//			push(s, c);
//		}
//
//	}
//}
//
//
//void	oper(double_elem*& result, char oper)
//{
//	double num1 = top(result);
//	pop(result);
//	double num2 = top(result);
//
//
//	double res;
//	switch (oper)
//	{
//	case '+':
//		res = num1 + num2;
//		break;
//	case '-':
//		res = num2 - num1;
//		break;
//
//	case '*':
//		res = num1 * num2;
//		break;
//	case '/':
//		res = double(num2 / num1);
//		break;
//	case '^':
//		res = pow(num2, num1);
//		break;
//	default:
//		break;
//	}
//}
//
//
