#include <string>
#include <iostream>
using namespace std;
bool solution(std::string const &str, std::string const &ending)
{
    long long tmp = str.size() - ending.size();
    std::string tmpstr = str;
    tmpstr.erase(0, tmp);
    cout << tmpstr;
    return ((tmpstr == ending) || !ending.size());
}
int main()
{
    std::string str = "abcde";
    std::string ending = "cde";
    std::string tmp = str.substr(ending.size() - 1);
    bool answer = solution(str, ending);
    //cout << answer;
    return 0;
}