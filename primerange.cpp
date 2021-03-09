/*If you already solved Prime Numbers Generation - here is an inverse version of it.

Given several pairs of primes (like a, b) you are to tell for each of them the total quantity of primes in the range limited by these values (inclusive), i.e. such p-s that:

isPrime(p) = true

    and

a <= p <= b
Input data: will contain the amount of pairs in the first line.
Next lines will contain one pair of primes each, the first value is always less than the second. All values will be less than 3000000.
Answer should contain the quantity of primes in the ranges specified by these pairs.

Example:

 input data:
 3
 5 19
 11 29
 2 23

 answer:
 6 6 9 */
#include <iostream>
using namespace std;
int main(){
int numbers;

cout << "\n" << "input data:" << "\n";
cin >> numbers;
int a,b;
int resarr[numbers];
for (int i = 0; i < numbers; i++){
     cin >> a >> b;
     int n = 1;
     int testn = 1;
     int noprime = 0;
     resarr[i] = 0;
     while (n<b){
          testn++;
          noprime = 0;
          for (int u = 2; u < (int)sqrt(testn)+1; u++)
               if (!(testn%u)){
                    noprime++;
                    break;
               }
          if (!noprime){
               n = testn;
               if (n >= a) resarr[i]++;
               }         
     }

}
cout << "\n" << "answer:" << "\n";
for (int i = 0; i < numbers; i++)
     cout << resarr[i] << " " ; 
return 0;
}
