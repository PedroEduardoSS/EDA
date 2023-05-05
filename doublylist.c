#include <stdio.h>;
#include <stdlib.h>;

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

void insert_beginning(struct node** head_ref, int new_data);
void insert_after(struct node* prev_node, int new_data);
void insert_end(struct node** head_ref, int new_data);

void print_list(struct node* head);

void update_node(struct node* head, int position, int new_data);

void delete_node(struct node** head_ref, struct node* del_node);



int main() {

    /* Initialize nodes */
    /*
    struct node *head;
    struct node *one = NULL;
    struct node *two = NULL;
    struct node *three = NULL;

    /* Allocate memory
    one = malloc(sizeof(struct node));
    two = malloc(sizeof(struct node));
    three = malloc(sizeof(struct node));

    /* Assign data values
    one->data = 1;
    two->data = 2;
    three->data = 3;

    /* Connect nodes
    one->next = two;
    one->prev = NULL;
    two->next = three;
    two->prev = one;
    three->next = NULL;
    three->prev = two;

    /* Save address of first node in head
    head = one;
    print_list(head);*/
    struct node* head = NULL;

    insert_beginning(&head, 5);
    insert_beginning(&head, 4);
    insert_beginning(&head, 3);
    insert_end(&head, 6);
    insert_end(&head, 7);
    insert_after(head->next, 10);

    printf("List before deletion: ");
    print_list(head);

    delete_node(&head, head->next->next);

    printf("List after deletion: ");
    print_list(head);

    update_node(head, 2, 11);

    printf("List after updating the node: ");
    print_list(head);
    return 0;
}

void insert_beginning(struct node** head_ref, int new_data) {
        struct node* new_node = (struct node*)malloc(sizeof(struct node));
        new_node->data = new_data;
        new_node->next = *head_ref;
        new_node->prev = NULL;
        if (*head_ref != NULL) {
            (*head_ref)->prev = new_node;
        }
        *head_ref = new_node;
    }

void insert_after(struct node* prev_node, int new_data) {
    if (prev_node == NULL) {
        printf("The given previous node cannot be NULL");
        return;
    }
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
    new_node->prev = prev_node;
    if (new_node->next != NULL) {
        new_node->next->prev = new_node;
    }
}

void insert_end(struct node** head_ref, int new_data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    struct node* last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL) {
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
    new_node->prev = last;
}

void delete_node(struct node** head_ref, struct node* del_node) {
    if (*head_ref == NULL || del_node == NULL) {
        return;
    }
    if (*head_ref == del_node) {
        *head_ref = del_node->next;
    }
    if (del_node->next != NULL) {
        del_node->next->prev = del_node->prev;
    }
    if (del_node->prev != NULL) {
        del_node->prev->next = del_node->next;
    }
    free(del_node);
}

void update_node(struct node* head, int position, int new_data) {
    struct node* temp = head;
    int count = 0;
    while (temp != NULL) {
        if (count == position) {
            temp->data = new_data;
            return;
        }
        count++;
        temp = temp->next;
    }
}

void print_list(struct node* head) {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
