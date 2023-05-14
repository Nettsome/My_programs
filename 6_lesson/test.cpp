#include <iostream>
#include <string>

using std::string;

// Данные об ученике
struct Student {
    string surname; // Фамилия
    float averageScore; // Средний балл
    Student* leftChild;
    Student* rightChild;
};

// Функция для построения узла дерева
Student* createNode(string surname, float averageScore) {
    Student* node = new Student;
    node->surname = surname;
    node->averageScore = averageScore;
    node->leftChild = NULL;
    node->rightChild = NULL;
    return node;
}

// Функция для добавления узла в дерево
Student* insertNode(Student* root, string surname, float averageScore) {
    if (root == NULL) return createNode(surname, averageScore);
    if (surname < root->surname)
        root->leftChild = insertNode(root->leftChild, surname, averageScore);
    else if (surname > root->surname)
        root->rightChild = insertNode(root->rightChild, surname, averageScore);
    return root;
}

// Функция для поиска узла в дереве по фамилии
Student* getNodeBySurname(Student* root, string surname) {
    if (root == NULL) return NULL;
    if (root->surname == surname) return root;
    if (surname < root->surname) return getNodeBySurname(root->leftChild, surname);
    else return getNodeBySurname(root->rightChild, surname);
}

// Функция для вывода студентов с заданной фамилией и их баллов
void printStudentsBySurname(Student* root, char letter) {
    if (root == NULL) return;
    if (root->surname[0] == letter) {
        std::cout << root->surname << " - " << root->averageScore << std::endl;
    }
    printStudentsBySurname(root->leftChild, letter);
    printStudentsBySurname(root->rightChild, letter);
}

// Пример использования
int main() {
    // Заполнение списка студентов и их средних баллов
    Student* root = NULL;
    root = insertNode(root, "Ivanov", 4.5);
    root = insertNode(root, "Petrov", 4.0);
    root = insertNode(root, "Sidorov", 3.5);
    root = insertNode(root, "Sergeev", 4.2);

    // Вывод студентов с фамилией на букву 'S'
    char letter = 'S';
    std::cout << "Students with surnames starting with letter " << letter << ": " << std::endl;
    printStudentsBySurname(root, letter);
    return 0;
}