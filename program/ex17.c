#include <stdio.h>
#include <stdlib.h>

struct Node {
    char data;
    struct Node *next;
};

void insert(struct Node **head, char value) {
    struct Node *newNode = malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node *temp = *head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
    }
}

void display(struct Node *head) {
    struct Node *temp = head;

    while (temp != NULL) {
        printf("%c -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main(void) {
    struct Node *head = NULL;
    int n, i;
    char value;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter character: ");
        scanf(" %c", &value);
        insert(&head, value);
    }

    printf("Linked list: ");
    display(head);

    while (head != NULL) {
        struct Node *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}