/*
Входные данные задают количество тесткейсов в первой строке.
Далее в отдельных строках следуют сами тесткейсы.
Каждый содержит 4 целых числа - x1 y1 x2 y2.
Ответы также должны быть целыми - значениями для a и b, объединёнными в скобки попарно и разделенными пробелами.
*/

#include <iostream>

using namespace std;
int main()
{
int n=1; //количество чисел
int x1,x2,y1,y2;
cout << "input data" << "\n";
cin >> n;
cout << "\n";
int *res1 = new int[n]; 
int *res2 = new int[n]; 
for (int i = 0; i < n; i++){
cin >> x1;
cin >> y1;
cin >> x2;
cin >> y2;
res1[i] = (y1-y2)/(x1-x2);
res2[i] = (y1-res1[i]*x1);

}
cout  << "\n" << "answer:" << "\n";
     for (int i=0; i < n; i++)
cout << "(" <<  res1[i] << " " << res2[i] << ")" << " ";
delete [] res1;
delete [] res2;
return 0;
}
