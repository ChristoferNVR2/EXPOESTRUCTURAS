#ifndef EXPOBUSQUEDAS_DOUBLYLINKEDLIST_H
#define EXPOBUSQUEDAS_DOUBLYLINKEDLIST_H

#include <iostream>
#include <conio.h>
#include "Node.h"

using namespace std;

class DoublyLinkedList {
private:
    Node* head;
    [[nodiscard]]Node* lastNode() const {
        if (head == nullptr) {
            return nullptr;
        }
        Node* last = head;
        while (last->next != nullptr) {
            last = last->next;
        }
        return last;
    }
    static Node* findMid(Node* first, Node* last) {
        if (first == nullptr || last == nullptr) {
            return nullptr;
        }

        while (first->next != nullptr && first->next != last) {
            first = first->next;
            if (last->prev != nullptr) {
                last = last->prev;
            }
        }

        return first;
    }

    static bool binarySearch(Node* start, Node* end, int ref) {
        if (start == end) {
            return (start != nullptr && start->value == ref);
        }

        while (start != nullptr && start != end) {
            Node* mid = findMid(start, end);

            if (mid->value == ref) {
                return true;
            } else if (mid->value < ref) {
                start = mid->next;
            } else {
                end = mid->prev;
            }
        }

        return false;
    }

    bool recursiveSearch(Node* start, Node* end, int ref) const { // NOLINT(misc-no-recursion)
        if (start == end) {
            return (start != nullptr && start->value == ref);
        }

        Node* mid = findMid(start, end);

        if (mid != nullptr) {
            if (mid->value == ref) {
                return true;
            } else if (mid->value < ref) {
                return recursiveSearch(mid->next, end, ref);
            } else {
                return recursiveSearch(start, mid->prev, ref);
            }
        }

        return false;
    }

public:

    DoublyLinkedList() : head(nullptr) {}

    void insert(int val) {
        Node* tail = lastNode();
        Node* newNode = new Node{val, nullptr, nullptr};
        if (head == nullptr) {
            head = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
        }
    }

    void displayList() const {
        if (head == nullptr) {
            cout << "-> NULL" << endl;
            return;
        }
        Node* iterator = head;
        while (iterator != nullptr) {
            cout << iterator->value << " -> ";
            iterator = iterator->next;
        }
        cout << "NULL" << endl;
    }

    void deleteList() {
        Node* killer = head;
        Node* next;

        while (killer != nullptr) {
            next = killer->next;
            delete killer;
            killer = next;
        }
        head = nullptr;
    }

    


    int sequentialSearch(int target) {
        if (head == nullptr){
            return 0;
        }

        Node* current = head;
        int pos = 1;

        do {
            if (current->value == target) {
                return pos;
            }
            pos++;
            current = current->next;
        } while (current != nullptr);

        return 0;
    }

    [[nodiscard]] bool binarySearch(int ref) const {
        return binarySearch(head, lastNode(), ref);
    }

    [[nodiscard]] bool recursiveSearch(int ref) const {
        return recursiveSearch(head, lastNode(), ref);
    }

    ~DoublyLinkedList() {
        deleteList();
    }
};

#endif //EXPOBUSQUEDAS_DOUBLYLINKEDLIST_H
