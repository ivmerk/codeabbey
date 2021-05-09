/* Now all you need to do is a calculation of raising A to power of B with result taken by modulo M.

This operation is the cornerstone of many algorithms like generation of probable primes, generating keys for modern cryptography etc.

Though some languages have built-in functions for such calculation, of course it would be better for you to find another approach!

Input data will contain the number of testcases in the first line.
Next lines will have three values for A B M each.
Answer should give (A^B)%M for each case.

Example:

input data:
3
14 28 219431273
30 56 351887801
43 47 289907803

wanswer:
5022695 292780914 140818938 */
#include <iostream>
#include <vector>
using namespace std;
vector<int> getDualVectorOfFigure(long long a)
{
    vector<int> res;
    while (a >= 1)
    {
        res.push_back(a % 2);
        a /= 2;
    }
    return res;
}
unsigned long long getVectorModularsOfArgument(unsigned long long a, unsigned long long m, vector<int> bDualVectof)
{
    unsigned long long res;
    vector<unsigned long long> buffer;
    buffer.push_back(a);
    if (bDualVectof[0] == 1)
    {
        res = a;
    }
    else
    {
        res = 1;
    }
    for (int i = 1; i < bDualVectof.size(); i++)
    {
        buffer.push_back(((unsigned long long)buffer[i - 1] * (unsigned long long)buffer[i - 1]) % (unsigned long long)m);
        if (bDualVectof[i] == 1)
        {
            res *= (unsigned long long)buffer[i];
            res %= (unsigned long long)m;
        }
    }
    return res % (unsigned long long)m;
}
int main()
{
    int number;
    unsigned long long a;
    unsigned long long b;
    unsigned long long m;
    vector<unsigned long long> results;
    cout << "\ninput data\n";
    cin >> number;
    for (int i = 0; i < number; i++)
    {
        cin >> a >> b >> m;
        vector<int> bDual = getDualVectorOfFigure(b);
        results.push_back(getVectorModularsOfArgument(a, m, bDual));
        bDual.clear();
    }
    cout << "\nanswer:\n";
    for (int i = 0; i < number; i++)
    {
        cout << results[i] << " ";
    }
    return 0;
}
