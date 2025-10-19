#ifndef AST1_H
#define AST_H
typedef struct Node{
    char *operator;
    int num;
    struct Node *left;
    struct Node *right;
}Node;

Node* makenum(int val);
Node* makeop(char *op,Node *l,Node *r);
void PrintNode(Node *root);
#endif