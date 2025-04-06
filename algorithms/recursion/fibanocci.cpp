#include <iostream>
using namespace std;

/* time complexity - O(2^n)
    space complexity - O(n)

                fib(n)                  - 1 call  (0th level)
          fib(n-1)  fib(n-2)            - 2 calls (1st level)
fib(n-2) fib(n-3)    fib(n-3) fib(n-4)  - 4 calls (2nd level)
    .........

    fib(1) fib(0)                       - 2^n calls (nth level)
    */
int fib(int n) {
    if (n <= 1)
        return n;
    int ans = fib(n - 1) + fib(n - 2);
    return ans;
}

int main() {
    int n;
    cin >> n;
    cout << fib(n) << endl;
    return 0;
}