#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void deleteElement(struct Node **head, int value) {
    struct Node *current = *head;
    struct Node *previous = NULL;

    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    /* Delete the first node */
    if (current->data == value) {
        *head = current->next;
        free(current);
        printf("Element deleted.\n");
        return;
    }

    /* Search for the element */
    while (current != NULL && current->data != value) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Element not found.\n");
        return;
    }

    previous->next = current->next;
    free(current);
    printf("Element deleted.\n");
}

void display(struct Node *head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void insertEnd(struct Node **head, int value) {
    struct Node *newNode = malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

int main(void) {
    struct Node *head = NULL;
    int n, value, key, i;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter element: ");
        scanf("%d", &value);
        insertEnd(&head, value);
    }

    printf("Original list: ");
    display(head);

    printf("Enter element to delete: ");
    scanf("%d", &key);

    deleteElement(&head, key);

    printf("Updated list: ");
    display(head);

    while (head != NULL) {
        struct Node *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}