/*The game of Life by John Conway is played on a grid. At start we place several "organisms" into some cells (only one organism per cell), leaving other cells empty. Cells which are touching by side or corner are neighboring, so each organism may have from 0 to 8 neighbors.

After this, at each turn the colony of organisms evolve by the following rules:

any organism which have less than 2 or more than 3 neighbors will die (not passing to next turn);
at the same in each empty cell, which is surrounded by exactly 3 neighbor organisms, a new one is born.
It is important, that birth and dying are performed simultaneously. So when programming you need work like this:

mark all places where new life will be born;
mark all organisms which will die;
remove all marked organisms;
fill all marked empty cells with new organisms.
Instead of marking cells you can store their coordinates in two dedicated arrays or lists to process them later.

Let us see an example:

- - - - -      - - - - -      - - - - -
- - - - -      - - X - -      - - - - -
- X X X -  =>  - - X - -  =>  - X X X -
- - - - -      - - X - -      - - - - -
- - - - -      - - - - -      - - - - -
Here is a colony of 3 organisms. Obviously, at the first turn two of them (left and right) should die. However, before dying they will participate in giving birth to another two ones. Really, empty cells just above the central and just below it have exactly 3 neighbors. So after first turn the colony looks the same but rotated by 90°. Of course after second move the configuration will return to exactly such form as it was initially.

In this problem you will run the given configuration for 5 turns and print the number of organisms after each step.

Input data will contain 5 lines of 7 characters each. They represent a 5 by 7 fragment of the game field.
Dash characters "-" represent empty cells, while each "X" represent a cell containing a live organism.
Answer should contain 5 values separated by spaces - the amounts of live organisms after each turn.

Example:

input data:
-------
---XX--
-XXX---
-------
-------

answer:
6 5 3 2 0
Note: if you will implement the game using a kind of 2D array, make sure it is large enough and the initial configuration is placed far from edges, so that it will not reach them in 5 moves - otherwise your results could be spoiled.

You also may be interested in solving an advanced version of the problem Hard Life which may require to come up with more efficient algorithm.*/
#include <iostream>
#include <vector>
using namespace std;
static const int NUM_STRING = 5;
static const int NUM_STEPS = 5;
static const int NUM_ROW = 7;
static const int NUM_BORDER = 20;
int main(int argc, char **argv)
{
    char ground[NUM_STRING + NUM_BORDER][NUM_ROW + NUM_BORDER];
    int mirGround[NUM_STRING + NUM_BORDER][NUM_ROW + NUM_BORDER];
    int res[NUM_STEPS];
    string tmp;
    cout << "input data:" << endl;
    for (int j = 0; j < NUM_STRING + NUM_BORDER; j++) // mirrow to zerro
    {
        for (int u = 0; u < NUM_ROW + NUM_BORDER; u++)
        {
            mirGround[j][u] = 0;
        }
    }
    for (int j = 0; j < NUM_STRING + NUM_BORDER; j++) // mirrow to zerro
    {
        for (int u = 0; u < NUM_ROW + NUM_BORDER; u++)
        {
            ground[j][u] = '-';
        }
    }
    for (int j = 0; j < NUM_STRING; ++j) // input playgraund
    {
        cin >> tmp;
        for (int u = 0; u < NUM_ROW; u++)
        {
            ground[j + NUM_BORDER / 2][u + NUM_BORDER / 2] = tmp[u];
        }
    }
    for (int i = 0; i < NUM_STEPS; i++) // steps begining
    {
        res[i] = 0;
        for (int j = 0; j < NUM_STRING + NUM_BORDER; j++) // checking the X and increaing mirrow by 1 around the X
        {
            for (int u = 0; u < NUM_ROW + NUM_BORDER; u++)
            {
                if (ground[j][u] == 'X')
                {
                    if (j != 0)
                    {
                        mirGround[j - 1][u]++;
                    }
                    if ((j != 0) && (u != NUM_ROW + NUM_BORDER))
                    {
                        mirGround[j - 1][u + 1]++;
                    }
                    if (u != NUM_ROW + NUM_BORDER)
                    {
                        mirGround[j][u + 1]++;
                    }
                    if ((j != NUM_STRING + NUM_BORDER) && (u != NUM_ROW + NUM_BORDER))
                    {
                        mirGround[j + 1][u + 1]++;
                    }
                    if (j != NUM_STRING + NUM_BORDER)
                    {
                        mirGround[j + 1][u]++;
                    }
                    if ((j != NUM_STRING + NUM_BORDER) && (u != 0))
                    {
                        mirGround[j + 1][u - 1]++;
                    }
                    if (u != 0)
                    {
                        mirGround[j][u - 1]++;
                    }
                    if ((j != 0) && (u != 0))
                    {
                        mirGround[j - 1][u - 1]++;
                    }
                }
            }
        }
        cout << endl;
        for (int j = 0; j < NUM_STRING + NUM_BORDER; j++) // checking the  mirrow if cell = 2 or 3 ground - X
        {
            for (int u = 0; u < NUM_ROW + NUM_BORDER; u++)
            {
                cout << mirGround[j][u] << " ";
            }
            cout << endl;
        }
        for (int j = 0; j < NUM_STRING + NUM_BORDER; j++) // checking the  mirrow if cell = 2 or 3 ground - X
        {
            for (int u = 0; u < NUM_ROW + NUM_BORDER; u++)
            {
                if (mirGround[j][u] == 3)
                {
                    res[i]++;
                    ground[j][u] = 'X';
                }
                else if ((mirGround[j][u] == 2) && (ground[j][u] == 'X'))
                {
                    res[i]++;
                    ground[j][u] = 'X';
                }
                else
                {
                    ground[j][u] = '-';
                }
                mirGround[j][u] = 0;
            }
        }
        cout << endl;
        for (int j = 0; j < NUM_STRING + NUM_BORDER; j++) // checking the  mirrow if cell = 2 or 3 ground - X
        {
            for (int u = 0; u < NUM_ROW + NUM_BORDER; u++)
            {
                cout << ground[j][u] << " ";
            }
            cout << endl;
        }
    }
    cout << "\nanswer:\n";
    for (int i = 0; i < NUM_STEPS; ++i)
    {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}