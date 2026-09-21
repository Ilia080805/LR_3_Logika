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

void push(char* name) {
    struct node* p = (struct node*)malloc(sizeof(struct node));
    strcpy_s(p->inf, sizeof(p->inf), name);
    p->next = head;
    head = p;
}

void pop(void) {
    if (head == NULL) {
        printf("Стек пуст!\n");
        return;
    }
    struct node* temp = head;
    printf("Вытолкнут из стека: %s\n", temp->inf);
    head = head->next;
    free(temp);
}

void print_stack(void) {
    struct node* curr = head;
    if (curr == NULL) {
        printf("Стек пуст.\n");
        return;
    }
    printf("\n--- СОДЕРЖИМОЕ СТЕКА (ВЕРШИНА СВЕРХУ) ---\n");
    while (curr != NULL) {
        printf("| %-20s |\n", curr->inf);
        curr = curr->next;
    }
    printf("-----------------------------------------\n");
}

int main(void) {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int choice = 0;
    char text[256];

    while (1) {
        printf("\n1. Положить в стек (push)\n2. Забрать из стека (pop)\n3. Показать стек\n0. Выход\nВыбор: ");
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
            print_stack();
        }
    }

    return 0;
}