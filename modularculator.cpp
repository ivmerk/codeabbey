/*
Dealing with remainders may cause heavy headache to novice programmers. Let us write a simple program which has this operation for its core to study integer division better. At the same time we'll have some practice in handing dates - which sometimes gives headache even to experienced coders.
In arithmetic, the remainder (or modulus) is the amount "left over" after performing the division of two integers which do not divide evenly (from Wiki). This task will provide further practice with modulo operation.
Suppose, we are given two timestamps - for example, when the train or ferry boat starts its travel and when it finishes. This may look like:

start: May 3, 17:08:30
end  : May 8, 12:54:15
and we are curious to know, how much time (in days, hours, minutes and seconds) is spent in traveling (perhaps, to choose faster variant). How this could be achieved?
One of the easiest way is:
* convert both timestamps to big numbers, representing seconds from the beginning of the month (or year, or century);
* calculate their difference - i.e. travel time in seconds;
* convert this difference back to days, hours, minutes and seconds.
First operation could be performed by multiplying minutes by 60 and hours by 60*60 etc. and summing all values up.
The third operation should be performed on contrary by several divisions with keeping remainders.
In this task we are given several pair of timestamps. We suppose that both dates in the pair are always in the same month, so only number of day will be given. We want to calculate difference between timestamps in each pair.
Input data: the first line contains number of test-cases, other lines contain test-cases themselves.
Each test-case contains 8 numbers, 4 for each timestamp: day1 hour1 min1 sec1 day2 hour2 min2 sec2 (second timestamp will always be later than first).
Answer: for each test-case you are to output difference as following (days hours minutes seconds) - please note brackets - separated by spaces.
Example:
input data:
3
1 0 0 0 2 3 4 5
5 3 23 22 24 4 20 45
8 4 6 47 9 11 51 13

answer:
(1 3 4 5) (19 0 57 23) (1 7 44 26)
*/

#include <iostream>
using namespace std;
int main()
{
int day1, hour1, minute1, second1, day2, hour2, minute2, second2;
int n=1; //количество чисел
cout << "input data" << "\n";
cin >> n;
cout << "\n";
int *res = new int[n]; 
for (int i = 0; i < n; i++){
cin >> day1;
cin >> hour1;
cin >> minute1;
cin >> second1;
cin >> day2;
cin >> hour2;
cin >> minute2;
cin >> second2;

res[i] = second2+minute2*60+hour2*3600+day2*3600*24-(second1+minute1*60+hour1*3600+day1*3600*24); 
//cout << "\n"<< res[i]<< "\n";
}
cout  << "\n" << "answer:" << "\n";
     for (int i=0; i < n; i++){
day1 = res[i]/(3600*24);
res[i] -= day1*(3600*24);
hour1 = res[i]/3600;
res[i] -= hour1*3600;
minute1 = res[i]/60;
res[i] -= minute1*60;
second1 = res[i];
             cout <<"("<<  day1<< " "<< hour1<< " "<< minute1<< " " << second1 <<")" <<" ";
     }
delete [] res;
return 0;
}
