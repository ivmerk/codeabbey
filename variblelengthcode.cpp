/*We know that to represent letters (and any symbols) of natural language computers use some encoding which assigns character values to integers, so that any array of numbers (bytes for example) could be printed out as the sequence of characters.

For example popular character set is ASCII which uses 7 or 8 bit integers to represent 128 or 256 characters, so that word Hello is stored in the computer memory as

0x48, 0x65, 0x6C, 0x6C, 0x6F
or, the same in decimal instead of hex:

72, 101, 108, 108, 111
Obviously it is not the only possible encoding. Moreover it is not necessary to use 7 or 8 bits. Really, many telegraph systems used 5 bits, like ITA2.

Even more interesting - we can create encodings which use different amount of bits for different letters. The obvious goal is to make the total number of bits required for translation of the message smaller, thanks to the fact that some letters are used more often than others.

Similar approach was used in Morse code - you may note that most frequent letters E, T, I, A, N - all uses very short sequences, unlike rare ones (J, Q, Z etc.)

So this approach is used in data compression algorithms like Huffman coding which we are going to study later.

Let us now practice in encoding the message with the predefined variable-length encoding.

Here are the codes to be used:

' ': 11             'e': 101
't': 1001           'o': 10001
'n': 10000          'a': 011
's': 0101           'i': 01001
'r': 01000          'h': 0011
'd': 00101          'l': 001001
'!': 001000         'u': 00011
'c': 000101         'f': 000100
'm': 000011         'p': 0000101
'g': 0000100        'w': 0000011
'b': 0000010        'y': 0000001
'v': 00000001       'j': 000000001
'k': 0000000001     'x': 00000000001
'q': 000000000001   'z': 000000000000
It is important that none of these codes is the prefix of any other - such coding scheme is called Prefix code and makes us sure that any sequence of bits could be decoded back in a unique way.

You may later learn how such tables are constructed from Shannon-Fano Coding or Huffman Coding exercises.

We do not use special codes for capital letters, instead let us agree that if capital letter is marked by prefixing it with an exclamation mark "!" - in normal text it always is followed by other punctuation symbol or space so it is unambigous rule.

Example
Let us encode the string world of !programming (you see, P is written as !p here).

Working with the table above we construct the following sequence:

w       o     r     l      d        o     f         !      p       r     o     g       r
0000011 10001 01000 001001 00101 11 10001 000100 11 001000 0000101 01000 10001 0000100 01000

a   m      m      i     n     g
011 000011 000011 01001 10000 0000100
Now let us join these bits into a single sequence and then split it into chunks of 8 bits - one chunk for one byte (adding few 0 at the end if the last byte has less than 8 bits):

00000111 00010100 00010010 01011110 00100010 01100100 00000101 01000100 01000010 00100001 10000110
00011010 01100000 00010000
It is more convenient to print bytes in hexadecimal, so result could be written as:

07 14 12 5E 22 64 05 44 42 21 86 1A 60 10
Note that while initial sequence consisted of 21 characters the result have only 14 bytes (more exactly 13.875 since we added one padding zero). So if we store this text in ASCII we spend 7 more bytes or 50%. Of course it is also due to the fact that we created encoding just for letters and not for all possible bytes.

If we use some 5-bit telegraph encoding (sufficient for 26 letters and 6 more symbols) we'll need only 13.125 bytes, i.e. even less than we used - this is because our test phrase have very "uncommon" letters distribution (many o-s and not a single e for example). ITA2 will require 14.375 bits (check it!)
You can measure the "compression rate" for the longer messages as a homework.
Anyway you probably get the idea of data compression which could be built upon this approach - we need to measure frequencies of different byte values in the file, create an optimal encoding and rewrite the file using it (of course adding the encoding table itself).
Problem Statement
Input data contains a line of text consisting only of characters from the table above.
Answer should contain byte sequence produced by our encoding algorithm using this table (in hexadecimal).

Example:

input data:
entertaining interpreter

answer:
B0 9A 89 69 82 60 13 4C 26 A0 2A 2C D4 00
Note: after you will succeed, you may try to write exercise on decompressing such a variable length code.*/
#include <iostream>
#include <istream>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;
class VariableLengthCode
{
    char letter_;
    int code_;
    int length_;

public:
    VariableLengthCode (char a_letter, int a_code, int a_length)
    {
        letter_ = a_letter;
        code_ = a_code;
        length_ = a_length;
    }
    VariableLengthCode() { letter_ = ' '; code_ = 3; length_ = 2;}
    
    char getLetter () {return letter_;}
    int getCode () {return code_;}
    int getLength () {return length_;}
   
    const VariableLengthCode operator=(const VariableLengthCode c)
    {
        letter_ = c.letter_; code_ = c.code_; length_ = c.length_; return *this;
    } 

};
int returnCodeFromLetter(VariableLengthCode s[], char c){
        int i = 0;
        while (s[i].getLetter() != c)
        {
            i++;
        }
        return s[i].getCode();
    }
int returnLengthFromLetter(VariableLengthCode s[], char c){
    int i = 0;
    while (s[i].getLetter() != c)
    {
        i++;
    }
    return s[i].getLength();
}
int main(int argc, char* argv[])

{
    char lette[28] = {' ','e','t','o','n','a','s','i','r','h','d','l','!','u','c','f','m','p','g','w','b','y','v','j','k','x','q','z'};
    int code[28] = {3, 5, 9, 17, 16, 3, 5, 9, 8, 3, 5, 9, 8, 3, 5, 4, 3, 5, 4, 3, 2, 1, 1, 1, 1, 1, 1, 0};
    int length[28] = {2, 3, 4, 5, 5, 3, 4, 5, 5, 4, 5, 6, 6, 5, 6, 6, 6, 7, 7, 7, 7, 7, 8, 9, 10, 11, 12, 12};
    int sizeOfWord = 0;
    vector <char> lettersOfWord(0);
    vector <int> codesOfWord(0);
    vector <int> lengthOfWord(0);
    vector <int> answer(0);
    int last = 0; // index of answer vector receving data
    int restOfBite = 8;
    int occupyOfBite = 8;
   // cout << lette[1];
    VariableLengthCode dictionary[28];
    for (int i = 0; i < 28; i++) // dictionary creating
    {
        VariableLengthCode tmp(lette[i], code[i], length[i]);
        dictionary[i] = tmp;
    }
    string str;
    cout << "\ninput data:\n";
    getline (cin, str);
    while(str.size() != 0) //vectors creation
    {   int tmp = returnCodeFromLetter(dictionary, str[0]);
        lettersOfWord.push_back(str[0]);
        codesOfWord.push_back(returnCodeFromLetter(dictionary, str[0]));
        lengthOfWord.push_back(returnLengthFromLetter(dictionary, str[0]));        
        str.erase(0, 1);
    }
    answer.push_back(0); 
    while (!codesOfWord.empty())
    {
        if (lengthOfWord[0] <= restOfBite)
        {
         //   cout << answer[last] << " ";
            answer[last] <<= lengthOfWord[0];
            answer[last] |= codesOfWord[0];
          //  cout << answer[last] << endl;
            occupyOfBite +=restOfBite;
            restOfBite -= lengthOfWord[0];
        }else if ((lengthOfWord[0] - restOfBite) < 8)
        {
            int temp = codesOfWord[0];
            temp >>= (lengthOfWord[0] - restOfBite); 
            answer[last] <<= restOfBite;
            answer [last] |= temp;
          //  cout << answer[last] << "|" << codesOfWord[0] << endl;
            temp = 0;
            temp = ~((~(temp >> (lengthOfWord[0] - restOfBite))) << (lengthOfWord[0] - restOfBite));
            temp &= codesOfWord[0];
            answer.push_back(0);
            last++;
            answer[last] |= temp;
            restOfBite = 8 - (lengthOfWord[0] - restOfBite); 
            occupyOfBite = 8 - restOfBite;
        } else {
            int temp = codesOfWord[0];
            temp >>= (lengthOfWord[0] - restOfBite); 
            answer[last] <<= restOfBite;
            answer [last] |= temp;
          //  cout << answer[last] << "|" << codesOfWord[0] << endl;
            temp = 0;
            temp = ~((~(temp >> (lengthOfWord[0] - restOfBite))) << (lengthOfWord[0] - restOfBite));
            temp &= codesOfWord[0];
            temp >>= (lengthOfWord[0] - 8 - restOfBite);
            answer.push_back(0);
            last++;
            answer[last] |= temp;
            restOfBite = lengthOfWord[0] - 8 - restOfBite;
            temp = 0;
            temp = ~((~(temp >> restOfBite)) << restOfBite);
            temp &= codesOfWord[0];
            answer.push_back(0);
            last++;
            answer[last] |= temp;
            restOfBite = 8 - restOfBite;
        }
        if (restOfBite == 0)
        {
           answer.push_back(0);
           restOfBite = 8;
           occupyOfBite =0;
           last++;
        }
       // cout << answer[last] << " " << codesOfWord[0] << " " << lengthOfWord[0] << endl;
        codesOfWord.erase(codesOfWord.begin());
        lengthOfWord.erase(lengthOfWord.begin());
    }
    answer[last] <<= restOfBite;
    if (answer[answer.size() - 1] == 0 )
    {
        answer.pop_back();
    }
    cout << "\nanswer:\n";
    for (int i = 0; i < answer.size(); i++)
    {   
        //uint8_t integer = answer[i];
        cout  << hex << setfill('0') << setw(2) << uppercase<< answer[i] << " ";
    }
    cout << endl;
    /*for (int i = 0; i < answer.size(); i++)
    {   
        //uint8_t integer = answer[i];
        cout << dec << answer[i] << " ";
    } 
    cout << endl;*/
    return 0;
}