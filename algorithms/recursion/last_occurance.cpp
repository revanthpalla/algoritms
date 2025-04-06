#include <iostream>
using namespace std;

/* arr 1, 2, 7, 6, 7, 5, key = 7
1 2 7 6 7 5  , 3+1 = 4
  2 7 6 7 5  , 2+1 = 3
    7 6 7 5  , 1+1 = 2
      6 7 5  , return 1 + 0 = 1;
        7 5  , 7 == 7 return 0;
          5  , after empty return here arr[0] == key, 5 != 7, return -1
          []
*/
int last_occur(int arr[], int n, int key) {
    if (n == 0)
        return -1;
    int result = last_occur(arr + 1, n - 1, key);
    if (result == -1) {
        if (arr[0] == key)
            return 0;
        else
            return -1;
    }
    return 1 + result;
}

int main() {
    int arr[] = { 1, 2, 7, 6, 7, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << last_occur(arr, n - 1, 8) << endl;
    return 0;
}