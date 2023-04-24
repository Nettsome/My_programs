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

// Функция возврата приоритета данного оператора.
// Чем выше приоритет, тем ниже его значение
int prec(char c)
{
    // Умножение и деление
    if (c == '*' || c == '/') {
        return 3;
    }

    // Сложение и вычитание
    if (c == '+' || c == '-') {
        return 4;
    }

    // Возведение в степень
    if (c == '^')
        return 2;

    return INT_MAX;            // для открывающей скобки '('
}

// Вспомогательная функция для проверки, является ли данный токен операндом
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
        // Случай 1. Если текущий токен является открывающей скобкой '(',
        // помещаем его в stack
        if (c == '(')
            push(s, c);

        // Случай 2. Если текущий токен является закрывающей скобкой ')'
       else if (c == ')')
        {
            // извлекаем токены из stack до тех пор, пока не появится соответствующая открывающая скобка '('
            // Добавляем каждый оператор в конец постфиксного выражения
            while (top(s) != '(')
            {
                postfix.push_back(top(s));
                pop(s);
            }
            pop(s);
        }

        // Случай 3. Если текущий токен является операндом, добавляем его в конец
        // постфиксное выражение
        else if (isOperand(c))
            postfix.push_back(c);

        // Случай 4. Если текущий токен является оператором
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

    // добавляем все оставшиеся операторы в stack в конце постфиксного выражения
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
