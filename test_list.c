#define _POSIX_C_SOURCE 200809L

#include "liblist.h"
#include <assert.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int tests_run = 0;
int tests_failed = 0;

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

void test_delete_node(void) {
    Node *head = create_node();
    assert(head != NULL);
    head->data = 7;
    head = add_node(head, 8);
    head = add_node(head, 9);

    head = delete_node(head, 8);
    assert(head != NULL);
    assert(head->data == 7);
    assert(head->next != NULL);
    assert(head->next->data == 9);
    assert(head->next->next == NULL);

    head = delete_node(head, 7);
    assert(head != NULL);
    assert(head->data == 9);
    assert(head->next == NULL);

    head = delete_node(head, 9);
    assert(head == NULL);
}

void test_print_list(void) {
    Node *head = create_node();
    assert(head != NULL);
    head->data = 7;
    head = add_node(head, 8);
    head = add_node(head, 9);
    head = add_node(head, 10);

    print_list(head);
    
    // Save original stdout
    int original_stdout = dup(fileno(stdout));
    
    // Redirect stdout to a file for testing
    freopen("output.txt", "w", stdout);
    print_list(head);
    fclose(stdout);
    
    // Restore stdout
    FILE *new_stdout = fdopen(original_stdout, "w");
    *stdout = *new_stdout;
    setvbuf(stdout, NULL, _IONBF, 0);
    
    printf("finished writing the file\n");

    // Read the output and verify its contents
    FILE *fp = fopen("output.txt", "r");
    assert(fp != NULL);

    char buffer[100];
    int line_count = 0;
    int values[3];

    while (fgets(buffer, sizeof(buffer), fp) && line_count < 3) {
        char *token = strtok(buffer, ",");
        if (token != NULL) {
            token = strtok(NULL, ","); // Get the second element
            if (token != NULL) {
                sscanf(token, " %d", &values[line_count]);
                line_count++;
            }
        }
        printf("%s\n", buffer);
    }

    fclose(fp);

    // Verify that there are exactly three lines
    assert(line_count == 3);

    // Verify the values in each line
    assert(values[0] == 7);
    assert(values[1] == 8);
    assert(values[2] == 9);
    
    printf("finished asserts\n");

    free(head->next->next);
    free(head->next);
    free(head);
    
    printf("finished frees\n");
}

void test_get_length(void) {
    Node *head = create_node();
    assert(head != NULL);
    head->data = 7;
    head = add_node(head, 8);
    head = add_node(head, 9);
    head = add_node(head, 10);
    int length = get_length(head);
    assert(length == 4);
}

void test_free_list() {
    // Create a linked list
    Node* head = malloc(sizeof(Node));
    Node* second = malloc(sizeof(Node));
    Node* third = malloc(sizeof(Node));
    
    head->data = 1;
    head->next = second;
    second->data = 2;
    second->next = third;
    third->data = 3;
    third->next = NULL;
    
    // Call free_list
    free_list(head);
}

void run_test(void (*test)(void), const char *name) {
    tests_run++;
    printf("Running test: %s\n", name);
    test();
    printf("Test passed: %s\n\n", name);
}

int main(void) {
    run_test(test_create_node, "create_node");
    run_test(test_add_node, "add_node");
    run_test(test_search, "search");
    run_test(test_delete_node, "delete_node");
    run_test(test_print_list, "print_list");
    run_test(test_get_length, "get_length");
    run_test(test_free_list, "free_list");

    printf("Tests run: %d\n", tests_run);
    printf("Tests failed: %d\n", tests_failed);

    return tests_failed ? EXIT_FAILURE : EXIT_SUCCESS;
}
