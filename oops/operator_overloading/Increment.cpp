#include <iostream>
using namespace std;

class Integer {
private:
    int i;
public:
    Integer() :i(0) {} // default constructor
    Integer(int x) :i(x) {} // parameterised constructor
    Integer(const Integer& robj) { // copy constructor
        this->i = robj.i;
    }
    // prefix
    void operator++() {
        ++i;
    }
    // postfix
    void operator++(int) {
        ++i;
    }
    friend ostream& operator<<(ostream&, const Integer&);
};

ostream& operator<<(ostream& out, const Integer& x) {
    out << x.i << endl;
    return out;
}

int main() {
    Integer x = Integer(10);
    cout << x;
    ++x;
    x++;
    cout << x;
    return 0;
}