#include <iostream>
#include <string>
using namespace std;
int main()
{
int n;
cout << "input data" << "\n";
cin >> n ;
cout << "\n";
int  *res_arr = new int [n]; //array of result
int c = 0;
int i;
int tmp = getchar();

for (int counter = 0; counter < n; counter++){
i = 1;
res_arr[counter] = 0;
//cout << "n";
//    for (int i=1;; i++)
while(((c=getchar())!=EOF)&&(c>='0')&&(c<='9')) {
        res_arr[counter] += (c - 48)*(i++);
//       cout << " " << c <<" "; 
//        c = getchar(); 
//if (c==' ') break;
        
}}
cout  << "\n" << "answer:" << "\n";
for (int counter = 0; counter < n; counter++){
     cout <<  res_arr[counter] << " ";
}
delete [] res_arr;
return 0;
}
