#include <iostream>
#include "stek.h"

using namespace std;

struct s_elem
{
    char c;
    s_elem* next = nullptr;
};

//  Finctions
//===================================
int prec(char c);

bool isOperand(char c);

void push(s_elem*& stack, char c);

bool pop(s_elem*& stack, char& c);

string infixToPostfix(string infix);
//===================================

int str_to_int(char* s)
{
    int acc = 0;
    for (int i = 0; i < strlen(s); i++) acc = acc * 10 + s[i] - '0';
    return acc;
}

// ������� �������� ���������� ������� ���������.
// ��� ���� ���������, ��� ���� ��� ��������
int prec(char c)
{
    // ��������� � �������
    if (c == '*' || c == '/') {
        return 3;
    }

    // �������� � ���������
    if (c == '+' || c == '-') {
        return 4;
    }

    // ���������� � �������
    if (c == '^')
        return 2;

    return INT_MAX;            // ��� ����������� ������ '('
}

// ��������������� ������� ��� ��������, �������� �� ������ ����� ���������
bool isOperand(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
}

// ��� ������� ������� ���������� ��������� ���������
//string infixToPostfix(string infix)
//{
//    // ������� ������ stack ��� �������� ����������
//    stack<char> s;
//
//    // ������� ������ ��� �������� ������������ ���������
//    string postfix;
//
//    // ������������ ��������� ��������� ����� �������
//    for (char c : infix)
//    {
//        // ������ 1. ���� ������� ����� �������� ����������� ������� '(',
//        // �������� ��� � stack
//        if (c == '(') {
//            s.push(c);
//        }
//
//        // ������ 2. ���� ������� ����� �������� ����������� ������� ')'
//        else if (c == ')')
//        {
//            // ��������� ������ �� stack �� ��� ���, ���� �� �������� ��������������� ����������� ������ '('
//            // ��������. ���������� ������ �������� � ����� ������������ ���������
//            while (s.top() != '(')
//            {
//                postfix.push_back(s.top());
//                s.pop();
//            }
//            s.pop();
//        }
//
//        // ������ 3. ���� ������� ����� �������� ���������, ��������� ��� � �����
//        // ����������� ���������
//        else if (isOperand(c)) {
//            postfix.push_back(c);
//        }
//
//        // ������ 4. ���� ������� ����� �������� ����������
//        else {
//            // ������� �� stack ��������� � ����� ������� ��� ������ �����������
//            // � ��������� �� � ����� ������������ ���������
//            while (!s.empty() && prec(c) >= prec(s.top()))
//            {
//                postfix.push_back(s.top());
//                s.pop();
//            }
//
//            // �������, �������� ������� �������� �� ������� stack
//            s.push(c);
//        }
//    }
//
//    // ��������� ��� ���������� ��������� � stack � ����� ������������ ���������
//    while (!s.empty())
//    {
//        postfix.push_back(s.top());
//        s.pop();
//    }
//
//    // ���������� ����������� ���������
//    return postfix;
//}



void push(s_elem*& stack, char c)
{
    s_elem* newel = new s_elem;

    newel->c = c;
    newel->next = stack;
    stack = newel;
}

bool pop(s_elem*& stack, char& c)
{
    if (!stack) return false;

    c = stack->c;
    auto old = stack;
    stack = stack->next;
    delete old;
    return true;
}

//char top(s_elem* stack)


string infixToPostfix(string infix)
{
    s_elem* s = nullptr;

    string postfix;

    for (char c : infix)
    {
        // ������ 1. ���� ������� ����� �������� ����������� ������� '(',
        // �������� ��� � stack
        if (c == '(')
            push(s, c);

        // ������ 2. ���� ������� ����� �������� ����������� ������� ')'
        else if (c == ')')
        {
            // ��������� ������ �� stack �� ��� ���, ���� �� �������� ��������������� ����������� ������ '('
            // ��������� ������ �������� � ����� ������������ ���������
            char pushIN;
            while (pop(s, pushIN) && pushIN != '(')
            {
                postfix.push_back(pushIN);
            }
            pop(s, pushIN);
        }

        // ������ 3. ���� ������� ����� �������� ���������, ��������� ��� � �����
        // ����������� ���������
        else if (isOperand(c))
            postfix.push_back(c);

        // ������ 4. ���� ������� ����� �������� ����������
        else
        {
            char pushIN;

            while (pop(s, pushIN) && prec(c) >= prec(pushIN))
            {
                postfix.push_back(pushIN);
            }

            push(s, c);
        }
    }

    // ��������� ��� ���������� ��������� � stack � ����� ������������ ���������
    char pushIN;
    while (pop(s, pushIN))
    {
        postfix.push_back(pushIN);
    }

    return postfix;
}

int main()
{
    string infix = "(a+b)^2/((c-d)(e+f^12)^3)";
    //string infix = "-d*2";


    string postfix = infixToPostfix(infix);
    cout << postfix << endl;

    return 0;
}
