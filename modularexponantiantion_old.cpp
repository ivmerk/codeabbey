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

answer:
5022695 292780914 140818938 */
#include <iostream>
#include <vector>
using namespace std;
unsigned int modexp(unsigned int a, unsigned int b, unsigned int m)
{
    if (b == 0)
    {
        return 1;
    }
    unsigned int z = modexp(a, b / 2, m);
    if (b % 2 == 0)
    {
        return (z * z) % m;
    }
    else
    {
        return (a * z * z) % m;
    }
}
int main()
{
    int number;
    unsigned int a;
    unsigned int b;
    unsigned int m;
    vector<unsigned int> results;
    cout << "\ninput data\n";
    cin >> number;
    for (int i = 0; i < number; i++)
    {
        cin >> a >> b >> m;
        results.push_back(modexp(a, b, m));
    }
    cout << "\nanswer:\n";
    for (int i = 0; i < number; i++)
    {
        cout << results[i] << " ";
    }
    return 0;
}