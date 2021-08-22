#include <iostream>
#
using namespace std;

int main()

{
    int n = 16;
    int result = 0;
    while (n) // ...
    {
        result += n % 10;
        n /= 10;
    }
    return result;
}