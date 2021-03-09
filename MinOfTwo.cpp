#include <iostream>
using namespace std;

int main()
{
int n;
int sum = 0;
//int loop;
cout << "data" << "\n";
cin >> n ;
int *a_arr = new int[n];
int *b_arr = new int[n];

for (int counter = 0; counter < n; counter++){
     cin >> a_arr[counter];
     cin >> b_arr[counter];
}
cout  << "answer:" << "\n";
for (int counter = 0; counter < n; counter++){
        if (a_arr[counter] > b_arr[counter]) {
     cout <<  b_arr[counter] << " ";

        }
        else {cout << a_arr[counter]  << " ";
}
}
delete [] a_arr;
delete [] b_arr;

return 0;
}
