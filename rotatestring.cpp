/*
To rotate string by K characters means to cut these characters from the beginning and transfer them to the end. If K is negative, characters, on contrary should be transferred from the end to the beginning.

Input data will contain the number of test-cases in the first line.
Following lines will contain number K and some string S separated by space - one pair in each line.
String S will contain only lowercase latin letters. K will not exceed half the length of S by absolute value.
Answer should contain strings rotated in accordance with the rule above, separated by spaces. For example:

input data:
2
3 forwhomthebelltolls
-6 verycomplexnumber

answer:
whomthebelltollsfor numberverycomplex
The task could be easily solved by creating new instance of string concatenating two substrings. However, if you want more serious challenge, you are encouraged to perform rotation "in-place", moving bytes of original string (i.e. without allocating memory for new instance). This could be done with the help of a loop and only one temporary variable.
*/

#include <iostream>
#include <string>
using namespace std;

int main ()
{
int n = 0;
cout << "\n" << "input data:" << "\n";
cin >> n; 
string* result = new string [n];
cout << "\n"; 
int numberschar; 
string wourds;
for (int i = 0; i < n; i++){
        cin >> numberschar;        
        cin >> wourds;
        if (numberschar > 0) {
                wourds.append(wourds.substr(0,numberschar));
                wourds.erase(0,numberschar);
        }
        else {
                string tmp;
                tmp.append(wourds.substr((wourds.size()+numberschar),(wourds.size()-1)));
                tmp.append(wourds.substr(0,(wourds.size()+numberschar)));
                wourds = tmp;
                tmp.clear();
        }
result[i] = wourds;
wourds.clear();
}

cout << "\n" << "answer" << "\n";
for (int i = 0; i < n; i++)
        cout << result[i] << " ";
cout << "\n";
delete [] result;
return 0;
}
