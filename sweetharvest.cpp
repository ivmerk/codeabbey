/*Here is a variation of another popular task for practicing dynamic programming approach (though of course precise algorithm is not explained by these words).

The Rabbit is going to cross the river. There is a straight chain of tiny isles across the flow and the animal should jump from one to another because it surely could not swim.

At each of the isles there are some candies. When the Rabbit arrives to the new isle, it collects all the candies here.

However, the Rabbit could not jump directly to the next isle in the chain - it just is too strong to make short jumps. So, instead, it can jump over the one or two isles (i.e. from the 1st for example to 3rd or 4th but not to 2nd or 5th and further). Also the Rabbit could not jump back.

You can see the sample of the Rabbit's path on the drawing above. It visits 1st, 3rd, 6th and 8th isles and collects:

11 + 3 + 13 + 7 = 34
the amount of 34 candies. Obviously he could do better if the path is chosen more wisely.

Your task is to choose the best path for Rabbit over the given chain of isles - i.e. to maximize the amount of the candies collected. Note that Rabbit starts from 1st isle and finishes either on the Nth or (N-1)th where N is the total number of isles (because from these two it will necessarily jump immediately to the other bank).

Input data will contain the number of test-cases in the first line.
Next lines contain one test-case each - i.e. one chain of isles, described by the array of numbers - amounts of candies at each isle.
Answer should contain the maximum possible amount of candies gathered for each test case.

Example:

input data:
2
11 5 3 17 2 13 19 7
9 7 12 7 16 3 7 17 14 13 4 6 11 6 3 3 5 4 11 3 15 12 14 2 15 19 11 12

answer:
48 157 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;
int getAmountOfCandies(vector<int> data)
{
    int result = 0;
    vector<int> placeOfTheRebbit;
    vector<int> amountOfTheRebbit;
    int lengthTmp;
    placeOfTheRebbit.push_back(0);
    amountOfTheRebbit.push_back(data[0]);
    while (!result)
    {
        lengthTmp = placeOfTheRebbit.size();
        for (int i = 0; i < lengthTmp; i++)
        {
            if (placeOfTheRebbit[i] <= (data.size() - 3))
            {
                placeOfTheRebbit[i] += 2;
                amountOfTheRebbit[i] += data[placeOfTheRebbit[i]];
                if (placeOfTheRebbit[i] <= (data.size() - 2))
                {
                    placeOfTheRebbit.push_back(placeOfTheRebbit[i] + 1);
                    amountOfTheRebbit.push_back(data[placeOfTheRebbit[i] + 1] - data[placeOfTheRebbit[i]] + amountOfTheRebbit[i]);
                }
            }
        }
        for (int i = 0; i < placeOfTheRebbit.size(); i++)
        {
            if (placeOfTheRebbit[i] != (data.size() - 1))
            {
                result = 0;
                break;
            }
            result = amountOfTheRebbit[i];
        }
    }

    return result;
}
void getVectorFromString(string input, vector<int> &output)
{
    //  vector <int> output;
    int tmp;
    if ((input[0] <= '9') && (input[0] >= '0') && (input[1] <= '9') && (input[1] >= '0'))
    {
        tmp = (input[0] - '0') * 10 + (input[1] - '0');
        output.push_back(tmp);
    }
    if ((input[0] <= '9') && (input[0] >= '0') && (input[1] == ' '))
    {
        tmp = (input[0] - '0');
        output.push_back(tmp);
    }

    for (int i = 2; i < input.size(); i++)
    {
        if ((input[i] <= '9') && (input[i] >= '0') && (input[i + 1] <= '9') && (input[i + 1] >= '0'))
        {
            tmp = (input[i] - '0') * 10 + (input[i + 1] - '0');
            output.push_back(tmp);
        }
        if ((input[i] <= '9') && (input[i] >= '0') && (input[i - 1] == ' ') && ((input[i + 1] == ' ') || (input[i + 1] == '\0')))
        {
            tmp = (input[i] - '0');
            output.push_back(tmp);
        }
    }
}
int main()
{
    int number;
    vector<int> data;
    string tmp;
    cout << "\ninput data:\n";
    cin >> number;
    cin.ignore();
    for (int i = 0; i < number; i++)
    {
        getline(cin, tmp);
        getVectorFromString(tmp, data);
        getAmountOfCandies(data);
    }
    return 0;
}