/* You have probably already wrote the program for calculating Area of Triangle - let us now get acquainted with the extention of this problem - the calculation of area for arbitrary convex polygon.

Polygon is called convex if each of its angles is less than PI/2, or in other words, if any line connecting any pair of points belonging to it lies completely inside. This somewhat simplifies handling of such shapes.

les. We hope that pictures above may give you idea on three different approaches to do this.

Input data contain the number of vertices of the polygon.
Next lines contain a pair of numbers each - X and Y coordinates for the vertex (in correct CCW order).
Answer should contain the area of the shape surrounded by these points.

Example:

input data:
5
51 9
77 10
92 71
62 84
29 94

answer:
3274.5 */
#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
int main(int argc, char* argv[])
{
    int number;
    cout << "\ninput data:\n";
    cin >> number;
    int x[number];
    int y[number];
    double a, b, c, p;
    double result = 0.0;
    for(int i = 0; i < number; i++)
    {
        cin >> x[i] >> y[i];
    }
    for(int i = 1; i < number-1; i++)
    { 
        a = sqrt((x[0] - x[i]) * (x[0] - x[i]) * 1.0 + (y[0] - y[i]) * (y[0] - y [i]) * 1.0);
        b = sqrt((x[0] - x[i+1]) * (x[0] - x[i+1]) * 1.0 + (y[0] - y[i+1]) * (y[0] - y [i+1]) * 1.0);
        c = sqrt((x[i+1] - x[i]) * (x[i+1] - x[i]) * 1.0 + (y[i+1] - y[i]) * (y[i+1] - y [i]) * 1.0);
        p = (a + b + c) / 2.0;
        result += sqrt(p * (p - a) * (p - b) * (p - c));
    }
    cout << setprecision(18);
    cout << "\nanswer:\n" << result << "\n";
    return 0;
}