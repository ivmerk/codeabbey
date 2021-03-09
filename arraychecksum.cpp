/*
This problem provides an exercise for learning core idea of infamous ordering algorithm - bubble sort - which we are supposed to learn a bit later.
Given integer array, we are to iterate through all pairs of neighbor elements, starting from beginning - and swap members of each pair where first element is greater than second.
For example, let us consider small array of elements 1 4 3 2 6 5, marking which pairs are swapped and which are not:
(1  4) 3  2  6  5  - pass
1 (4  3) 2  6  5  - swap
1  3 (4  2) 6  5  - swap
1  3  2 (4  6) 5  - pass
1  3  2  4 (6  5) - swap
1  3  2  4  5  6  - end
This operation moves some greater elements right (to the end of array) and some smaller elements left (to the beginning).
What is the most important: the largest element is necessarily moved to the last position.
Input data contain sequence of elements of the array, all positive. After this value -1 follows to mark the end (it should not be included into an array).
Answer should contain two values - number of performed swaps and checksum of the array after processing (separated by spaces).
Checksum should be calculated with exactly the same method as in the task Array Checksum
Example:
input data:
1 4 3 2 6 5 -1
answer:
3 5242536
   Нам дан массив для которого нужно посчитать контрольную сумму. Делается это следующим образом: каждый элемент (начиная с первого) добавляем к текущему результату и умножаем то что получилось на 113 - то что получилось берем по модулю 10000007 - оно и будет новым значением результата, и так далее.
*/

#include <vector>
#include <iostream>

using namespace std;
int arraychecksum (vector<int>a){
        int res=0;
for (int counter = 0; counter < a.size()-1; counter++){
 res = (res+a[counter])*113;
 res = res > 10000007?res%10000007:res;}
return res;
}
int main()
{
vector<int>data;
int c = 0;
int phassnumber = 0;
int n = 0; // number of vectors elements
cout << "input data" << "\n";
while (c != -1) {
        cin >> c;
        data.push_back(c);
        n++;
}
for (int i = 0; i < n-2; i++){
        if (data[i] > data[i+1]){
               int tmp = data[i];
               data[i] = data[i+1];
               data[i+1] = tmp;
               phassnumber++;
        }
}
int res = arraychecksum(data);
cout  << "\n" << "answer:" << "\n";
cout << "\n" << phassnumber << " " << res << "\n";
return 0;
}
