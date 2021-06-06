/* Very common problem in computational geometry is to find distance between the point and the line segment. It is heavily exploited in programming 3D video games when recalculating visibility of walls for player while redrawing each frame (i.e it is could be solved for 1000 wall fragments in each frame and about 50 frames are completely recalculated during each second).

The definition of the distance between point and segment is like following:

draw a line through both ends of a segment (i.e. the line to which this segment belongs);
from our point cast a perpendicular to this line - the length of this perpendicular is the distance between the point and the line;
if the other end of the perpendicular belongs to our segment (i.e. lays between its ends), then the distance to this segment equals to distance to this line;
otherwise distance from point to segment equals to distance to nearest of its ends.
For example, see the picture above - line segment is drawn with blue and perpendiculars from 2nd and 3rd points fall directly onto this segment, so they represent the distance from these points. On other hand perpendiculars from 1st and 4th points fall out of segment (and they are not shown), so that distances are defined simply by the nearest end of a segment (distances from all points are represented with grey lines). The line on which the segment lays is shown with light-green.

Input data will contain the number of test-cases in first line.
The following lines contain six values each: x1 y1 x2 y2 xp yp - denoting the segment between points (x1,y1) and (x2,y2) and the point (xp,yp) to which a distance should be calculated.
Answer should contain distances from points to segments for each test-case, separated with spaces.

Example:

input data:
3
1 1 5 5 2 3
2 3 7 8 2 0
12 8 18 3 5 7

answer:
0.707106781 3 7.07106781187 */
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;
double getLength(int x1, int y1, int x2, int y2)
{
    return sqrt((x1 - x2) * (x1 - x2) * 1.0 + (y1 - y2) * (y1 - y2) * 1.0);
}
double getDistance(int x1, int y1, int x2, int y2, int xp, int yp)
{
    double a, b, c, cosb, cosc;
    a = getLength(x1, y1, x2, y2);
    b = getLength(x1, y1, xp, yp);
    c = getLength(xp, yp, x2, y2);
    cosc = (a * a + b * b - c * c) / (2 * a * b);
    cosb = (a * a - b * b + c * c) / (2 * a * c);
    if (cosc <= 0)
    {
        return b;
    }
    if (cosb <= 0)
    {
        return c;
    }
    return (sqrt(1 - cosc * cosc) * b);
}
int main()
{
    int numbers;
    int x1, y1, x2, y2, xp, yp;
    vector<double> result;
    string data;
    cout << "\ninput data:\n";
    cin >> numbers;
    cout << "\n";
    cin.ignore();
    for (int i = 0; i < numbers; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2 >> xp >> yp;
        result.push_back(getDistance(x1, y1, x2, y2, xp, yp));
    }
    cout << "\nanswer\n";
    cout << setprecision(13) << fixed;
    while (result.size())
    {
        //  double tmp = result[0];
        cout << result.front() << " ";
        result.erase(result.begin());
    }
    cout << endl;
    return 0;
}
