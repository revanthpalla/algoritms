#include <iostream>
using namespace std;

/* time complexity - O(n) n function calls
    space complexity - O(n)
*/
int fact(int n) {
    if (n == 0)
        return 1;
    return n * fact(n - 1);
}

int main() {
    int n;
    cin >> n;
    cout << fact(n) << endl;
    return 0;
}