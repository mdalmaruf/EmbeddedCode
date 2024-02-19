//Write a function in C to reverse a linked list.
struct Node {
    int data;
    struct Node* next;
};

struct Node* reverseLinkedList(struct Node* head) {
    struct Node *prev = NULL, *current = head, *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}
