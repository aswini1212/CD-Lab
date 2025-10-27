#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char symbol;
    char expression[20];
} ProductionRule;

typedef struct {
    char start;
    int nump;
    ProductionRule rules[20];
} Grammar;

typedef struct Stack {
    char symbol;
    struct Stack *next;
} Stack;

Grammar g;
Stack *outputstack = NULL, *inputstack = NULL;
char input[50];

// Operator precedence table
//      i    +    *    $
char prec[4][4] = {
// i
    {'>', '>', '>', '>'},
// +
    {'<', '>', '<', '>'},
// *
    {'<', '>', '>', '>'},
// $
    {'<', '<', '<', '>'}
};

int findIndex(char ch) {
    switch (ch) {
        case 'i': return 0;
        case '+': return 1;
        case '*': return 2;
        case '$': return 3;
        default:  return 3;
    }
}

Stack* push(Stack *st, char inp) {
    Stack *node = (Stack*) malloc(sizeof(Stack));
    node->symbol = inp;
    node->next = st;
    return node;
}

char pop(Stack **st) {
    if (*st) {
        char symbol = (*st)->symbol;
        Stack *temp = *st;
        *st = (*st)->next;
        free(temp);
        return symbol;
    }
    return '$';
}

void printstack(Stack *st) {
    Stack *arr[100];
    int top = -1;
    while (st) {
        arr[++top] = st;
        st = st->next;
    }
    while (top >= 0)
        printf("%c", arr[top--]->symbol);
    printf("\t\t");
}

char precedence(char a, char b) {
    return prec[findIndex(a)][findIndex(b)];
}

void read_grammar() {
    printf("Enter the start symbol: ");
    scanf(" %c", &g.start);

    printf("Enter the number of productions: ");
    scanf("%d", &(g.nump));

    printf("Enter the productions (like E->E+T):\n");
    for (int i = 0; i < g.nump; i++) {
        scanf(" %c->%s", &g.rules[i].symbol, g.rules[i].expression);
    }
}

int shift() {
    if (inputstack) {
        char sym = pop(&inputstack);
        outputstack = push(outputstack, sym);
        printf("$");
        printstack(outputstack);
        printstack(inputstack);
        printf("SHIFT\n");
        return 1;
    }
    return 0;
}

int reduce_once() {
    for (int i = 0; i < g.nump; i++) {
        ProductionRule rule = g.rules[i];
        Stack *ptr = outputstack;
        int len = strlen(rule.expression);
        int flag = 1;

        // Match RHS from top of stack backwards
        for (int j = len - 1; j >= 0; j--) {
            if (!ptr || ptr->symbol != rule.expression[j]) {
                flag = 0;
                break;
            }
            ptr = ptr->next;
        }

        if (flag) {
            // Matched — perform reduction
            printf("$");
            printstack(outputstack);
            printstack(inputstack);
            printf("REDUCE(%c->%s)\n", rule.symbol, rule.expression);

            for (int k = 0; k < len; k++)
                pop(&outputstack);
            outputstack = push(outputstack, rule.symbol);
            return 1;
        }
    }
    return 0;
}

void parse() {
    // Add end marker to input
    strcat(input, "$");

    // Push input string in reverse
    for (int j = strlen(input) - 1; j >= 0; j--)
        inputstack = push(inputstack, input[j]);

    // Initialize output stack with $
    outputstack = push(outputstack, '$');

    printf("OUTPUT\t\tINPUT\t\tACTION\n");

    while (1) {
        char a = outputstack ? outputstack->symbol : '$';
        char b = inputstack ? inputstack->symbol : '$';
        char rel = precedence(a, b);

        if (rel == '<' || rel == '=') {
            if (!shift())
                break;
        } 
        else if (rel == '>') {
            // Keep reducing while possible
            if (!reduce_once())
                break;
        } 
        else {
            break;
        }

        // Accept condition: only $E$ remains
        if (inputstack && inputstack->symbol == '$' &&
            outputstack && outputstack->next &&
            outputstack->symbol == g.start &&
            outputstack->next->symbol == '$') {
            printf("$");
            printstack(outputstack);
            printstack(inputstack);
            printf("ACCEPTED\n");
            return;
        }

        // Reject early if precedence invalid
        if (a == '$' && b == '$') break;
    }

    printf("$");
    printstack(outputstack);
    printstack(inputstack);
    printf("REJECTED\n");
}

int main() {
    read_grammar();
    printf("Enter the input string (e.g., i+i*i): ");
    scanf("%s", input);
    parse();
    return 0;
}
