#include <iostream>
using namespace std;

int avarage(int sum, int n);

int main()
{
int n;
cout << "input data" << "\n";
cin >> n ;
cout << "\n";
int  *res_arr = new int [n]; //array of result
int digits = 1;
int sumofdigit;
int numberofdigits;
for (int counter = 0; counter < n; counter++){
    sumofdigit = 0;
    digits = 1;
    numberofdigits = 0;
        while (digits!=0){
        cin >> digits;
        numberofdigits++;
          sumofdigit += digits;
         }
        res_arr[counter] = avarage(sumofdigit, --numberofdigits);
}
cout  << "\n" << "answer:" << "\n";
for (int counter = 0; counter < n; counter++){
     cout <<  res_arr[counter] << " ";
}
delete [] res_arr;
return 0;
}
int avarage(int sum, int n)
{
        int res;
         float nrounded_res = 0.0;

        nrounded_res =(1.0*sum) / n; 
        res = nrounded_res;
        float ost = 10 * nrounded_res - 10 * res;
        if (ost >= 5) {++res;}
       return res;
}
