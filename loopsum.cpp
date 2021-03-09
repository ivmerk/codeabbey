#include <iostream>
using namespace std;

int main()
{
int n;
int sum = 0;
int loop;
cout << "input data" << "\n";
cin >> n ;
cout  << "\n";
for (int counter = 0; counter < n; counter++){
cin >> loop;
sum += loop;
};
cout  << "\n" <<  sum << "\n";
return 0;
}
