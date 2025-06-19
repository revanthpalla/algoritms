#include <iostream>
using namespace std;

class node {
private:
    int data;
    node* next;
public:
    node(int d) :data(d), next(nullptr) {}
    friend class linked_list;
};

class linked_list {
private:
    node* head;
public:
    linked_list() :head(nullptr) {}
    linked_list(int d) {
        node* x = new node(d);
        head = x;
    }
    ~linked_list() {
        node* x;
        while (head) {
            x = head;
            head = head->next;
            delete x;
        }
    }
    void push_front(int d);
    void push_back(int d);
    void deleteByValue(int d);
    void reverse_list();
    void display();
};

void linked_list::push_back(int d) {
    node* x = new node(d);
    if (head == nullptr) {
        head = x;
        return;
    }
    node* curr = head;
    while (curr->next) {
        curr = curr->next;
    }
    curr->next = x;
    return;
}

void linked_list::display() {
    if (head == nullptr) {
        cout << "linked list is empty" << endl;
        return;
    }
    node* temp = head;
    while (temp) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "null" << endl;
}

void linked_list::push_front(int d) {
    node* x = new node(d);
    if (head == nullptr) {
        head = x;
        return;
    }
    x->next = head;
    head = x;
    return;
}

void linked_list::deleteByValue(int d) {
    // special case for head
    if (head != nullptr and head->data == d) {
        node* curr = head;
        head = curr->next;
        curr->next = nullptr;
        delete curr;
        return;
    }
    node* prev = head;
    node* curr = head;
    while (curr) {
        if (curr->data == d) {
            prev->next = curr->next;
            curr->next = nullptr;
            delete curr;
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}

void linked_list::reverse_list() {
    node* curr_node = head;
    node* prev_node = nullptr;
    node* next_node = nullptr;
    while (curr_node) {
        next_node = curr_node->next;
        curr_node->next = prev_node;
        prev_node = curr_node;
        curr_node = next_node;
    }
    head = prev_node;
}

int main() {
    linked_list l = linked_list(5);
    l.push_back(6);
    l.push_front(7);
    l.deleteByValue(7);
    l.display();
    l.reverse_list();
    l.display();
    return 0;
}