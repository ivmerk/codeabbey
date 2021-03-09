/*Входные данные имеют такой формат:

первая строка содержит число N - количество тестов которые нужно обработать;
следующие N строк содержат по три целых числа A B C, составляющих один тест;
для каждого теста нужно умножить A на B и добавить C (т.е. A * B + C) - после чего сосчитать сумму цифр результата.
Ответ должен содержать N результатов, разделенных пробелами.

*/


#include <iostream>
#include <string>
using namespace std;
int sumofdigit (int i[]){
       int res=0;
        int d = i[0] * i[1] + i[2];  
 //       cout << "\n" <<  i[0] << " "<< i[1] << " "<< i[2] << " " << d << "\n";
       while (d != 0){
          res += d % 10;
          d = (d - d % 10) /10;
       }
return res;
} 
int main()
{
int n;
cout << "input data" << "\n";
cin >> n ;
cout << "\n";
int  *res_arr = new int [n]; //array of result
int c = 1;
int abc[3];
int tmp = getchar();
for (int counter = 0; counter < n; counter++){
    for (int i = 0; i<3; i++){
        cin >> abc[i] ; 
        
        
}

res_arr[counter] += sumofdigit(abc);
}
cout  << "\n" << "answer:" << "\n";
for (int counter = 0; counter < n; counter++){
     cout <<  res_arr[counter] << " ";
}
delete [] res_arr;
return 0;
}
