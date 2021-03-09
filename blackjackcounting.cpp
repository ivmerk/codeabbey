/*The game of Blackjack has very simple rules: players should take cards one by one trying to collect more points than opponents, but not exceeding 21 (refer Wikipedia for complete rules).

The deck contains all cards from 2 to 10 inclusive, which are counted according to their value, also Kings, Queens and Jacks which cost 10 points each and also Aces, which could be counted as 1 or 11 points, whatever is better.

Let us learn the programming of scoring algorithm for such game.

Input data will contain the number of test-cases in the first line.
Then test-cases will follow on separate lines. Each test-case consists of several cards expressed with symbols:
2, 3, 4, 5, 6, 7, 8, 9,
T, J, Q, K - for 10, Jack, Queen, King,
A - for Ace.
Answer should contain the number of points in each test-case, not exceeding 21 - or the word Bust if the total is greater than 21 (i.e. player immediately loss).

Example:

input data:
4
A T
2 K 4
3 A Q 8
A 3 3 3 A

answer:
21 16 Bust 21
*/
#include <iostream>
#include <string>
using namespace std;
int main(){
int numbers;
cout << "\n" << "input data:" << "\n";
cin >> numbers;
cout << "\n";
cin.ignore();
int*resarr = new int [numbers];
for (int i = 0; i<numbers; i++){
        resarr[i] = 0;
        string data;
        int flagace = 0;
        getline(cin, data);
        int c = 0;
        while (data[c] != '\0'){
                if (isdigit(data[c]))
                        resarr[i] += data[c] - '0';
               if ((data[c] == 'T')||(data[c] == 'J')||(data[c] == 'Q')||(data[c] == 'K'))
                      resarr[i] += 10;
              if (data[c] == 'A'){
                     resarr[i] += 1;
                     flagace++;
              } 
              c++;
        }
        while (flagace){
                if (resarr[i] <= 11)
                        resarr[i] +=10;
                        flagace--;
                

        }
//cout << resarr[i];
}
cout << "\n" << "answer:" << "\n";
for (int i = 0; i < numbers; i++){
        if (resarr[i] > 21)
                cout <<  "Bust ";
        
        else cout << resarr[i] << " ";
}
delete [] resarr;
return 0;        
}
