#include <iostream>
#include <string>
using namespace std;
int checktriangels(int i[]){
if  (((i[0] + i[1]) < i[2]) || ((i[2] + i[1]) < i[0]) || ((i[0] + i[2]) < i[1]))
       return 0;
return 1;
} 
int main()
{
int n;
cout << "input data" << "\n";
cin >> n ;
cout << "\n";
int  *res_arr = new int [n]; //array of result
int digits[3];
for (int counter = 0; counter < n; counter++){
    for (int i = 0; i <3; i++){
        cin >> digits[i]; }
        res_arr[counter] = checktriangels(digits);
}
cout  << "\n" << "answer:" << "\n";
for (int counter = 0; counter < n; counter++){
     cout <<  res_arr[counter] << " ";
}
delete [] res_arr;
return 0;
}
