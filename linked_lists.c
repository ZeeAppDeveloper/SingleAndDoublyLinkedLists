#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Animal {
    char name[50];
    char species[50];
    char caretaker[50];
} Animal;

typedef struct Node {
    Animal data;
    struct Node* next;
} Node;

typedef struct DoublyNode {
    Animal data;
    struct DoublyNode* next;
    struct DoublyNode* prev;
} DoublyNode;

void addAnimal(Node** head, Animal animal) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = animal;
    new_node->next = *head;
    *head = new_node;
}

void addAnimalDoubly(DoublyNode** head, Animal animal) {
    DoublyNode* new_node = (DoublyNode*)malloc(sizeof(DoublyNode));
    new_node->data = animal;
    new_node->next = *head;
    new_node->prev = NULL;
    if (*head != NULL) {
        (*head)->prev = new_node;
    }
    *head = new_node;
}

void listAnimalsByCaretaker(Node* head, const char* caretaker) {
    Node* current = head;
    while (current != NULL) {
        if (strcmp(current->data.caretaker, caretaker) == 0) {
            printf("Animal: %s, Species: %s\n", current->data.name, current->data.species);
        }
        current = current->next;
    }
}

int main() {
    Node* head = NULL;

    Animal a1 = {"Leo", "Lion", "John"};
    Animal a2 = {"Ella", "Elephant", "John"};
    Animal a3 = {"Milo", "Monkey", "Anna"};

    addAnimal(&head, a1);
    addAnimal(&head, a2);
    addAnimal(&head, a3);

    printf("Animals cared for by John:\n");
    listAnimalsByCaretaker(head, "John");

    return 0;
}
