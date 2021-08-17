/*The task is just the same as Fibonacci Divisibility, however, input values here are greater to prevent you from implementing straightforward calculations using long arithmetics (this allows users in Java or Python to solve the mentioned task easily enough).

You should implement solution which works fast. A second or two is sufficient to run the proper solution (even with not very modern computer).

Hint: you need not long arithmetic for this task.

Input data in the first line will contain the number of test-cases.
Next line will contain exactly this of divisors M for which you should give answers.
Answer should contain indices of members of Fibonacci Sequence, separated by spaces.

Example:

input data:
2
233328 433156

answer:
1620 282
Values will not exceed 2000000. */
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
    int data;
    int fibNumber = 3;
    int mdata;
    int fibvalueminus = 1;
    int tmp;
    int fibvalue = 2;
    vector<int> result;
    string datastring;
    cout << "\nввести число\n";
    cin >> data;
    cin.ignore();
    getline(cin, datastring);
    for (int i = 0; i < data; i++)
    {
        tmp = 0;
        while ((datastring[0] != ' ') && (datastring[0] != '\n') && (datastring[0] != '\0'))
        {

            tmp = tmp * 10 + (datastring[0] - '0');
            datastring.erase(datastring.begin());
        }
        datastring.erase(datastring.begin());
        mdata = tmp;
        fibNumber = 3;
        fibvalueminus = 1;
        fibvalue = 2;
        while (((fibvalue + fibvalueminus) % mdata))

        {
            tmp = (fibvalue + fibvalueminus) % mdata;
            fibvalueminus = fibvalue;
            fibvalue = tmp;
            fibNumber++;
        }
        result.push_back(++fibNumber);
    }
    cout << "\n";
    while (result.size())
    {

        cout << result[0] << " ";
        result.erase(result.begin());
    }
    return 0;
}