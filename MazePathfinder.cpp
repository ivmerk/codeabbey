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
int main(int argc, char *argv[])
{
    int widthOfTheField, highOfTheField;
    string datastring;
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
    for (int i = 0; i < highOfTheField; i++)
    {
        cout << "\n";
        for (int j = 0; j < widthOfTheField; j++)
        {
            cout << field[i * widthOfTheField + j];
        }
    }
    cout << "\n";
    return 0;
}