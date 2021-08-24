/*Nowadays many applications perform spell-checking as you type in text. Among first programs to implement this feature was Microsoft Word - you know, you type the misspelled word and it is marked with red wavy line below.

You also know that usually such spell-checking not only checks the word in question by some internal vocabulary, but also suggests some substitutions. For example if you enter crain you are proposed to change it to brain, train or chain.

How these substitutions are chosen? One of the basic and popular solution is to run through vocabulary and calculate the Levenshtein Distance between the misspelled word and each of dictionary words. Words which give minimal distance are, probably, the best substitutions.

What is the Levenshtein Distance?

Shortly speaking it is the diference between two strings. Levenshtein distance counts 1 point of penalty for each of three mismatch kind:

the letter is present in the first string but absent in the second (like plain and plan);
the letter is absent in the first string but present in the second (like tree and three);
the letter is different in the same position of two words (like woman and women).
As an example, let us see what is the distance between hate and shot:

hate -> hat      (one letter removed)
hat  -> hot      (one letter substituted)
hot  -> shot     (one letter inserted)
So the distance is 3.

Your task now is simply to calculate the Levenshtein Distance between two strings. There are different algorithms, of which most popular uses dynamic programming with a table M by N (however it could be reduced to only two lines, previous and current, reassigned after each current line is completed). You can read more in the wikipedia article on Levenshtein Distance or get info from many other sources.

Input data will contain the number of test-cases in the first line.
Next lines will contain 2 "words" each - words will contain of capital latin letters only.
Answer should contain the distances for each pair of words, separated by spaces.

Example:

input data:
5
PLAIN PLAN
TREE THREE
WOMAN WOMEN
KITTEN SITTING
YPOEHOHRIWUBXMNHZF YCPOEHORIDUBXNHZF

answer:
1 1 1 3 4
Note: this algorithm works good for languages where words are pronounced similarly to how they are spelled, like Italian, Russian, German etc. However, it is not very good for English, where women is pronounced like weeman etc., so the English have more special and complicated algorithms, like Soundex.*/
//#include "inputdata.hpp"
#include <iostream>
#include <vector>
#include <string.h>
#define MIN(x, y) ((x) < (y) ? (x) : (y))
using namespace std;
int distanceLevenshtein(vector<char> firstWord, vector<char> secondWord);
int main(int argc, char *argv[])
{
    vector<int> result;
    int number;
    int matrix[50][50];
    vector<char> wordFirst, wordSecond;
    string datastring;
    cout << "\ninput data:\n";
    cin >> number;
    cin.ignore();
    for (int i = 0; i < number; i++)
    {
        getline(cin, datastring);
        while (datastring.size())
        {
            if ((datastring[0] != ' ') && (!wordSecond.size()))
            {
                wordFirst.push_back(datastring[0]);
                datastring.erase(0, 1);
            }
            else
            {
                if (!wordSecond.size())
                {
                    datastring.erase(0, 1);
                    wordSecond.push_back(datastring[0]);
                    datastring.erase(0, 1);
                }
                else
                {
                    wordSecond.push_back(datastring[0]);
                    datastring.erase(0, 1);
                }
            }
        }
        int tmp;
        int distance = 0;
        for (int i = 0; i <= wordFirst.size(); i++)
        {
            matrix[0][i] = i;
        }
        for (int i = 0; i <= wordSecond.size(); i++)
        {
            matrix[i][0] = i;
        }
        for (int i = 1; i <= wordSecond.size(); i++)
        {
            for (int j = 1; j <= wordFirst.size(); j++)
            {
                if (wordFirst[j - 1] == wordSecond[i - 1])
                {
                    distance = 0;
                }
                else
                {
                    distance = 1;
                }
                tmp = MIN(matrix[i - 1][j] + 1, matrix[i][j - 1] + 1);
                matrix[i][j] = MIN(tmp, matrix[i - 1][j - 1] + distance);
            }
        }
        result.push_back(matrix[wordSecond.size()][wordFirst.size()]);
        wordFirst.clear();
        wordSecond.clear();
    }
    cout << "\nanswer:\n";
    while (result.size())
    {
        cout << result.front() << ' '; /* code */
        result.erase(result.begin());
    }
    cout << endl;
    return 0;
}

int distanceLevenshtein(vector<char> firstWord, vector<char> secondWord /*,int distance*/)
{
    /* int firstVariant, secondVariant, thirdVariant, minDistance;
    vector<char> tmp, tmp1;
    if ((!firstWord.size()) && (!secondWord.size()))
    {
        return distance;
    }
    if (!firstWord.size())
    {
        return distance + secondWord.size();
    }
    if (!secondWord.size())
    {
        return distance + firstWord.size();
    }
    if (firstWord.back() == secondWord.back())
    {
        firstWord.pop_back();
        secondWord.pop_back();
        return distanceLevenshtein(firstWord, secondWord, distance);
    }
    tmp = firstWord;
    tmp1 = secondWord;
    distance++;
    tmp.pop_back();
    tmp1.pop_back();
    firstVariant = distanceLevenshtein(tmp, secondWord, distance);
    secondVariant = distanceLevenshtein(firstWord, tmp1, distance);
    thirdVariant = distanceLevenshtein(tmp, tmp1, distance);
    minDistance = (firstVariant < secondVariant) ? firstVariant : secondVariant;
    minDistance = (minDistance < thirdVariant) ? minDistance : thirdVariant;
    return minDistance;*/
    int a = firstWord.size() + 1;
    int b = secondWord.size() + 1;
    int matrix[a][b];
    int tmp;
    int distance = 0;
    for (int i = 0; i < firstWord.size() + 1; i++)
    {
        matrix[0][i] = i;
    }
    for (int i = 0; i < secondWord.size() + 1; i++)
    {
        matrix[i][0] = i;
    }
    for (int i = 1; i <= firstWord.size(); i++)
    {
        for (int j = 1; j <= secondWord.size(); j++)
        {
            if (firstWord[i - 1] == secondWord[j - 1])
            {
                distance = 1;
            }
            else
            {
                distance = 0;
            }
            tmp = MIN(matrix[i - 1][j] + 1, matrix[i][j - 1] + 1);
            matrix[i][j] = MIN(tmp, matrix[i - 1][j + 1] + distance);
        }
    }
    return matrix[firstWord.size() + 1][secondWord.size() + 1];
}