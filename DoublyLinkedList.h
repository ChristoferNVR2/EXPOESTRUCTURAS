#ifndef EXPOBUSQUEDAS_DOUBLYLINKEDLIST_H
#define EXPOBUSQUEDAS_DOUBLYLINKEDLIST_H

#include <iostream>
#include <conio.h>
#include "Node.h"

using namespace std;

class DoublyLinkedList {
public:
    Node* head;

    DoublyLinkedList() : head(nullptr) {}

    [[nodiscard]] Node* lastNode() const {
        if (head == nullptr) {
            return nullptr;
        }
        Node* last = head;
        while (last->next != nullptr) {
            last = last->next;
        }
        return last;
    }

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

    [[nodiscard]] bool binarySearch(int ref) const {
        if (head == nullptr) {
            return false;
        }

        Node* start = head;
        Node* end = lastNode();

        //se compara con nullptr para el caso en que no exista
        while (start != nullptr && end != nullptr && start != end) {
            Node* mid = findMid(start, end);

            if (mid->value == ref) {
                return true;
            } else if (mid->value < ref) {
                start = mid->next;
            } else {
                end = mid->prev;
            }
        }

        //aca tambien
        return ((start != nullptr && start->value == ref) || (end != nullptr && end->value == ref));
    }

    ~DoublyLinkedList() {
        deleteList();
    }

private:
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
};


#endif //EXPOBUSQUEDAS_DOUBLYLINKEDLIST_H
