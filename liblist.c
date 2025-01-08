#include "liblist.h"

#include <stdlib.h>

Node *create_node(void) {
  Node *temp = malloc(sizeof(Node));
  if (temp == NULL) {
    return NULL;
  }
  temp->next = NULL;
  return temp;
}

/*
 * Add a node to the end of the list
 * If head is NULL, create a new node and return it
 * If head is not NULL, add a new node to the end of the list
 */
Node *add_node(Node *head, int value) {
  Node *end = create_node();
  if (end == NULL) {
    return NULL;
  }
  end->data = value;

  if (head == NULL) {
    return end;
  }

  Node *p = head;
  while (p->next != NULL) {
    p = p->next;
  }
  p->next = end;
  return head;
}

Node *search(Node *head, int value) {
  if (head == NULL) {
    return NULL;
  }

  Node *p = head;
  while (p != NULL) {
    if (p->data == value) {
      return p;
    }
    p = p->next;
  }
  return p;
}

Node *delete_node(Node *head, int value) {
  if (head == NULL) {
    return NULL;
  }

  Node *p = head;
  Node *prev = NULL; /* only the head's prev can be null */
  while (p->next != NULL || prev == NULL) {
    if (p->data == value) {
      if (prev == NULL) {
        Node *temp = p;
        head = p->next;
        free(temp);
      } else {
        Node *temp = p;
        prev->next = p->next;
        free(temp);
      }
    }
    prev = p;
    p = p->next;
  }
  return head;
}
