Task 1:
int numbers[100]; // creates array of 100 integers (uninitialized)

Task 2: 

#include <iostream>
using namespace std;

int main() {
    int arr[100];
    cout << "Size of one int element: " << sizeof(arr[0]) << " bytes" << endl;

    double darr[100];
    cout << "Size of one double: " << sizeof(darr[0]) << " bytes" << endl;

    char carr[100];
    cout << "Size of one char: " << sizeof(carr[0]) << " bytes" << endl;

    return 0;
}


Task 3:
Operation,Number of steps (worst case),Big-O notation,Explanation
Reading (by index),1,O(1),Direct memory access – constant time
Searching for a value not in array,100,O(N),Must check every element in worst case
Insertion at beginning,~100,O(N),Shift all 99 elements right by one position
Insertion at end,1,O(1),Just place value at last position (if space available)
Deletion at beginning,~100,O(N),Shift all 99 elements left by one position
Deletion at end,1,O(1),Just decrease logical size / ignore last element

Task 4:

count = 0
for i from 0 to N-1:
    if array[i] == "apple":
        count = count + 1
return count

Task 5:

#include <iostream>
using namespace std;

int main() {
    int arr[100];

    cout << "Array base address (arr)     : " << arr << endl;
    cout << "Same using &arr[0]            : " << &arr[0] << endl;
    cout << "Address of second element     : " << &arr[1] << endl;  // usually +4 bytes

    return 0;
}



