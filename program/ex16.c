#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void search(struct node *head, int key)
{
    int position = 1;

    while (head != NULL)
    {
        if (head->data == key)
        {
            printf("Element found at position %d\n", position);
            return;
        }

        head = head->next;
        position++;
    }

    printf("Element not found\n");
}

int main()
{
    struct node *head = NULL;
    struct node *temp, *newNode;
    int n, i, value, key;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        newNode = malloc(sizeof(struct node));

        if (newNode == NULL)
        {
            printf("Memory allocation failed!\n");
            return 1;
        }

        printf("Enter element: ");
        scanf("%d", &value);

        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL)
            head = newNode;
        else
        {
            temp = head;

            while (temp->next != NULL)
                temp = temp->next;

            temp->next = newNode;
        }
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    search(head, key);

    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}