#include <iostream>

using namespace std;

// Define a structure for a doubly linked list node
struct ListNode {
    int data;
    ListNode* next;
    ListNode* prev;
    ListNode(int val) : data(val), next(nullptr), prev(nullptr) {}
};

// Function to insert a new node at the end of the doubly linked list
void insertAtEnd(ListNode*& head, int val) {
    ListNode* newNode = new ListNode(val);
    if (!head) {
        head = newNode;
    } else {
        ListNode* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}

// Function to swap two nodes in a doubly linked list
void swapNodes(ListNode* node1, ListNode* node2) {
    if (node1 == node2) return;

    // Swap the next pointers
    ListNode* temp = node1->next;
    node1->next = node2->next;
    node2->next = temp;

    if (node1->next) {
        node1->next->prev = node1;
    }
    if (node2->next) {
        node2->next->prev = node2;
    }

    // Swap the prev pointers
    temp = node1->prev;
    node1->prev = node2->prev;
    node2->prev = temp;

    if (node1->prev) {
        node1->prev->next = node1;
    }
    if (node2->prev) {
        node2->prev->next = node2;
    }
}

// Function to partition a doubly linked list
ListNode* partition(ListNode* left, ListNode* right) {
    int pivotValue = right->data;
    ListNode* i = left->prev;

    for (ListNode* j = left; j != right; j = j->next) {
        if (j->data < pivotValue) {
            i = (i == nullptr) ? left : i->next;
            swapNodes(i, j);
        }
    }

    i = (i == nullptr) ? left : i->next;
    swapNodes(i, right);

    return i;
}

// Function to perform quick sort on a doubly linked list
void quickSort(ListNode* left, ListNode* right) {
    if (right != nullptr && left != right && left != right->next) {
        ListNode* pivot = partition(left, right);
        quickSort(left, pivot->prev);
        quickSort(pivot->next, right);
    }
}

// Function to perform quick sort on a doubly linked list
ListNode* quickSortList(ListNode* head) {
    ListNode* tail = head;
    while (tail != nullptr && tail->next != nullptr) {
        tail = tail->next;
    }
    quickSort(head, tail);
    return head;
}

// Function to print a doubly linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    ListNode* head = nullptr;

    // Insert elements into the doubly linked list
    insertAtEnd(head, 8);
    insertAtEnd(head, 3);
    insertAtEnd(head, 1);
    insertAtEnd(head, 6);
    insertAtEnd(head, 4);
    insertAtEnd(head, 7);
    insertAtEnd(head, 2);
    insertAtEnd(head, 5);

    cout << "Original Doubly Linked List: ";
    printList(head);

    // Perform Quick Sort on the doubly linked list
    head = quickSortList(head);

    cout << "Sorted Doubly Linked List: ";
    printList(head);

    return 0;
}
