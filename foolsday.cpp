/*Fool's Day 2014
Problem #94 

Tags: puzzle

Who solved this?

Meet HTTP web protocol
Manually sending requests to web-servers,
Using telnet, curl and browser console.
Video by CodeAbbey

Also available in: Slovak

Today I wanted to create new task and found it is April 1 2014 - the Fool's Day when people are trying to overjoke each other.

So here is a small programming problem without the problem statement. Nevertheless you can do it! Good luck! :)

Example:

input data:
5
1 2
1 2 3
2 3 4
2 4 6 8 10
7 11 19

answer:
5 14 29 220 531 */
#include <iostream>
#include <string>
using namespace std;
int main(){
int numbers;
cout <<  "\n" << "input data:";
cout << "\n";
cin >> numbers;
cout << "\n";
cin.ignore();
int k;
int *resarr = new int[numbers];
for (int i = 0; i < numbers; i++){
        string data;
        resarr[i] = 0;
        int c = 0;
        getline (cin,data);
        while (data[c] !='\0'){
                if ((isdigit(data[c]))&&(isdigit(data[c+1]))){
                                resarr[i] += ((((int)data[c] - 48) * 10) + ((int)data[c+1]) - 48) * ((((int)data[c] - 48) * 10) + ((int)data[c+1]) - 48);
                                c++;c++;c++;
                }
                if ((isdigit(data[c]))&&(!isdigit(data[c+1]))){
                                resarr[i] += ((int)data[c] - 48) * ((int)data[c] - 48);
                c++;c++;
                }
        }         
}
cout << "\n" << "answer:" << "\n";
for (int i = 0; i < numbers; i++)
        cout << resarr[i] << " ";

return 0;
}
