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
#include <algorithm>
using namespace std;
struct node
{
    int pos;
    string steps;
    node(int _pos, string _steps) : pos(_pos), steps(_steps) {}
};
bool checkItemsInVector(vector<node> vector, int pos);
string findTheWay(int x, int y, int widthOfTheField, int highOfTheField, bool *field);
string optimizateString(string data);
int main(int argc, char *argv[])
{
    int widthOfTheField, highOfTheField;
    string datastring;
    string result;
    int position;
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
    cout << "\nanswer\n";
    result = findTheWay(widthOfTheField - 1, 0, widthOfTheField, highOfTheField, field);
    result = optimizateString(result);
    cout << result << " ";
    result = findTheWay(0, highOfTheField - 1, widthOfTheField, highOfTheField, field);
    result = optimizateString(result);
    cout << result << " ";

    result = findTheWay(widthOfTheField - 1, highOfTheField - 1, widthOfTheField, highOfTheField, field);
    result = optimizateString(result);
    cout << result << " ";

    cout << "\n";
    return 0;
}

bool checkItemsInVector(vector<node> vector, int pos)
{
    while (vector.size())
    {
        if (vector.back().pos == pos)
        {
            return true;
        }
        vector.pop_back();
    }
    return false;
}
string findTheWay(int x, int y, int widthOfTheField, int highOfTheField, bool *field)
{
    string result;
    vector<node> way;
    bool finish = false;
    node tmpnode = {y * widthOfTheField + x, ""};
    way.push_back(tmpnode);
    while (!finish)
    {
        for (int i = 0; i < way.size(); i++)
        {
            node tmp = way[i];
            int x = (way[i].pos) % widthOfTheField;
            int y = (way[i].pos) / widthOfTheField;

            //      cout << "\n"
            //    << y * widthOfTheField + x - 1 << " " << field[y * widthOfTheField + x - 1] << "\n";
            if ((y > 0) && (field[(y - 1) * widthOfTheField + x]) && (!checkItemsInVector(way, (y - 1) * widthOfTheField + x)))
            {
                tmp.pos = (y - 1) * widthOfTheField + x;
                tmp.steps.push_back('U');
                way.push_back(tmp);
            }
            else
            {
                if ((x > 0) && (field[y * widthOfTheField + x - 1]) && (!checkItemsInVector(way, y * widthOfTheField + x - 1)))
                {
                    tmp.pos = y * widthOfTheField + x - 1;
                    tmp.steps.push_back('L');
                    way.push_back(tmp);
                }
                else
                {
                    if ((y < highOfTheField - 1) && (field[(y + 1) * widthOfTheField + x]) && (!checkItemsInVector(way, (y + 1) * widthOfTheField + x)))
                    {
                        tmp.pos = (y + 1) * widthOfTheField + x;
                        tmp.steps.push_back('D');
                        way.push_back(tmp);
                    }
                    else
                    {
                        if ((x < widthOfTheField - 1) && (field[y * widthOfTheField + x + 1]) && (!checkItemsInVector(way, (y * widthOfTheField + x + 1))))
                        {
                            tmp.pos = y * widthOfTheField + x + 1;
                            tmp.steps.push_back('R');
                            way.push_back(tmp);
                        }
                    }
                }
            }
        }
        for (int i = 0; i < way.size(); i++)
        {
            if (way[i].pos == 0)
            {
                result = way[i].steps;
                finish = true;
            }
        }
    }

    return result;
}
string optimizateString(string data)
{
    string result;
    char tmp;
    while (data.size())
    {
        result.push_back('1');
        tmp = data[0];
        data.erase(data.begin());
        while (tmp == data[0])
        {
            result.back()++;
            if (result.back() == ':')
            {
                if ((result[result.size() - 2] > '0') && (result[result.size() - 2] <= '9'))
                {
                    result[result.size() - 2]++;
                    result.back() = '0';
                }
                else
                {
                    result.back() = '1';
                    result.push_back('0');
                }
            }
            data.erase(data.begin());
        }
        result.push_back(tmp);
    }
    return result;
}