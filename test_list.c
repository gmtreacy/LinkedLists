#include "liblist.h"

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  Node *head = create_node();
  if (head == NULL) {
    fprintf(stderr, "Memory allocation failed\n");
    return EXIT_FAILURE;
  }

  head->data = 7;
  printf("single node with value %d\n", head->data);
  free(head);
  return EXIT_SUCCESS;
}
