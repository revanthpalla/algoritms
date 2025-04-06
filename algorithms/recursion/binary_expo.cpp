#include <iostream>
using namespace std;

int power(int a, int N) {
    if (N == 0)
        return 1;
    int ans = power(a, N / 2);
    if (N % 2 == 0) // even
        return ans * ans;
    else // odd
        return a * ans * ans;
}

int main() {
    cout << power(2, 10) << endl;
    return 0;
}