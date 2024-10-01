#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct Node {
    int data;
    int priority;
    struct Node* next;
} Node;

Node* createNode(int data, int priority) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;
    return newNode;
}

void enqueue(Node** head, int data, int priority) {
    Node* newNode = createNode(data, priority);

    if (*head == NULL || priority > (*head)->priority) {
        newNode->next = *head;
        *head = newNode;
    }
    else {
        Node* current = *head;
        while (current->next != NULL && current->next->priority >= priority) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

int deleteByPriority(Node** head) {
    setlocale(LC_ALL, "Russian");
    if (*head == NULL) {
        printf(" Очередь пуста\n");
        return -1;
    }

    Node* temp = *head;
    int data = temp->data;
    *head = (*head)->next;
    free(temp);
    return data;
}



void deleteByContent(Node** head, int data) {
    setlocale(LC_ALL, "Russian");
    if (*head == NULL) {
        printf(" Очередь пуста\n");
        return;
    }

    if ((*head)->data == data) {
        Node* temp = *head;
        *head = (*head)->next;
        free(temp);
        printf(" Элемент %d удален\n", data);
        return;
    }

    Node* current = *head;
    Node* prev = NULL;

    while (current != NULL && current->data != data) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf(" Элемент %d не найден\n", data);
        return;
    }

    prev->next = current->next;
    free(current);
    printf(" Элемент %d удален\n", data);
}

void printList(Node* head) {
    setlocale(LC_ALL, "Russian");
    if (head == NULL) {
        printf(" Список пуст\n");
        return;
    }
    Node* current = head;
    while (current != NULL) {
        printf("(Данные: %d, Приоритет: %d), ", current->data, current->priority);
        current = current->next;
    }
    printf("\n");
}

int main() {
    setlocale(LC_ALL, "Russian");
    Node* head = NULL;
    int choice, data, priority;

    while (1) {
        printf("\n Выберите действие:\n");
        printf(" 1. Добавить элемент\n");
        printf(" 2. Удалить элемент с наибольшим приоритетом\n");
        printf(" 3. Удалить элемент по содержимому\n");
        printf(" 4. Показать очередь\n");
        printf(" 5. Выйти\n");
        printf(" Ваш выбор: ");
        scanf(" %d", &choice);

        switch (choice) {
        case 1:
            printf(" Введите данные: ");
            scanf(" %d", &data);
            printf(" Введите приоритет: ");
            scanf(" %d", &priority);
            enqueue(&head, data, priority);
            printf(" Элемент добавлен\n");
            break;
        case 2:
            data = deleteByPriority(&head);
            if (data != -1) {
                printf(" Удален элемент: %d\n", data);
            }
            break;
        case 3:
            printf(" Введите данные элемента для удаления: ");
            scanf(" %d", &data);
            deleteByContent(&head, data);
            break;
        case 4:
            printf(" Текущая очередь: ");
            printList(head);
            break;
        case 5:
            printf(" Программа завершила свою работу.\n");
            exit(0);
        default:
            printf(" Неверный выбор. Попробуйте снова.\n");
        }
    }
    return 0;
}