/*In this task we are going to implement the primes generator. Primes are positive integers which have no other divisors except 1 and itself. You may read more in wiki article. Most popular algorithms to practice are either Sieve of Eratosthene or Trial division. You are encouraged to google for them if you need more details.
So let us create the array (or list) of prime numbers in ascending order, i.e.:
[2, 3, 5, 7, 11, 13, 17, 19, 23, 29, ...]
And then print the primes corresponding to the indices given in the input data.
Input data will contain the amount of primes to print in the first line.
Next line will contain indices of array of primes for which values should be printed. They will be in range from 1 to 200000.
Answer should contain prime numbers corresponding the specified positions of the array.
Note that for this task we start indexing an array from 1 rather than 0 (this may help you in checking your program with many lists of primes which could be found online).

Example:

input data:
4
7 1 199999 4

answer:
17 2 2750131 7
Take care of implementing the algorithm efficiently - with proper approach all 200000 primes should be generated in about a second (somewhat slower with scripting languages like Python, or older computer).*/
#include <iostream>
#include <math.h>
using namespace std;
int main(){
int numbers;
cout << "\n" << "input data:" << "\n";
cin >> numbers;
long  long int  *dataarr = new long long int [numbers];
long  long int  *resarr = new long long int [numbers];
long long int figure = 2;
long long int figureindex = 1;
for (int i = 0; i < numbers; i++)
        cin >> dataarr[i];
cout << "\n";
for (int i = 0; i < numbers; i++)
        cout <<  dataarr[i] << " ";

cout << "\n";
int resultindex = 0;
for (int i = 0; i < numbers; i++){
        if (dataarr[i] == figureindex){
                resarr[i] = figure;
        resultindex++;
}}
while (resultindex < numbers){
        int nextfigflag = 0;
        while (!nextfigflag){
                figure++;
                int sqrtfigure = sqrt(figure*1.0);
                for (int i = 2; i < sqrtfigure; i++){
                        if (figure%i == 0){
                                nextfigflag = 0;
                                break;
                        }
                }
                if (nextfigflag){
                        nextfigflag++;
                        figureindex++;
                }
        }

        for (int i = 0; i < numbers; i++){
                if (dataarr[i] == figureindex)
                        resarr[i] = figure;
                resultindex++;
        }
}
cout << "\n" << "answer:" << "\n";
for (int i = 0; i < numbers; i++)
        cout << resarr[i] << " ";
delete [] dataarr;
delete [] resarr;
return 0;
}
