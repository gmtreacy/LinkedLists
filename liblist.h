#ifndef LIBLIST_H
#define LIBLIST_H

typedef struct Node {
  int data;
  struct Node *next;
} Node;

Node *create_node(void);
Node *add_node(Node *head, int value);
Node *search(Node *head, int value);
Node *delete_node(Node *head, int value);
void free_list(Node *head);
void print_list(Node *head);
int get_length(Node *head);

#endif // LIBLIST_H
