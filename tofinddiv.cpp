/*ищим делители от вводимого числа и заносим в ыектор*/
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int data;
    int fibNumber = 3;
    int fibvalueminus = 1;
    int tmp;
    int fibvalue = 2;
    vector<int> result;

    cout << "\nввести число\n";
    cin >> data;
    while (((fibvalue + fibvalueminus) % data))
    {
        tmp = (fibvalue + fibvalueminus) % data;
        fibvalueminus = fibvalue;
        fibvalue = tmp;
        fibNumber++;
    }
    result.push_back(++fibNumber);
    cout << "\n"
         << fibNumber << "\n";
    return 0;
}