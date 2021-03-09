/*Even beginner programmers are usually acquainted with the Fibonacci Sequence which is generated as following:
0-th value is 0;
1-st value is 1;
all next values are sum of two immediately preceeding.
So we have:
0: 0
1: 1
2: 1 = 0 + 1
3: 2 = 1 + 1
4: 3 = 1 + 2
5: 5 = 2 + 3
6: 8 = 3 + 5
and so on, so if you continue calculations yourself, you get the the beginning of the sequence like this:
0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, ...
One easily notes that values grow fast! The 17-th value already exceeds thousand, the 31-st is larger than million.
Problem statement
You will be given several Fibonacci numbers. Your task is to tell their indices in the sequence.
Input data contain the amount of Fibonacci numbers to process.
Next lines contain one Fibonacci number each (from the first 1000 values).
Answer should contain their indices in the sequence, separated by spaces.
Example:
input data:
5
610
34
0
1346269
10946
answer:
15 9 0 31 21
Take care: values could be of hundred or more digits long!*/
#include<iostream>
#include<vector>

using namespace std;
int main(){
int n;
cout << "\n" << "input data:" << "\n";
cin >> n;
    cout << "\n";
    int i = getchar();
    vector <int>  data, fibfig, fibfigl;
    int*resarr = new int[n];
    int c=5;
    for (int i = 0; i < n; i++){
        data.clear();
        fibfigl.clear();
        fibfig.clear();
        fibfig.push_back(0);
        fibfigl.push_back(1);
        int flag =0;
            resarr[i] = 1;
            while(((c=getchar())!=EOF)&&(c!='\n')){
                    data.insert(data.begin(), 1,(c-48));
            }
            if ((data[0] == 0)&&(data.size() ==1)) {
                    resarr[i] = 0;
                    flag = 1;
            }
            if ((data[0] == 1)&&(data.size() == 1)){
                    resarr[i] = 1;
                    flag = 1;
            }
            
            while (flag!=1){
                            vector <int> tmp(fibfigl.size());// буфер для прошлого челена
                            tmp = fibfigl;
                            resarr[i]++;
                            if ((fibfigl[fibfigl.size()-1]) >= 6) //добавляем разряд если возможно увеличение
                               fibfigl.resize(fibfigl.size()+1);
                              if ((fibfig[fibfig.size()-1]) >= 6) //добавляем разряд если возможно увеличение
                              fibfig.resize(fibfig.size()+1);
                            for (int m = 0; m < fibfig.size(); m++){// создаём вектор с числом фибоначи
                                    if (fibfig[m]+fibfigl[m] < 10) {
                                            fibfigl[m] += fibfig[m];
                                    }
                                    else {
                                            fibfigl[m] += fibfig[m]-10;
                                            fibfigl[m+1] +=1;
                                    }
                            }
                            fibfig = tmp;
                            tmp.clear();
                         /*   if (fibfigl[fibfigl.size()-1] == 0)
                                fibfigl.erase(fibfigl.begin());
                           if (fibfig[fibfig.size()-1] == 0)
                             fibfig.erase(fibfig.begin());*/
                    
                    for (int y = 0; y < data.size(); y++) {
                        if (fibfigl[y] == data[y]){
                            flag = 1;
                            y++;}
                            if (fibfigl[y] != data[y]){
                                    flag = 0;
                                    break;
                            }
                   }
         }
    }
    cout << "\n" << "answer" << "\n";
    for (int i =0; i < n; i++)
    cout << resarr[i] << " ";
        cout << "\n";
    delete [] resarr;
        return 0;
    }

