/* Let's practice the geometry programming of rotations. Such functionality is quite popular in graphic editors, but it is not the only use.

For example here is the widget Sphere Tag Cloud which can be used in creating funny design of the web-page. Dragging the mouse over the cloud you should see it scrolling like a globe. The effect is achieved by performing just two rotations around two axes (for each of floating element).

We'll start with something simpler. Suggest we have a planar map with points on it. For example it could be the picture of a sky with stars shining.

The task is to perform rotation of the map by the given angle. Round the resulting coordinates to nearest integer.

To check the result please output the names of stars sorted by Y coordinate and then by X (if the Ys are equal).

Input data contain the number of stars N and the rotation angle A (counterclockwise, from 0 to 360 degrees).
Next lines will contain data about one star each in form Name X Y. Coordnates would be integer, not exceeding 1000 in absolute value.
Answer should give the names of stars sorted by Y and then by X after rotation (and rounding).

Note: sorting should be performed in ascending order, i.e. from smallest values to largest.

Example:

input data:
4 45
Deneb -10 10
Algol 10 10
Sirius -10 -10
Mira 10 -10

answer:
Sirius Deneb Mira Algol
You may see schematic diagram of such rotation on the picture above. Here Sirius is green, Deneb is red, Mira is yellow and Algol is blue.*/
#include <iostream>
#include <cmath>
using namespace std;
#define PI 3.14159265
int main(int argc, char **argv)
{
    int numbers;
    float angle;
    cout << "\ninput data:\n";
    cin >> numbers >> angle;
    angle = angle / 180 * PI;
    string names[numbers];
    int gorisontal[numbers];
    int intGorisontal[numbers];
    int vertical[numbers];
    int intVertical[numbers];
    int res[numbers];
    int temp1, temp2;
    for (int i = 0; i < numbers; i++)
    {
        cin >> names[i] >> temp1 >> temp2;
        gorisontal[i] = temp1;
        vertical[i] = temp2;
        res[i] = i;
    }
    float tmpAngle;
    float tmpRadius;
    for (int i = 0; i < numbers; i++)
    {
        tmpRadius = sqrt(gorisontal[i] * gorisontal[i] * 1.0 + 1.0 * vertical[i] * vertical[i]);
        tmpAngle = atan((float)vertical[i] / (float)gorisontal[i]);
        if ((vertical[i] > 0) && (gorisontal[i] < 0))
        {
            tmpAngle += PI;
        }
        if ((vertical[i] < 0) && (gorisontal[i] < 0))
        {
            tmpAngle += PI;
        }
        if ((vertical[i] < 0) && (gorisontal[i] > 0))
        {
            tmpAngle += 2 * PI;
        }
        tmpAngle += angle;
        vertical[i] = sin(tmpAngle) * tmpRadius;
        gorisontal[i] = cos(tmpAngle) * tmpRadius;
        intGorisontal[i] = (int)gorisontal[i];
        intVertical[i] = (int)vertical[i];
    }
    /*  for (int i = 0; i < numbers; i++)
    {
        cout << names[res[i]] << " " << intGorisontal[i] << " " << intVertical[i] << endl;
    }*/
    cout << endl;
    int tmp;
    for (int i = 0; i < numbers - 1; i++)
    {
        for (int j = numbers - 1; j > i; j--)
        {
            if ((intVertical[j] < intVertical[j - 1]) || ((intVertical[j] == intVertical[j - 1]) && (intGorisontal[j] < intGorisontal[j - 1])))
            {
                tmp = res[j - 1];
                res[j - 1] = res[j];
                res[j] = tmp;
                tmp = intGorisontal[j - 1];
                intGorisontal[j - 1] = intGorisontal[j];
                intGorisontal[j] = tmp;
                tmp = intVertical[j - 1];
                intVertical[j - 1] = intVertical[j];
                intVertical[j] = tmp;
            }
        }
    }
    for (int i = 0; i < numbers; i++)
    {
        //    cout << names[res[i]] << " ";
        cout << names[res[i]] << " " << intGorisontal[i] << " " << intVertical[i] << endl;
    }
    for (int i = 0; i < numbers; i++)
    {
        cout << names[res[i]] << " ";
        //    cout << names[res[i]] << " " << intGorisontal[i] << " " << intVertical[i] << endl;
    }
    cout << endl;
    return 0;
}