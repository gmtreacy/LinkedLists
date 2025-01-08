#include "liblist.h"

#include <stdio.h>
#include <stdlib.h>
#include <threads.h>

Node *create_node(void) {
    Node *node = malloc(sizeof(Node));
    if (node == NULL) {
        return NULL;
    }
    node->next = NULL;
    node->data = 0;
    return node;
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

    Node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = end;
    return head;
}

const Node *search(const Node *head, int value) {
    if (head == NULL) {
        return NULL;
    }

    const Node *current = head;
    while (current != NULL) {
        if (current->data == value) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// deletes all nodes with this value
Node *delete_node(Node *head, int value) {
    Node *current = head;
    Node *prev = NULL; /* only the head's currentrev can be null */

    while (current != NULL) {
        if (current->data == value) {
            Node *temp = current;
            if (prev == NULL) {
                head = current->next;
            } else {
                prev->next = current->next;
            }
            current = current->next;
            free(temp);
        } else {
            prev = current;
            current = current->next;
        }
    }

    return head;
}

void print_list(const Node *head) {
    int idx = 0;
    while (head != NULL) {
        printf("%d, %d, %p, %p\n", idx, head->data, (void *)head, (void *)head->next);
        head = head->next;
        ++idx;
    }
}

int get_length(const Node *head) {
    int idx = 0;
    while (head != NULL) {
        head = head->next;
        ++idx;
    }
    return idx;
}

void free_list(Node *head) {
    while (head != NULL) {
        Node *temp = head;
        head = head->next;
        free(temp);
    }
}
