#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

struct node {
    char inf[256];
    struct node* next;
};

struct node* head = NULL;
struct node* last = NULL;

void push(char* name) {
    struct node* p = (struct node*)malloc(sizeof(struct node));
    strcpy_s(p->inf, sizeof(p->inf), name);
    p->next = NULL;

    if (head == NULL) {
        head = last = p;
    }
    else {
        last->next = p;
        last = p;
    }
}

void pop(void) {
    if (head == NULL) {
        printf("Очередь пуста!\n");
        return;
    }
    struct node* temp = head;
    printf("Извлечен из очереди: %s\n", temp->inf);
    head = head->next;
    if (head == NULL) last = NULL;
    free(temp);
}

void print_queue(void) {
    struct node* curr = head;
    if (curr == NULL) {
        printf("Очередь пуста.\n");
        return;
    }
    printf("\nОчередь (FIFO): ");
    while (curr != NULL) {
        printf("[%s] -> ", curr->inf);
        curr = curr->next;
    }
    printf("NULL\n");
}

int main(void) {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int choice = 0;
    char text[256];

    while (1) {
        printf("\n1. Встать в очередь (push)\n2. Выйти из очереди (pop)\n3. Показать очередь\n0. Выход\nВыбор: ");
        if (scanf_s("%d", &choice) != 1) break;
        getchar();

        if (choice == 0) break;

        if (choice == 1) {
            printf("Введите значение: ");
            gets_s(text, sizeof(text));
            push(text);
        }
        else if (choice == 2) {
            pop();
        }
        else if (choice == 3) {
            print_queue();
        }
    }

    return 0;
}