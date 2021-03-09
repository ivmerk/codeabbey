#include <iostream>
using namespace std;
const int t = 300;
int main()
{
signed int min, max;
cout << "input data" << "\n";
signed int b_arr [t];
for (int counter = 0; counter < t-1; counter++){
     cin >> b_arr[counter];
}
min = b_arr[0];
max = min;
cout  <<  "\n" << "answer:" << "\n";
for (int counter = 0; counter < t; counter++){
          if (b_arr[counter] > max) {
               max = b_arr[counter];
          }
          if (b_arr[counter] < min) {
               min = b_arr[counter];
          }
}
cout << max << " " << min << "\n";
return 0;
}
