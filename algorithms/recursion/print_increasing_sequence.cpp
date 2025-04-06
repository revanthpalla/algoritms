#include <iostream>
using namespace std;

void print_increasing_order(int n) {
    if (n == 1) {
        cout << n << "\t";
        return;
    }
    print_increasing_order(n - 1);
    cout << n << "\t";
}

void print_decreasing_order(int n) {
    if (n == 1) {
        cout << n << "\t";
        return;
    }
    cout << n << "\t";
    print_decreasing_order(n - 1);
}

int main() {
    print_increasing_order(5);
    print_decreasing_order(5);
    return 0;
}