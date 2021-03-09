#include <iostream>
using namespace std;

int main()
{
int n;
int sum = 0;
//int loop;
cout << "input data" << "\n";
cin >> n ;
float  *a_arr = new float [n];
float  *b_arr = new float [n];
float *c_arr = new float[n];
float div;
for (int counter = 0; counter < n; counter++){
     cin >> a_arr[counter];
     cin >> b_arr[counter];
}
int sign = 1;
cout  << "answer:" << "\n";
for (int counter = 0; counter < n; counter++){
        c_arr[counter] = 0.0;
        c_arr[counter] = a_arr[counter] / b_arr[counter]; 
        int g = c_arr[counter];
     
        float ost = 10 * c_arr[counter] - 10 * g;
        if (ost >= 5) {++g;}
        if (ost <= -5) {--g;}
        cout << g << " " <<  " ";

}
delete [] a_arr;
delete [] b_arr;
delete [] c_arr;
return 0;
}
