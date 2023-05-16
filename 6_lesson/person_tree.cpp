#include "Tree.h"
#include <fstream>

using namespace std;

bool	add(person_node*& root, person pers);
void	drop(person_node*& root);
int		get_height(const person_node* root);
void	find(person_node* root, char c, queue_p q);

bool	printStudentsBySurname(person_node* root, char c);

int		get_height_difference(const person_node* n);
void	_balance_person_tree(person_node*& n);
void	_small_left_rotate(person_node*& n);
void	_small_right_rotate(person_node*& n);
void	_big_left_rotate(person_node*& n);
void	_big_right_rotate(person_node*& n);

void	postfix_traverse(person_node* root, queue_p& q);


bool	add(person_tree& tree, person pers)
{
	return add(tree.root, pers);
}

queue_p		find(person_tree tree, char c)
{
	queue_p q;
	find(tree.root, c, q);
	return q;
}

void	drop(person_tree& tree)
{
	drop(tree.root);
}



void	drop(person_node*& root)
{
	if (!root) return;
	if (root->left) drop(root->left);
	if (root->right) drop(root->right);
	delete root;
	root = nullptr;
}

bool	add(person_node*& root, person pers)
{
	if (!root)
	{
		auto* new_node = new person_node;
		strcpy_s(new_node->p.name, pers.name);
		new_node->p.score = pers.score;
		root = new_node;
		return true;
	}
	if (strcmp(root->p.name, pers.name) == 0)
	{
		root->p.count++;
		root->p.score = (double)(root->p.score + pers.score) / 2;
		return false;
	}
	const auto result = add(strcmp(pers.name, root->p.name) < 0 ? root->left : root->right, pers);
	if (result) root->height = get_height(root);
	return result;
}

int		get_height(const person_node* root)
{
	if (!root) return 0;
	const auto lh = (root->left) ? root->left->height : 0;
	const auto rh = (root->right) ? root->right->height : 0;
	return 1 + (lh < rh ? rh : lh);
}

void	find(person_node* root, char c, queue_p q)									// Not complete
{
	if (root)
	{
		if (c == root->p.name[0])
		{
			enqueue(q, root);
			find(c == root->right->p.name[0] ? root->right : nullptr, c, q);
			return;
		}
		find(c >= root->p.name[0] ? root->right : root->left, c, q);
	}
	else return;
}


// Функция для вывода студентов на заданную букву и их баллов
bool	printStudentsBySurname(person_tree t, char c)
{
	return printStudentsBySurname(t.root, c);
}

bool	printStudentsBySurname(person_node* root, char c)
{
	if (!root) return false;
	if (root->p.name[0] == c)
	{
		std::cout << root->p.name << " - " << root->p.score << std::endl;

		printStudentsBySurname(root->left, c);
		printStudentsBySurname(root->right, c);
		return true;
	}
	if (printStudentsBySurname(c > root->p.name[0] ? root->right : root->left, c)) 
		return true;
	else
		return false;
}


// open file function
void	open_file(const char* filename, person_node*& t)
{
	ifstream f(filename);

	person p;

	if (f.is_open())
	{
		const int linelen = 256;
		char* line = new char[linelen];
		while (!f.eof())
		{
			f.getline(line, linelen);
			p = CreatPerson(line);
			add(t, p);
		}
		delete[] line;
		f.close();
	}
}

person	CreatPerson(char* pers_data)
{
	person p;

	char* name = new char[20];
	double score;

	sscanf_s(pers_data, "%s %lf", name, 20, &score);
	strcpy_s(p.name, name);
	p.score = score;
	delete[] name;

	return p;
}


// Balance tree function
void	balance_person_tree(person_tree& tree)
{
	_balance_person_tree(tree.root);
}

void	_balance_person_tree(person_node*& n)
{
	if (!n) return;

	while (get_height_difference(n) >= 2)
	{
		auto lh = get_height(n->left);
		auto rh = get_height(n->right);

		if (rh > lh)
		{
			auto rlh = get_height(n->right->left);
			auto rrh = get_height(n->right->right);

			if (rrh > rlh) _small_left_rotate(n);
			else _big_left_rotate(n);
		}
		else
		{
			auto llh = get_height(n->left->left);
			auto lrh = get_height(n->left->right);

			if (llh > lrh) _small_right_rotate(n);
			else _big_right_rotate(n);
		}
	}
	_balance_person_tree(n->right);
	_balance_person_tree(n->left);

	n->height = get_height(n);

}

void	_small_left_rotate(person_node*& n)
{
	person_node* new_root = n->right;
	n->right = new_root->left;
	new_root->left = n;
	n->height = get_height(n);	//
	n = new_root;
	n->height = get_height(n);
}
void	_small_right_rotate(person_node*& n)
{
	person_node* new_root = n->left;
	n->left = new_root->right;
	new_root->right = n;
	n->height = get_height(n);	//
	n = new_root;
	n->height = get_height(n);
}

void	_big_left_rotate(person_node*& n)
{
	_small_right_rotate(n->right);
	_small_left_rotate(n);
}
void	_big_right_rotate(person_node*& n)
{
	_small_left_rotate(n->left);
	_small_right_rotate(n);
}

int		get_height_difference(const person_node* n)
{
	if (!n) return 0;

	// Определяем высоты левого и правого поддеревьев
	auto lh = get_height(n->left);
	auto rh = get_height(n->right);
	// Определяем разность высот двух поддеревьев
	auto dh = lh - rh;
	// Находим абсолютную величину разности
	return dh >= 0 ? dh : -dh;
}



// Функции вывода на экран
// Постфиксный обход дерева, т.е. вывод студентов в алфавитном порядке
queue_p	postfix_traverse(person_tree& t)
{
	queue_p q;
	postfix_traverse(t.root, q);
	return q;
}

void	postfix_traverse(person_node* root, queue_p& q)
{
	if (root)
	{
		postfix_traverse(root->left, q);
		postfix_traverse(root->right, q);
		enqueue(q, root);
	}
}