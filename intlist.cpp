// intlist.cpp
// Implements class IntList
// Amit Karthikeyan, Neil Gadagkar 04/16/2025

#include "intlist.h"

#include <iostream>
using std::cout;

// copy constructor
IntList::IntList(const IntList& source) {
   head = nullptr;
   tail = nullptr;
   if (source.head == nullptr) return;
   head = new Node{source.head->info, nullptr};
   Node* p = head;
   Node* q = source.head->next;
   while (q != nullptr) {
    p->next = new Node{q->info, nullptr};
    p = p->next;
    q = q->next;
   }
   tail = p;
}

// destructor deletes all nodes
IntList::~IntList() {
    //IMPLEMENT THIS
    Node* p = head;
    while (p != nullptr) {
        Node* q = p->next;
        delete p;
        p = q;
    }

}


// return sum of values in list
int IntList::sum() const {
    Node* p = head;
    int sum = 0;
    while (p != nullptr) {
        sum += p->info;
        p = p->next;
    }
    return sum; 
}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
    Node* p = head;
    while(p != nullptr) {
        if (p->info == value) {
            return true;
        }
        p = p->next;
    }
    return false; 
}

// returns maximum value in list, or 0 if empty list
int IntList::max() const {
    int max;
    Node* p = head;
    if (p == nullptr) {
        return 0;
    } else {
        max = p->info;
    }
    while(p != nullptr) {
        if (p->info > max) {
            max = p->info;
        }
        p = p->next;
    }
    return max; 
}

// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
    int count = 0;
    double sum = 0;
    Node* p = head;
    while(p != nullptr) {
        count++;
        sum += p->info;
        p =  p->next;
    }
    return sum/count; // REPLACE THIS NON-SOLUTION
}

// inserts value as new node at beginning of list
void IntList::push_front(int value) {
    // IMPLEMENT
    Node* p = new Node;
    p->info = value;
    p->next = head;
    head = p;
}

// append value at end of list
void IntList::push_back(int value) {
    // IMPLEMENT
    Node* p = new Node;
    p->info = value;
    p->next = nullptr;
    if (tail == nullptr) { 
        head = p;
        tail = p;
    } else {
        tail->next = p;
        tail = p;
    }
 
}

// return count of values
int IntList::count() const {
   Node* p = head;
   int count = 0;
   while(p != nullptr) {
    count++;
    p = p->next;
   }
   return count;
}


//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source) {
    if (this == &source) return *this;
    Node* p = head;
    while (p != nullptr) {
        Node* q = p->next;
        delete p;
        p = q;
    }
    head = nullptr;
    tail = nullptr;
    if (source.head == nullptr) {
        return *this;
    }
    head = new Node{source.head->info, nullptr};
    p = head;
    Node* q = source.head->next;
    while (q != nullptr) {
        p->next = new Node{q->info, nullptr};
        p = p->next;
        q = q->next;
    }
    tail = p;
    return *this;
}

// constructor sets up empty list
IntList::IntList(){ 
    head = nullptr;
    tail = nullptr;
}


// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)

// print values enclose in [], separated by spaces
void IntList::print() const {
    Node *n = head;
    cout << '[';
    while (n) {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}

