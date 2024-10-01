#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

struct node
{
    char inf[256];
    struct node* next;
};

struct node* head = NULL;
int size = 0;

void push(void);
void pop(void);
void display(void);
struct node* front(void);
int is_empty(void);

struct node* get_struct(void)
{
    setlocale(LC_ALL, "Russian");
    struct node* p = NULL;
    char s[256];

    if ((p = (struct node*)malloc(sizeof(struct node))) == NULL)
    {
        printf("Ошибка при распределении памяти\n");
        exit(1);
    }

    printf("Введите данные: \n");
    scanf("%s", s);
    if (*s == 0)
    {
        printf("Запись не была произведена\n");
        return NULL;
    }
    strcpy(p->inf, s);

    p->next = head;

    return p;
}

void push(void)
{
    setlocale(LC_ALL, "Russian");
    struct node* p = get_struct();
    head = p;
    if (p == NULL) return;

    if (is_empty())
    {
        head = p;
    }

    size++;
    printf("Элемент добавлен в стек\n");
}

void pop(void)
{
    setlocale(LC_ALL, "Russian");
    if (is_empty())
    {
        printf("Стек пуст\n");
        return;
    }

    struct node* temp = head;
    head = head->next;
    free(temp);
    size--;

    if (size == 0)
    {
        head = NULL;
    }

    printf("Элемент удален из стека\n");
}

void display(void)
{
    setlocale(LC_ALL, "Russian");
    if (is_empty())
    {
        printf("Стек пуст\n");
        return;
    }

    struct node* current = head;
    printf("Содержимое стека:\n");
    while (current)
    {
        printf("%s\n", current->inf);
        current = current->next;
    }
}

struct node* front(void)
{
    setlocale(LC_ALL, "Russian");
    if (is_empty())
    {
        printf("Стек пуст\n");
        return NULL;
    }
    return head;
}

int is_empty(void)
{
    return size == 0;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int choice;
    while (1)
    {
        printf("\nВыберите действие:\n");
        printf("1. Добавить элемент в стек\n");
        printf("2. Удалить элемент из стека\n");
        printf("3. Показать содержимое стека\n");
        printf("4. Показать верхний элемент стека\n");
        printf("5. Выйти\n");
        printf("Ваш выбор: ");
        if (!scanf("%d", &choice)) return 1;

        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
        {
            struct node* first = front();
            if (first)
                printf("Верхний элемент стека: %s\n", first->inf);
        }
        break;
        case 5:
            exit(0);
        default:
            printf("Неверный выбор. Попробуйте снова.\n");
        }
    }
    return 0;
}