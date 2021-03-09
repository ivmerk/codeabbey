/*Being able to calculate area of triangle is quite important since many more complex tasks are often easily reduced to this (and we will use it too later).
One of the oldest known methods is Heron's Formula which takes as inputs the lengths of the triangle's sides.
In this problem you however is to write a program which uses X and Y coordinates of the triangle's vertices instead. So you can use either this formula somehow or find another one.
Input data will contain the number of triangles to process.
Next lines will contain 6 values each, in order X1 Y1 X2 Y2 X3 Y3, describing three vertices of a triangle.
Answer should give areas of triangles separated by space (precision about 1e-7 is expected).
Example:

data:
3
1 3 9 5 6 0
1 0 0 1 10000 10000
7886 5954 9953 2425 6250 2108

answer:
17 9999.5 6861563
*/
#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
int main(){
int numbers;
cout << "\n" << "data:" << "\n";
cin >> numbers;
cout << "\n";
double*resarr = new double [numbers];
int x1, y1, x2, y2, x3, y3;
for (int i = 0; i < numbers; i++){
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        double a = sqrt((x1-x2)*(x1-x2)*1.0+(y1-y2)*(y1-y2)*1.0);
        double b = sqrt((x3-x2)*(x3-x2)*1.0+(y3-y2)*(y3-y2)*1.0);
        double c = sqrt((x3-x1)*(x3-x1)*1.0+(y3-y1)*(y3-y1)*1.0);
        resarr[i] =0.5*sqrt(a*a*c*c - ((a*a+c*c-b*b)*(a*a+c*c-b*b))/4);
                
}
cout  <<  setprecision(8);
cout << "\n" << "answer:" << "\n";
for (int i = 0; i < numbers; i++){
        cout << resarr[i] << " ";
}
delete [] resarr;
return 0;
}
