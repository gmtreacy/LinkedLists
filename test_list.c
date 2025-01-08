#include "liblist.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int tests_run = 0;
int tests_failed = 0;

void run_test(void (*test)(void), const char *name) {
  tests_run++;
  printf("Running test: %s\n", name);
  test();
  printf("Test passed: %s\n\n", name);
}

void test_create_node(void) {
  Node *node = create_node();
  node->data = 7;
  assert(node != NULL);
  assert(node->data == 7);
  assert(node->next == NULL);
  free(node);
}

void test_add_node(void) {
  Node *head = create_node();
  head->data = 7;

  head = add_node(head, 8);
  assert(head->data == 7);
  assert(head->next != NULL);
  assert(head->next->data == 8);
  assert(head->next->next == NULL);

  free(head->next);
  free(head);
}

void test_search(void) {
  Node *head = create_node();
  head->data = 7;
  head = add_node(head, 8);
  head = add_node(head, 9);

  Node *found = search(head, 8);
  assert(found != NULL);
  assert(found->data == 8);

  found = search(head, 10);
  assert(found == NULL);

  free(head->next->next);
  free(head->next);
  free(head);
}

void test_delete(void) {
  Node *head = create_node();
  head->data = 7;
  head = add_node(head, 8);
  head = add_node(head, 9);

  head = delete_node(head, 8);
}

int main(void) {
  run_test(test_create_node, "create_node");
  run_test(test_add_node, "add_node");
  run_test(test_search, "search");
  run_test(test_delete, "delete");

  printf("Tests run: %d\n", tests_run);
  printf("Tests failed: %d\n", tests_failed);

  return tests_failed ? EXIT_FAILURE : EXIT_SUCCESS;
}
