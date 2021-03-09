/*Many computer games are played by moving some pieces or heroes over a map or a field of some kind. There are two popular kinds for geometry of such maps:

rectangular grid - the field is tiled by rectangles or squares;
hexagonal grid - the field is tiled by hexagons.
Well-known game Heroes of Might and Magic for example utilized both variants - rectangular grid is used on the world map while riding between castles (with ability of diagonal movements), while hexagonal grid is used as a battle field in combat mode.

Hexagonal tiling looks more beautiful for user, but the programming its geometry is slightly more tricky. That is what we are going to practice now.

Problem statement

Suppose the "hero" is placed at some cell of hexagonal grid. Then he can move in six directions. On the picture above X marks the initial cell and letters A, B, C, D, E, F - the possible movements for 1 step. A moves the hero directly to the right and other directions are named in the counter-clockwise order.

You will be given a sequence of steps, performed by hero, each step described by a corresponding letter. You are to tell after all these steps, how far the hero is now from his initial position.

We agree that the hero is always placed at the center of the cell and that distance between centers of two adjacent cells (i.e. sharing a side) is 1.0.

Input data1 will contain number of test-cases in the first line.
Next lines will contain the sequence of steps (one sequence per line) as a string of letters.
Answer should contain the distances between starting and ending point for each of sequences, separated by spaces and with accuracy of 1e-7 at least.

Example:

input data1:
3
AABF
FEDCBA
BCB

answer:
3.0 0.0 2.64575131 */
#include <iostream>
#include <cmath>
#include <string>
using namespace std;
int main(int argc, char*argv[])
{
    int number;
    string data1;
    cout << "\ninput data1:\n";
    cin >> number;
    double x, y; // coordinates
    double heigth = 1.0;
    double width = sqrt(3.0) / 2;

    double res[number];
    for (int i = 0; i < number; i++)
    {
        y = 0;
        x = 0;
        
        cin >> data1;
        for (int j = 0; j < data1.size(); j++)
        {
            if ( data1[j] == 'A')
            {
                y+=heigth;
            };
            if ( data1[j] == 'B')
            {
                y+=heigth*0.5;
                x+= width;
            };
            if ( data1[j] == 'C')
            {
               y -=heigth*0.5;
               x += width; 
            };
            if ( data1[j] == 'D')
            {
                y -= heigth;
            };
            if ( data1[j] == 'E')
            {
                y -= heigth * 0.5;
                x -= width;

            };
            if ( data1[j] == 'F')
            {
                y+=heigth*0.5;
                x -= width;
            };
        }
        double tmp;
    //    cout << "\n" << x << " " << y;
        tmp = x*x + (y)*(y);
       res[i] = sqrt(tmp);   
        //t = begin(data1);
    }
    //cout << data1[data1.size()-1] << endl;
    cout << "\nanswer:\n";
    cout.precision(9);
    for (int i = 0; i < number; i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}