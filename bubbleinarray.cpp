/*
 Нам дан массив для которого нужно посчитать контрольную сумму. Делается это следующим образом: каждый элемент (начиная с первого) добавляем к текущему результату и умножаем то что получилось на 113 - то что получилось берем по модулю 10000007 - оно и будет новым значением результата, и так далее.
*/

#include <iostream>

using namespace std;
int main()
{
int n=1; //количество чисел
cout << "input data" << "\n";
cin >> n;
int c = 1;
long res = 0; // результат
//while (((c = getchar()) != EOF ) && (c != '\n')){
//      n++;
//      stack.push_back(c);  }
for (int counter = 0; counter < n; counter++){
cin >> c;
 res = (res+c)*113;
 res = res > 10000007?res%10000007:res;

}
cout  << "\n" << "answer:" << "\n";
cout << "\n" << res << "\n";
return 0;
}
