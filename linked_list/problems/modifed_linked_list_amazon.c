#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int size = 0;
struct Node* head = NULL;

void Insert_end(int val);
void print();
void modify_list(struct Node* he);

int main() {
    Insert_end(10);
    Insert_end(4);
    Insert_end(5);
    Insert_end(3);
    Insert_end(6);
    print();
  

    struct Node* he = head;
    struct Node* ab = head;
    int k = 1;
    while (he != NULL) {
        if (k == (size / 2) + 2) {
            break;
        }
        he = he->next;
        k++;
    }
    modify_list(he);
    printf("\n");
    head = ab;
    print();

    return 0;
}

void Insert_end(int val) {
    struct Node* tmp = (struct Node*)malloc(sizeof(struct Node));
    tmp->data = val;
    tmp->next = NULL;

    if (head == NULL) {
        head = tmp;
        return;
    }

    struct Node* abd = head;
    while (abd->next != NULL) {
        abd = abd->next;
    }
    abd->next = tmp;
}

void print() {
    struct Node* gh = head;
    while (gh != NULL) {
        size++;
        printf("%d \t", gh->data);
        gh = gh->next;
    }
    printf("\n");
}

void modify_list(struct Node* he) {
    if (he == NULL) {
        return;
    }
    modify_list(he->next);
    int a = head->data;
    head->data = he->data - head->data;
    he->data = a;
    head = head->next;
}
