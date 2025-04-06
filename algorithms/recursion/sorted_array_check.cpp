#include <iostream>
#include <stdbool.h>
using namespace std;

bool is_sorted(int arr[], int start, int end) {
    bool result = false;
    // base case
    if (start == end)
        return true;
    if (arr[start] <= arr[start + 1]) {
        result = is_sorted(arr, start + 1, end);
    }
    return result;
}

int main() {
    int arr[] = { 1, 2, 4, 3, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << is_sorted(arr, 0, n - 1) << endl;
    return 0;
}