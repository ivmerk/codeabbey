/*Переворот строки - очень простая задача - для тех кто начинает изучать текстовые строки...
Входные данные содержат одну строку из латинских букв и пробелов.
Ответ должен содержать строку такой же длины, но с символами в обратном порядке.*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;
//int countval (char i){        
//  char vowel[6] = {'a', 'o', 'u', 'i', 'e', 'y'};
//          for (int r = 0; r < 6; r++){
//               if (i == vowel[r]) return 1;
//          }
//return 0;
//} 
int main()
{
        vector <char> stack;
int n=1; //счетчик символов в строке
cout << "input data" << "\n";
//cin >> n ;
//cout << "\n";
//int  *res_arr = new int [n]; //array of result
int c = 1;
//int tmp = getchar();
//for (int counter = 0; counter < n; counter++){
while (((c = getchar()) != EOF ) && (c != '\n')){
      n++;
      stack.push_back(c);  }
//for (i;;){
//        c = getchar(); 
//        res_arr[counter] += countval(c);
//if (c=='\n') break;
        
//}}
cout  << "\n" << "answer:" << "\n";
for (int counter = 0; counter < n; counter++){
     cout <<  stack.pop_back();
}
//delete [] res_arr;
return 0;
}
