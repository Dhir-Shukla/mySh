#include <stddef.h>
#include <stdlib.h>
#include "variables.h"

struct node* start = NULL;


// create a linked list (a pointer Node of a character), where each element has 64chars memory allocated to it. Each element/node should have the variable stored in it.

// Creating a node structure and defining it as type Node.
typedef struct node {
    char name;
    char value;
    struct node *next;
} Node;

// Inside the main, have a pointer- Node *front, that points to node with null values or the first node


char* valid_node(char *s){
    Node *curr_ptr = start;
    while (curr_ptr != NULL) {
        if ((curr_ptr->name) == *s) {
            return &(curr_ptr->value);
        }
        curr_ptr = curr_ptr->next;
    }
    return NULL;
}

// We recieve data and want to create a node from it
Node* create_node(char name, char value){
    Node *new_node = malloc(sizeof(Node));
    new_node->name = name;
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

// Insert node into our linked list, list pointer must be passed as a parameter, variable must be passed as a parameter
int insert_node(char name, char value){
    Node *curr_ptr = start;
    if (start == NULL) {
        start = create_node(name, value);
        return 0;
    }
    else if (start->next == NULL) {
        start->next = create_node(name, value);
        return 0;
    }
    while (curr_ptr->next != NULL){
        if (curr_ptr->name == name){
            curr_ptr->value = value;
            return 0;
        curr_ptr = curr_ptr->next;
        }
    }
    if (curr_ptr->name == name) {
        curr_ptr->value = value;
        return 0;
    }
    curr_ptr->next = create_node(name, value);
    return 0;
}