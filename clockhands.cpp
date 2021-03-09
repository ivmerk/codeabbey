/* The face of analog clock has two hands and is proportionally divided by 12 marks. The shorter hour hand makes the whole turn (360 degrees) in 12 hours, while the longer minute hand makes the whole circle each hour. See Clock Face on wiki for more details.

Suppose, the Cartesian Coordinate System (i.e. ordinary rectangular coordinate grid) is placed upon the clock face so that the center of the face has coordinates 10, 10 and Y axis is directed upwards while X axis is directed to the right (i.e. at 3:00 minute hand is parallel to Y axis and hour hand is parallel to X axis).

Assuming the length of the minute hand be 9 and the length of the hour hand be 6 you are to find coordinates of the hand ends for each given time - e.g. (16 10) and (10 19) for the time 3:00.

Input data contain the number of test cases.
Following line contains the testcases themselves in form 03:15, 21:44 etc.
Answer should contain four real numbers for each test case - X and Y coordinates for hour hand, then X and Y coordinate for minute hand. All values should be simply separated with spaces.

Real values should have accuracy of 1e-7 or better. Time is specified as a value from 0:00 to 23:59. 
Example:

input data:
3
12:00 15:00 09:30

answer:
10.0 16.0 10.0 19.0 16.0 10.0 10.0 19.0 4.20444504 11.55291427 10.0 1.0
Please, refer to the picture above for hands position at 09:30!*/
//9.99999996 16.00000000 10.00000000 19.00000000 16.00000000 10.00000005 10.00000000 19.00000000 4.20444503 11.55291424 10.00000003 1.00000000 

//10.00000000 16.00000000 10.00000000 19.00000000 16.00000000 10.00000000 10.00000000 19.00000000 4.20444489 11.55291462 10.00000000 1.00000000 
#include <iostream>
#include <cmath>
#define PI 3.14159265
using namespace std;
int main(){
int number;
//cout << (cos((float)9/12.0*2.0*PI)*6.0) + 10.0;
cout << "\n" << "input data:" << "\n";
cin >> number;
cout << "\n";
double hour = 6.0;
double minute = 9.0;
double res[4*number];
char data[6*number];
for (int i =0; i< number; i++){
     cin >> data;
     int x, y;
     x = (data[0] - '0')*10 + (data[1] - '0');
     y = (data[3] - '0')*10 + (data[4] - '0');
//     cout << x << ":" << y << " ";
     res [i*4] = (sin((double)x/12.0*2.0*PI + (double)y/60*2/12*PI)*hour) + 10.0; 
     res [i*4+1] = (cos((double)x/12.0*2.0*PI + (double)y/60*2/12*PI)*hour) + 10.0; 
     res [i*4+2] = (sin((double)y/60.0*2.0*PI)*minute) + 10.0; 
     res [i*4+3] = (cos((double)y/60.0*2.0*PI)*minute) + 10.0; 
}
cout.setf(std::ios::fixed);
cout.precision(8);
cout << "\n" << "answer:" << "\n";
for (int i = 0;i < 4*number; i++){
     cout << res [i] << " ";
}
return 0;
}

