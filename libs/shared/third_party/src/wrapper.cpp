#include "complex.h"

// do not mangle the names 
extern "C" {
    void* create_complex(int a, int b) {
        return new Complex(a, b);
    }
    void add_complex(void* complex_ptr1, void* complex_ptr2) {
        if (!complex_ptr1)
            return;
        Complex* cp_ptr1 = static_cast<Complex*>(complex_ptr1);
        Complex* cp_ptr2 = static_cast<Complex*>(complex_ptr2);
        cp_ptr1-> operator+= (*cp_ptr2);
    }
    void sub_complex(void* complex_ptr1, void* complex_ptr2) {
        if (!complex_ptr1)
            return;
        Complex* cp_ptr1 = static_cast<Complex*>(complex_ptr1);
        Complex* cp_ptr2 = static_cast<Complex*>(complex_ptr2);
        cp_ptr1-> operator-= (*cp_ptr2);
    }
    void print_complex(void* complex_ptr) {
        if (complex_ptr != nullptr) {
            Complex* cp_ptr = static_cast<Complex*>(complex_ptr);
            std::cout << *cp_ptr;
        }
    }
    void destroy_complex(void* complex_ptr) {
        if (complex_ptr != nullptr) {
            Complex* cp_ptr = static_cast<Complex*>(complex_ptr);
            delete cp_ptr;
        }
    }
}
