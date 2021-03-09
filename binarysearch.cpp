/*Programming of Binary Search is the common task since it is used for searching through sorted arrays (that's why we learnt sorting) as well as for solving math equations. Let us practice the latter application. Please kindly refer to the Binary Search article for thorough explanations if you feel not well acquainted with the idea of the algorithm.

The goal is to solve the equation which has the following form:

A * x + B * sqrt(x ^ 3) - C * exp(-x / 50) - D = 0
here A, B and C all would be positive so that function is monotonic. Solution is guaranteed to exist somewhere in range 0 <= x <= 100.

Solution should be calculated with precision 0.0000001 = 1e-7 or better.

Input data will contain number of test-cases in the first line.
Next lines will contain four numbers for each test-case, i.e. A B C D separated by values.
Answer should contain solutions - i.e. values of x which satisfy equation with given coefficents - several answers (for several test-cases) should be separated with spaces.

Example:

input data:
2
0.59912051 0.64030348 263.33721367 387.92069617
15.68387514 1.26222280 695.23706506 698.72384731

answer:
73.595368554162 41.899174957955
Please note, as stated above, your results may be slightly different as stated above, due to nature of floating point arithmetics, e.g. 73.595368554951 41.899174957417 will pass anyway.

You may also want to try the Binary Search in Array problem - even more popular use-case for this algorithm! */
#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
long double checking (long double a, long double b, long double c,  long double x){
        return a*x*1.0 + b*sqrt(x*x*x*1.0) - c*exp(1.0*(-x)/50);

}
int main(){
const long double omega = 1e-10;
int number;
cout << "\n" << "input data:" << "\n";
cin >> number;
long double a, b, c, d, res, oldres, tmp, xmin, xmax;
cout << "\n";
long double resarr[number];
for (int i = 0; i < number; i++){
        xmin = 0.0;
        oldres = xmin;
        xmax = 100.0;
        res = (xmin+xmax)/2.0;

        cin >> a >> b >> c >> d;
        //cout << checking(a,b,c, res) << " "<< res;
        do {
                oldres = res;
                if (checking(a,b,c,res) < d) {
                        xmin = res;

                }
                else xmax = res;
                res = (xmin + xmax)/2.0;

        } while ((((res - oldres)) >0 && ((res - oldres*1.0) > omega))||((oldres-res) > 0)&&((oldres - res) > omega));
 cout.precision(17);
        resarr[i] = res;        
//cout << res <<  "\n";
}
cout << "\n" << "answere:" << "\n";
for (int i = 0; i < number; i++)
        cout << resarr[i] << " ";
cout << "\n";
return 0;
}
