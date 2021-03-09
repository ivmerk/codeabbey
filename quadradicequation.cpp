/*Now we are to create a program for solving quadratic equation. Supposedly you have learnt in school that such equation has a form of:

A * x^2 + B * x + C = 0
where A, B and C are some constants (called "coefficients" of equation) and x is a variable. To solve such equation means to find x for which the formula becomes true. For example with coefficients 3, -5 and -2 we have equation:

3 * x^2 - 5 * x - 2 = 0
and we can see that value x = 2 is quite suitable.

General formula for finding such values (or "roots") via coefficients of equation is the following:

x1 = (-B + sqrt(B^2 - 4*A*C)) / (2*A)
x2 = (-B - sqrt(B^2 - 4*A*C)) / (2*A)
For example above these expressions will produce:

x1 = (5 + sqrt(5^2 + 4*3*2)) / (2*3) = (5 + 7) / 6 = 2
x2 = (5 - sqrt(5^2 + 4*3*2)) / (2*3) = (5 - 7) / 6 = -1/3
I.e. the equation really has two roots. Strictly speaking, here are always two roots. However, they could be: - either distinct, when expression under sqrt is positive; - or equal, when expression under sqrt is zero; - and in other cases even complex numbers - i.e. values like U+V*i where i = sqrt(-1).

Refer to wikipedia for more about Complex Numbers or Quadratic Equations at whole.

Input data will contain number of test-cases in the first line.
Each of test-cases will consist of three values (for A, B and C respectively).
Answer should contain a pair of roots for each case (even when they are equal). Use space to separate values of the pair and use semicolon followed by space to separate pairs themselves. Complex numbers should be given like 5-2i or -1+1i.

Note also:

order of values inside the pair is important - for real roots output the bigger one first; for complex roots output a+bi first and a-bi last;
roots would be always expressed with integer numbers in this task, so print no any decimal points etc.
Example:

input data:
3
3 -3 -6
1 0 1
9 90 225

answer:
2 -1; 0+1i 0-1i; -5 -5 */
#include <iostream>
#include <math.h>
int diskrat2 (int a, int b, int c){
        return (b*b - 4*a*c);}
using namespace std;
int main(){
int numbers;
cout << "\n" << "input data:" << "\n";
cin >> numbers;
cout << "\n";
int*resarr1 = new int [numbers];
int*resarr2 = new int [numbers];
int*resarr3 = new int [numbers];
int a, b, c, d;
for (int i = 0; i < numbers; i++){
        cin >> a >> b >> c;
        d = diskrat2(a, b ,c);
        if (d >= 0) {
                resarr1[i] = ((-b + (int)sqrt(d))/(2*a));
                resarr2[i] = ((-b - (int)sqrt(d))/(2*a));
        }
        if (d < 0) {
                resarr1[i] = (-b )/(2*a);
                resarr2[i] = (-b )/(2*a);
                resarr3[i] = ((int)sqrt(-d))/(2*a);
                if (resarr3[i] < 0)
                        resarr3[i] *= -1;
        }
        if (resarr1[i] < resarr2[i]){
                 int tmp = resarr1[i];
                 resarr1[i] = resarr2[i];
                 resarr2[i] =tmp;
                }
}
cout << "\n" << "answer" << "\n";
for (int i = 0; i < numbers-1; i++){
        if (resarr3[i])
                cout << resarr1[i] << "+" << resarr3[i] << "i " << resarr2[i] << "-" << resarr3[i] << "i; ";
        else 
                cout <<resarr1[i] << " " << resarr2[i] << "; ";
}
        if (resarr3[numbers-1])
                cout << resarr1[numbers-1] << "+" << resarr3[numbers-1] << "i " << resarr2[numbers-1] << "-" << resarr3[numbers-1] << "i ";
        else 
                cout <<resarr1[numbers-1] << " " << resarr2[numbers-1] << " ";
cout << "\n";
delete [] resarr1;
delete [] resarr2;
delete [] resarr3;
return 0;
}
