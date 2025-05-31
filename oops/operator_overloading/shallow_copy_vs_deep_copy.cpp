#include <iostream>
#include <cstring>
using namespace std;

class student {
private:
    int id;
    char* name;
public:
    student() :id(0), name(NULL) {}
    student(int id, const char* name) {
        this->id = id;
        int len = strlen(name);
        this->name = new char[len + 1];
        strcpy(this->name, name);
    }
    // copy constrcutor avoid shallo copy
    student(const student& obj) {
        id = obj.id;
        int len = strlen(obj.name);
        name = new char[len + 1];
        strcpy(name, obj.name);
    }
    // set name
    void set_name(const char* new_name) {
        int len = strlen(new_name);
        delete[] name;
        name = NULL;
        name = new char[len + 1];
        strcpy(name, new_name);
    }
    void print() {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
    }
};

int main() {
    student s(10, "Revanth");
    student s1 = s;
    s1.print();
    s1.set_name("Rajesh");
    s1.print();
    s.print();
    return 0;
}