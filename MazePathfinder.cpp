/* This problem is very simple: just find the way out of the maze.

Hint: you can choose any algorithm you know/like but a kind of wave propagation method is recommended.

Maze is given as a rectangular matrix of 0 and 1 characters. Exit is in top-left corner. You are to find the ways from top-right, bottom-left and bottom-right corners, i.e.

X-----A            1110001
-------            0010001
-------            1111111
-------            0000101
B-----C            1111101
For example in 7 * 5 rectangle (on the left) we should find ways from corners A, B and C to corner X. And for topology given (on the right) paths should be:

from A: DDLLLLUULL
from B: RRRRUULLUULL
from C: UULLLLUULL
Where U denotes step up, L is one step left, R and D are steps right and down respectively. We will use short form like:

from A: 2D4L2U2L
from B: 4R2U2L2U2L
from C: 2U4L2U2L
You see, each letter is preceded by amount of steps in this direction, like - 2 down, 4 left, 2 up, 2 left etc.

Input data will contain width and height of the maze in first line (both are odd values).
Then maze itself will follow, with 1 depicting passages and 0 for impassable walls.
Answer should contain three paths, space separated, in the format explained above.

Example:

input data:
13 9
1111101110111
0010001000001
1011111111111
1000000010100
1111111110101
0010000010001
1111101010111
1010001000100
1011111111111

answer:
2D10L2U2L 2U2R2U6R2U6L2U2L 10L4U6R2U6L2U2L */
#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<char> findTheWay(int widthStart, int highStart, int widthOfTheField, int highOfTheField, bool field[], vector<char> result);
void vectorOptimization(vector<char> &result);
int main(int argc, char *argv[])
{
    int widthOfTheField, highOfTheField;
    string datastring;
    vector<char> result;
    cout << "\ninput data:\n";
    cin >> widthOfTheField >> highOfTheField;
    bool *field = new bool[widthOfTheField * highOfTheField]();
    cin.ignore();
    for (int i = 0; i < highOfTheField; i++)
    {
        getline(cin, datastring);
        for (int j = 0; j < widthOfTheField; j++)
        {
            field[i * widthOfTheField + j] = datastring[j] - '0';
        }
    }

    /*for (int i = 0; i < highOfTheField; i++)
    {
        cout << "\n";
        for (int j = 0; j < widthOfTheField; j++)
        {
            cout << field[i * widthOfTheField + j];
        }
    }*/
    result = findTheWay(0, highOfTheField - 1, widthOfTheField, highOfTheField, field, result);

    cout << "\n";
    return 0;
}
vector<char> findTheWay(int widthStart, int highStart, int widthOfTheField, int highOfTheField, bool field[], vector<char> result)
{
    if (widthStart || highStart)
    {
        vector<char> newResult;
        if (((highStart - 1) >= 0) && (field[widthOfTheField * (highStart - 1) + widthStart]))
        {
            bool *newField = new bool[widthOfTheField * highOfTheField]();
            field[widthOfTheField * (highStart) + widthStart] = false;
            field[widthOfTheField * (highStart - 1) + widthStart] = false;
            newField = field;
            newField[widthOfTheField * (highStart) + widthStart] = false;
            result.push_back('U');
            newResult = findTheWay(widthStart, highStart - 1, widthOfTheField, highOfTheField, newField, result);
            delete[] newField;
            return newResult;
        }
        else
        {
            if (((highStart + 1) < highOfTheField) &&
                (field[widthOfTheField * (highStart + 1) + widthStart]))
            {
                bool *newField = new bool[widthOfTheField * highOfTheField]();
                field[widthOfTheField * (highStart) + widthStart] = false;
                field[widthOfTheField * (highStart + 1) + widthStart] = false;
                newField = field;
                newField[widthOfTheField * (highStart) + widthStart] = false;
                result.push_back('D');
                result = findTheWay(widthStart, highStart + 1, widthOfTheField, highOfTheField, newField, result);
                delete[] newField;
                return result;
            }
            else
            {
                if (((widthStart - 1) >= 0) && (field[widthOfTheField * highStart + widthStart - 1]))
                {
                    bool *newField = new bool[widthOfTheField * highOfTheField]();
                    field[widthOfTheField * (highStart) + widthStart] = false;
                    field[widthOfTheField * (highStart) + widthStart - 1] = false;
                    newField = field;
                    newField[widthOfTheField * (highStart) + widthStart] = false;
                    result.push_back('L');
                    result = findTheWay(widthStart - 1, highStart, widthOfTheField, highOfTheField, field, result);
                    delete[] newField;
                    return result;
                }
                else
                {

                    if (((widthStart + 1) < widthOfTheField) &&
                        (field[widthOfTheField * highStart + widthStart + 1]))
                    {
                        bool *newField = new bool[widthOfTheField * highOfTheField]();
                        field[widthOfTheField * (highStart) + widthStart] = false;
                        field[widthOfTheField * (highStart) + widthStart + 1] = false;
                        newField = field;
                        newField[widthOfTheField * (highStart) + widthStart] = false;
                        result.push_back('R');
                        result = findTheWay(widthStart + 1, highStart, widthOfTheField, highOfTheField, field, result);
                        delete[] newField;
                        return result;
                    }

                    else
                    {
                        result.push_back('T');
                        return result;
                    }
                }
            }
        }
    }
    return result;
}