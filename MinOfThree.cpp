#include <iostream>
using namespace std;

int main()
{
int n;
cout << "data" << "\n";
cin >> n ;
signed int *a_arr = new signed int[n];
signed int *b_arr = new signed int[n];
signed int *c_arr = new signed int[n];
signed int *sum_arr = new signed int[n];
for (int counter = 0; counter < n; counter++){
     cin >> a_arr[counter];
     cin >> b_arr[counter];
     cin >> c_arr[counter];
}
cout  << "answer:" << "\n";
for (int counter = 0; counter < n; counter++){
          if (a_arr[counter] > b_arr[counter]) {
               sum_arr[counter] = b_arr[counter];
          }
          else
          {  
               sum_arr[counter] = a_arr[counter];
          }
          if (sum_arr[counter] > c_arr[counter]) {
               cout << c_arr[counter]  << " ";
        }
               else {cout << sum_arr[counter]  << " ";
}
}
delete [] a_arr;
delete [] b_arr;
delete [] c_arr;
delete [] sum_arr;
return 0;
}
