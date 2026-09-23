#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

struct node {
    char inf[256];
    int priority;
    struct node* next;
};

struct node* head = NULL;

void push(char* name, int pr) {
    struct node* p = (struct node*)malloc(sizeof(struct node));
    strcpy_s(p->inf, sizeof(p->inf), name);
    p->priority = pr;
    p->next = NULL;

    if (head == NULL || pr > head->priority) {
        p->next = head;
        head = p;
    }
    else {
        struct node* curr = head;
        while (curr->next != NULL && curr->next->priority >= pr) {
            curr = curr->next;
        }
        p->next = curr->next;
        curr->next = p;
    }
}

void pop(void) {
    if (head == NULL) {
        printf("Очередь пуста!\n");
        return;
    }
    struct node* temp = head;
    printf("Извлечен элемент: %s (приоритет: %d)\n", temp->inf, temp->priority);
    head = head->next;
    free(temp);
}

void change_priority(char* name, int new_pr) {
    if (head == NULL) {
        printf("Очередь пуста!\n");
        return;
    }

    struct node* curr = head;
    struct node* prev = NULL;

    while (curr != NULL && strcmp(curr->inf, name) != 0) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL) {
        printf("Элемент \"%s\" не найден в очереди!\n", name);
        return;
    }

    if (prev == NULL) {
        head = curr->next;
    }
    else {
        prev->next = curr->next;
    }
    free(curr);

    push(name, new_pr);
    printf("Приоритет элемента \"%s\" успешно изменен на %d!\n", name, new_pr);
}

void print_list(void) {
    struct node* curr = head;
    if (curr == NULL) {
        printf("Очередь пуста.\n");
        return;
    }
    printf("\n--- ТЕКУЩАЯ ПРИОРИТЕТНАЯ ОЧЕРЕДЬ ---\n");
    while (curr != NULL) {
        printf("[Приоритет: %d] %s\n", curr->priority, curr->inf);
        curr = curr->next;
    }
    printf("-----------------------------------\n");
}

int main(void) {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int choice = 0;
    char text[256];
    int pr = 0;

    while (1) {
        printf("\n1. Добавить элемент\n2. Извлечь элемент (pop)\n3. Изменить приоритет элемента\n4. Показать очередь\n0. Выход\nВыбор: ");
        if (scanf_s("%d", &choice) != 1) break;
        getchar();

        if (choice == 0) break;

        if (choice == 1) {
            printf("Введите название объекта: ");
            gets_s(text, sizeof(text));
            printf("Введите его приоритет (целое число): ");
            scanf_s("%d", &pr);
            push(text, pr);
        }
        else if (choice == 2) {
            pop();
        }
        else if (choice == 3) {
            printf("Введите название объекта, приоритет которого хотите изменить: ");
            gets_s(text, sizeof(text));
            printf("Введите НОВЫЙ приоритет: ");
            scanf_s("%d", &pr);
            change_priority(text, pr);
        }
        else if (choice == 4) {
            print_list();
        }
    }

    return 0;
}