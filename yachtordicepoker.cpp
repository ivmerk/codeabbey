/* Dice game of Yacht is played with 5 standard dice (having from 1 to 6 points on their sides). The player' s goal is to gather some beautiful combination of points. Suppose, the following combinations are respected:

two of dice have the same points, like 3 6 5 6 1 - called pair;
three of dice have the same points, like 2 4 5 4 4 - called three;
four of dice have the same points, like 1 4 1 1 1 - called four;
all five dice have the same points, like 2 2 2 2 2 - called yacht;
two pairs at once, like 3 6 5 3 5 - called two-pairs;
pair and three at once, like 1 6 6 1 6 - called full-house;
sequence from 1 to 5, like 2 4 3 5 1 - called small-straight (see notes);
sequence from 2 to 6, like 6 3 4 2 5 - called big-straight.
Note1: combinations named with two words are written with dash, same as answers which our code should produce.
Note2: "small-straight" should be called "little-straight", this was mistakenly borrowed from "Yachtzee" game rules, where it denotes straight of 4 dice - but now it is too late to change checker code, sorry :)

Such combinations increase player's score by different values, but it is not important now.

Our goal is to write a program which for given combination of dice will determine its type.

Input data contains a number of test-cases in the first line.
Next lines contain 5 values each - points of player's dice.
Answer should contain the name for each of combinations. Names could be pair, two-pairs, three, four, yacht, full-house, small-straight, big-straight or none, separated with spaces.

Example:

input data:
3
3 6 5 6 1
1 6 6 1 6
2 4 3 5 1

answer:
pair full-house small-straight   */
#include <iostream>
using namespace std;
int main(){
int number;
cout << "\n" << "input data:" <<"\n";
cin >> number;
cout << "\n";
int data[5];
int res[number];
for (int i = 0; i < number; i++){
     int sum = 0;
     res[i] =0;
     bool fllag = false;
     bool flpair = false;
     bool flpair_ = false;
     bool flthree = false;
     bool flthree_ = false;
     bool flfour= false;
     bool flyacht= false;
     bool fl2pair= false;
     bool flfullh= false;
     for (int u=0; u < 5; u++){
          cin >> data[u];
          sum +=data[u];  }
     for (int u=0; u<5-1; u++){
          for (int y = u+1; y < 5 ; y++){
               if ((data[u] == data[y])&&!flpair&&!flthree&&flfour&&!res[i]&&data[y]){
                    flfour = false;
                    flyacht = true;
                    data[y] =0; }
               if ((data[u] == data[y])&&!flpair&&flthree&&!flfour&&!res[i]&&data[y]){
                    flthree = false;
                    flfour = true; 
                    data[y] =0;}
               if ((data[u] == data[y])&&flpair&&!flthree&&!flfour&&data[y]){
                    flpair = false;
                    flthree = true;
                    data[y] =0; }   
                 if ((data[u] == data[y])&&!flpair&&!flthree&&!flfour&&data[y]) {
                    flpair = true; 
                    data[y] = 0; }
          }
          if (flpair&&!flpair_&&!flthree_){
               flpair_ = flpair;
               flpair = false;
               res[i] =1; }
          if ((flthree_&&flpair)||(flthree&&flpair_)){
               res[i] = 6;
               break; }
          if (flyacht){
               res[i] = 5;
               break; }
          if (flfour){
               res[i] = 4;
               break; }
          if (flpair&&flpair_){
               res[i] = 2;
               break; }
          if (flthree){
               flthree_ = flthree;
               flthree = false;
               res[i] = 3;}
          }
     if ((sum ==15)&&!res[i])
          res[i] = 7;
     if ((sum ==20)&&!res[i])
          res[i] = 8;}
cout << "\n" << "answer:" << "\n";
for (int i = 0; i<number; i++){
     if (res[i] ==1)
          cout << "pair ";
     if (res[i] ==2)
          cout << "two-pairs ";
     if (res[i] ==3)
          cout << "three ";
      if (res[i] ==4)
          cout << "four ";
      if (res[i] ==5)
          cout << "yacht ";
     if (res[i] ==6)
          cout << "full-house ";
     if (res[i] ==7)
          cout << "small-straight ";
     if (res[i] ==8)
          cout << "big-straight ";
     if (res[i] == 0)
          cout << "none ";
}
return 0;     
}
