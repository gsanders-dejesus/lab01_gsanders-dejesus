// intlist.cpp
// Implements class IntList
// YOUR NAME(S), AND DATE

#include "intlist.h"

#include <iostream>
using std::cout;

// copy constructor
IntList::IntList(const IntList& source) {
    head = nullptr;
    Node *tail = nullptr;
    for(Node *p = source.head; p; p = p->next){
	    Node *n = new Node;
	    n->info = p->info;
	    n->next = nullptr;
	    if(tail){
		    tail->next = n;
	    }
	    else{
		    head = n;
	    }
	    tail = n;
    }
}

// destructor deletes all nodes
IntList::~IntList() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}


// return sum of values in list
int IntList::sum() const {
    int total = 0;

    for (Node* p = head; p != nullptr; p = p->next) {
        total += p->info;
    }

    return total;
}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
    for (Node* p = head; p != nullptr; p = p->next) {
        if (p->info == value) {
            return true;
        }
    }

    return false;
}

// returns maximum value in list, or 0 if empty list
int IntList::max() const {
    if (head == nullptr) {
        return 0;
    }

    int largest = head->info;

    for (Node* p = head->next; p != nullptr; p = p->next) {
        if (p->info > largest) {
            largest = p->info;
        }
    }

    return largest;
}

// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
    int total = 0;
    int number = 0;

    for (Node* p = head; p != nullptr; p = p->next) {
        total += p->info;
        number++;
    }

    if (number == 0) {
        return 0.0;
    }

    return static_cast<double>(total) / number;
}

// inserts value as new node at beginning of list
void IntList::push_front(int value) {
    Node* n = new Node;
    n->info = value;
    n->next = head;
    head = n;
}

// append value at end of list
void IntList::push_back(int value) {
    Node* n = new Node;
    n->info = value;
    n->next = nullptr;

    if (head == nullptr) {
        head = n;
        return;
    }

    Node* p = head;
    while (p->next != nullptr) {
        p = p->next;
    }

    p->next = n;
 
}

// return count of values
int IntList::count() const {
   int total = 0;

    for (Node* p = head; p != nullptr; p = p->next) {
        total++;
    }

    return total;
}


//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source){

    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    Node* tail = nullptr;

    for (Node* p = source.head; p != nullptr; p = p->next) {
        Node* n = new Node;
        n->info = p->info;
        n->next = nullptr;

        if (head == nullptr) {
            head = n;
        } else {
            tail->next = n;
        }

        tail = n;
    }

    return *this;
}

// constructor sets up empty list
IntList::IntList(){ 
    head = nullptr; 
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

