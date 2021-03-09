/* Given usual Fibonacci Sequence, starting with 0 and 1:

0 1 1 2 3 5 8 13 21 34 ...
and some value M you will be asked to find the index of the first non-zero member of this list, which is evenly divisible by this M, e.g. if you are given M = 17 the answer is 9 (the index of the element 34).

Input data in the first line will contain the number of test-cases.
Next line will contain exactly this of divisors M (not exceeding 10000) for which you should give answers.
Answer should contain indices of members of Fibonacci Sequence, separated by spaces.

Example:

input data:
3
17 12 61

answer:
9 12 15 */
#include <iostream>
using namespace std;
int main(){
int number;
cout << "\n" << "input data:" << "\n";
cin >> number;
cout << "\n";
int data[number];
int res [number];
for (int i = 0; i < number; i++){
     cin >> data[i];
     unsigned long long  figiur = 1;
     unsigned long long figiurlast =1;
     unsigned long long tmp;
     int r =2;
     while (figiur < 8000000000000000000){
          tmp = figiur;
          figiur +=figiurlast;
          figiurlast = tmp;
          r++;
         cout << figiur << " ";
          if (!(figiur%data[i])){
               res[i] = r;
               break;
          }
     }
}
cout << "\n" << "answer:" << "\n";
for (int i = 0; i < number; i++)
cout << res[i] << " ";
cout << "\n";
return 0;
}
