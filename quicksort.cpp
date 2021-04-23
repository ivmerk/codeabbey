/*Now that you have learned about three sorting algorithms with quadratic time complexity (Bubble, Selection and Insertion sorts) you should be curious, whether it is possible to perform the task significantly faster.

The problem is that if these algorithms solrt 10000 elements in a second, then they will sort 100 times more elements (one million) in about 100*100 longer time, i.e. several hours!

Luckily there really are other approaches. One of them is a Quick-sort. It uses quite simple idea and allows to sort with time complexity of O(N*log(N)) which increases almost proportional to simple N rather than N*N as with simpler methods!

Algorithm
Suggest we have an array of numbers:

5 3 8 1 4 7 2 9 6
Let us choose some element - call it pivot and try to reorder others in such a way that ones which are lesser than pivot will be put before it while others, which are greater, will take place behind it. For example if pivot is 5 then we want something like this:

2 3 4 1 5 7 8 9 6
Now we can say that array is partially sorting - it have two unordered parts, but these parts are ordered in relation to each other. We need not move elements between them any more - only inside them.

Now let us regard this array like composition of pivot and two subarrays:

[2 3 4 1] 5 [7 8 9 6]
Obviously we can apply the same strategy to each of sub-parts, and proceed until subarrays will decrease to the size of 1. It is convenient to use recursive function for such algorithm:

function quicksort(array, left, right):
    pivot_pos = partition(array, left, right)
    if pivot_pos - left > 1
        quicksort(array, left, pivot_pos - 1)
    end if
    if right - pivot_pos > 1
        quicksort(array, pivot_pos + 1, right)
    end if
end fun
Here the function receives the array being sorted as an argument and also two indices specifying which range should be sorted by this call.

Partitioning
The only tricky moment is how to perform "partitioning" - i.e. choosing pivot and reordering elements to the sides of it. Lazy implementations, especially in functional programming languages, may create two new sub-arrays and filter elements into them - however it is not "honest" since proper quicksort could be done "in-place".

Here is one of the approaches, based on moving large elements to the rightmost end and small elements to the leftmost end step by step:

Pivot is initially copied to temporary variable to provide one "empty" cell and is returned to array only when the pass is over.
Empty space is initially placed on the left side of array.
We maintain two pointers to the segment still not processed - left lt and right rt; the algorithm moves lt and rt towards each other leaving partitioned elements outside.
When the empty space is on the left, we compare elements pointed by other end rt (decreasing it in loop) with pivot, until we find one which is less (and so it should not be on the right side); then this element is swapped with the "empty" space.
Now (when empty space is on the right) we compare elements pointed by lt (increasing it at each step) until we find the element which is greater than pivot and should be swapped with empty space on the right.
So we continue steps 4 and 5 until lt and rt meet - then we restore pivot to this point (which is "empty").
Here is the pseudocode:

function partition(array, left, right)
    lt = left
    rt = right
    dir = ' <left'        #specifies at which side is currently "empty" space
    pivot = array[left]
    while lt < rt
        if dir = 'left'
            if array[rt] > pivot
                rt = rt - 1
            else
                a[lt] = a[rt]
                lt = lt + 1
                dir = 'right'
            end if
        else
            if array[lt] < pivot
                lt = lt + 1
            else
                a[rt] = a[lt]
                rt = rt - 1
                dir = 'left'
            end if
        end if
    end while
    array[lt] = pivot       #here lt = rt - both points to empty cell where pivot should return
    return lt
end fun
Examine this algorithm step by step with pencil and paper to see how it works.

Problem statement
Please implement the described algorithm and run it on a sample array. For each call of quicksort please output its left and right parameters.

Input data will contain N - the size of array - in the first line.
Next line will contain the array itself (all elements will be different).
Answer should contain left-right ranges for each call of the recursive function in order. Separate values of each pair with a dash, while pairs itself should be separated with spaces.

Example:

input data:
10
38 23 9 19 113 5 42 85 71 112

answer:
0-9 0-3 1-3 1-2 5-9 5-8 5-7  */
#include <iostream>
#include <vector>
using namespace std;
void quickSort(vector<int> &data, int left, int right)
{
     int tmp;
     int service_right = right;
     int pivot = left;
     cout << left << "-" << right << " ";
     while (pivot < service_right)
     {
          if (data[pivot] < data[service_right])
          {
               service_right--;
          }
          else
          {
               tmp = data[pivot];
               data[pivot] = data[service_right];
               data[service_right] = data[pivot + 1];
               data[++pivot] = tmp;
          }
          /*
          for (int i = left; i <= right; i++)
          {
               cout << data[i] << " ";
          }
          cout << endl;*/
     }
     /*if ((pivot == left) && (right - left > 1))
     {
          pivot++;
          quickSort(data, pivot, right);
     }*/
     // if (((pivot - 1 - left > 1)) || ((pivot - 1 - left > 0) && (data[left] > data[left + 1])))
     if ((pivot - left > 1))
     {
          quickSort(data, left, pivot - 1);
     }
     //if ((((right - pivot - 1 > 0) && (data[right] < data[right - 1])) || (right - pivot - 1 > 1)))
     if (right - pivot > 1)
     {
          quickSort(data, pivot + 1, right);
     }
}
int main(int argc, char **argv)
{
     int numbers;
     int tmp;
     int low = 0;
     vector<int> data;
     cout << "\ninput data:\n";
     cin >> numbers;

     int high = numbers - 1;
     //     new *data = new int[numbers];
     for (int i = 0; i < numbers; i++)
     {
          cin >> tmp;
          data.push_back(tmp);
     }
     cout << "\nanswer\n";
     quickSort(data, low, high);
     cout << endl;
     for (int i = 0; i < numbers; i++)

     {
          cout << data[i] << " ";
     }
     cout << endl;
     cout << endl;
     return 0;
}
