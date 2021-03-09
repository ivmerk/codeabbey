/*Переворот строки - очень простая задача - для тех кто начинает изучать текстовые строки...
Входные данные содержат одну строку из латинских букв и пробелов.
Ответ должен содержать строку такой же длины, но с символами в обратном порядке.*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;
int main()
{
        vector <char> stack;
int n=1; //счетчик символов в строке
cout << "input data" << "\n";
char c = 1;
while (((c = getchar()) != EOF ) && (c != '\n')){
      n++;
      stack.push_back(c);  }
cout  << "\n" << "answer:" << "\n";
for (int counter = 0; counter <= n; counter++){
        c = stack[n-counter];
     cout <<  c;
   
}
cout << "\n";
return 0;
}
