#include <iostream>
#include <string>
using namespace std;
int median (int i[]){
if  (((i[0] < i[1])&&(i[1] < i[2]))||((i[0] > i[1])&&(i[1] > i[2])))
       return i[1];
if  (((i[0] > i[1])&&(i[0] < i[2]))||((i[0] < i[1])&&(i[0] > i[2])))
       return i[0];
if  (((i[0] < i[2])&&(i[1] > i[2]))||((i[0] > i[2])&&(i[1] < i[2])))
       return i[2];
} 
int main()
{
int n;
cout << "input data" << "\n";
cin >> n ;
cout << "\n";
int  *res_arr = new int [n]; //array of result
int digits[3];
//int c = 1;
//int tmp = getchar();
for (int counter = 0; counter < n; counter++){
    for (int i = 0; i <3; i++){
        cin >> digits[i]; }
        res_arr[counter] = median(digits);
//if (c=='\n') break;
        
}
cout  << "\n" << "answer:" << "\n";
for (int counter = 0; counter < n; counter++){
     cout <<  res_arr[counter] << " ";
}
delete [] res_arr;
return 0;
}
