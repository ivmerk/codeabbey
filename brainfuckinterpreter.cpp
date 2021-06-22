/* We are going to make extension for our site - to add problems which should be solved in Brainfuck programming language.

But of course we need an executing system (interpreter) for this funny esoteric language.

In this problem you should create such interpreter. Do not be afraid - it is easier to write Brainfuck interpreter itself than to write Brainfuck problems for such interpreter.

We ask you to implement slightly altered version of the language - Brainfuck++ which includes two additional commands ; and :.

Please, refer to the wiki article by the link above to read specification of the language.

Input data will contain two lines.
The first input line contains Brainfuck program without any spare characters.
The second line contains a sequence of numbers which would be consumed as input.
Answer should contain output of the program.

Example:

input data:
;>;<[->+<]:>:
3 5

answer:
0 8 */
#include <iostream>
#include <vector>
#include <sstream>
#include <limits>
#include <stack>
#include <string>
using namespace std;
int main(int argc, char **argv)
{
    vector<int> figuresData;
    string programmData;
    vector<char> programmDataForFuncion;
    vector<int> result;
    stack<char> steck;
    int ram[100];
    int pointerOfTheRam = 0;
    string tmp, tmp1;
    int tmpInt;
    for (int i = 0; i < 100; i++)
    {
        ram[i] = 0;
    }
    bool isCorrect = true;
    cout << "\ninput data:\n";
    cin >> programmData;
    getline(cin, tmp);
    while ((cin.peek() != '\n') && (cin.peek() != '\0'))
    {
        cin >> tmpInt;
        figuresData.push_back(tmpInt);
    }
    int openBurk = 0;
    for (int i = 0; i < programmData.size(); i++)
    {
        switch (programmData[i])
        {
        case ';':
            ram[pointerOfTheRam] = figuresData.front();
            figuresData.erase(figuresData.begin());
            break;
        case '>':
            pointerOfTheRam++;
            break;
        case '<':
            pointerOfTheRam--;
            break;
        case '+':
            ram[pointerOfTheRam]++;
            break;
        case '-':
            ram[pointerOfTheRam]--;
            break;
        case '[':
            if (!ram[pointerOfTheRam])
            {
                openBurk++;
                while (openBurk)
                {
                    i++;
                    if (programmData[i] == ']')
                    {
                        openBurk--;
                    }
                    if (programmData[i] == '[')
                    {
                        openBurk++;
                    }
                }
            }
            break;
        case ']':
            if (ram[pointerOfTheRam])
            {
                openBurk++;
                while (openBurk)
                {
                    i--;
                    if (programmData[i] == ']')
                    {
                        openBurk++;
                    }
                    if (programmData[i] == '[')
                    {
                        openBurk--;
                    }
                }
                i--;
            }
            break;
        case ':':
            result.push_back(ram[pointerOfTheRam]);
            break;
        default:
            break;
        }
    }

    cout << "\nanswer:\n";
    while (result.size())
    {
        cout << result.front() << " ";
        result.erase(result.begin());
    }
    cout << endl;
    return 0;
}