/*As we know, the Pythagorean Theorem tells us about the simple equation:

a^2 + b^2 = c^2
There really exist such triples a, b, c of integer numbers, which satisfy this equation. This is not self-evident fact, moreover there are no such triples for any other powers except 2 - this is the famous Fermat Theorem which could not be solved for more than 350 years.

However, for the power of 2 there are countless amount of such triples. One of them 3, 4, 5, for example.

Nevertheless, it is not always easy to find a triple satisfying some specific conditions:

In this problem you need to write a program which for given value of s = a + b + c will find the only triple which satisfies the equation.

For example, given sum of 12 the only 3, 4, 5 triple fits, for sum 30 the only 5, 12, 13 etc.

Input data will contain the number of test-cases in the first line.
Other lines will contain a single value each - the sum for which triple should be found.
Answer should contain the values of c^2 for each triple found (it is equal to a^2 + b^2 of course), separated with spaces.

Note: the real values of s would be large enough, about 10e+7 - so the simplest solutions could be inefficient.

Example:

input data:
2
12
30

answer:
25 169  */
#include <iostream>
#include <math.h>
using namespace std;
int main(int argc, char*argv[])
{
    int number;
    cout << "\ninput data:\n";
    cin >> number;
    cout << "\n";
    int s[number];
    long int res[number];
    for (int i = 0; i < number; i++)
    {
        long int a = 1;
        long int b = 1;
        long int c = 1;
        cin >> s[i];
        while ((a*a + b*b != c*c )&&(a < s[i]/3))
        {
            a++;
//          cout << a << "\n";
            b = s[i]/3;
            c = s[i] - a - b;
            while ((a*a + b*b < c*c)&&(2*b < s[i]))
            {
                b++;
                c = s[i] - a - b;
            }
        
        }
        res[i] = c*c;
    }
    cout << "\nanswer:\n";
    for (int i = 0; i < number; i++)
    {
        cout << res[i] << " ";
    }
    return 0;
}
