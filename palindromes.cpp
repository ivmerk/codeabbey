/*The word or whole phrase which has the same sequence of letters in both directions is called a palindrome. Here are few examples:

Stats
Amore, Roma
No 'x' in Nixon
Was it a cat I saw?
As you see, case of the letters is ignored. Spaces and punctuations are ignored too.

Your goal in this programming exercise is to determine, whether the phrase represents a palindrome or not.

Input data contains number of phrases in the first line.
Next lines contain one phrase each.
Answer should have a single letter (space separated) for each phrase: Y if it is a palindrome and N if not.

Example:

input data:
3
Stars
O, a kak Uwakov lil vo kawu kakao!
Some men interpret nine memos

answer:
N Y Y
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main ()
{
vector <char> myvector;        
int n = 0;
cout << "\n" << "input data:" << "\n";
cin >> n; 
int* result = new int [n];
cout << "\n"; 
int t = getchar();
int c = 5;
for (int i = 0; i < n; i++){
        while (((c = getchar()) != EOF)&&(c != '\n'))
                if (isalpha(c))
                        myvector.push_back(toupper(c));
        
        for (int m = 0; m < myvector.size(); m++)
                if (myvector[m] != myvector[ myvector.size() - 1 - m ]){
                        result[i] = 10;
                        break;
                }
        myvector.clear();//нужно обнулить вектор
}
cout << "\n" << "answer" << "\n";
for (int i = 0; i < n; i++)
        if (result[i] == 10)
        cout << "N ";
        else cout << "Y ";
cout << "\n";
delete [] result;
return 0;
}
