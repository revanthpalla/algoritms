#include <iostream>
using namespace std;

/*  arr - [1, 3, 5, 7, 6, 2], key = 7 final ans = 3(index)
arr[0] = 1, (1 == 7) false search in arr+1, 2+1 = 3
arr[0] = 3, (3 == 7) false search in arr+1, 1+1 = 2
arr[0] = 5, (5 == 7) false search in arr+1, 1+0 = 1
arr[0] = 7, (7 == 7) true, return 0
*/
int first_occur(int arr[], int n, int key) {
    if (arr[0] == arr[n] && arr[0] != key)
        return -1;
    if (arr[0] == key)
        return 0;
    else {
        int ans = first_occur(arr + 1, n, key);
        if (ans != -1)
            return 1 + ans;
        return ans;
    }
}

int main() {
    int arr[] = { 1, 3, 5, 7, 6, 2 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << first_occur(arr, n - 1, 11) << endl;
    return 0;
}