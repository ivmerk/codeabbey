/*This useless program is sometimes proposed by school teachers: using extended console functions for positioning cursor and printing text in any possible position on the screen, pupils are to create effect of the flying text with the given string.

Text should move diagonally with the constant speed (for example, 3 cells per second) and bounce from the borders. Bouncing means that when the string reaches last or first line, it changes the vertical direction - and when its end or start touches last or first column respectively - it changes the horizontal direction.
                                        
Text:  
Flying Text screensaver on the alpha-numeric display
Play with the demo above to get better idea of how it works. Or, perhaps, write such program using what means your programming language offer - and see it in action.

Your task now is to track the path of the flying text.

Input data will contain Width and Height of the imaginary screen and the Length of text string.
Answer should dump pairs of coordinates X and Y of the beginning of the text for first 100 steps (spaces should be used to separate values in the pair and pairs themselves) - i.e. 202 integers in total (including coordinates of the starting position).

Coordinate system of the screen usually has the (0, 0) in the left top corner.

Example:

input data:
9 3 4

answer:
0 0 1 1 2 2 3 1 4 0 5 1 4 2 3 1 2 0 ... 4 0 3 1 2 2 1 1 0 0 */
#include<iostream>
using namespace std;
int main(){
const int steps = 100;
int width, high, length;
int x, y; //present coordinate
int xd, yd;
cout <<"\n"<< "input data:" <<"\n";
cin >> width >> high >> length;
cout << "\n" << "answer:" << "\n";
x = 0;
y = 0;

for (int i=0; i <= steps; i++){
     if (x ==0)
          xd = 1;
     if (y == 0)
          yd = 1;
     if (y == high-1)
          yd = -1;
     if (x == width-length)
          xd = -1;
cout << x << " "<< y << " ";
     x += xd;
     y += yd;


}
return 0;}
