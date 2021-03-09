/*Random numbers are often used in programming games and scientific researches, but also they could be useful even in business applications (to generate unique user keys, passwords etc.). We are going to learn how they are generated and have a practice with some simple of simpler methods.

Here is one of the earliest methods for producing sequence of seemingly independed (i.e. pseudorandom) numbers:

Choose some initial value with 4 digits (i.e. in range 0000 ... 9999).
Multiply it by itself (i.e. raise to power 2) to get value consisting of 8 digits (add leading zeroes if necessary).
Truncate two first and two last digits in decimal representation of this result.
New value will contain 4 digits and it is the next value of a sequence.
To get more values, repeat from step 2.
Example:

5761                      - let it be the first number
5761 * 5761 = 33189121    - raised to power 2
33(1891)21 => 1891        - truncate to get the middle

1891                      - it is the second number in the sequence
1891 * 1891 = 3575881    - raised to power 2 (add leading zero to get 8 digits)
03(5758)81 => 5758         - truncate to get the middle

5758                      - it is the third number in the sequence (and so on...)
It is obvious that sooner or later each sequence will come to a kind of loop, for example:

0001 -> 0000 -> 0000                   - came to loop after 2 iterations
4100 -> 8100 -> 6100 -> 2100 -> 4100   - came to loop after 4 iterations
You will be given initial numbers for several sequences. For each of them report the number of iterations needed to come to repetition.

Input data will contain amount of initial values in the first line. Second line contains initial values themselves, separated by spaces.
Answer should contain number of iterations for sequences with such initial values to come to the loop.

Example:

input data:
3
0001 4100 5761

answer
2 4 88
Hint: To truncate the 8-digit value, divide it by 100 and then take remainder of division by 10000.
*/
#include <iostream>
#include <vector>
using  namespace std; 
int cut (int a){
return (((a*a)/100)%10000);
}
int main(){
int n;
vector <int> myarr;
cout << "\n" << "input data:" << "\n";
cin >> n;
int data;
int*resarr = new int [n];
for (int i=0; i<n; i++){
        cin >> data;
        int finish=0;
        myarr.push_back(data);
        while (finish!=1){
                myarr.push_back(cut(myarr[myarr.size()-1]));
                for (int m=0; m < myarr.size()-1;m++)
                        if (myarr[m] == myarr[myarr.size()-1]){
                                resarr[i] = myarr.size()-1;
                                finish++;
        }
}
       myarr.clear();

}
cout << "answer" << "\n";
for (int i = 0; i < n; i++){
        cout << resarr[i] << " ";
}
return 0;
}
