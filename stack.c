#include <stdio.h>
#include <stdbool.h>

#define MAX 10

typedef struct {
    int itens[MAX];
    int top;
} Stack;

void start_stack(Stack *p) {
    p->top = -1;
}

bool full_stack(Stack *p) {
    return p->top == MAX - 1;
}

bool empty_stack(Stack *p) {
    return p->top == -1;
}

bool push(Stack *p, int value) {
    if (full_stack(p)) {
        return false;
    }
    p->top++;
    p->itens[p->top] = value;
    return true;
}

bool pop(Stack *p, int *value) {
    if (empty_stack(p)) {
        return false;
    }
    *value = p->itens[p->top];
    p->top--;
    return true;
}

int peek(Stack *p) {
    if (empty_stack(p)) {
        printf("A pilha está vazia.\n");
        return -1;
    }
    return p->itens[p->top];
}

int length_stack(Stack *p) {
    return p->top + 1;
}

void print_stack(Stack *p) {
    printf("Pilha: ");
    for (int i = 0; i <= p->top; i++) {
        printf("%d ", p->itens[i]);
    }
    printf("\n");
}

int main() {
    Stack p;
    int value;

    full_stack(&p);

    push(&p, 10);
    push(&p, 20);
    push(&p, 30);

    if (pop(&p, &value)) {
        printf("Elemento removido do topo da pilha: %d\n", value);
    } else {
        printf("A pilha está vazia.\n");
    }

    return 0;
}

