/* Two bicyclist start moving from different cities heading to meet each other somewhere in the middle (not exactly since they travel with different speed).

The road is laid in straight line between two cities.

You will be given the distance between cities S (in kilometers) and speed values for two bicyclists (A and B in kilometers per hour). Your task is to find their meeting point (its distance from the first of cities).

Input data will have the number of test-cases in the first line.
Next lines will contain three values each S A B.
Answer should contain the distances between first city and rendezvous point (i.e. distance travelled by first cyclist before they meet), separated with spaces.

Example:

input data:
2
10 1 1
20 1 2

answer:
5 6.66666667
Note: the floating point values should have precision 10e-7 or better*/
#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;
int main()
{
int n;
cout << "\n" << "input data;" << "\n";
cin >> n;
double* resarr = new double[n];
for (int i = 0; i < n; i++){
        int dist, speeda, speedb;
        cin >> dist >> speeda>> speedb;
        resarr[i] = (1.0*dist/(speeda+speedb)*speeda);
}
cout << "\n" << "answer:" << "\n";
cout.precision(10);
for (int i = 0; i < n; i++){
        cout << resarr[i] << " ";
}
delete [] resarr;
return 0;
}
