#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node* next;
} Node;

void insert_with_priority(Node** queue, int value) {
    Node* newNode = malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;

    if (*queue == NULL) {
        *queue = newNode;
    } else {
        if (value > (*queue)->value) {
            newNode->next = *queue;
            *queue = newNode;
        } else {
            Node* current = *queue;
            while (current->next != NULL && value <= current->next->value) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }
}

int remove_highest_priority(Node** queue) {
    if (*queue == NULL) {
        printf("Priority queue is empty.\n");
        return -1;
    }

    Node* first = *queue;
    int value = first->value;
    *queue = first->next;
    free(first);

    return value;
}

void print_queue(Node* queue) {
    if (queue == NULL) {
        printf("Priority queue is empty.\n");
        return;
    }

    Node* current = queue;
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Node* queue = NULL;

    insert_with_priority(&queue, 10);
    insert_with_priority(&queue, 5);
    insert_with_priority(&queue, 20);
    insert_with_priority(&queue, 15);

    print_queue(queue);

    int highestPriority = remove_highest_priority(&queue);
    printf("Removed element with highest priority: %d\n", highestPriority);

    print_queue(queue);

    return 0;
}
