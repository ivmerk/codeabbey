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
using namespace std;
int main(int argc, char *argv[])
{
    vector<int> result;
    int number;
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
        result.push_back(0);
        while (wordFirst.size() || wordSecond.size())
        {
            if (wordFirst.back() == wordSecond.back())
            {
                wordFirst.pop_back();
                wordSecond.pop_back();
            }
            else
            {

                if ((wordSecond.size() == 1) && (wordFirst.size() == 1))
                {
                    wordFirst.pop_back();
                    wordSecond.pop_back();
                    result.back()++;
                }
                else
                {
                    if (!wordFirst.size())
                    {
                        result.back()++;
                        wordSecond.pop_back();
                    }
                    else
                    {
                        if (!wordSecond.size())
                        {
                            result.back()++;
                            wordFirst.pop_back();
                        }
                        else
                        {
                            while (((wordFirst.back() == wordFirst[wordFirst.size() - 2]) && (wordSecond[wordSecond.size() - 2]) == wordFirst.back()) || ((wordSecond.back() == wordSecond[wordSecond.size() - 2]) && (wordFirst[wordFirst.size() - 2]) == wordSecond.back()))
                            {
                                wordFirst.erase(wordFirst.end() - 2);
                                wordSecond.erase(wordSecond.end() - 2);
                            }
                            if ((wordFirst[wordFirst.size() - 2] == wordSecond.back()) && (wordFirst.back() != wordSecond[wordSecond.size() - 2]))

                            {
                                wordFirst.pop_back();
                                wordFirst.pop_back();
                                wordSecond.pop_back();
                                result.back()++;
                            }
                            else
                            {

                                if (wordSecond[wordSecond.size() - 2] == wordFirst.back())
                                {
                                    wordFirst.pop_back();
                                    wordSecond.pop_back();
                                    wordSecond.pop_back();
                                    result.back()++;
                                }
                                else
                                {
                                    bool finish = false;
                                    int indexFirst = 0;
                                    int indexSecond = 0;
                                    while ((!finish) || indexFirst < 3)
                                    {
                                        if (wordFirst.back() == wordSecond[wordSecond.size() - (++indexSecond + 1)])
                                        {
                                            wordSecond.erase(wordSecond.end() - indexSecond, wordSecond.end());
                                            while (indexSecond)
                                            {
                                                indexSecond--;
                                                result.back()++;
                                                finish = true;
                                            }
                                        }
                                        if (wordSecond.back() == wordFirst[wordFirst.size() - (++indexFirst + 1)])
                                        {
                                            wordFirst.erase(wordFirst.end() - indexFirst, wordFirst.end());
                                            while (indexFirst)
                                            {
                                                indexFirst--;
                                                result.back()++;
                                                finish = true;
                                            }
                                        }
                                        if (wordSecond[wordSecond.size() - (indexSecond + 1)] == wordFirst[wordFirst.size() - (indexFirst + 1)])
                                        {
                                            wordFirst.erase(wordFirst.end() - indexFirst, wordFirst.end());
                                            wordSecond.erase(wordSecond.end() - indexSecond, wordSecond.end());
                                            while (indexFirst)
                                            {
                                                indexFirst--;
                                                result.back()++;
                                                finish = true;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
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