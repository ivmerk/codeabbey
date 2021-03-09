/*
 Many mathematical problems are solved in programming not precisely, but approximately, by several computations of the result, each of which is more and more close to the goal.

Let us practice the method of approximate calculation of the square root with the following approach:

Let us search for square root r of the given value X.
Use some arbitrary value, say r = 1 as the first approximation (surely it is too rough).
For proper square root the equation r = X / r should hold.
So let us calculate d = X / r (it would not be equal to r since r is not precise root).
And take average between r and d as the new approximation.
E.g. overall formula of the calculation step is (here := is an assignment):

      r  +  X / r
r := -------------
           2
Refer to Square Root Approximation article for more details on the Heron's Method.

So we are given values X for which to perform calculations and number of steps N to perform.
Use r = 1 at the beginning, and output resulting approximation (after N steps).

Input data will give the number of test-cases in first line.
Next lines will contain test-cases themselves, each containing the value X for which square root should be calculated and N - the number of calculation steps.
Answer should contain calculated approximations for each case, separated by space.

Example:

input data:
3
150 0
5 1
10 3

answer:
1 3 3.196
Results should have precision of 1e-7 = 0.0000001 or better!
 */
#include <iomanip>
#include <iostream>
using namespace std;
double stepcalc(double a, int b)

{
        double r = 1.0;
        int i=0;
while (i<b){        
        r = (r + a/r)/2;
        i++;
      }
                return r;
}
int  main ()
{
int n,  arg2;
double arg1;
cout << "\n" << "input data" << "\n";
cin >> n;
cout << "\n";
double* arr = new double[n];
for (int i = 0; i < n; i++){
        cin >> arg1;
        cin >> arg2;
        arr[i] = stepcalc(arg1, arg2);
}
cout << "\n" << "answer" << "\n";
for (int i = 0; i < n; i++)
     cout << setprecision(9)<< arr[i] << " " ;
return 0;
}
