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
