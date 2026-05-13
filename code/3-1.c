#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node {
    char name[50];
    int score;
    struct Node* next;
};
int main() {
    struct Node* head = NULL;
    char word[20];
    char name[50];
    int score;
    while (1) {
        scanf("%s", word);
        if (strcmp(word, "add") == 0) {
            scanf("%s %d", name, &score);
            struct Node* n = (struct Node*)malloc(sizeof(struct Node));
            strcpy(n -> name, name);
            n -> score = score;
            n -> next = NULL;
            if (head == NULL) {
                head = n;
            } else {
                struct Node* node = head;
                while (node -> next != NULL) {
                    node = node -> next;
                }
                node -> next = n;
            }
        } else if (strcmp(word, "delete") == 0) {
            scanf("%s", name);
            struct Node* node = head;
            struct Node* a = NULL;
            if (strcmp(node -> name, name) == 0) {
                head = node -> next;
                free(node);
                continue;
            }
            while (node != NULL && strcmp(node -> name, name) != 0) {
                a = node;
                node = node -> next;
            }
            if (node != NULL) {
                a -> next = node -> next;
                free(node);
            }
        } else if (strcmp(word, "print") == 0) {
            struct Node* node = head;
            while (node != NULL) {
                printf("%s %d\n", node -> name, node -> score);
                node = node -> next;
            }
        } else if (strcmp(word, "quit") == 0) {
            break;
        }
    }
    return 0;
}
