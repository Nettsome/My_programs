#pragma once
#ifndef steck_h
#define steck_h

struct elem
{
    int x;
    elem* next = nullptr;
};

struct twoelem
{
    int x, y;
    twoelem* next = nullptr;
};


void push(elem*& stek, int value);
bool pop(elem*& stek, int& value);
bool peek(elem* stek, int& value);

void push2(twoelem*& top, int x, int y);
bool peek2(twoelem* top, int& x, int& y);
bool pop2(twoelem*& top, int& x, int& y);

//=========================================================================================================

struct T_cell
{
    int i_;
    int j_;
    T_cell(int i, int j) : i_(i), j_(j)
    {}

    bool operator==(const T_cell& c)
    {
        return i_ == c.i_ && j_ == c.j_;
    }

    bool operator!=(T_cell c)
    {
        return !(*this == c);
    }
};

struct T_path_node
{
    T_cell  prev_cell_;
    T_cell  cur_cell_;

    T_path_node
    (
        T_cell  prev_cell,
        T_cell  cur_cell
    ) : prev_cell_(prev_cell), cur_cell_(cur_cell)
    {}
};



struct S_cell
{
    int i;
    int j;
};

struct S_path_node
{
    S_cell curr_cell;
    S_cell prev_cell;

    S_path_node* next = nullptr;
};

bool        pop_S(S_path_node*& stack, S_cell& curr, S_cell& prev);

void        push_S(S_path_node*& path_stack, int i_curr, int j_curr, int i_prev, int j_prev);

//=========================================================================================================
// lesson 2_2
//


struct m_elem
{
    char skobka;
    int pos;
    m_elem* next = nullptr;
};

void        push(m_elem*& stack, char skob, int pos);

bool        pop(m_elem*& stack, char& skob, int& pos);








 
#endif