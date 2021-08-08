/*Have you ever played 2048 Game? If no, then probably it is worth trying :)

Many programmers spend many hours on this (both instead of work and instead of sleep). However, though it is addictive enough it is still simple to code. And now we are going to try - and try to invent solution which does not look too clumsy.

You will be given a 4-by-4 field randomly covered with values 2 and 4 along with the sequence of player moves, specified with letters U for "up", D for "down", L for "left" and R for "right".

At each move all numbers at the field start sliding in a given direction and if two "tiles" with the same values are "pressed" against each other by this move, they combine producing a single tile with the sum value. Of course this frees one square of the board.

In case when more than 2 tiles with same numbers are so "pressing" in one line, firstly two "front" are combined, i.e. if moving "down" and we have 3 similar tiles in column, two lowest are joined.

For example:

initial         D            R            D

2 2 4 2      - - - -      - - - -      - - - -
4 2 2 4      2 2 4 2      - 4 4 2      - - 4 2
2 2 2 2      4 4 2 4      - 8 2 4      - 4 2 4
2 4 2 2      4 4 4 4      - - 8 8      - 8 8 8
Here three steps after initial position are shown - "down", "right" and "down". As you can see the last move joins nothing, only aligns tiles against the edge of the field.

Input data will contain initial setup - 4 lines of 4 values each.
The 5-th line will contain the sequence of moves.
Answer should contain the counts of tiles of each kind after these moves, in order - i.e. first the amount of 2-s, then amount of 4-s etc.

Example:

input data:
2 2 4 2
4 2 2 4
2 2 2 2
2 4 2 2
D R D L U

answer:
0 2 2 1 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;
void moveToTheRight(int *right);
void moveToTheDown(int *down);
void moveToTheUp(int *up);
void moveToTheLeft(int *left);
int main(int argc, char **argv)
{
    int dataArr[16];
    cout << "\ninput data\n";
    string tmp;
    vector<char> directionOfMoving;
    vector<int> qttOfFigures;
    bool isArrEmpti = false;
    int index = 0;
    int figure = 1;
    //  cin.get();
    for (int i = 0; i < 4; i++)
    {
        getline(cin, tmp);
        int n = 0;
        while (n != '\n')
        {
            if (isdigit(tmp[n++]))
            {
                dataArr[index++] = tmp[n - 1] - '0';
            }
        }
    }

    getline(cin, tmp);
    while (tmp[0] != '\0')
    {
        if (tmp[0] == ' ')
        {
            tmp.erase(tmp.begin());
            continue;
        }
        if (tmp[0] == 'D')
        {
            moveToTheDown(dataArr);
            tmp.erase(tmp.begin());
            continue;
        }
        if (tmp[0] == 'R')
        {
            moveToTheRight(dataArr);
            tmp.erase(tmp.begin());
            continue;
        }
        if (tmp[0] == 'U')
        {
            moveToTheUp(dataArr);
            tmp.erase(tmp.begin());
            continue;
        }
        if (tmp[0] == 'L')
        {
            moveToTheLeft(dataArr);
            tmp.erase(tmp.begin());
            continue;
        }
    }
    while (!(isArrEmpti))
    {
        figure *= 2;
        int tmp = 0;
        isArrEmpti = true;
        for (int row = 0; row < 4; row++)
        {
            for (int string = 0; string < 4; string++)
            {
                if (dataArr[string * 4 + row] == figure)
                {
                    tmp++;
                    dataArr[string * 4 + row] = 0;
                }
                if (dataArr[string * 4 + row])
                {

                    isArrEmpti = false;
                }
            }
        }
        qttOfFigures.push_back(tmp);
    }
    //qttOfFigures.pop_back();
    cout << "\nanswer:\n";
    while (!(qttOfFigures.empty()))
    {
        cout << qttOfFigures[0] << " ";
        qttOfFigures.erase(qttOfFigures.begin());
    }
    cout << endl;

    return 0;
}
void moveToTheRight(int *right)
{
    for (int string = 0; string < 4; string++)
    {
        bool stringComplete = false;
        while (!stringComplete)
        {
            for (int row = 3; row > 0; row--)
            {
                if (!right[string * 4 + row])
                {
                    stringComplete = true;
                }
                else
                {
                    stringComplete = false;
                    break;
                }
            }
            if (stringComplete == true)
            {
                break;
            }
            while ((!right[string * 4 + 3]) && ((right[string * 4 + 2]) || (right[string * 4 + 1]) || (right[string * 4])))
            {
                right[string * 4 + 3] = right[string * 4 + 2];
                right[string * 4 + 2] = right[string * 4 + 1];
                right[string * 4 + 1] = right[string * 4];
                right[string * 4] = 0;
            }
            while ((!right[string * 4 + 2]) && ((right[string * 4 + 1]) || (right[string * 4])))
            {
                right[string * 4 + 2] = right[string * 4 + 1];
                right[string * 4 + 1] = right[string * 4];
                right[string * 4] = 0;
            }
            while ((!right[string * 4 + 1]) && ((right[string * 4])))
            {
                right[string * 4 + 1] = right[string * 4];
                right[string * 4] = 0;
            }
            for (int row = 3; row > 0; row--)

            {
                if (right[string * 4 + row])
                {
                    if (right[string * 4 + row] == right[string * 4 + row - 1])
                    {
                        right[string * 4 + row] *= 2;
                        right[string * 4 + row - 1] = 0;
                        if (row == 3)
                        {
                            right[string * 4 + row - 1] = right[string * 4 + row - 2];
                            right[string * 4 + row - 2] = right[string * 4 + row - 3];
                            right[string * 4 + row - 3] = 0;
                        }
                        if (row == 2)
                        {
                            right[string * 4 + row - 1] = right[string * 4 + row - 2];
                            right[string * 4 + row - 2] = 0;
                        }
                    }
                }
            }
            stringComplete = true;
        }
    }
}
void moveToTheDown(int *down)
{
    for (int row = 0; row < 4; row++)
    {
        bool rowComplete = false;
        while (!rowComplete)
        {
            for (int string = 3; string > 0; string--)
            {
                if (!down[string * 4 + row])
                {
                    rowComplete = true;
                }
                else
                {
                    rowComplete = false;
                    break;
                }
            }
            if (rowComplete == true)
            {
                break;
            }
            while ((!down[3 * 4 + row]) && ((down[2 * 4 + row]) || (down[4 + row]) || (down[row])))
            {
                down[3 * 4 + row] = down[2 * 4 + row];
                down[2 * 4 + row] = down[4 + row];
                down[4 + row] = down[row];
                down[row] = 0;
            }
            while ((!down[2 * 4 + row]) &&
                   ((down[4 + row]) ||
                    (down[row])))
            {
                down[2 * 4 + row] = down[4 + row];
                down[4 + row] = down[row];
                down[row] = 0;
            }
            while ((!down[4 + row]) && (down[row]))
            {
                down[4 + row] = down[row];
                down[row] = 0;
            }
            for (int string = 3; string > 0; string--)
            {
                if (down[string * 4 + row])
                {
                    if (down[string * 4 + row] == down[(string - 1) * 4 + row])
                    {
                        down[string * 4 + row] *= 2;
                        down[(string - 1) * 4 + row] = 0;
                        if (string == 3)
                        {
                            down[(string - 1) * 4 + row] = down[(string - 2) * 4 + row];
                            down[(string - 2) * 4 + row] = down[(string - 3) * 4 + row];
                            down[(string - 3) * 4 + row] = 0;
                        }
                        if (string == 2)
                        {
                            down[(string - 1) * 4 + row] = down[(string - 2) * 4 + row];
                            down[(string - 2) * 4 + row] = 0;
                        }
                    }
                }
            }
            rowComplete = true;
        }
    }
}
void moveToTheUp(int *up)
{
    for (int row = 0; row < 4; row++)
    {
        bool rowComplete = false;
        while (!rowComplete)
        {
            for (int string = 3; string > 0; string--)
            {
                if (!up[string * 4 + row])
                {
                    rowComplete = true;
                }
                else
                {
                    rowComplete = false;
                    break;
                }
            }
            if (rowComplete == true)
            {
                break;
            }
            while ((!up[row]) && ((up[4 + row]) || (up[2 * 4 + row]) || (up[3 * 4 + row])))
            {
                up[row] = up[4 + row];
                up[4 + row] = up[2 * 4 + row];
                up[2 * 4 + row] = up[3 * 4 + row];
                up[3 * 4 + row] = 0;
            }
            while ((!up[4 + row]) &&
                   ((up[2 * 4 + row]) ||
                    (up[3 * 4 + row])))
            {
                up[4 + row] = up[4 * 2 + row];
                up[4 * 2 + row] = up[3 * 4 + row];
                up[3 * 4 + row] = 0;
            }
            while ((!up[2 * 4 + row]) && (up[3 * 4 + row]))
            {
                up[2 * 4 + row] = up[3 * 4 + row];
                up[3 * 4 + row] = 0;
            }
            for (int string = 0; string < 3; string++)
            {
                if (up[string * 4 + row])
                {
                    if (up[string * 4 + row] == up[(string + 1) * 4 + row])
                    {
                        up[string * 4 + row] *= 2;
                        up[(string + 1) * 4 + row] = 0;
                        if (string == 0)
                        {
                            up[(string + 1) * 4 + row] = up[(string + 2) * 4 + row];
                            up[(string + 2) * 4 + row] = up[(string + 3) * 4 + row];
                            up[(string + 3) * 4 + row] = 0;
                        }
                        if (string == 1)
                        {
                            up[(string + 1) * 4 + row] = up[(string + 2) * 4 + row];
                            up[(string + 2) * 4 + row] = 0;
                        }
                    }
                }
            }
            rowComplete = true;
        }
    }
}
void moveToTheLeft(int *left)
{
    for (int string = 0; string < 4; string++)
    {
        bool stringComplete = false;
        while (!stringComplete)
        {
            for (int row = 3; row > 0; row--)
            {
                if (!left[string * 4 + row])
                {
                    stringComplete = true;
                }
                else
                {
                    stringComplete = false;
                    break;
                }
            }
            if (stringComplete == true)
            {
                break;
            }
            while ((!left[string * 4]) && ((left[string * 4 + 1])))
            {
                left[string * 4] = left[string * 4 + 1];
                left[string * 4 + 1] = left[string * 4 + 2];
                left[string * 4 + 2] = left[string * 4 + 3];
                left[string * 4 + 3] = 0;
            }
            while ((!left[string * 4 + 1]) && ((left[string * 4 + 2])))
            {
                left[string * 4 + 1] = left[string * 4 + 2];
                left[string * 4 + 2] = left[string * 4 + 3];
                left[string * 4 + 3] = 0;
            }
            while (((!left[string * 4 + 2]) && ((left[string * 4 + 3]))))
            {
                left[string * 4 + 2] = left[string * 4 + 3];
                left[string * 4 + 3] = 0;
            }
            for (int row = 0; row < 3; row++)

            {
                if (left[string * 4 + row])
                {
                    if (left[string * 4 + row] == left[string * 4 + row + 1])
                    {
                        left[string * 4 + row] *= 2;
                        left[string * 4 + row + 1] = 0;
                        if (row == 0)
                        {
                            left[string * 4 + row + 1] = left[string * 4 + row + 2];
                            left[string * 4 + row + 2] = left[string * 4 + row + 3];
                            left[string * 4 + row + 3] = 0;
                        }
                        if (row == 1)
                        {
                            left[string * 4 + row + 1] = left[string * 4 + row + 2];
                            left[string * 4 + row + 2] = 0;
                        }
                    }
                }
            }
            stringComplete = true;
        }
    }
}