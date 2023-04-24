#include <iostream>
#include <stack>
#include <string>

using std::stack;
using std::string;

// Структура дерева
struct Node {
    string data;
    Node* left;
    Node* right;
};

// Создание нового узла дерева
Node* newNode(char data) {
    Node* node = new Node;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Построение дерева по выражению в виде постфиксной записи
Node* buildTree(string expr) {
    stack<Node*> st;
    Node* t1, * t2, * t;

    for (int i = 0; i < expr.length(); i++) {
        if (!isdigit(expr[i])) {
            t = newNode(expr[i]);
            t1 = st.top();
            st.pop();
            t2 = st.top();
            st.pop();
            t->left = t2;
            t->right = t1;
            st.push(t);
        }
        else {
            t = newNode(expr[i]);
            st.push(t);
        }
    }

    t = st.top();
    st.pop();
    return t;
}

// Вывод выражения в стандартной форме
void inorder(Node* t) {
    if (t) {
        if (!isdigit(t->data[0]))
            std::cout << "(";
        inorder(t->left);
        std::cout << t->data;
        inorder(t->right);
        if (!isdigit(t->data[0]))
            std::cout << ")";
    }
}

// Вывод выражения в постфиксной форме
void postorder(Node* t) {
    if (t) {
        postorder(t->left);
        postorder(t->right);
        std::cout << t->data;
    }
}

// Пример использования
int main() {
    string postfix = "53+42-6*";
    Node* root = buildTree(postfix);

    std::cout << "Infix Expression: ";
    inorder(root);
    std::cout << std::endl;

    std::cout << "Postfix Expression: ";
    postorder(root);
    std::cout << std::endl;

    return 0;
}