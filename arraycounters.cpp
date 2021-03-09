/*
 Input data contain M and N in the first line.
The second (rather long) line will contain M numbers separated by spaces.
Answer should contain exactly N values, separated by spaces. First should give amount of 1-s, second - amount of 2-s and so on.
*/

#include <iostream>

using namespace std;
int main()
{
int n=1; //количество чисел
int m;
cout << "input data" << "\n";
cin >> n;
cin >> m;
cout << "\n";
int *res = new int[m]; 
for (int i = 0; i < m; i++)
          res[i] = 0;
int c;
for (int counter = 0; counter < n; counter++){
     cin >> c;
     for (int i=0; i < m; i++){
          if (c == i+1)
                  ++res[i];

}
}
cout  << "\n" << "answer:" << "\n";
     for (int i=0; i < m; i++)
cout <<  res[i] << " ";
     
return 0;
}
