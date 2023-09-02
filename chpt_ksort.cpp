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

// Function to merge two sorted doubly linked lists
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode dummy(0); // Dummy node for the merged list
    ListNode* tail = &dummy;

    while (list1 && list2) {
        if (list1->data < list2->data) {
            tail->next = list1;
            list1->prev = tail;
            list1 = list1->next;
        } else {
            tail->next = list2;
            list2->prev = tail;
            list2 = list2->next;
        }
        tail = tail->next;
    }

    if (list1) {
        tail->next = list1;
        list1->prev = tail;
    } else {
        tail->next = list2;
        list2->prev = tail;
    }

    return dummy.next;
}

// Function to perform K-Merge Sort on a doubly linked list
ListNode* kMergeSort(ListNode* head) {
    if (!head || !head->next) {
        return head; // Base case: List is already sorted or empty
    }

    // Split the list into two halves
    ListNode* slow = head;
    ListNode* fast = head->next;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode* left = head;
    ListNode* right = slow->next;
    slow->next = nullptr;

    // Recursively sort the two halves
    left = kMergeSort(left);
    right = kMergeSort(right);

    // Merge the sorted halves
    return mergeTwoLists(left, right);
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

    // Perform K-Merge Sort on the doubly linked list
    head = kMergeSort(head);

    cout << "Sorted Doubly Linked List: ";
    printList(head);

    return 0;
}
