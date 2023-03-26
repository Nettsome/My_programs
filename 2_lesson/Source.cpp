#include <iostream>
#include "stek.h"
#include <cstdlib>
#include <time.h>




using namespace std;

bool fill_stack(S_path_node*& pathstack);

void print_path(S_path_node*& stack);


void task1()
{
    int x, y;

    twoelem* stack = nullptr;

    // srand(time(0));

    for (int i = 0; i < 50; i++)
    {
        push2(stack, i % 7, i % 3);
    }




    twoelem* stack2 = nullptr;
    int a;
    cin >> a;


    while (pop2(stack, x, y))
    {
        cout << "(" << x << ", " << y << ")" << "\t";

        if (x + y == a)
        {
            push2(stack2, 0, 0);
        }
        else
        {
            push2(stack2, x, y);
        }
    }

    cout << "======================================================" << endl;
    while (pop2(stack2, x, y))
    {
        cout << "(" << x << ", " << y << ")" << "\t";
    }
}

void task2()
{
    elem* stack = nullptr;

    for (int i = 1; i > -50; i -= 1)
    {
        push(stack, i);
    }

    int value;
    elem* stack2 = nullptr;         // reversed stack

    while (pop(stack, value))
    {
        push(stack2, value);
    }

    delete stack;


    elem* even = nullptr;
    elem* odd = nullptr;

    while (pop(stack2, value))
    {
        if (value % 2 == 0)
        {
            push(even, value);
        }
        else
        {
            push(odd, value);
        }
    }


    cout << "\neven stack:" << endl;
    while (pop(even, value))
    {
        cout << value << endl;
    }
    cout << "\nodd stack:" << endl;
    while (pop(odd, value))
    {
        cout << value << endl;
    }
}

void task3()
{
    S_path_node* path_stack = nullptr;;

    if (!fill_stack(path_stack))
    {
        cout << "No exit!"
            << endl;
    }
    else
    {
        print_path(path_stack);
    }
}



const int OPEN_VAL = 0;
const int CLOSE_VAL = 1;
const int START_VAL = -1;

bool fill_stack(S_path_node*& pathstack)
{
    const int n = 9; // ширина лабиринта
    const int m = 9; // длина

    int labirint[][n] = {{1, 1,  1, 0,  1, 1, 1, 1, 1},
                         {1, 0,  0, 0,  1, 0, 1, 0, 1},
                         {1, 0,  1, 0,  0, 0, 1, 0, 1},
                         {1, 0,  1, 0,  1, 0, 1, 0, 1},
                         {1, 0,  0, 0,  0, 0, 1, 0, 1},
                         {1, 0,  1, 1,  1, 1, 1, 0, 1},
                         {1, 0,  0, 1,  0, 0, 0, 0, 1},
                         {1, 1,  0, 0,  0, 1, 1, 1, 1},
                         {1, 1,  1, 1, -1, 1, 1, 1, 1}};

    /*
    *                     0  1   2  3   4  5  6  7  8
                        {{1, 1,  1, 1,  1, 1, 1, 0, 1}, 0
                         {1, 0,  0, 0,  1, 0, 1, 0, 1}, 1
                         {1, 0,  1, 0,  0, 0, 1, 0, 1}, 2
                         {1, 0,  1, 0,  1, 0, 1, 0, 1}, 3   
                         {1, 0,  0, 0,  0, 0, 1, 0, 1}, 4
                         {1, 0,  1, 1,  1, 1, 1, 0, 1}, 5
                         {1, 0,  0, 1,  0, 0, 0, 0, 1}, 6
                         {1, 1,  0, 0,  0, 1, 1, 1, 1}, 7
                         {1, 1,  1, 1, -1, 1, 1, 1, 1}} 8
                         
                         */
    int stack_size = 0;
    // заполнение пустых клеток значениями (длины пути + 1) умноженного на -1
    for (int curr_cell_val = START_VAL; ; --curr_cell_val)
    {
        int start_stack = stack_size;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (labirint[i][j] == curr_cell_val)
                {
                    // заполняем соседние клетки значениями curr_cell_val - 1

                    for (int i_neighb = max(i - 1, 0); i_neighb <= min(i + 1, m - 1); ++i_neighb)
                    {
                        for (int j_neighb = max(j - 1, 0); j_neighb <= min(j + 1, n - 1); ++j_neighb)
                        {

                            if ((i_neighb == i || j_neighb == j) && (labirint[i_neighb][j_neighb] == OPEN_VAL))
                            {
                                labirint[i_neighb][j_neighb] = curr_cell_val - 1;
                                push_S(pathstack, i_neighb, j_neighb, i, j);
                                stack_size++;
                                //cout << "(" << i_neighb << ", " << j_neighb << ") = " << curr_cell_val - 1 << endl;


                                // if exit was find:
                                if(i_neighb == 0 || j_neighb == 0 || i_neighb == m - 1 || j_neighb == n - 1)
                                {
                                    return true;
                                }
                            }
                        }
                    }
                }
            }
        }
        if (start_stack == stack_size)
            return false;
    }
}


/*
    j
    #
i # x #
    #

*/

//void print_path(R_path_stack*& stack)
//{
//    cout << "The route in the maze from the exit to the starting cell:" << endl;
//
//    int i_curr;
//    int j_curr;
//    int i_prev;
//    int j_prev;
//
//    cout << "=========================" << endl;
//    pop_R(stack, i_curr, j_curr, i_prev, j_prev);
//    cout << "(" << i_curr << ", " << j_curr << ")" << endl;
//    while (pop_R(stack, i_curr, j_curr, i_prev, j_prev))
//    {
//        // cout << "Yes" << endl;
//        cout << "(" << i_curr << ", " << j_curr << ")" << endl;
//    }
//    cout << "(" << i_prev << ", " << j_prev << ")" << endl;
//}



void print_path(S_path_node*& stack)
{
    cout << "The route in the maze from the exit to the starting cell:" << endl;

    S_cell curr;
    S_cell prev;
    S_cell tmp;

    pop_S(stack, curr, prev);
    tmp = prev;
    cout << "(" << curr.i << ", " << curr.j << ")" << endl;
    while (pop_S(stack, curr, prev))
    {
        if (tmp.i == curr.i && tmp.j == curr.j)
        {
            cout << "(" << curr.i << ", " << curr.j << ")" << endl;
            cout << "(" << prev.i << ", " << prev.j << ")" << endl;
            cout << "\n";

            tmp = prev;
        }
    }
    cout << "(" << prev.i << ", " << prev.j << ")" << endl;
}









// g++ ./test.cpp ./stek.cpp
int main()
{
    // task1();
    // task2();
    task3();



    return 0;
}