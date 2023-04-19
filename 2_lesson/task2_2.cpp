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

// Эта функция ожидает корректное инфиксное выражение
//string infixToPostfix(string infix)
//{
//    // создаем пустой stack для хранения операторов
//    stack<char> s;
//
//    // создаем строку для хранения постфиксного выражения
//    string postfix;
//
//    // обрабатываем инфиксное выражение слева направо
//    for (char c : infix)
//    {
//        // Случай 1. Если текущий токен является открывающей скобкой '(',
//        // помещаем его в stack
//        if (c == '(') {
//            s.push(c);
//        }
//
//        // Случай 2. Если текущий токен является закрывающей скобкой ')'
//        else if (c == ')')
//        {
//            // извлекаем токены из stack до тех пор, пока не появится соответствующая открывающая скобка '('
//            // устранен. Добавляйте каждый оператор в конец постфиксного выражения
//            while (s.top() != '(')
//            {
//                postfix.push_back(s.top());
//                s.pop();
//            }
//            s.pop();
//        }
//
//        // Случай 3. Если текущий токен является операндом, добавляем его в конец
//        // постфиксное выражение
//        else if (isOperand(c)) {
//            postfix.push_back(c);
//        }
//
//        // Случай 4. Если текущий токен является оператором
//        else {
//            // удаляем из stack операторы с более высоким или равным приоритетом
//            // и добавляем их в конец постфиксного выражения
//            while (!s.empty() && prec(c) >= prec(s.top()))
//            {
//                postfix.push_back(s.top());
//                s.pop();
//            }
//
//            // наконец, помещаем текущий оператор на вершину stack
//            s.push(c);
//        }
//    }
//
//    // добавляем все оставшиеся операторы в stack в конце постфиксного выражения
//    while (!s.empty())
//    {
//        postfix.push_back(s.top());
//        s.pop();
//    }
//
//    // возвращаем постфиксное выражение
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
        // Случай 1. Если текущий токен является открывающей скобкой '(',
        // помещаем его в stack
        if (c == '(')
            push(s, c);

        // Случай 2. Если текущий токен является закрывающей скобкой ')'
        else if (c == ')')
        {
            // извлекаем токены из stack до тех пор, пока не появится соответствующая открывающая скобка '('
            // Добавляем каждый оператор в конец постфиксного выражения
            char pushIN;
            while (pop(s, pushIN) && pushIN != '(')
            {
                postfix.push_back(pushIN);
            }
            pop(s, pushIN);
        }

        // Случай 3. Если текущий токен является операндом, добавляем его в конец
        // постфиксное выражение
        else if (isOperand(c))
            postfix.push_back(c);

        // Случай 4. Если текущий токен является оператором
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

    // добавляем все оставшиеся операторы в stack в конце постфиксного выражения
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
