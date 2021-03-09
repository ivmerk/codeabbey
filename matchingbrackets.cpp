/*We are given strings containing brackets of 4 types - round (), square [], curly {} and angle <> ones. The goal is to check, whether brackets are in correct sequence. I.e. any opening bracket should have closing bracket of the same type somewhere further by the string, and bracket pairs should not overlap, though they could be nested:
(a+[b*c] - {d/3})  - here square and curly brackets are nested in the round ones
(a+[b*c) - 17]     - here square brackets overlap with round ones which does not make sense
Input data will contain number of testcases in the first line.
Then specified number of lines will follow each containing a test-case in form of a character sequence.
Answer should contain 1 (if bracket order is correct) or 0 (if incorrect) for each of test-cases, separated by spaces.
Example:

input data:
4
(a+[b*c]-{d/3})
(a + [b * c) - 17]
(((a * x) + [b] * y) + c
auf(zlo)men [gy<psy>] four{s}

answer:
1 0 0 1
*/

#include <iostream>

using namespace std;

int main(){
int numbers;
cout << "\n" << "input data:" << "\n";
cin >> numbers; 
cout << "\n";
int t = getchar();
char *data = new char [1000];
int *resarr = new int [numbers];
char c = 's';
for (int i = 0; i < numbers; i++){
        resarr[i] = 0;
        int m = 0; //индекс массива данных
        data[m] = 0;

        while (((c = getchar()) != EOF) && (c != '\n')){
                
                if (((c == ')')&&(data[m] !='('))||((c == ']')&&(data[m] !='['))||((c == '}')&&(data[m] !='{'))||((c == '>')&&(data[m] !='<')))
                        m+=100;
                if (c == '(') 
                        data[++m] = c;
                if ((c == ')')&&(data[m]=='(')) 
                        m--;                     
                
                if (c == '[') 
                        data[++m] = c;
                if ((c == ']')&&(data[m]=='[')) 
                        m--;               
       
                if (c == '{') 
                        data[++m] = c;
                if ((c == '}')&&(data[m]=='{')) 
                        m--;               
                
                if (c == '<') 
                        data[++m] = c;
                if ((c == '>')&&(data[m]=='<')) 
                        m--;               
                
//                cout << data[m];
        }        
        if (m == 0)
                resarr[i]++;

}
cout << "\n" << "answear" << "\n";
for (int i = 0; i < numbers; i++)
        cout << resarr[i] << " ";
delete [] resarr;
cout << "\n";
return 0;
}
