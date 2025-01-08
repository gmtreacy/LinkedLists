#ifndef LIBLIST_H
#define LIBLIST_H

typedef struct Node {
  int data;
  struct Node *next;
} Node;

Node *create_node(void);

#endif // LIBLIST_H
