#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
typedef struct node {
    int data;
    struct node *next;
} node_t;

// Function to create a new node with given data
node_t *create_node(int data) {
    node_t *new_node = (node_t *) malloc(sizeof(node_t));
    if (new_node == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to insert a new node at the beginning of the list
void insert_beginning(node_t **head, int data) {
    node_t *new_node = create_node(data);
    if (new_node == NULL) return;
    new_node->next = *head;
    *head = new_node;
}

// Function to delete a node with the given key
void delete_node(node_t **head, int key) {
    node_t *temp = *head, *prev;

    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    prev->next = temp->next;
    free(temp);
}

// Function to insert a new node at the end of the list
void insert_end(node_t **head, int data) {
    node_t *new_node = create_node(data);
    if (new_node == NULL) return;

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    node_t *last = *head;
    while (last->next != NULL) {
        last = last->next;
    }

    last->next = new_node;
}

void update_node_value(node_t *head, int old_value, int new_value) {
    node_t *current = head;
    while (current != NULL) {
        if (current->data == old_value) {
            current->data = new_value;
            break;
        }
        current = current->next;
    }
}

// Function to search for a node with the given key
node_t *search(node_t *head, int key) {
    node_t *current = head;
    while (current != NULL) {
        if (current->data == key) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Function to display the linked list
void display_list(node_t *head) {
    node_t *current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    node_t *head = NULL;

    insert_beginning(&head, 3);
    insert_beginning(&head, 2);
    insert_beginning(&head, 1);

    int key = 2;
    node_t *result = search(head, key);

    if (result != NULL) {
        printf("Found node with data %d\n", result->data);
    } else {
        printf("Node with data %d not found\n", key);
    }

    display_list(head);

    update_node_value(head, 2, 5);

    display_list(head);

    return 0;
}
