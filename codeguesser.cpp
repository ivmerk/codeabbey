/* If you know the old game Bulls and Cows, this programming problem will look familiar to you.

Andrew and Peter play the code-guessing game. Andrew chooses a secret number consisting of 3 digits. Peter tries to guess it, proposing several values, one by one.

For each guess Andrew should answer how many digits are correct - i.e. are the same in the proposed value and in his secret number - and are placed in the same position. For example, if secret number is 125 and Peter calls 523, then Andrew answers with 1. Here is the sample of the game:

Andrew chooses a secret number 846

Peter's guess             Andrew's answer
      402                        0
      390                        0
      816                        2
      848                        2
      777                        0
      815                        1
      846                        3
So Peter have guessed correct number after 6 attempts.

You are to write program which reads guesses given by Peter (except the last) and prints out the secret number choosen by Andrew. It is guaranteed that exactly one solution exists.

Input data will contain number of guesses in the first line.
Then answers with attempts will follow - each contains the number told by Peter and the answer given by Andrew.
In contrast with examples numbers will be of 4 digits.
Answer should contain the secret number (also 4 digits). See example:

input data:
6
402 0
390 0
816 2
848 2
777 0
815 1

answer:
846 */
#include <iostream>
using namespace std;
int testraw(int a, int b){
     int res=0;
     if ((a%10)==(b%10))
          res++;
     a /=10;
     b /=10;
     if ((a%10)==(b%10))
          res++;
     a /=10;
     b /=10; 
     if ((a%10)==(b%10))
          res++;
     a /=10;
     b /=10; 
     if ((a%10)==(b%10))
          res++; 
     return res; 
}
int main(){
int number;
bool resflag = false;
int res = 0;
cout << "\n" << "input data:" << "\n";
cin >> number;
int dataraw [number];
int test [number];

for (int i = 0; i < number; i++)
     cin >> dataraw[i] >> test[i];
while((!resflag)&&(res < 10000)){
     res++;
     for (int i=0; i < number; i++){
          if (testraw(res,dataraw[i]) == test[i]){
               resflag = true;
          }
          else {
               resflag = false;
               break;
          }
     }
}
cout << "\n" << "answer:" << "\n" << res << "\n";
return 0;     
}
