#include <iostream>
using namespace std;

/* https://medium.com/@RobuRishabh/beginners-guide-to-linked-list-in-c-d8445ef906ab */
class node {
private:
    int data;
    node* next;
public:
    node(int d) :data(d), next(nullptr) {}
    friend class linked_list;
    /* some common algo's */
    int get_data() {
        return data;
    }
    node* get_next_node() {
        return next;
    }
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
    void removeNthNodeFromEnd(int pos);
    // common algo's making it as friends
    friend linked_list* merge(linked_list*, linked_list*);
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

// merge two sorted lists
linked_list* merge(linked_list* l1, linked_list* l2) {
    linked_list* merged = new linked_list();
    node* c1 = l1->head;
    node* c2 = l2->head;
    while (c1 != nullptr && c2 != nullptr) {
        if (c1->get_data() < c2->get_data()) {
            merged->push_back(c1->get_data());
            c1 = c1->get_next_node();
        } else {
            merged->push_back(c2->get_data());
            c2 = c2->get_next_node();
        }
    }
    while (c1 != nullptr) {
        merged->push_back(c1->get_data());
        c1 = c1->get_next_node();
    }
    while (c2 != nullptr) {
        merged->push_back(c2->get_data());
        c2 = c2->get_next_node();
    }
    return merged;
}

void linked_list::removeNthNodeFromEnd(int pos) {
    node* slow = head;
    node* fast = head;
    for (int i = 1;i < pos;i++) {
        fast = fast->next;
        if (fast == nullptr) {
            cout << "linked list length is less than position" << endl;
            return;
        }
    }
    static bool one_cycle_less = 1;
    while (fast->next != nullptr) {
        fast = fast->next;
        if (one_cycle_less) {
            one_cycle_less = 0;
            continue;
        }
        slow = slow->next;
    }
    node* x = slow->next;
    slow->next = x->next;
    x->next = nullptr;
    delete x;
}

int main() {
    linked_list l = linked_list(7);
    l.push_back(5);
    l.push_back(6);
    l.push_back(12);
    l.push_back(3);
    l.push_back(9);
    l.push_back(11);
    l.display();
    l.removeNthNodeFromEnd(2);
    l.display();
    return 0;
}