#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    struct node* next;
    struct node* prev;
    char* data;
} typedef Node;

struct linkedList {
    int size;
    Node** nodes;
} typedef LinkedList;

void add(char* word);

void delete(char* word);

int findInsertionPoint(char* word);

void printList();

LinkedList* list; // declare as global var

int main() {
    // Create LL
    list = malloc(sizeof(LinkedList));
    list->size = 0;
    list->nodes = malloc(sizeof(Node) * 100); // give it a fuck ton of initial space
    add("AAA");
    // add("BBB");
    // add("DDD");
    // add("CCC");
    delete("AAA");
    add("AAA");
    add("DDD");
    add("BBB");
    add("CCC");
    printList();
}

void add(char* word) {
    // Allocate memory for a new node
    Node* newNode = malloc(sizeof(Node));
    newNode->next = malloc(sizeof(Node));
    newNode->prev = malloc(sizeof(Node));
    newNode->data = word;
    if (list->size == 0) { // List empty
        printf("Inserting %s at front of list\n", word);
        list->nodes[list->size] = newNode;
        newNode->next = NULL;
        newNode->prev = NULL;
        list->size += 1;
        return;
    }
    else { // List is not empty
        int insertionPoint = findInsertionPoint(word);
        if (insertionPoint == -1) {
            perror("Error: Word already in list\n");
            exit(-1);
        }
        else if (insertionPoint == 0){ // Insert at front of list
            printf("Inserting %s at front of list\n", word);
            list->nodes[0]->prev = newNode;
            newNode->next = list->nodes[0];
            newNode->prev = NULL;
            list->nodes[0] = newNode;
            list->size += 1;
            return;
        }
        else if (insertionPoint == list->size) { // Insert at end of list
            printf("Inserting %s at end of list\n", word);
            Node* currNode = list->nodes[0];
            while (currNode->next != NULL) {
                currNode = currNode->next;
            }
            currNode->next = newNode;
            newNode->prev = currNode;
            newNode->next = NULL;
            list->size += 1;
            return;
        }
        else { // Insert at middle of list
            printf("Inserting %s at middle of list: %d\n", word, insertionPoint);
            int count = 0;
            Node* currNode = list->nodes[0];
            while (currNode != NULL) {
                if (count == insertionPoint) { // Insertion point found
                    // printf("Replacing %s\n", currNode->data);
                    break;
                }
                count++;
                currNode = currNode->next;
            }
            // Adjust pointers
            currNode->prev->next = newNode;
            newNode->prev = currNode->prev;
            newNode->next = currNode;
            currNode->prev = newNode;
            return;
        }
    }
}

void delete(char* word) {
    int count = 0;
    // Search for node to remove
    Node* currNode = list->nodes[0];
    while (currNode != NULL) {
        if (word == currNode->data) { // Node found
            printf("Removing %s\n", currNode->data);
            break;
        }
        count++; 
        currNode = currNode->next;
    }
    printf("Deleting %s\n", currNode->data);
    if (strcmp(currNode->data, list->nodes[0]->data) == 0) { // Removing the only node in our list
        free(currNode->next);
        free(currNode->prev);
        free(currNode);
        return;
    }
}

int findInsertionPoint(char* word) {
    // Loop thru and strcmp until we find where we belong
    int comparison;
    int nodeCount = 0;
    Node* currNode = list->nodes[0];
    while (currNode != NULL){
        comparison = strcmp(word, currNode->data);
        if (comparison<0) { // Insertion point found
            return nodeCount;
        }
        else if (comparison == 0) { // Error, can't have duplicate words
            return -1;
        }
        currNode = currNode->next;
        nodeCount++;
    }
    // Word is greater than all other words in the list
    return list->size;
}

void printList() {
    if (list->nodes[0] == NULL) {
        // List is empty
        printf("No data to display\n");
        return;
    }
    Node* currNode = list->nodes[0];
    while (currNode != NULL) {
        printf("%s\n", currNode->data);
        currNode = currNode->next;
    }
}
