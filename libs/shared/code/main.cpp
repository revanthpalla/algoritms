#include <iostream>
#include <dlfcn.h> // The header for dynamic loading
using namespace std;

/* function pointers inside header of external lib */
typedef void* (*create_complex_t)(int, int);
typedef void(*add_complex_t)(void*, void*);
typedef void(*sub_complex_t)(void*, void*);
typedef void(*print_complex_t)(void*);
typedef void(*destroy_complex_t)(void*);

int main() {
    void* lib_handle = dlopen("/Users/revanthpalla/code/libs/shared/code/build/libComplex.dylib", RTLD_LAZY);
    if (!lib_handle) {
        std::cerr << "error() of external lib: " << dlerror() << endl;
        return 1;
    }
    // resolve the c names from .dylib
    create_complex_t cc_complex = (create_complex_t)dlsym(lib_handle, "create_complex");
    add_complex_t ad_complex = (add_complex_t)dlsym(lib_handle, "add_complex");
    sub_complex_t sb_complex = (sub_complex_t)dlsym(lib_handle, "sub_complex");
    print_complex_t pr_complex = (print_complex_t)dlsym(lib_handle, "print_complex");
    destroy_complex_t dy_complex = (destroy_complex_t)dlsym(lib_handle, "destroy_complex");

    // call those functions 
    void* my_complex_1 = cc_complex(5, 6);
    void* my_complex_2 = cc_complex(7, 8);

    cout << "Normal prints of 2 complexes: " << endl;
    pr_complex(my_complex_1);
    pr_complex(my_complex_2);

    ad_complex(my_complex_1, my_complex_2);
    cout << "After adding 2 complexes and storing result in 1st complex: " << endl;
    pr_complex(my_complex_1);
    pr_complex(my_complex_2);

    dy_complex(my_complex_1);
    dy_complex(my_complex_2);

    dlclose(lib_handle);
    return 0;
}