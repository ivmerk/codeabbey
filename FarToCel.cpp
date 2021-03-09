#include <iostream>
using namespace std;

int main()
{
int n;
cout << "input data" << "\n";
cin >> n ;
float  *far_arr = new float [n];
float res = 0.0;
for (int counter = 0; counter < n; counter++){
     cin >> far_arr[counter];
}
cout  << "answer:" << "\n";
for (int counter = 0; counter < n; counter++){
        res = (far_arr[counter] -32) * 100 / 180;
        int intres  = res;
        float ost = 10 * res- 10 * intres;
        if (ost >= 5) {++res;}
        if (ost <= -5) {--res;}
        intres = res; 
        cout << intres << " " ;

}
delete [] far_arr;
return 0;
}
