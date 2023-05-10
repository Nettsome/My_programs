#include "Tree.h"

using namespace std;

bool add(node*& root, int value);
int find(const node* root, int value);
bool remove(node*& root, int val);
void drop(node*& root);
int get_height(const node* root);

void prefix_traverse(node* root, queue& q);
void infix_traverse(node* root, queue& q);
void postfix_traverse(node* root, queue& q);
void wide_traverse(node* root, queue& q);

void	_balance(node*& n);
void	_small_left_rotate(node*& n);
void	_small_right_rotate(node*& n);
void	_big_left_rotate(node*& n);
void	_big_right_rotate(node*& n);


bool add(tree& t, int value)
{
	return add(t.root, value);
}

int find(tree t, int value)
{
	return find(t.root, value);
}

bool remove(tree& t, int value)
{
	return remove(t.root, value);
}

void remove_leaf(node*& parent, node*& rem, bool is_sub_right, value& saved_value)
{
	auto& sub = (is_sub_right) ? rem->left : rem->right;
	if (sub) remove_leaf(rem, sub, is_sub_right, saved_value);
	else
	{
		auto del = rem;
		saved_value = rem->v;
		rem = is_sub_right ? rem->right : rem->left;
		delete del;
	}
	parent->height = get_height(parent);
}

bool remove(node*& root, int val)
{
	// 1. Èùåì óäàëÿåìûé ýëåìåíò
	if (root)
	{
		if (root->v.x != val) { // Ýëåìåíò ïîêà íå íàéäåí
			auto res = remove(val < root->v.x ? root->left : root->right, val);
			if (res) root->height = get_height(root);
			return res;
		}
		// Ýëåìåíò íàéäåí
		// 2. Îïðåäåëÿåì êàêîå èç ïîääåðåâüåâ âûøå
		auto lh = get_height(root->left);
		auto rh = get_height(root->right);
		if (lh == 0 && rh == 0) // Óäàëÿåìûé ýëåìåíò - ëèñò
		{
			delete root;
			return true;
		}
		auto is_sub_right = lh < rh;
		// 3. Ïîèñê íàèìåíüøåãî ýëåìåíòà â ïðàâîì ïîääåðåâå
		auto* rem = (is_sub_right) ? root->right : root->left;
		value saved_value;
		remove_leaf(root, rem, is_sub_right, saved_value);
		root->v = saved_value;
		return true;
	}
	return false;
}

int find(const node* root, int value)
{
	if (root) {
		if (root->v.x == value) return root->v.count;
		return find(value < root->v.x ? root->left : root->right, value);
	}
	return 0;
}

void drop(tree& t)
{
	drop(t.root);
}

queue prefix_traverse(tree& t)
{
	queue q;
	prefix_traverse(t.root, q);
	return q;
}

void prefix_traverse(node* root, queue& q)
{
	if (root) {
		enqueue(q, root);
		prefix_traverse(root->left, q);
		prefix_traverse(root->right, q);
	}
}

queue infix_traverse(tree& t)
{
	queue q;
	infix_traverse(t.root, q);
	return q;
}

void infix_traverse(node* root, queue& q)
{
	if (root) {
		infix_traverse(root->left, q);
		enqueue(q, root);
		infix_traverse(root->right, q);
	}
}

queue postfix_traverse(tree& t)
{
	queue q;
	postfix_traverse(t.root, q);
	return q;
}

void postfix_traverse(node* root, queue& q)
{
	if (root) {
		postfix_traverse(root->left, q);
		postfix_traverse(root->right, q);
		enqueue(q, root);
	}
}

queue wide_traverse(tree& t)
{
	queue q;
	wide_traverse(t.root, q);
	return q;
}

void wide_traverse(node* root, queue& q)
{
	if (root) {
		auto h = root->height;
		enqueue(q, root);
		queue_elem* curr = q.first;
		for (int i = 1; i < (1 << h) - 1; i += 2)
		{
			enqueue(q, curr->tree_node ? curr->tree_node->left : nullptr);
			enqueue(q, curr->tree_node ? curr->tree_node->right : nullptr);
			curr = curr->next;
		}
	}
}

void drop(node*& root)
{
	if (!root) return;
	if (root->left) drop(root->left);
	if (root->right) drop(root->right);
	delete root;
	root = nullptr;
}

bool add(node*& root, int value)
{
	if (!root)
	{
		auto* new_node = new node;
		new_node->v.x = value;
		root = new_node;
		return true;
	}
	if (root->v.x == value)
	{
		root->v.count++;
		return false;
	}
	const auto result = add(value < root->v.x ? root->left : root->right, value);
	if (result) root->height = get_height(root);
	return result;
}

int get_height(const node* root)
{
	if (!root) return 0;
	const auto lh = (root->left) ? root->left->height : 0;
	const auto rh = (root->right) ? root->right->height : 0;
	return 1 + (lh < rh ? rh : lh);
}


// balance
void	balance(tree& t)
{
	_balance(t.root);
}

void _balance(node*& n)
{
	// Проверяем, что переданный узел существует
	if (!n) return;
	// Определяем высоты левого и правого поддеревьев
	auto lh = get_height(n->left);
	auto rh = get_height(n->right);
	// Определяем разность высот двух поддеревьев
		auto dh = lh - rh;
	// Находим абсолютную величину разности
		dh = dh >= 0 ? dh : -dh;
	// Если разность высот 2 или более, требуется балансировка
		if (dh >= 2)
		{
		// Если правая ветвь длиннее, делаем левый поворот
			if (rh > lh)
			{
				// Определим высоты поддеревьев в правом поддереве
				auto rlh = get_height(n->right->left);
				auto rrh = get_height(n->right->right);
				// Если правое под-поддерево больше, делаем малый поворот
				if (rrh > rlh) _small_left_rotate(n);
				// иначе - большой
				else _big_left_rotate(n);
			}
			// Будем делать правый поворот, если левая ветвь больше
			else
			{
				// Определим высоты поддеревьев в левом поддереве
				auto llh = get_height(n->left->left);
				auto lrh = get_height(n->left->right);
				// Если левое под-поддерево больше, делаем малый поворот
				if (llh > lrh) _small_right_rotate(n);
				// иначе - большой
				else _big_right_rotate(n);
			}
		}
		else
		{
			// Разбалансировки нет. Просто уточняем высоту текущего узла
			get_height(n);
		}
}


void	_small_left_rotate(node*& n)
{
	node* new_root = n->right;
	n->right = new_root->left;
	new_root->left = n;
	n->height = get_height(n);	//
	n = new_root;
	n->height = get_height(n);
}

void	_small_right_rotate(node*& n)
{
	node* new_root = n->left;
	n->left = new_root->right;
	new_root->right = n;
	n->height = get_height(n);	//
	n = new_root;
	n->height = get_height(n);
}

void	_big_left_rotate(node*& n)
{
	_small_right_rotate(n->right);
	_small_left_rotate(n);
}

void	_big_right_rotate(node*& n)
{
	_small_left_rotate(n->left);
	_small_right_rotate(n);
}