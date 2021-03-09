/* Also available in: Russian

Anna lives at Algol and Bob lives at Betelgeuse. Long distance separates them since these stars are in different constellations - Perseus and Orion.

They found a way to communicate via e-mail. However, due to big distance, some letters could be changed during transmission. Simple form of error-checking is proposed by Anna:

All letters are transmitted in usual ASCII code, one byte per symbol. Each byte consists of 8 bits, but the highest bit is not used for English language - it is normally always 0.

Let us set this bit to either 0 or 1 in order that sum of bits in the whole byte is always even (2, 4, 6 or 8). That is how some letters are encoded:

symbol     ascii-code     binary     num-of-bits    encoded-binary   encoded-dec

 'A'           65        01000001         2            01000001           65
 'B'           66        01000010         2            01000010           66
 'C'           67        01000011         3            11000011          195
 '.'           46        00101110         4            00101110           46
 ' '           32        00100000         1            10100000          160
It is supposed that communication line could not change more than one bit in each of the transmitted bytes. So the bytes which have odd amount of bits are considered corrupted.

We are given the message in this protected encoding. Our task is to check each letter and remove those which are corrupted. Others should be converted to normal ASCII and printed as characters.

Input data will contain bytes of the message transmitted (represented by the sequence of decimal values, separated with spaces).
Original message consists only of latin letters (small and capital), digits and spaces.
The end of message is signalled by dot character '.' - you can assume this will never be corrupted.
Answer should contain message with corrupted bytes removed, highest bits cleared - and represented as characters rather than numbers.

Example:

input data:
65 238 236 225 46

answer:
Ana.   */
#include <iostream>
using namespace std;
int main (){
int data;
//cout << (38&128);
string result;
cout << "\n" << "input data:" << "\n";
cin >> data;
do{
        int bit = 1;
        int res = 0;
        for (int i = 0; i < 7; i++){
                if ((data & bit)!=0)
                        res++;
                bit <<=1;
        }
        if (((data & bit)/bit) == (res % 2)){
               result.push_back(data&127);
        }
        cin >> data;
}while (data != 46);
result.push_back(46);
cout << result;
return 0;
}
