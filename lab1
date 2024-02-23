#include <iostream>
using namespace std;

struct Tovar {
    int id;
    int q;
    Tovar* next;
};

void AddFirst(Tovar*& head, int id, int q) {
    Tovar* newTovar = new Tovar;
    newTovar->id = id;
    newTovar->q = q;
    newTovar->next = head;
    head = newTovar;
}

void PrintList(Tovar* head) {
    if (head == nullptr) {
        cout << "This list is empty" << endl;
        return;
    }
    Tovar* current = head;
    while (current != nullptr) {
        cout << "Tovar id: " << current->id << ", q: " << current->q << endl;
        current = current->next;
    }
}

int main() {
    Tovar* head = nullptr;

    int id1 = 1;
    int q1 = 5;

    int id2 = 2;
    int q2 = 11;

    PrintList(head);
    cout << "++++++++++++++++++++++++++++++++++" << endl;

    AddFirst(head, id1, q1);
    PrintList(head);
    cout << "===================================" << endl;

    AddFirst(head, id2, q2);
    PrintList(head);

    return 0;
}
