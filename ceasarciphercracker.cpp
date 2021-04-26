/*Input data will contain the number of encrypted messages in the first line.
Next lines will contain the encrypted lines themselves. Each line is encoded with separate key!
Answer should contain three first words of each decrypted line followed by the value of the key. Several answers should be separated with spaces.

Additional info:

the key will always be a value between 1 and 25 inclusive;
lines will contain only capital latin letters and spaces to separate words;
original messages are in English, from 60 to 100 characters long.
Example:

input data:
2
XIP DBSFT PG ESFBNT
VJQWIJ KV OCMGU VJKPIU XGTA SWGGT

answer:
WHO CARES OF 1 THOUGH IT MAKES 2 */
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;
const int KEYMIN = 1;
const int KEYMAX = 25;
bool checkTheWord(string checkingWord) //checking words from dictionarry
{
    //cout << "\nstartingchecking\n";
    string wordFromFile;
    ifstream in("./words.txt");
    if (in.is_open())
    {
        while (getline(in, wordFromFile))
        {
            if (checkingWord == wordFromFile)
            {
                in.close();
               // cout << "\ntrue\n";
                return true;
            }
        }
    }
    in.close();
   // cout << "\nfalse\n";
    return false;
}
string decodWordLow (int key, string incomingWord)
{
    //cout << "\n" << incomingWord;
    string outWord;
    outWord = incomingWord;
    for (int u = 0; u < outWord.size(); u++)
        {   
            if (key <= (outWord[u] - 'A'))
            {
                outWord[u] -= key;
            } else {
                outWord[u] += 'Z' - 'A' - key + 1;
            }
            outWord[u] += 'a' - 'A';
        }
    return outWord;
}
string decodWordUpper (int key, string incomingWord)
{
    string outWord;
    outWord = incomingWord;
    for (int u = 0; u < outWord.size(); u++)
        {   
            if (key <= (outWord[u] - 'A'))
            {
                outWord[u] -= key;
            } else {
                outWord[u] += 'Z' - 'A' - key + 1;
            }
        }
    return outWord;
}
int checkingTheKey(vector <string> inputedWord)
{
    int key = KEYMIN;
    bool keyReceived = false;
    string wordBuffer;
    while (!(keyReceived))
    {
        for (key = KEYMIN; key < KEYMAX; key++)
        {
            //cout << "\n" << key;
            int k = 0;
            do {
            wordBuffer = inputedWord[k++];
            wordBuffer = decodWordLow(key, wordBuffer);
            wordBuffer.push_back('\r');
            if (!checkTheWord(wordBuffer))
            {
                keyReceived = false;
                break;
            } else {
                keyReceived = true;
                //cout << wordBuffer;
            }
            } while (k < 3); // if key ok 3 words have to be in dict
            if (keyReceived)
            {
                break;
            }    
        }
    }

    return key;
}
int main(int argc, char **argv)
{
    //string test = "XIP";
    //int y = 1;
    //cout << decodWord(y,test);
    int number_of_string;
    vector <string> inputedWords;
    vector <string> firstWordOfAnswer;
    vector <string> secondWordOfAnswer;
    vector <string> firdWordOfAnswer;
    vector <int> keyResult;
    cout << "input data:" << "\n";
    cin >> number_of_string;
    string lineBuffer, wordBuffer;
    cin.ignore();
    for (int i = 0; i < number_of_string; i++)
    {
        getline(cin, lineBuffer); // reading the line of input message
        wordBuffer.erase();
        int k = 0; // deviding string by words and putting to inputedWords vector
        do {
            if ((lineBuffer[k] != ' ') && (lineBuffer [k] != '\0'))
            {
                wordBuffer.push_back(lineBuffer[k++]);
            } else {
                k++; 
                inputedWords.push_back(wordBuffer);
                wordBuffer.erase();
            }
        } while (k <= lineBuffer.size());
        keyResult.push_back(checkingTheKey(inputedWords));// send vestor to checking the key
        firstWordOfAnswer.push_back(decodWordUpper(keyResult[i], inputedWords[0]));
        secondWordOfAnswer.push_back(decodWordUpper(keyResult[i], inputedWords[1]));
        firdWordOfAnswer.push_back(decodWordUpper(keyResult[i], inputedWords[2]));
        inputedWords.clear(); 
    } 
    cout << "\nanswer:\n";
    for (int i = 0; i < number_of_string; i++)
    {
        cout <<firstWordOfAnswer[i] << " " << secondWordOfAnswer[i] << " " << firdWordOfAnswer[i] << " " << keyResult[i] << " ";
    }
    cout << endl;
    return 0;
}