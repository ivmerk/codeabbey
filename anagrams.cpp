/* The idea proposed by Guy Gervais was so fruitful that it allows to create more than one problem from it. Here is the simpler one.

In many natural languages we can find some pairs of words which could be transformed to each other by changing the order of letters. I.e. they consist of the same set of letters, for example:

cat - act take - teak ate - eat - tea

Such words are called anagrams and as we see in the third example sometimes there are more than two words.

Your task is to find out the amount of anagrams for given word by the dictionary.

Click this link with right mouse button and select "Save As" to download dictionary file

Dictionary file contains a list of english words, one per line. It was taken from Ubuntu linux distribution and stripped of words containing capital letters, apostrophes and non-english letters.

Input data will contain the number of test-cases in the first line.
Next lines will contain a single word each.
Answer should contain the number of anagrams for each word (not including the word itself).

Example:

input data:
3
bat
coal
lots

answer:
1 1 2 */
#include <iostream>
#include <fstream>
#include <filesystem>
using namespace std;
int checkanagram(char a[]){
ifstream fout;
char buff[50];
char tmp[50];
int i,k;
int res=0;
bool flag = true;
fout.open("words.txt", ios::in);
while (fout >> buff){
     i=0;
     for (int i = 0; i < 50; i++)
     tmp[i] = buff[i];
     while (a[i] != '\0'){
          k=0;
          while (buff[k] != '\0'){
               if (a[i] == buff[k]){
                    buff[k] = '*';
                    break;
               }k++;}
          i++;}
          k=0;
          flag = true;
          while(buff[k]!='\0'){
               if (buff[k]!='*') {flag=false;
               break;}
          k++;}
          if (flag) {
               res++;
          bool flag1 = false;
          for (int i = 0; a[i] != '\0'; i++){
                  if (a[i] == tmp[i])
                       flag1 = true;
                  else {flag1 = false;
                  break;}}
          for (int i = 0; a[i] != '\0'; i++){
                  if (tmp[i]== '\0') {
                       flag1 = true;
                       break;}
          }
          if (flag1)
               res--;}
}
fout.close();
return res;}
int main(){
int number;
cout << "\n" << "input data:" << "\n";
cin >> number;
char data[50];
cout << "\n";
int res[number];
for (int i = 0; i < number; i++){
     res[i] =0;
     cin >> data;
     res[i] = checkanagram(data);
}
cout << "\n" << "answer:" << data << "\n";
for (int i = 0; i < number;i++)
cout << res[i] << " ";
return 0;
}
