/*Here is the classical programming puzzle though it came from ancient times when there are no computers at all. We can see that practicing math and logic can sometimes save one's life!

About 2000 years ago there was some war, and during one of its battles defendants were blocked by attackers in the cave.

To avoid capture they decided to stand in a circle and kill each third until only one person remains - who was supposed to commit suicide - though he eventually prefer to surrender to enemies. The problem is called after this person - you may read the full story of Josephus and get math explanation of the problem in wikipedia article

Your task is to determine for given number of people N and constant step K the position of a person who remains the last - i.e. the safe position. For example if there are 10 people and they eliminate each third:

N = 10, K = 3
sequence of counting looks like this (brackets show persons who are elimintated):

1st round: 1 2 (3) 4 5 (6) 7 8 (9) 10
2nd round:                            1 (2) 4 5 (7) 8 10
3rd round:                                                (1) 4 5 (8) 10
4th round:                                                               4 (5) 10
5th round:                                                                        4 (10)
so the "winner" is one who was #4 at initial standing.

Input data will contain number of people N and the counting step K.
Answer should contain the number of person who will remain at the end. Initial numbering starts from 1.

Example:

initial data:
10 3

answer:
4
*/
#include <iostream>
using namespace std;
int main(){
int number;
int radius;
cout << "\n" << "initial data:" << "\n";
cin >> number >> radius;
int*resarr = new int[number];
for (int i = 0; i < number; i++) {
resarr[i] = i+1;
}
int g=radius;
int delno=0;
int res=number%radius;
while (number != 1){
        while (g <= number){
               
                for (int i=g-delno; i<number; i++){
                        resarr[i-1] = resarr[i];
                }
                delno++;
                
                g+=radius;
        }
      // cout << "\n" << g<< " " << number << " "<< delno << " " << resarr[0] <<"\n";
       for (int i = 0; i<number-delno; i++){
               cout << " " << resarr[i]; 
       } 
       
       g-=number;

        number-=delno;
        delno=0;
     
}
cout << "\n" << "answer" << "\n";
cout << resarr[0];

return 0;
}
