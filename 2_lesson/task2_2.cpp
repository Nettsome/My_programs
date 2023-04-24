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

void pop(s_elem*& stack);

char	top(s_elem* stack);

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






void push(s_elem*& stack, char c)
{
    s_elem* newel = new s_elem;

    newel->c = c;
    newel->next = stack;
    stack = newel;
}

void pop(s_elem*& stack)
{
    if (!stack) return;

    auto old = stack;
    stack = stack->next;
    delete old;
    return;
}

char	top(s_elem* stack)
{
    return stack->c;
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
            while (top(s) != '(')
            {
                postfix.push_back(top(s));
                pop(s);
            }
            pop(s);
        }

        // ������ 3. ���� ������� ����� �������� ���������, ��������� ��� � �����
        // ����������� ���������
        else if (isOperand(c))
            postfix.push_back(c);

        // ������ 4. ���� ������� ����� �������� ����������
        else
        {

            while (s && prec(c) >= prec(top(s)))
            {
                postfix.push_back(top(s));
                pop(s);
            }

            push(s, c);
        }
    }

    // ��������� ��� ���������� ��������� � stack � ����� ������������ ���������
    while (s)
    {
        postfix.push_back(top(s));
        pop(s);
    }

    return postfix;
}

int main()
{
    string infix = "e-x^2";
    //string infix = "2*2+2";


    string postfix = infixToPostfix(infix);
    cout << postfix << endl;

    return 0;
}
