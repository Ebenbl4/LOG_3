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

struct node* head = NULL, * tail = NULL;
int size = 0;

void enqueue(void);
void dequeue(void);
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

    printf("Введите название объекта: \n");
    scanf("%s", s);
    if (*s == 0)
    {
        printf("Запись не была произведена\n");
        return NULL;
    }
    strcpy(p->inf, s);

    p->next = NULL;

    return p;
}

void enqueue(void)
{
    setlocale(LC_ALL, "Russian");
    struct node* p = get_struct();
    if (p == NULL) return;

    if (is_empty())
    {
        head = tail = p;
    }
    else
    {
        tail->next = p;
        tail = p;
    }
    size++;
    printf("Элемент добавлен в очередь\n");
}

void dequeue(void)
{
    setlocale(LC_ALL, "Russian");
    if (is_empty())
    {
        printf("Очередь пуста\n");
        return;
    }

    struct node* temp = head;
    head = head->next;
    free(temp);
    size--;

    if (size == 0)
    {
        tail = NULL;
    }

    printf("Элемент удален из очереди\n");
}

void display(void)
{
    setlocale(LC_ALL, "Russian");
    if (is_empty())
    {
        printf("Очередь пуста\n");
        return;
    }

    struct node* current = head;
    printf("Содержимое очереди:\n");
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
        printf("Очередь пуста\n");
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
        printf("1. Добавить элемент в очередь\n");
        printf("2. Удалить элемент из очереди\n");
        printf("3. Показать содержимое очереди\n");
        printf("4. Показать первый элемент очереди\n");
        printf("5. Выйти\n");
        printf("Ваш выбор: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
        {
            struct node* first = front();
            if (first)
                printf("Первый элемент очереди: %s\n", first->inf);
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