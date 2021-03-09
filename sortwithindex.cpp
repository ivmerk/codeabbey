/*After solving the task Bubble Sort we are supposed to learn about sorting arrays. Now we have a bit more complicated programming problem for you, since it is important to have practice in sorting and handling not only primitive values but also more complex objects.

As previously, we are given an array of numbers. It should be sorted first (in non-decreasing order) - and then for each value its initial index should be printed (indexes start from 1).

I.e., suppose we have an array 50 98 17 79 which after sorting becomes 17 50 79 98. Now:

17 was at 3-rd place initially
50 was at 1-st place initially
79 was at 4-th place initially
98 was at 2-nd place initially

so result is
3 1 4 2
Initial data will contain array size at first line and array values itself in the second (integers separated by spaces).
Answer should contain initial indexes of the array members after they are reordered by sorting.

Example:

input data:
4
50 98 17 79

answer:
3 1 4 2
 */
#include <iostream>
using namespace std;
int  main ()
{
int n, tmp;
cout << "\n" << "input data" << "\n";
cin >> n;
cout << "\n";
int* arrdata = new int[n];
int* arrindex = new int[n];

for (int i = 0; i < n; i++)
        arrindex[i] = i+1;
//for (int i = 0; i < n; i++)
//     cout <<  arrindex[i] << " " ;

//cout << "\n";

for (int i = 0; i < n; i++){
        cin >> arrdata[i];
}
for (int i = 0; i < n-1; i++){
        for (int j = n-1; j > i; j--){
                if (arrdata[j] < arrdata[j-1]){
                        tmp = arrdata[j];
                        arrdata[j] = arrdata[j-1];
                        arrdata[j-1] = tmp;
                        tmp = arrindex[j];
                        arrindex[j] = arrindex[j-1];
                        arrindex[j-1] = tmp;
                }
        }
}

cout << "\n" << "answer" << "\n";
//for (int i = 0; i < n; i++)
//     cout <<  arrdata[i] << " " ;

//cout << "\n";
for (int i = 0; i < n; i++)
     cout <<  arrindex[i] << " " ;
return 0;
}
