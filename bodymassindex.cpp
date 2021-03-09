#include <iostream>
#include <string>
using namespace std;
float bobymassindex(float w, float h){
return w/(h*h);
} 
int main()
{
int n;
cout << "input data" << "\n";
cin >> n ;
cout << "\n";
float  *res_arr = new float [n]; //array of result
float weigth, higth;
for (int counter = 0; counter < n; counter++){
        cin >> weigth >> higth; 
        res_arr[counter] = bobymassindex(weigth, higth);
}
cout  << "\n" << "answer:" << "\n";
for (int counter = 0; counter < n; counter++){
//     cout <<  res_arr[counter] << " ";
if (res_arr[counter]< 18.5) cout << " under ";
if ((res_arr[counter] >= 18.5)&&(res_arr[counter] < 25.0)) cout << " normal ";
if ((res_arr[counter]>= 25.0)&&(res_arr[counter]< 30.0)) cout << " over ";
if (res_arr[counter] > 30.0) cout << " obese ";
}
delete [] res_arr;
return 0;
}
