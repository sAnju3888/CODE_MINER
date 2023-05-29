#include <iostream>
#include <stack>
using namespace std;

struct Node {
    int data;
    struct Node* next;
};

struct Node* head;

void Insert(int x);
void print();
void stack_reverse();

int main() {
    head = NULL;
    Insert(2);
    Insert(5);
    Insert(10);
    print();
    stack_reverse();
    print();

    return 0;
}

void Insert(int x) {
    struct Node* tmp = new Node;
    tmp->data = x;
    tmp->next = NULL;
    if (head == NULL) {
        head = tmp;
        return;
    }
    struct Node* pnt;
    pnt = head;
    while (pnt->next != NULL) {
        pnt = pnt->next;
    }
    pnt->next = tmp;
}

void print() {
    struct Node* mgr;
    mgr = head;
    while (mgr != NULL) {
        cout << mgr->data << "\t";
        mgr = mgr->next;
    }
    cout << endl;
}

void stack_reverse() {
    stack<struct Node*> s;
    struct Node* ab = head;
    while (ab != NULL) {
        s.push(ab);
        ab = ab->next;
    }
    head = s.top();
    s.pop();
    struct Node* temp = head;
    while (!s.empty()) {
        temp->next = s.top();
        s.pop();
        temp = temp->next;
    }
    temp->next = NULL;  // Set the last node's next pointer to NULL
}
