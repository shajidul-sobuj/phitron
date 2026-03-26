#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Node {
    char data;
    struct Node* next;
} Node;

void push(Node** top, char ch) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = ch;
    newNode->next = *top;
    *top = newNode;
}

char pop(Node** top) {
    if (*top == NULL) return '\0';
    Node* temp = *top;
    char ch = temp->data;
    *top = (*top)->next;
    free(temp);
    return ch;
}

char peek(Node* top) {
    if (top == NULL) return '\0';
    return top->data;
}

int isEmpty(Node* top) {
    return top == NULL;
}

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

void infixToPostfix(const char* infix) {
    Node* stack = NULL;
    int len = strlen(infix);

    for (int i = 0; i < len; i++) {
        char ch = infix[i];

        if (ch == ' ') continue;

        if (isdigit(ch) || isalpha(ch)) {
            printf("%c ", ch);
        }
        else if (ch == '(') {
            push(&stack, ch);
        }
        else if (ch == ')') {
            while (!isEmpty(stack) && peek(stack) != '(') {
                printf("%c ", pop(&stack));
            }
            pop(&stack);
        }
        else if (isOperator(ch)) {
            while (!isEmpty(stack) &&
                   peek(stack) != '(' &&
                   isOperator(peek(stack)) &&
                   (ch == '^' ? precedence(peek(stack)) > precedence(ch)
                               : precedence(peek(stack)) >= precedence(ch))) {
                printf("%c ", pop(&stack));
            }
            push(&stack, ch);
        }
    }

    while (!isEmpty(stack)) {
        printf("%c ", pop(&stack));
    }
    printf("\n");
}

int main() {
    char infix[200];

    if (fgets(infix, sizeof(infix), stdin) == NULL) {
        return 0;
    }

    infix[strcspn(infix, "\n")] = '\0';
    if (strlen(infix) == 0) {
        return 0;
    }

    printf("Infix expression: %s\n", infix);
    printf("Postfix expression: ");
    infixToPostfix(infix);

    return 0;
}