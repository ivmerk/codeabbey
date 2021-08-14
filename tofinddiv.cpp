/*ищим делители от вводимого числа и заносим в ыектор*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
    int data;
    int fibNumber = 3;
    int mdata;
    int fibvalueminus = 1;
    int tmp;
    int fibvalue = 2;
    vector<int> result;
    string datastring;
    cout << "\nввести число\n";
    cin >> data;
    cin.ignore();
    getline(cin, datastring);
    for (int i = 0; i < data; i++)
    {
        tmp = 0;
        while ((datastring[0] != ' ') && (datastring[0] != '\n') && (datastring[0] != '\0'))
        {

            tmp = tmp * 10 + (datastring[0] - '0');
            datastring.erase(datastring.begin());
        }
        datastring.erase(datastring.begin());
        mdata = tmp;
        fibNumber = 3;
        fibvalueminus = 1;
        fibvalue = 2;
        while (((fibvalue + fibvalueminus) % mdata))

        {
            tmp = (fibvalue + fibvalueminus) % mdata;
            fibvalueminus = fibvalue;
            fibvalue = tmp;
            fibNumber++;
        }
        result.push_back(++fibNumber);
    }
    cout << "\n";
    while (result.size())
    {

        cout << result[0] << " ";
        result.erase(result.begin());
    }
    return 0;
}