#ifndef LIBLIST_H
#define LIBLIST_H

typedef struct Node {
  int data;
  struct Node *next;
} Node;

Node *create_node(void);
Node *add_node(Node *head, int value);
const Node *search(const Node *head, int value);
Node *delete_node(Node *head, int value);
void free_list(Node *head);
void print_list(const Node *head);
int get_length(const Node *head);

// todo
// Insert a node at the beginning of the list
Node *insert_at_beginning(Node **head, int value);

// Insert a node at a specific position in the list
Node *insert_at_position(Node **head, int value, int position);

// Get a node at a specific index in the list
Node *get_node_at_index(Node *head, int index);

// Reverse the order of nodes in the list
Node *reverse_list(Node **head);

// Concatenate two lists
Node *concatenate_lists(Node *list1, Node *list2);

// Create a deep copy of the list
Node *copy_list(Node *head);


#endif // LIBLIST_H
