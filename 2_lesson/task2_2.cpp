#include <iostream>
//#include <stack>
#include <string>
#include <cmath>

using namespace std;

struct c_elem
{
    char c;
    c_elem* next = nullptr;
};


struct d_elem
{
    double num;
    d_elem* next = nullptr;
};



void push(c_elem*& stack, char c)
{
    c_elem* newel = new c_elem;

    newel->c = c;
    newel->next = stack;
    stack = newel;
}
void push(d_elem*& stack, double c)
{
    d_elem* newel = new d_elem;

    newel->num = c;
    newel->next = stack;
    stack = newel;
}

void pop(c_elem*& stack)
{
    if (!stack) return;

    auto old = stack;
    stack = stack->next;
    delete old;
    return;
}
void pop(d_elem*& stack)
{
    if (!stack) return;

    auto old = stack;
    stack = stack->next;
    delete old;
    return;
}

char	top(c_elem* stack)
{
    return stack->c;
}
double  top(d_elem* stack)
{
    return stack->num;
}



// Функция для получения приоритета оператора
int getPriority(char op) {
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '^')
        return 3;
    else
        return 0;
}

// Функция для проверки, является ли символ оператором
bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

bool _isdigit(char c)
{
    return (c >= 'a' && c <= 'z' || (c >= '0' && c <= '9') || c == '.');
}

double what_is_a_const(string c)
{
    if (!c.compare("e"))
        return exp(1);
    else if (!c.compare("pi"))
        return acos(-1);
    else if (!c.compare("phi"))
        return 1.6180339887498948482;
    else
    {
        double num;
        cin >> num;
        return num;
        // нужна проверка повторяющихся букв
    }
}

// Функция для преобразования выражения в постфиксную форму
string infixToPostfix(string infix) {
    //stack<char> opStack;
    c_elem* opStack = nullptr;  // стек с операциями
    string postfix;

    for (int i = 0; i < infix.length(); i++) 
    {
        // Пропускаем пробелы
        if (infix[i] == ' ')
            continue;

        // Добавляем операнд к выходной строке
        else if (_isdigit(infix[i])) {
            while (i < infix.length() && _isdigit(infix[i])) 
            {
                postfix += infix[i];
                i++;
            }
            postfix += ' ';
            i--;
        }

        // Обрабатываем операторы
        else if (isOperator(infix[i])) {
            while (opStack && getPriority(top(opStack)) >= getPriority(infix[i]))
            {
                postfix += top(opStack);
                postfix += ' ';
                pop(opStack);
            }
            push(opStack, infix[i]);
        }

        // Обрабатываем открывающие скобки
        else if (infix[i] == '(') {
            push(opStack, infix[i]);
        }
        // Обрабатываем закрывающие скобки
        else if (infix[i] == ')') {
            while (opStack && top(opStack) != '(')
            {
                //postfix += opStack.top();  
                postfix += top(opStack);
                postfix += ' ';
                //opStack.pop();          
                pop(opStack);
            }
            //opStack.pop();  
            pop(opStack);
        }
    }

    while (opStack) 
    {
        postfix += top(opStack);
        postfix += ' ';
        pop(opStack);
    }

    return postfix;
}


// =====================


// Функция для выполнения операции над двумя операндами
double performOperation(char op, double operand1, double operand2) {
    switch (op) {
    case '+':
        return operand1 + operand2;
    case '-':
        return operand1 - operand2;
    case '*':
        return operand1 * operand2;
    case '/':
        return operand1 / operand2;
    case '^':
        return pow(operand1, operand2);
    default:
        return -1;
    }
}

// Функция для вычисления значения выражения, заданного в постфиксной форме
double evaluatePostfix(string postfix)
{
    d_elem* operandStack = nullptr;                    // stack with numbers

    for (int i = 0; i < postfix.length(); i++)
    {
        // Пропускаем пробелы
        if (postfix[i] == ' ')
            continue;
        // Добавляем операнд в стек
        else if (isdigit(postfix[i]))                                       
        {
            //if (is_letter(postfix[i]))                                      // мохно добавить проверку известных констант
            //{
            //    string let;
            //    while (i < postfix.length() && is_letter(postfix[i]))
            //    {
            //        let += postfix[i];
            //        i++;
            //    }
            //    double _const = what_is_a_const(let);
            //    push(operandStack, _const);
            //}
            //else
            //{       //  То, что написано дальше 

            double operand = 0;
            while (i < postfix.length() && isdigit(postfix[i]))
            {
                operand = operand * 10 + (postfix[i] - '0');
                i++;
            }
            if (postfix[i] == '.')
            {
                i++;
                int tmp = 10;
                while (i < postfix.length() && isdigit(postfix[i]))
                {

                    operand += (double)(postfix[i] - '0') / tmp;
                    tmp *= 10;
                    i++;
                }
            }
            push(operandStack, operand);
            i--;
        }

        // Выполняем операцию над двумя последними операндами в стеке
        else if (isOperator(postfix[i]))
        {
            double operand2 = top(operandStack);
            pop(operandStack);
            double operand1 = top(operandStack);
            pop(operandStack);
            double result = performOperation(postfix[i], operand1, operand2);
            push(operandStack, result);
        }
    }

    return top(operandStack);
}

int main()
{
    //string postfix = "4 5 + 0.5 ^";
    //string infix = "((1 + 2)^3)/((5-6)*(2.718281828+0.5^12)^3)";
    string infix = "5*2^(3 + 2)";



    cout.precision(25);
    cout << "Postfix expression: " << infixToPostfix(infix) << endl;
    cout << "Result: " << evaluatePostfix(infixToPostfix(infix)) << endl;


    return 0;
}