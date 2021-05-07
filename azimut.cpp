/* A group of pirates was lucky to lay their hands on the map of the Treasure Island.

To their disappointment the map does not contain a vague drawings with a small black cross - but instead just several lines like the following:

at the southern beach of the Island find the pole stuck into the sand with the plaque Start attached;
turn azimuth 50 and go 300 feet;
proceed 500 feet by azimuth 270;
stride 150 feet more by azimuth 300;
dig here!
Pirates read in Wikipedia that azimuth 0 is the direction to the North, azimuth 90 is the direction to the East and so on.

However, they use a kind of GPS-navigator in place of compass. Instead of directions the device can show coordinates or offsets in feets.

So pirates need to solve the following problem: suggesting that the point of "the pole with the plaque Start" is the origin of coordinate system with Y axis pointing to the North and X axis pointing to the East - what are the coordinates of the treasure point?

Input data will be in format close to the directions inscribed on a map:
The first line contains words Stand at the pole with the plaque START - you can safely ignore this.
Next lines contain words go X feet by azimuth Y - you are to extract numbers from them.
Last line contains phrase Dig here!
Answer should contain coordinates of the point where the Treasure is hidden, rounded to closest integers.

Example:

input data:
Stand at the pole with the plaque START
go 140 feet by azimuth 332
go 460 feet by azimuth 78
Dig here!

answer:
384 219 */
#include <iostream>
#include <cmath>
//#include "stdafx.h"
#include <iomanip>
#include <vector>
using namespace std;
const float PI = 3.141528;
const string FINISH = "Dig here!";
int reciveAximutandDistamceFromLine(vector<float> azimut, vector<float> distance) //recevie vectors with azimut and distance and show new coordanates from 0;0
{
    float x = 0.0;
    float y = 0.0;
    for (int i = 0; i < azimut.size(); i++)
    {
        x += sin(azimut[i] / 180 * PI) * distance[i];
        y += cos(azimut[i] / 180 * PI) * distance[i];
    }
    cout << round(x) << " " << round(y) << endl;
    return 0;
}
int main()
{
    float abcis = 0;
    float ordinate = 0;
    float a;
    vector<float> azimut;
    vector<float> distance;
    string buffer;
    cout << "\nInput data:\n";
    getline(cin, buffer);
    while (buffer != FINISH)
    {
        getline(cin, buffer); /* code */
        int tmp = 0;
        a = 0.0;
        for (int i = 0; i < buffer.size(); i++)
        {

            if (isdigit(buffer[i]))
            {
                tmp = tmp * 10 + buffer[i] - '0';
                if (!isdigit(buffer[i + 1]))
                {
                    a = tmp * 1.0;
                    tmp = 0;
                }
                if ((buffer[i + 1] == ' ') && (a != 0))
                {
                    distance.push_back(a);
                    a = 0;
                }
                if ((buffer[i + 1] == '\0') && (a != 0))
                {
                    azimut.push_back(a);
                    a = 0;
                }
            }
        }
    }

    a = reciveAximutandDistamceFromLine(azimut, distance);
    return 0;
}