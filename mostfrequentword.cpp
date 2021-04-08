/* The task Matching Words allows easy but ineffective solution because it works with very small input data.

This problem is similar, but you will need to proceed almost one million words and choose a single, most frequent of them - it is very often and very important task - for example performed by search engines over web pages. You will need to use efficient algorithm, otherwise your program will work for hours and perhaps days.

Since it is not practical to provide test-cases consisting of so many letters along with problem statement, you will generate the words yourself.

Use algorithm from the task Funny Words Generator to create a list of exactly 900000 words, each 6 letters long.
You should use exactly the same Linear Congruential Generator as random generator. The only input parameter would be the seed for your random number generator (LCG).

Input data will contain a single value - the seed for random generator which you will use to generate list of words.
Answer should contain a single word - one most frequently encountered in the list.

Example:

input data:
99658

answer:
riguzi */
#include <vector>
#include <string>
#include <iostream>
using namespace std;
void wordsGenerator(int x0, int n, vector<string> &words)
{
    const char consanant[] = {'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'r', 's', 't', 'v', 'w', 'x', 'z'}; // 19 letters
    const char vowels[] = {'a', 'e', 'i', 'o', 'u', '\0'};                                                                    // 5 letters
    int a = 445;
    int c = 700001;
    int m = 2097152;
    int xn = x0;
    char tmp[7];
    vector<int> res;
    int numbers = 6;
    for (int i = 0; i < n; i++)
    {
        for (int u = 0; u < numbers; u++)
        {
            xn = (a * xn + c) % m;
            if (u % 2 == 0)
                tmp[u] = consanant[xn % 19];
            else
                tmp[u] = vowels[xn % 5];
        }
        if ((i == 0) || (i == 1))
        {
            res.push_back(1);
            words.push_back(tmp);
        }
        else
        {
            for (int j = 0; j < words.size(); j++)
            {
                if (tmp == words[j])
                {
                    res[j]++;
                    break;
                }
                if (j == words.size() - 1)
                {
                    words.push_back(tmp);
                    res.push_back(1);
                    break;
                }
            }
        }
    }
    int max = 0;
    int index = 0;

    for (int i = 0; i < res.size(); i++)
    {
        if (max < res[i])
        {
            max = res[i];
            index = i;
        }
    }
    cout << "\n"
         << words[index] << endl;
}
int main(int argc, char **argv)
{
    vector<string> data;
    int figure;
    cout << "/ninput data:/n";
    cin >> figure;
    string finish;
    int quantityOfTheWords = 900000;
    wordsGenerator(figure, quantityOfTheWords, data);
    //  countingOfWord(finish, data);
    return 0;
}
