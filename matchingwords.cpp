/*Ali-Baba found a secret cave with treasures, stored by The Forty Thieves. However, famous magical phrase Open Sesame obviously does not work.

Instead there is a long and strange text inscribed on the stone wall - and Ali-Baba guessed that one should find matching words in this inscription (i.e. ones which are encountered more than once) and pronounce them in alphabetical order.

We are to help the poor craftsman to access the thieves' treasury. Let's write a program that sieves necessary words from the given text, and prints them in the proper order.

Input data consist of about 300 words, each made of 3 Latin letters. The end is signaled by the word end.
Answer should contain all the words which are encountered more than once in lexicographic order.

Example:

input data:
nun lam mip tex bal pif sot bal bod tex end

answer:
bal tex
Note: although for small amount of words one can write double nested loop to compare words, this approach is inefficient for large numbers of words - it is not suitable for one million words etc. Try to invent a better approach.*/
#include <iostream>
#include <string>
using namespace std;
int main(){
cout << "\n" << "inpur data:" << "\n";
string*resarr = new string [400];
string*check = new string[400];
string data = "111";
int ires = 0;
int nres = 0;
int ich = 0;
int nch = 0;
while (data != "end"){
        cin >> data;
        if (nch == 0){
                check [nch++] = data;
                continue;
        }
        for (ich = 0; ich < nch; ich++){
                if (data == check[ich]){
                        if (nres == 0)
                               resarr[nres++] = data;
                        for (ires = 0; ires < nres; ires++){
                                if (data == resarr[ires])
                                        break;
                                if (ires == nres-1){
                                        resarr[nres++] = data;
                                        ires++;
                                }
                        }
                }
            if (ich == nch-1){
                        check[nch++] = data;
                ich++;}
        }
}
cout << "\n" << "answer:" << "\n";
for (ires = 0; ires < nres; ires++)
        cout << resarr[ires] << " ";
delete [] resarr;
delete [] check;
return 0;
}
