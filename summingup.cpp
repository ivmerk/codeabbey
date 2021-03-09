/*It is easy to sum two numbers in Brainfuck, for example by code like this:

;>;        input two numbers into cells 0 and 1
[          while the number in the cell 1 is not zero
    -      decrement cell 1
    <      shift to cell 0
    +      increment cell 0
    >      shift back to cell 1
]
<:         shift to cell 0 and print the result
This task is only a bit more tricky. You need not only to get the sum of two values, but also keep these values. More exactly:

Please note that stack operations are not enabled for this task. Otherwise it would be too trivial! :)
Input data has two values A and B in the single line.
Output should have the sum A+B printed into it.
Additionally after the stop the program should have values A, B, A+B in the cells 0, 1 and 2 respectively.*/
#include <iostream>
#include <string>
using namespace std;
int main(int argc, char *argv[])
{
    int a, b;
    cout << "\ninput data:\n";
    cin >> a >> b;
    string answer;
    for (int i = 0; i < a; i++) //input a;
    {
        answer.push_back('+');
    }
    answer.push_back('>');      // next cell;
    for (int i = 0; i < b; i++) // input b;
    {
        answer.push_back('+');
    }
    answer.push_back('<'); //retur to 0 cell;
    answer.push_back('['); //starting of dubkicating the first value and puting one to summary cell;
    for (int i = 0; i < a; i++)
    {
        answer.push_back('-');
        answer.push_back('>');
        answer.push_back('>');
        answer.push_back('+');
        answer.push_back('>');
        answer.push_back('+');
        answer.push_back('<');
        answer.push_back('<');
        answer.push_back('<');
    }
    answer.push_back(']');
    answer.push_back('>'); //return to 1 cell;
    answer.push_back('['); //starting of dubkicating to second value and puting one to summary cell;
    for (int i = 0; i < b; i++)
    {
        answer.push_back('-');
        answer.push_back('>');
        answer.push_back('+');
        answer.push_back('>');
        answer.push_back('>');
        answer.push_back('+');
        answer.push_back('<');
        answer.push_back('<');
        answer.push_back('<');
    }
    answer.push_back(']');
    answer.push_back('>');
    answer.push_back('>');
    answer.push_back('[');
    for (int i = 0; i < a; i++)
    {
        answer.push_back('-');
        answer.push_back('<');
        answer.push_back('<');
        answer.push_back('<');
        answer.push_back('+');
        answer.push_back('>');
        answer.push_back('>');
        answer.push_back('>');
    }
    answer.push_back(']');
    answer.push_back('>');
    answer.push_back('[');
    for (int i = 0; i < b; i++)
    {
        answer.push_back('-');
        answer.push_back('<');
        answer.push_back('<');
        answer.push_back('<');
        answer.push_back('+');
        answer.push_back('>');
        answer.push_back('>');
        answer.push_back('>');
    }
    answer.push_back(']');
    answer.push_back('<');
    answer.push_back('<');
    answer.push_back(':');

    cout << answer << endl;
    return 0;
}